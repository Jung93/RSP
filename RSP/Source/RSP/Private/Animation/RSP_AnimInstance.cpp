// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/RSP_AnimInstance.h"
#include "RSP_Character.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimMontage.h"

URSP_AnimInstance::URSP_AnimInstance()
{
}

void URSP_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	auto pawn = TryGetPawnOwner();

	ARSP_Character* character = Cast<ARSP_Character>(pawn);

	if (character != nullptr)
	{
		_speed = character->GetVelocity().Size();

		_isJump = character->GetCharacterMovement()->IsFalling();

		//_vertical = character->GetMyVertical();
		//_horizontal = character->GetMyHorizontal();
		//_isDead = character->IsDead();
	}
}
