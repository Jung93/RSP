// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RSP_ItemShop.h"
#include "RSP_Player.h"
#include "Blueprint/UserWidget.h"
#include "UI/RSP_KeyPressEvent.h"
#include "UI/RSP_InvenUI.h"
#include "UI/RSP_StoreUI.h"
#include "UI/RSP_InvenComponent.h"
#include "RSP_PlayerController.h"

#include "RSP_GameInstance.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
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

	static ConstructorHelpers::FClassFinder<URSP_KeyPressEvent> keyPressUI(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_RSP_KeyPressEvent.BP_RSP_KeyPressEvent_C'"));
	if (keyPressUI.Succeeded())
	{
		_shopEnterWidget->SetWidgetClass(keyPressUI.Class);
	}
	static ConstructorHelpers::FClassFinder<URSP_StoreUI> invenClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_RSP_StoreUI.BP_RSP_StoreUI_C'"));
	if (invenClass.Succeeded()) {
		_storeWidget = CreateWidget<URSP_StoreUI>(GetWorld(), invenClass.Class);
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
	
	_storeWidget->AddToViewport();
	_storeWidget->SetVisibility(ESlateVisibility::Collapsed);

	_storeWidget->RSP_ExitButton->OnClicked.AddDynamic(this, &ThisClass::CloseShopUI);
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
		auto controller = Cast<ARSP_PlayerController>(player->GetController());
		controller->ShowUI();
		player->_interaction = true;
	}
}

void ARSP_ItemShop::ColliderEndOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	_shopEnterWidget->GetWidget()->SetVisibility(ESlateVisibility::Collapsed);
	bCanInteraction = false;
	auto player = Cast<ARSP_Player>(OtherActor);
	if (player) {
		auto controller = Cast<ARSP_PlayerController>(player->GetController());
		controller->HideUI();
		player->_interaction = false;
		
	}
	_storeWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void ARSP_ItemShop::OpenShopUI(AActor* actor)
{
	_storeWidget->SetVisibility(ESlateVisibility::Visible);	
	bCanInteraction = false;
	//플레이어에게 추가효과 넣기 가능
}

void ARSP_ItemShop::CloseShopUI()
{
	_storeWidget->SetVisibility(ESlateVisibility::Collapsed);
	bCanInteraction = true;
}

