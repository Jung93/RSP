// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_InvenUI.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "UI/RSP_GridSlot.h"

bool URSP_InvenUI::Initialize()
{	
	auto result = Super::Initialize();

	_defaultTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/Tex_Default.Tex_Default'"));
	_hpPotionTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Assets/UI/T_Potion_025_256x256.T_Potion_025_256x256'"));
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
	//FString GoldString = FString::Printf(TEXT("GOLD : %d"), _curGold); 골드획득시에 델리게이트 쓸 예정
	//RSP_Gold->SetText(FText::FromString(GoldString));

	RSP_GoldImage->SetBrushFromTexture(_goldTexture);
	RSP_ExitButtonImage->SetBrushFromTexture(_exitTexture);
}
