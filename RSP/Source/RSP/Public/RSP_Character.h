// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RSP_Character.generated.h"

UCLASS()
class RSP_API ARSP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARSP_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void AttackEnd(class UAnimMontage* Montage, bool bInterrupted);

	void Attack_Hit();
	void DeadEvent();

	void AddHp(float amount);

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	bool IsDead();
	bool IsAttacking() { return _isAttack; }

	float GetAttackRange() { return _attackRange; }


private:
	//UPROPERTY()
	//class UMyAnimInstance* _animInstance;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	//class UMyStatComponent* _statComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	bool _isAttack;

	int32 _curAttackSection = 1;

	UPROPERTY(EditAnywhere)
	float _attackRange = 400.0f;
};
