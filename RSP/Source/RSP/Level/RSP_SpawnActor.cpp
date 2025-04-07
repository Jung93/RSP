// Fill out your copyright notice in the Description page of Project Settings.


#include "Level/RSP_SpawnActor.h"
#include "RSP_Character.h"
#include "RSP_Player.h"
#include "AI/RSP_AIController.h"
#include "Components/BoxComponent.h"
// Sets default values
ARSP_SpawnActor::ARSP_SpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_triggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));

	RootComponent = _triggerBox;

	_triggerBox->SetCollisionProfileName(TEXT("Trigger"));
	_triggerBox->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ARSP_SpawnActor::BeginPlay()
{
	Super::BeginPlay();
	_triggerBox->OnComponentBeginOverlap.AddDynamic(this, &ARSP_SpawnActor::OnOverlapBegin);

}

// Called every frame
void ARSP_SpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
}

void ARSP_SpawnActor::SpawnCharacter()
{
	for (int32 i = 0; i < _spawnCount; i++) {

		auto vector = GetActorLocation() + FVector(50 * i, 50 * i, -88.0f);
		auto rotator = GetActorRotation();

		_spawnedActor = GetWorld()->SpawnActor<ARSP_Character>(CharacterClass, vector, rotator);
		_spawnedActor->SetLevel(_level);

	}
}

void ARSP_SpawnActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto player = Cast<ARSP_Player>(OtherActor);
	if (!player) {
		return;
	}
	SpawnCharacter();
	_triggerBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

