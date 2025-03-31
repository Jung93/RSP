// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_InvenUI.h"

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
	
	auto array = RSP_InvenGrid->GetAllChildren();
	for (auto& widget : array) {
		auto slot = Cast<URSP_GridSlot>(widget);
		if (slot) {
			slot->SetTexture(_defaultTexture);
			_invenSlots.Add(slot);
		}		
	}	

	RSP_Title->SetText(FText::FromString(TEXT("INVENTORY")));	

	RSP_GoldImage->SetBrushFromTexture(_goldTexture);
	RSP_ExitButtonImage->SetBrushFromTexture(_exitTexture);
}

void URSP_InvenUI::UpdateStoreInven_inven(int32 index, FRSP_ItemInfo info, AActor* actor)
{
	auto store = Cast<ARSP_ItemShop>(actor);
	auto playerController = Cast<ARSP_PlayerController>(GetWorld()->GetFirstPlayerController());
	auto player = Cast<ARSP_Player>(playerController->GetPawn());

	store->SetItemTexture(index, info);
	player->SetItemTexture(index, info);

	UTextBlock* text = Cast<UTextBlock>(_invenSlots[index]->GetParent()->GetChildAt(1));
	if (text) {
		auto thisItemToolTip = _invenSlots[index]->GetItemInfo().itemToolTip;
		text->SetText(FText::FromString(thisItemToolTip));
	}
}

void URSP_InvenUI::SetItemTexture(int32 index, FRSP_ItemInfo info)
{
	_invenSlots[index]->SetToolTipText(FText::FromString(info.itemToolTip));
	_invenSlots[index]->SetItemInfo(info);
	switch (info.itemId)
	{
	case 0:
		_invenSlots[index]->SetTexture(_defaultTexture);
		break;
	case 1:
		_invenSlots[index]->SetTexture(_hpPotionTexture_High);
		break;
	case 2:
		_invenSlots[index]->SetTexture(_hpPotionTexture_Low);
		break;
	default:
		break;
	}
}


void URSP_InvenUI::SetDropTexture(int32 index)
{
	_invenSlots[index]->SetTexture(_defaultTexture);

}

void URSP_InvenUI::UseInventoryItem(int32 index)
{
	_invenSlots[index]->SetTexture(_defaultTexture);

	FString text = FString::Printf(TEXT("Current Index  :  %d "), index);
	_invenSlots[index]->SetItemToolTip(text);
}

void URSP_InvenUI::SetGold(int32 value)
{
	_playerGold = value;
	FString GoldString = FString::Printf(TEXT("%d"), _playerGold);
	RSP_Gold->SetText(FText::FromString(GoldString));
}

void URSP_InvenUI::AddGold(int32 value)
{
	_playerGold += value;
	FString GoldString = FString::Printf(TEXT("%d"), _playerGold);
	RSP_Gold->SetText(FText::FromString(GoldString));
}

void URSP_InvenUI::SendHealValue(int32 index)
{
	auto healvalue = _invenSlots[index]->GetItemInfo().itemStat;
	healValue.Broadcast(healvalue);
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.0f,
		FColor::Black,
		FString::Printf(TEXT("%d"), healvalue)
	);
}
