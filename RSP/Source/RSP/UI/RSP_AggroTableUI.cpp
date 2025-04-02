// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_AggroTableUI.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Components/SizeBox.h"
#include "Components/ProgressBar.h"

#include "RSP_Boss.h"

void URSP_AggroTableUI::NativeConstruct()
{
	Super::NativeConstruct();

	auto children = AggroBox->GetAllChildren();

	for (auto child : children)
	{
		auto textBlock = Cast<UTextBlock>(Cast<UVerticalBox>(child)->GetChildAt(0));
		auto progressBar = Cast<UProgressBar>(Cast<USizeBox>(Cast<UVerticalBox>(child)->GetChildAt(1))->GetChildAt(0));

		if(textBlock->IsValidLowLevel())
			_textArray.Add(textBlock);

		if (progressBar->IsValidLowLevel())
			_progressBarArray.Add(progressBar);

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
	}

}

void URSP_AggroTableUI::SetAggroProgressBar(int32 index, float ratio)
{

	_progressBarArray[index]->SetPercent(ratio);


}



