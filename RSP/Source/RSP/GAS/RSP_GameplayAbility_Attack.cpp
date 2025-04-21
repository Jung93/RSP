// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/RSP_GameplayAbility_Attack.h"
#include "RSP_Character.h"
#include "GAS/RSP_AbilityTask_PlayerAttack.h"
#include "RSP_Player.h"

URSP_GameplayAbility_Attack::URSP_GameplayAbility_Attack()
{
	AbilityTags.AddTag(RSP_GamePlayTags::Action_Attack_Nomal);
}

bool URSP_GameplayAbility_Attack::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	if (Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags) == false)
	{
		return false;
	}

	return true;
}

void URSP_GameplayAbility_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	auto Task = URSP_AbilityTask_PlayerAttack::PlayerAttack(this, "PlayerAttack", AttackMontage, 3, 0.3f);
	if (Task->IsValidLowLevel()) {
		Task->ReadyForActivation();
	}
}

void URSP_GameplayAbility_Attack::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

}
