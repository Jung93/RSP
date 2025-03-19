// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RSP_AnimInstance.generated.h"

UCLASS()
class RSP_API URSP_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	URSP_AnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds);

	//UFUNCTION()
	//	void PlayAnimMontage();

	//UFUNCTION()
	//void AnimNotify_Attack_Hit();

	//UFUNCTION()
	//void AnimNotify_Dead();

	//void JumpToSection(int32 sectionIndex);





private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	float _speed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	bool _isJump = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage", meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* _animMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage", meta = (AllowPrivateAccess = "true"))
	float _vertical;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage", meta = (AllowPrivateAccess = "true"))
	float _horizontal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontate", meta = (AllowPrivateAccess = "true"))
	bool _isDead = false;
};
