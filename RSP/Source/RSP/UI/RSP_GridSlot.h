// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RSP_GridSlot.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_GridSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

	void SetTexture(class UTexture2D* texture);
	class UTexture2D* GetTexture();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	int32 curIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, meta = (BindWidget))
	class UImage* itemImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	int32 itemCount = 0;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* itemCountText;

	UPROPERTY()
	class UTexture2D* curTexture;
};
