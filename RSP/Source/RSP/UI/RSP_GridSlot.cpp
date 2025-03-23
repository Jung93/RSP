// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_GridSlot.h"
#include "UI/RSP_InvenUI.h"
#include "Item/RSP_Item.h"
#include "Components/UniformGridPanel.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Blueprint/WidgetTree.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Texture2D.h"
#include "Input/Reply.h"
#include "Components/Widget.h"

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


FReply URSP_GridSlot::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	HandleDoubleClick();

	return FReply::Handled();
}

void URSP_GridSlot::HandleDoubleClick()
{
	auto defaultScale = FVector2D(1.0f, 1.0f);
	auto largeScale = FVector2D(5.5f, 5.5f);

	URSP_InvenUI* invenWidget = GetTypedOuter<URSP_InvenUI>();
	invenWidget->hpPotionUsed.Broadcast(curIndex);
}

void URSP_GridSlot::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	FVector2d scale = FVector2D(1, 1);
	FVector2D newScale = scale * 1.2f;
	
	itemImage->SetRenderScale(newScale);
}

void URSP_GridSlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	FVector2d scale = FVector2D(1, 1);

	FVector2D newScale = scale / 1.2f;
	itemImage->SetRenderScale(newScale);
}





