// Fill out your copyright notice in the Description page of Project Settings.

#include "RSP_Player.h"
#include "RSP_Character.h"
#include "RSP_Enemy.h"
#include "RSP_StatComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Engine/DamageEvents.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Animation/RSP_AnimInstance.h"


ARSP_Player::ARSP_Player()
{
	PrimaryActorTick.bCanEverTick = true;

	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));
	_springArm->SetRelativeLocation(FVector(-50, 0, 88));

	_springArm->bUsePawnControlRotation = true;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("RSP_Player"));

	_level = 1;
}

void ARSP_Player::Attack_Hit()
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
			if (victim->IsDead()) {
				TakeExp(victim);
			}
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

void ARSP_Player::BeginPlay()
{
	Super::BeginPlay();
	
	_animInstance->OnMontageEnded.AddDynamic(this, &ARSP_Character::AttackEnd);
	_animInstance->_attackEvent.AddUObject(this, &ARSP_Player::Attack_Hit);
	//_animInstance->_deadEvent.AddUObject(this, &ARSP_Player::DeadEvent);

}

void ARSP_Player::TakeExp(ARSP_Enemy* enemy)
{
	auto exp = enemy->GetExp();
	auto gold = enemy->GetGold();
	_statComponent->AddExp(exp);
	_statComponent->AddGold(gold);
}

void ARSP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARSP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent) {
		enhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &ARSP_Player::Move);
		enhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &ARSP_Player::Look);
		enhancedInputComponent->BindAction(_attackAction, ETriggerEvent::Triggered, this, &ARSP_Player::Attack);
		enhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Triggered, this, &ARSP_Player::JumpA);
	}
}

void ARSP_Player::Move(const FInputActionValue& value)
{
	if (_isAttack) { return; }

	FVector2D moveVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		if (moveVector.Length() > 0.01f) {
			FVector forWard = GetActorForwardVector();
			FVector right = GetActorRightVector();

			_vertical = moveVector.Y;
			_horizontal = moveVector.X;

			AddMovementInput(forWard, moveVector.Y * 10);
			AddMovementInput(right, moveVector.X * 10); //10은 임시값 스탯컴포넌트에서 받아와야함 
		}
	}
}

void ARSP_Player::Look(const FInputActionValue& value)
{
	//if (_isInvenOpen) { return; }
	FVector2D lookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		AddControllerYawInput(lookAxisVector.X);
		AddControllerPitchInput(-lookAxisVector.Y);
	}
}

void ARSP_Player::JumpA(const FInputActionValue& value)
{
	if (_isAttack) return;

	bool isPress = value.Get<bool>();

	if (isPress)
	{
		ACharacter::Jump();
	}
}

void ARSP_Player::Attack(const FInputActionValue& value)
{
	if (_isAttack)
		return;

	bool isPress = value.Get<bool>();

	if (isPress)
	{
		_isAttack = true;

		_curAttackSection = (_curAttackSection) % 3 + 1;

		_animInstance->PlayAnimMontage();
		_animInstance->JumpToSection(_curAttackSection);
	}

}
