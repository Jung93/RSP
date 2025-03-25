// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RSP_ItemShop.h"
#include "RSP_Player.h"
#include "RSP_GameInstance.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ARSP_ItemShop::ARSP_ItemShop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	_collider->SetupAttachment(_mesh);
	RootComponent = _mesh;

	_collider->SetCollisionProfileName(TEXT("RSP_Item"));
	_collider->SetRelativeLocation(FVector(0, 0, 44.0f));
	//콜라이더의 크기는 에디터에서 조정

	//static ConstructorHelpers::FClassFinder<URSP_HpBar> hpBarClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_RSP_HpBar.BP_RSP_HpBar_C'"));
	//if (hpBarClass.Succeeded())
	//{
	//	_shopEnterWidget->SetWidgetClass(hpBarClass.Class);
	//}
	//
}

// Called when the game starts or when spawned
void ARSP_ItemShop::BeginPlay()
{
	Super::BeginPlay();
	_collider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::ColliderOverlapped);

}

// Called every frame
void ARSP_ItemShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARSP_ItemShop::ColliderOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

