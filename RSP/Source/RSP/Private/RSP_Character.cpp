// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_Character.h"
#include "Animation/RSP_AnimInstance.h"
#include "RSP_StatComponent.h"
#include "RSP_PlayerController.h"

// Sets default values
ARSP_Character::ARSP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	_statComponent = CreateDefaultSubobject<URSP_StatComponent>(TEXT("StatComponent"));

}

// Called when the game starts or when spawned
void ARSP_Character::BeginPlay()
{
	Super::BeginPlay();

	_animInstance = Cast<URSP_AnimInstance>(GetMesh()->GetAnimInstance());
	if(_animInstance)
		_animInstance->_deadEvent.AddUObject(this, &ARSP_Character::DeadEvent);

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
	_isAttack = false;
}

void ARSP_Character::Attack_Hit()
{
}

void ARSP_Character::DeadEvent()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	Controller->UnPossess();
}

void ARSP_Character::AddHp(float amount)
{
}

float ARSP_Character::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	_statComponent->AddCurHp(-Damage);

	auto attackerController = Cast<ARSP_PlayerController>(EventInstigator);
	if (attackerController)
	{
		if (IsDead())
		{
			UE_LOG(LogTemp, Error, TEXT("Be Dead by Player"));
		}
	}
	
	return Damage;
}

bool ARSP_Character::IsDead()
{
	return _statComponent->IsDead();
}

