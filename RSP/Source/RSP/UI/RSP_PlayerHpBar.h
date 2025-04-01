// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/RSP_HpBar.h"
#include "RSP_PlayerHpBar.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_PlayerHpBar : public URSP_HpBar
{
	GENERATED_BODY()
public:
	void SetEXPBarValue(float ratio);
protected:
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* RSP_EXPbar;
};
