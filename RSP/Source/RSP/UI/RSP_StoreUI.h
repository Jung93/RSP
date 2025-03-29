// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/RSP_InvenUI.h"
#include "RSP_StoreUI.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_StoreUI : public URSP_InvenUI
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;

public:
	void UpdateShopItems_Sell(AActor* actor);
	void SetItemTexture_Buy(int32 index, struct FRSP_ItemInfo info);
public:
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* RSP_StoreGrid;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_ItemPriceText;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* RSP_BuyButton;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* RSP_SellButton;
protected:
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TArray<class URSP_GridSlot*> _storeSlots;

};
