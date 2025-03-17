// Fill out your copyright notice in the Description page of Project Settings.

#include "RSP_Character.h"
#include "RSP_Player.h"
#include "RSP_Enemy.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Engine/DamageEvents.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


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

	//start 에서 end까지 쓸고 지나가는 형태의 충돌 판정
	FVector Center = GetActorLocation() + forward * _attackRange * 0.5f; 
	FVector Start = GetActorLocation() + forward * _attackRange * 0.5f; 
	FVector End = GetActorLocation() + forward * _attackRange * 0.5f; 

	bool bResult = GetWorld()->SweepSingleByChannel( 
		OUT hitResult,
		Start,
		End,
		quat,
		ECC_GameTraceChannel2,
		FCollisionShape::MakeCapsule(attackRadius, _attackRange * 0.5f),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		drawColor = FColor::Red;
		ARSP_Character* victim = Cast<ARSP_Player>(hitResult.GetActor());
		if (victim) {
			FDamageEvent damageEvent = FDamageEvent();
			//UE_LOG(LogTemp, Warning, TEXT("Att Name : %s , HP : %d"), *GetName(), _statComponent->GetCurHp());

			FVector hitPoint = hitResult.ImpactPoint;
			//EFFECT_M->PlayEffect("BigFire", hitPoint);
			//victim->TakeDamage(_statComponent->GetAtk(), damageEvent, GetController(), this);
			//if (victim->_statComponent->IsDead()) {
			//	TakeEXP(victim);
			//}
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
}

void ARSP_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARSP_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
