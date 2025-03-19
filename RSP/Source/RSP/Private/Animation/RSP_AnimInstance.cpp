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
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto pawn = TryGetPawnOwner();

	ARSP_Character* character = Cast<ARSP_Character>(pawn);

	if (character != nullptr)
	{
		_speed = character->GetVelocity().Size();

		_isJump = character->GetCharacterMovement()->IsFalling();

		_vertical = character->Vertical();
		_horizontal = character->Horizontal();		
		_isDead = character->IsDead();
	}
}

void URSP_AnimInstance::PlayAnimMontage()
{
	if (_animMontage == nullptr)
		return;

	if (!Montage_IsPlaying(_animMontage))
		Montage_Play(_animMontage);
}

void URSP_AnimInstance::AnimNotify_Attack_Hit()
{
	
	if (_attackEvent.IsBound())
		_attackEvent.Broadcast();
}

void URSP_AnimInstance::AnimNotify_Dead()
{

	if (_deadEvent.IsBound())
		_deadEvent.Broadcast();

}

void URSP_AnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Section%d"), sectionIndex));

	Montage_JumpToSection(sectionName);

}
