// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/RSP_AttributeSet.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"
URSP_AttributeSet::URSP_AttributeSet()
{
	InitHealth(80.0f);
	InitMaxHealth(100.f);
}

void URSP_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeBaseChange(Attribute,NewValue);
	if (Attribute == GetHealthAttribute()) {
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
}

void URSP_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    
}


