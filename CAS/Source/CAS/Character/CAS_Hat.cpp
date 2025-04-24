// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CAS_Hat.h"
#include "Components/SphereComponent.h"

// Sets default values
ACAS_Hat::ACAS_Hat()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	_collider->SetupAttachment(_mesh);
	RootComponent = _mesh;
}

// Called when the game starts or when spawned
void ACAS_Hat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACAS_Hat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACAS_Hat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

