// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_HpBar.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
void URSP_HpBar::SetHpBarValue(float ratio)
{
	RSP_HpBar->SetPercent(ratio);
}

void URSP_HpBar::SetLevelText(int32 level)
{
	FString levelText = FString::Printf(TEXT("%d"), level);
	RSP_LevelText->SetText(FText::FromString(levelText));
}

void URSP_HpBar::SetOwnerName(FString string)
{
	RSP_Name->SetText(FText::FromString(string));
}
