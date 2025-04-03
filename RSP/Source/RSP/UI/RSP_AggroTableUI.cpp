// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_AggroTableUI.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Components/SizeBox.h"
#include "Components/ProgressBar.h"
#include "Components/CanvasPanel.h"

#include "RSP_Boss.h"

void URSP_AggroTableUI::NativeConstruct()
{
	Super::NativeConstruct();

	auto children = AggroBox->GetAllChildren();

	for (auto child : children)
	{
		auto textBlock = Cast<UTextBlock>(Cast<UVerticalBox>(child)->GetChildAt(0));
		auto progressCanvas = Cast<UCanvasPanel>(Cast<USizeBox>(Cast<UVerticalBox>(child)->GetChildAt(1))->GetChildAt(0));

		auto progressBar = Cast<UProgressBar>(progressCanvas->GetChildAt(0));
		auto progressPercent = Cast<UTextBlock>(progressCanvas->GetChildAt(1));
		auto damageBlock = Cast<UTextBlock>(progressCanvas->GetChildAt(2));

		if(textBlock->IsValidLowLevel())
			_textArray.Add(textBlock);

		if (progressBar->IsValidLowLevel())
			_progressBarArray.Add(progressBar);

		if (progressPercent->IsValidLowLevel())
			_progressPercentArray.Add(progressPercent);

		if (damageBlock->IsValidLowLevel())
			_damageArray.Add(damageBlock);

	}

}

void URSP_AggroTableUI::SetAggroTableInfo(TArray<FAggroTable>& aggroInfo)
{
	if (aggroInfo.IsEmpty())
		return;

	for (int i = 0; i < aggroInfo.Num(); i++)
	{
		FString name = aggroInfo[i].character->GetName();
		_textArray[i]->SetText(FText::FromString(name));

		if(aggroInfo[i].character->IsDead())
			_textArray[i]->SetColorAndOpacity(FLinearColor(0.2f, 0.2f, 0.2f, 1.0f));

	}

}

void URSP_AggroTableUI::SetAggroProgressBar(int32 index, float ratio, float damage)
{

	_progressBarArray[index]->SetPercent(ratio);

	//if(index != 0)
	//	_progressBarArray[index]->SetFillColorAndOpacity(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f));

	FString str = FString::Printf(TEXT("%.1f%%"), ratio * 100.0f);
	FString damageStr = FString::Printf(TEXT("%d"), (int32)damage);

	_progressPercentArray[index]->SetText(FText::FromString(str));
	_damageArray[index]->SetText(FText::FromString(damageStr));

}

void URSP_AggroTableUI::SetProgressBarColor(int32 index)
{

	for (int i = 0; i < _progressBarArray.Num(); i++)
	{
		if (i == index)
		{
			_progressBarArray[i]->SetFillColorAndOpacity(FLinearColor(0.25f, 0.0f, 0.0f, 1.0f));
		}
		else
		{
			_progressBarArray[i]->SetFillColorAndOpacity(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f));
		}
	}

}



