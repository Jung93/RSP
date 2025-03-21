// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RSP_InvenUI.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_InvenUI : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override; 
	virtual void NativeConstruct() override;
	
	//void SetItemTexture(int32 index);

	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* RSP_Grid;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* RSP_ExitButton;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_Gold; // deligate로 수치 변경 이벤트
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_Title;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RSP_GoldImage;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RSP_ExitButtonImage;

protected:
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TArray<class URSP_GridSlot*> _slot;
	UPROPERTY()
	UTexture2D* _hpPotionTexture;
	UPROPERTY()
	UTexture2D* _mpPotionTexture;
	UPROPERTY()
	UTexture2D* _defaultTexture;
	UPROPERTY()
	UTexture2D* _goldTexture;
	UPROPERTY()
	UTexture2D* _exitTexture;

	int32 _curGold = 0;

	int32 _row = 4;
	int32 _column = 3;
};
