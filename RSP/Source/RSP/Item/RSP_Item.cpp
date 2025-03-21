// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RSP_Item.h"
#include "RSP_Player.h"
#include "Components/CapsuleComponent.h"
// Sets default values
ARSP_Item::ARSP_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	_collider->SetupAttachment(_mesh);
	RootComponent = _mesh;
	
	_collider->SetCollisionProfileName(TEXT("RSP_Item"));
	_collider->SetRelativeLocation(FVector(0, 0, 44.0f));
}

// Called when the game starts or when spawned
void ARSP_Item::BeginPlay()
{
	Super::BeginPlay();
	_collider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);

}

// Called every frame
void ARSP_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARSP_Item::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto character = Cast<ARSP_Player>(OtherActor);
	if (character == nullptr) {
		return;
	}
	//character->AddHp(_healValue); 이후 추가될 기능
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	DrawDebugString(GetWorld(), GetActorLocation(), TEXT("ITEM"), nullptr, FColor::Blue, 5.0f, true);
}

