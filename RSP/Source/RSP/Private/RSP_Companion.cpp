// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_Companion.h"
#include "RSP_Enemy.h"
#include "RSP_StatComponent.h"



#include "Components/CapsuleComponent.h"
#include "Animation/RSP_AnimInstance.h"
#include "Engine/DamageEvents.h"



ARSP_Companion::ARSP_Companion()
{

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("RSP_Player"));

	_level = 1;
}

void ARSP_Companion::BeginPlay()
{
	Super::BeginPlay();

	_animInstance->OnMontageEnded.AddDynamic(this, &ARSP_Character::AttackEnd);
	_animInstance->_attackEvent.AddUObject(this, &ARSP_Companion::Attack_Hit);

}

void ARSP_Companion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARSP_Companion::Attack_Hit()
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
		ARSP_Enemy* victim = Cast<ARSP_Enemy>(hitResult.GetActor());
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

void ARSP_Companion::Attack()
{
	if (_isAttack || IsDead())
		return;

	_isAttack = true;

	_curAttackSection = (_curAttackSection) % 3 + 1;

	_animInstance->PlayAnimMontage();
	_animInstance->JumpToSection(_curAttackSection);
}

void ARSP_Companion::TakeExp(ARSP_Enemy* enemy)
{
	auto exp = enemy->GetExp();
	auto gold = enemy->GetGold();
	_statComponent->AddExp(exp);
	_statComponent->AddGold(gold);
}
