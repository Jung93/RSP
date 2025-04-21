// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/RSP_AbilityTask_attack2.h"



void URSP_AbilityTask_attack2::Activate()
{
	if (!AttackMontage)
	{
		EndTask(); // 몽타주 없으면 즉시 태스크 종료
		return;
	}

	if (Ability == nullptr)
	{
		EndTask();
		return;
	}

}
