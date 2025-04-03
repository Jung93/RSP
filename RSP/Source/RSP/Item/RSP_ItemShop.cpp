// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RSP_ItemShop.h"
#include "Item/RSP_Item.h"
#include "RSP_GameInstance.h"
#include "RSP_Player.h"
#include "Blueprint/UserWidget.h"
#include "UI/RSP_KeyPressEvent.h"
#include "UI/RSP_InvenUI.h"
#include "UI/RSP_StoreUI.h"
#include "UI/RSP_InvenComponent.h"
#include "RSP_PlayerController.h"

#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/WidgetTree.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFrameWork/PlayerController.h"
// Sets default values
ARSP_ItemShop::ARSP_ItemShop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_keyTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/Icon/T_f_256px_gray.T_f_256px_gray'"));

	_itemCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	_itemCollider->SetupAttachment(_mesh);
	RootComponent = _mesh;

	_itemCollider->SetCollisionProfileName(TEXT("RSP_Item"));
	_itemCollider->SetRelativeLocation(FVector(0, 0, 44.0f));

	FVector currentScale = _itemCollider->GetRelativeScale3D();
	_itemCollider->SetRelativeScale3D(currentScale * 10.0f);

	_shopEnterWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction"));
	_shopEnterWidget->SetupAttachment(_mesh);
	_shopEnterWidget->SetWidgetSpace(EWidgetSpace::Screen);

	_storeComponent = CreateDefaultSubobject<URSP_InvenComponent>(TEXT("StoreComponent"));

	static ConstructorHelpers::FClassFinder<URSP_StoreUI> invenClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_StoreUI.BP_StoreUI_C'"));
	if (invenClass.Succeeded()) {
		storeUIClass = invenClass.Class;
	}
	static ConstructorHelpers::FClassFinder<URSP_KeyPressEvent> keyPressUI(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_RSP_KeyPressEvent.BP_RSP_KeyPressEvent_C'"));
	if (keyPressUI.Succeeded())
	{
		_shopEnterWidget->SetWidgetClass(keyPressUI.Class);
	}
}

// Called when the game starts or when spawned
void ARSP_ItemShop::BeginPlay()
{
	Super::BeginPlay();

	_itemCollider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::ColliderBeginOverlapped);
	_itemCollider->OnComponentEndOverlap.AddDynamic(this, &ThisClass::ColliderEndOverlapped);
	
	_shopEnterWidget->SetCastShadow(false);

	auto widget = _shopEnterWidget->GetWidget();
	auto keyPressWidget = Cast<URSP_KeyPressEvent>(widget);
	keyPressWidget->SetTexture(_keyTexture);

	_shopEnterWidget->GetWidget()->SetVisibility(ESlateVisibility::Collapsed);

	_storeWidget = CreateWidget<URSP_StoreUI>(GetWorld(), storeUIClass);
	_storeWidget->AddToViewport();

	_storeWidget->RSP_ExitButton->OnClicked.AddDynamic(this, &ThisClass::CloseShopUI);
	_storeWidget->totalItemPriceEvent_Buy.AddUObject(_storeWidget, &URSP_StoreUI::TotalItemPrice_Buy);
	_storeWidget->totalItemPriceEvent_Sell.AddUObject(_storeWidget, &URSP_StoreUI::TotalItemPrice_Sell);
	_storeWidget->RSP_BuyButton->OnClicked.AddDynamic(this, &ThisClass::MoveItem_StoreToInven);
	_storeWidget->RSP_SellButton->OnClicked.AddDynamic(this, &ThisClass::MoveItem_InvenToStore);

	_storeComponent->setitemTextureEvent.AddUObject(_storeWidget, &URSP_StoreUI::UpdateStoreInven);
	
	_storeWidget->SetVisibility(ESlateVisibility::Collapsed);


}

// Called every frame
void ARSP_ItemShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto playerCameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	if (playerCameraManager)
	{
		FVector widgetLocation = _shopEnterWidget->GetComponentLocation();
		FVector cameraLocation = playerCameraManager->GetCameraLocation();
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(widgetLocation, cameraLocation);
		_shopEnterWidget->SetWorldRotation(rotation);
	}

}

void ARSP_ItemShop::ColliderBeginOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	_shopEnterWidget->GetWidget()->SetVisibility(ESlateVisibility::Visible);
	bCanInteraction = true;
	auto player = Cast<ARSP_Player>(OtherActor);
	if (player) {
		
		player->_interaction = true;
	}
}

