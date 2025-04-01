// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_PlayerHpBar.h"
#include "Components/ProgressBar.h"

void URSP_PlayerHpBar::SetEXPBarValue(float ratio)
{
	RSP_EXPbar->SetPercent(ratio);
}
