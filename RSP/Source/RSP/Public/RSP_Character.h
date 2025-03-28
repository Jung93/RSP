// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RSP_Character.generated.h"

UCLASS(Abstract)
class RSP_API ARSP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARSP_Character();

protected:
	virtual void PostInitializeComponents()override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void AttackEnd(class UAnimMontage* Montage, bool bInterrupted);

	virtual void Attack_Hit();
	
	UFUNCTION()
	void DeadEvent();

	void AddHp(float amount);

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	bool IsDead();
	bool IsAttacking() { return _isAttack; }

	float GetAttackRange() { return _attackRange; }

	float Vertical() { return _vertical; }
	float Horizontal() { return _horizontal; }

	const int16& GetLevel() { return _level; }
	FString GetMyName() { return _name; }
protected:
	UPROPERTY()
	class URSP_AnimInstance* _animInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	class URSP_StatComponent* _statComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	bool _isAttack = false;

	int32 _curAttackSection = 0;

	UPROPERTY(EditAnywhere)
	float _attackRange = 400.0f;

	UPROPERTY(VisibleAnywhere)
	int32 _gold = 0;

	UPROPERTY(EditAnywhere, Category = "Level", meta = (AllowPrivateAccess = "true"))
	int16 _level = 1;

	UPROPERTY()
	float _critical = 10.0f;

	float _vertical = 0.0f;
	float _horizontal = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* _hpBarWidget;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Name", meta = (AllowPrivateAccess = "true"))
	FString _name;
};
