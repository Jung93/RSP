// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RSP_KeyPressEvent.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_KeyPressEvent : public UUserWidget
{
	GENERATED_BODY()
public:

protected:
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RSP_KeyImage;
};
