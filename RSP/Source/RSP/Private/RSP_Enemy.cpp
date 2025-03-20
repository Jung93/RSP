// Fill out your copyright notice in the Description page of Project Settings.

#include "RSP_Enemy.h"
#include "RSP_Character.h"
#include "RSP_Player.h"
#include "RSP_StatComponent.h"

#include "InputActionValue.h"

#include "Engine/DamageEvents.h"
#include "Components/CapsuleComponent.h"

#include "Animation/RSP_AnimInstance.h"

ARSP_Enemy::ARSP_Enemy()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("RSP_Enemy"));

}

void ARSP_Enemy::Attack_Hit()
{
	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	FVector forward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);


	float attackRadius = 100.0f;

	FVector Center = GetActorLocation() + forward * _attackRange * 0.5f; 
	FVector Start = GetActorLocation() + forward * _attackRange * 0.5f; 
	FVector End = GetActorLocation() + forward * _attackRange * 0.5f; 

	bool bResult = GetWorld()->SweepSingleByChannel( 
		OUT hitResult,
		Start,
		End,
		quat,
		ECC_GameTraceChannel1,
		FCollisionShape::MakeCapsule(attackRadius, _attackRange * 0.5f),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		drawColor = FColor::Red;
		ARSP_Player* victim = Cast<ARSP_Player>(hitResult.GetActor());
		if (victim) {
			FDamageEvent damageEvent = FDamageEvent();
			FVector hitPoint = hitResult.ImpactPoint;
			//EFFECT_M->PlayEffect("BigFire", hitPoint);
			victim->TakeDamage(_statComponent->GetAtk(), damageEvent, GetController(), this);
			
		}
	}

	DrawDebugCapsule(
		GetWorld(),
		Center,
		_attackRange * 0.5f,
		attackRadius,
		quat,
		drawColor,
		false,
		3.0f
	);
}

void ARSP_Enemy::BeginPlay()
{
	Super::BeginPlay();

	//_animInstance->OnMontageEnded.AddDynamic(this, &ARSP_Character::AttackEnd);
	//_animInstance->_attackEvent.AddUObject(this, &ARSP_Enemy::Attack_Hit);
	//_animInstance->_deadEvent.AddUObject(this, &ARSP_Enemy::DeadEvent);
}

void ARSP_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARSP_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
