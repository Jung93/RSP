// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "RSP_InvenUI.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FHpPotionUsed, int32);
DECLARE_MULTICAST_DELEGATE_OneParam(FHealValue, int32);
DECLARE_MULTICAST_DELEGATE_OneParam(FGainGold, int32);

UCLASS()
class RSP_API URSP_InvenUI : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override; 
	virtual void NativeConstruct() override;
	
	void SetItemTexture(int32 index , struct FRSP_ItemInfo info);
	void SetDropTexture(int32 index);
	void UseInventoryItem(int32 index);
	UFUNCTION()
	int32 GetSlotSize() { return _slots.Num(); }

	class URSP_GridSlot* GetGridSlot(int32 index) { return _slots[index]; }

	void AddGold(int32 amount);
	void SendHealValue(int32 index);
public:
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* RSP_Grid;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* RSP_ExitButton;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_Gold;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_Title;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RSP_GoldImage;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RSP_ExitButtonImage;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_ItemText;
	
	FGainGold gainGold;
	FHpPotionUsed hpPotionUsed;
	FHealValue healValue;
protected:	
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TArray<class URSP_GridSlot*> _slots;
	UPROPERTY()
	class UTexture2D* _hpPotionTexture_High;
	UPROPERTY()
	class UTexture2D* _hpPotionTexture_Low;
	UPROPERTY()
	class UTexture2D* _mpPotionTexture;
	UPROPERTY()
	class UTexture2D* _defaultTexture;
	UPROPERTY()
	class UTexture2D* _goldTexture;
	UPROPERTY()
	class UTexture2D* _exitTexture;

};
