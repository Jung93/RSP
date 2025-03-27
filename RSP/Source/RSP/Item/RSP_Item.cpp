// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RSP_Item.h"
#include "RSP_Player.h"
#include "RSP_GameInstance.h"
#include "UI/RSP_KeyPressEvent.h"
#include "Blueprint/UserWidget.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
ARSP_Item::ARSP_Item()
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
}

// Called when the game starts or when spawned
void ARSP_Item::BeginPlay()
{
	Super::BeginPlay();
	_itemCollider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
	_itemCollider->OnComponentEndOverlap.AddDynamic(this, &ThisClass::EndOverlap);

	_shopEnterWidget->SetCastShadow(false);

	auto widget = _shopEnterWidget->GetWidget();
	auto keyPressWidget = Cast<URSP_KeyPressEvent>(widget);
	keyPressWidget->SetTexture(_keyTexture);

	_shopEnterWidget->GetWidget()->SetVisibility(ESlateVisibility::Collapsed);

}

// Called every frame
void ARSP_Item::Tick(float DeltaTime)
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

void ARSP_Item::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	_shopEnterWidget->GetWidget()->SetVisibility(ESlateVisibility::Visible);
	bCanInteraction = true;
}

void ARSP_Item::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	_shopEnterWidget->GetWidget()->SetVisibility(ESlateVisibility::Collapsed);
	bCanInteraction = false;
}


void ARSP_Item::ActivateItemEffect(AActor* actor)
{
}

void ARSP_Item::SetInfomation(FString name)
{
	auto gameInstance = Cast<URSP_GameInstance>(GetWorld()->GetGameInstance());
	auto RSP_info = gameInstance->GetItemInfo(name);

	_itemId = RSP_info.itemId;
	_itemName = RSP_info.itemName;
	_itemPrice = RSP_info.itemPrice;
	_itemToolTip = RSP_info.itemToolTip;
	_itemStat = RSP_info.itemStat;
	_itemMaxCount = RSP_info.itemMaxCount; ;

	_info = RSP_info;
}

