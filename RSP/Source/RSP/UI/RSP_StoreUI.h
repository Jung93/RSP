// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/RSP_InvenUI.h"
#include "RSP_StoreUI.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FTotalItemPriceEvent_Buy, int32);
DECLARE_MULTICAST_DELEGATE_OneParam(FTotalItemPriceEvent_Sell, int32);

UCLASS()
class RSP_API URSP_StoreUI : public URSP_InvenUI
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;

public:	
	void UpdateStoreInven(int32 index, struct FRSP_ItemInfo info, AActor* actor);
	void SetItemTexture_Buy(int32 index, struct FRSP_ItemInfo info);
	void SetSoldOutTexture(int32 index);

	void TotalItemPrice_Buy(int32 value); 
	void TotalItemPrice_Sell(int32 value); 
	
	int32 GetTotalItemPrice_Buy() { return totalItemPrice_Buy; }
	int32 GetTotalItemPrice_Sell() { return totalItemPrice_Sell; }
	void SetTotalItemPrice_Sell(int32 value) { totalItemPrice_Sell = value; }
	int32 GetCurPlayerGold() { return _playerGold; }

	TArray<class URSP_GridSlot*> GetStoreSlots() { return _storeSlots; }
	void SetThisItemToopTip(class URSP_GridSlot* slot , FString str);
public:
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* RSP_StoreGrid;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_ItemPriceText_Buy;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_ItemPriceText_Sell;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* RSP_BuyButton;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* RSP_SellButton;
	
	FTotalItemPriceEvent_Buy totalItemPriceEvent_Buy;
	FTotalItemPriceEvent_Sell totalItemPriceEvent_Sell;
protected:
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TArray<class URSP_GridSlot*> _storeSlots;
	
	int32 totalItemPrice_Buy = 0;
	int32 totalItemPrice_Sell = 0;
};
