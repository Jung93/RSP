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

void ARSP_Character::AttackEnd(UAnimMontage* Montage, bool bInterrupted)
{
}

void ARSP_Character::Attack_Hit()
{
}

void ARSP_Character::DeadEvent()
{
}

void ARSP_Character::AddHp(float amount)
{
}

float ARSP_Character::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	return 0.0f;
}

bool ARSP_Character::IsDead()
{
	return false;
}

