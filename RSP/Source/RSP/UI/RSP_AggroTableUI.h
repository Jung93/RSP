// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "RSP_Boss.h"

#include "RSP_AggroTableUI.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FAggroEvent, TArray<FAggroTable>&);
DECLARE_MULTICAST_DELEGATE_TwoParams(FAggroProgressBarEvent, int32, float);

UCLASS()
class RSP_API URSP_AggroTableUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	
	void SetAggroTableInfo(TArray<FAggroTable>& aggroInfo);
	void SetAggroProgressBar(int32 index, float ratio);

	FAggroEvent aggroEvent;
	FAggroProgressBarEvent aggroProgressBarEvent;

private:
	UPROPERTY(Editanywhere,  meta = (BindWidget))
	class UVerticalBox* AggroBox;

	UPROPERTY(Editanywhere,  meta = (BindWidget))
	TArray<class UTextBlock*> _textArray;

	UPROPERTY(Editanywhere, meta = (BindWidget))
	TArray<class UProgressBar*> _progressBarArray;
};
