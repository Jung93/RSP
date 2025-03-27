// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RSP_HpBar.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_HpBar : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetHpBarValue(float ratio);
	void SetLevelText(int32 level);
	void SetOwnerName(FString string);
protected:
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* RSP_HpBar;

	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_LevelText;
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* RSP_Name;
};
