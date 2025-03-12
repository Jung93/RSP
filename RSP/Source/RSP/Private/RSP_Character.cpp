// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_Character.h"

// Sets default values
ARSP_Character::ARSP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARSP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARSP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARSP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

