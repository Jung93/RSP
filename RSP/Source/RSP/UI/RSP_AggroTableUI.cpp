// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_AggroTableUI.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"

#include "RSP_Boss.h"

void URSP_AggroTableUI::NativeConstruct()
{
	Super::NativeConstruct();

	auto children = VerticalBox->GetAllChildren();

	for (auto child : children)
	{
		auto textBlock = Cast<UTextBlock>(child);

		if(textBlock->IsValidLowLevel())
			_textArray.Add(textBlock);
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


