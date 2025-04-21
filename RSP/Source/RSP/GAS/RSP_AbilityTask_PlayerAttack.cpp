// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/RSP_AbilityTask_PlayerAttack.h"
#include "Public/Animation/RSP_AnimInstance.h"
URSP_AbilityTask_PlayerAttack* URSP_AbilityTask_PlayerAttack::PlayerAttack(UGameplayAbility* OwningAbility,	FName TaskInstanceName,
	UAnimMontage* MontageToPlay,int32 SectionNum,float Rate)
{
	if (!MontageToPlay) {
		return nullptr;
	}

	URSP_AbilityTask_PlayerAttack* MyTask = NewAbilityTask<URSP_AbilityTask_PlayerAttack>(OwningAbility, TaskInstanceName);

	MyTask->AttackMontage = MontageToPlay;
	MyTask->SectionNum = SectionNum;
	MyTask->PlayRate = Rate;
	MyTask->CurrentSectionIndex = 0;

	return MyTask;
}

void URSP_AbilityTask_PlayerAttack::Activate()
{
	if (!AttackMontage) {
		return;
	}
	auto AvatarActor = GetAvatarActor();
	if (!AvatarActor) {
		return;
	}
	auto player = Cast<ARSP_Player>(AvatarActor);

	if (player)
	{
		auto Mesh = player->GetMesh();
		if (Mesh)
		{
			auto AnimInstance = Mesh->GetAnimInstance();
			AnimInstance->Montage_Play(AttackMontage, PlayRate);
		}
	}
}