void ARSP_ItemShop::ColliderEndOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	_shopEnterWidget->GetWidget()->SetVisibility(ESlateVisibility::Collapsed);
	bCanInteraction = false;
	auto player = Cast<ARSP_Player>(OtherActor);
	if (player) {
	
		player->_interaction = false;
		
	}
	_storeWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void ARSP_ItemShop::OpenShopUI(AActor* actor)
{
	_storeWidget->SetVisibility(ESlateVisibility::Visible);
	bCanInteraction = false;

	auto player = Cast<ARSP_Player>(actor);
	if (player) {
		auto controller = Cast<ARSP_PlayerController>(player->GetController());
		controller->ShowUI(_storeWidget);
		auto curGold = player->GetCurGold();

		_storeWidget->SetGold(curGold);

		TArray<ARSP_Item*> playerInven = player->GetItemArray_Inven();
		_storeComponent->SetItemArray_Inven(playerInven);
		_storeComponent->UpdateInven(this);
	}
}

void ARSP_ItemShop::CloseShopUI()
{
	_storeWidget->SetVisibility(ESlateVisibility::Collapsed);
	bCanInteraction = true;
	ARSP_PlayerController* playerController = Cast<ARSP_PlayerController>(GetWorld()->GetFirstPlayerController());
	
	if (playerController) {
		playerController->HideUI();
		auto player = Cast<ARSP_Player>(playerController->GetPawn());
		auto curGold = _storeWidget->GetGold();
		player->SetCurGold(curGold);
	
		TArray<ARSP_Item*> storeInven = _storeComponent->GetItemArray_Inven();
		player->SetItemArray_Inven(storeInven);
		_storeComponent->UpdateInven(this);
	}
}

void ARSP_ItemShop::SetItemTexture(int32 index, FRSP_ItemInfo info)
{
	_storeWidget->SetItemTexture(index, info);
}


void ARSP_ItemShop::MoveItem_StoreToInven()
{	
	auto playerGold = _storeWidget->GetCurPlayerGold();
	auto totalItemPrice = _storeWidget->GetTotalItemPrice_Buy();
	if (playerGold < totalItemPrice) {
		return;
	}
	_storeWidget->AddGold(-totalItemPrice);

	auto storeSlots = _storeWidget->GetStoreSlots();	
	auto invenSlots = _storeWidget->GetInvenSlots();

	for (auto& slot : storeSlots) {
		if (slot->bIsChosen) {
			FRSP_ItemInfo itemInfo = slot->GetItemInfo();
			int32 slotIndex = slot->curIndex;
			
			ARSP_Item* spawnedItem = GetWorld()->SpawnActor<ARSP_Item>(FVector::ZeroVector, FRotator::ZeroRotator);			
			spawnedItem->SetInfo(itemInfo);
			int32 itemIndex = _storeComponent->GetEmptyIndex();
			_storeComponent->AddItem_Store(spawnedItem,this);
						
			_storeWidget->SetThisItemToopTip(slot, "Sold Out");
			slot->HighLightAction();
			_storeWidget->SetItemTexture_Buy(slotIndex, FRSP_ItemInfo());
			_storeWidget->SetSoldOutTexture(slotIndex);

		}
	}
	
}

void ARSP_ItemShop::MoveItem_InvenToStore()
{
	auto totalItemPrice = _storeWidget->GetTotalItemPrice_Sell();
	_storeWidget->AddGold(totalItemPrice);

	auto invenSlots = _storeWidget->GetInvenSlots();

	for (auto& slot : invenSlots) {
		if (slot->bIsChosen) {
			auto index = slot->curIndex;
			
			slot->HighLightAction();
			_storeComponent->SellThisItem(index);
			_storeWidget->SetItemTexture(index, FRSP_ItemInfo());		
			_storeWidget->SetThisItemToopTip(slot, "");
			if (FMath::Abs(_storeWidget->GetTotalItemPrice_Sell()) >= 1 && FMath::Abs(_storeWidget->GetTotalItemPrice_Sell()) < 2) {
				_storeWidget->SetTotalItemPrice_Sell(0);
				auto str = FString::Printf(TEXT("%d"), 0);
				_storeWidget->RSP_ItemPriceText_Sell->SetText(FText::FromString(str));
			}

		}
	}

}



