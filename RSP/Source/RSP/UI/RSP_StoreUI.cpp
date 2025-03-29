// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_StoreUI.h"
#include "RSP_GameInstance.h"

#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
bool URSP_StoreUI::Initialize()
{
	auto result = Super::Initialize();
	return result;
}

void URSP_StoreUI::NativeConstruct()
{
	Super::NativeConstruct();

	RSP_Title->SetText(FText::FromString(TEXT("STORE")));

	UVerticalBox* v_box = Cast<UVerticalBox>(RSP_StoreGrid->GetChildAt(0));
	auto array = v_box->GetAllChildren();
	int32 arrayNum = array.Num();

	for (int32 i = 0; i < arrayNum; i++) {
		FString WidgetName = FString::Printf(TEXT("Slot_%d"), i);
		URSP_GridSlot* storeSlot = WidgetTree->FindWidget<URSP_GridSlot>(*WidgetName);
		_storeSlots.Add(storeSlot);

		auto gameInstancebase = GetGameInstance();
		auto gameInstance = Cast<URSP_GameInstance>(gameInstancebase);
		FRSP_ItemInfo itemInfo;
		if (i < 3) {
			itemInfo = gameInstance->GetItemInfo("HpPotion_Low");
		}
		else if (3 <= i && i < 5) {
			itemInfo = gameInstance->GetItemInfo("HpPotion_High");
		
		}
		else {
			itemInfo = FRSP_ItemInfo();
		}		

		UTextBlock* text = Cast<UTextBlock>(storeSlot->GetParent()->GetChildAt(1));
		auto thisItemToolTip = itemInfo.itemToolTip;

		SetItemTexture_Buy(i, itemInfo);
		storeSlot->SetItemInfo(itemInfo);
		text->SetText(FText::FromString(thisItemToolTip));
		storeSlot->bStoreMode = true;

		_storeSlots[i] = storeSlot;

	}
}

void URSP_StoreUI::UpdateShopItems_Sell(AActor* actor)
{	
	UVerticalBox* v_box = Cast<UVerticalBox>(RSP_InvenGrid->GetChildAt(0));
	auto array = v_box->GetAllChildren();
	int32 arrayNum = array.Num();

	for (int32 i = 0; i < arrayNum; i++) {
		FString WidgetName = FString::Printf(TEXT("InvenSlot_%d"), i);
		URSP_GridSlot* invenSlot = WidgetTree->FindWidget<URSP_GridSlot>(*WidgetName);
		_invenSlots.Add(invenSlot);

		auto player = Cast<ARSP_Player>(actor);
		if (player) {
			auto playerInven = player->GetInvenUI();
			auto playerInvenItemInfo = playerInven->GetGridSlotItemInfo(i);

			UTextBlock* text = Cast<UTextBlock>(invenSlot->GetParent()->GetChildAt(1));
			auto thisItemToolTip = playerInvenItemInfo.itemToolTip;
						
			SetItemTexture(i, playerInvenItemInfo);
			invenSlot->SetItemInfo(playerInvenItemInfo);
			text->SetText(FText::FromString(thisItemToolTip));
			invenSlot->bStoreMode = true;

			_invenSlots[i] = invenSlot;

		}
	}
	
}

void URSP_StoreUI::SetItemTexture_Buy(int32 index, FRSP_ItemInfo info)
{	
	_storeSlots[index]->SetToolTipText(FText::FromString(info.itemToolTip));
	_storeSlots[index]->SetItemInfo(info);
	switch (info.itemId)
	{
	case 0:
		_storeSlots[index]->SetTexture(_exitTexture);
		break;
	case 1:
		_storeSlots[index]->SetTexture(_hpPotionTexture_High);
		break;
	case 2:
		_storeSlots[index]->SetTexture(_hpPotionTexture_Low);
		break;
	default:
		break;
	}
}
