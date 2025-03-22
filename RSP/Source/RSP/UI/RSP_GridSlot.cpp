// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_GridSlot.h"
#include "UI/RSP_InvenUI.h"
#include "Components/UniformGridPanel.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Blueprint/WidgetTree.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Texture2D.h"


bool URSP_GridSlot::Initialize()
{
	auto result = Super::Initialize();

	FString slotName = GetName();
	FString temp = TEXT("");

	for (auto ch : slotName) {
		if (FChar::IsDigit(ch)) {
			temp += ch;
		}
	}
	int32 number = FCString::Atoi(*temp);

	curIndex = number;

	FString text = FString::Printf(TEXT("Current Index  :  %d ") , curIndex);
	SetToolTipText(FText::FromString(text));
	
	auto border = Cast<UBorder>(itemCountText->GetParent());
	auto alpha = border->GetBrushColor();
	alpha.A = 0.0f;
	border->SetBrushColor(alpha);

	return result;
}

void URSP_GridSlot::SetTexture(UTexture2D* texture)
{
	curTexture = texture;
	itemImage->SetBrushFromTexture(texture);
}

UTexture2D* URSP_GridSlot::GetTexture()
{
	return curTexture;
}



