// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/RSP_PlayerState.h"
#include "GAS/RSP_AbilitySystemComponent.h"
ARSP_PlayerState::ARSP_PlayerState()
{
    NetUpdateFrequency = 100.0f;

    AbilitySystemComponent = CreateDefaultSubobject<URSP_AbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

}
UAbilitySystemComponent* ARSP_PlayerState::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}
