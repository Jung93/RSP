// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_InvenUI.h"
#include "Item/RSP_Item.h"
#include "UI/RSP_GridSlot.h"

#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"


bool URSP_InvenUI::Initialize()
{	
	auto result = Super::Initialize();

	_defaultTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/Tex_Default.Tex_Default'"));
	
	_hpPotionTexture_High = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/T_Potion_115_256x256.T_Potion_115_256x256'"));
	_hpPotionTexture_Low = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/T_Potion_025_256x256.T_Potion_025_256x256'"));
	_mpPotionTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/T_Potion_162_256x256.T_Potion_162_256x256'"));
	
	_goldTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/21067_1.21067_1'"));
	
	_exitTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/T_x_256px_gray.T_x_256px_gray'"));
	

	return result;
}

void URSP_InvenUI::NativeConstruct()
{
	Super::NativeConstruct();
	
	auto array = RSP_Grid->GetAllChildren();
	for (auto& widget : array) {
		auto slot = Cast<URSP_GridSlot>(widget);
		if (slot) {
			slot->SetTexture(_defaultTexture);
			_slots.Add(slot);
		}		
	}	

	RSP_Title->SetText(FText::FromString(TEXT("INVENTORY")));	

	RSP_GoldImage->SetBrushFromTexture(_goldTexture);
	RSP_ExitButtonImage->SetBrushFromTexture(_exitTexture);

	FString GoldString = FString::Printf(TEXT("%d"), 0);
	RSP_Gold->SetText(FText::FromString(GoldString));
}

void URSP_InvenUI::SetItemTexture(int32 index, FRSP_ItemInfo info)
{
	_slots[index]->SetToolTipText(FText::FromString(info.itemToolTip));
	_slots[index]->SetItemInfo(info);
	switch (info.itemId)
	{
	case 0:
		_slots[index]->SetTexture(_exitTexture);
		break;
	case 1:
		_slots[index]->SetTexture(_hpPotionTexture_High);
		break;
	case 2:
		_slots[index]->SetTexture(_hpPotionTexture_Low);
		break;
	default:
		break;
	}
}

void URSP_InvenUI::SetDropTexture(int32 index)
{
	_slots[index]->SetTexture(_defaultTexture);

}

void URSP_InvenUI::UseInventoryItem(int32 index)
{
	_slots[index]->SetTexture(_defaultTexture);
}

void URSP_InvenUI::AddGold(int32 amount)
{
	FString GoldString = FString::Printf(TEXT("%d"), amount);
	RSP_Gold->SetText(FText::FromString(GoldString));
}

void URSP_InvenUI::SendHealValue(int32 index)
{
	auto healvalue = _slots[index]->GetItemInfo().itemStat;
	healValue.Broadcast(healvalue);
}
