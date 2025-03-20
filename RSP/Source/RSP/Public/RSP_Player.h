// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RSP_Character.h"
#include "RSP_Player.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API ARSP_Player : public ARSP_Character
{
	GENERATED_BODY()
public:
	ARSP_Player();
	virtual void Attack_Hit() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void TakeExp(class ARSP_Enemy* enemy);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const struct FInputActionValue& value);
	UFUNCTION()
	void Look(const struct FInputActionValue& value);
	UFUNCTION()
	void JumpA(const struct FInputActionValue& value);
	UFUNCTION()
	void Attack(const struct FInputActionValue& value);
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* _moveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* _lookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* _jumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* _attackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* _camera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* _springArm;

	
};
