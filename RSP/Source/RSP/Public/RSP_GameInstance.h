// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RSP_StatComponent.h"
#include "RSP_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	URSP_GameInstance();
private:

public:
	FRSP_StatData GetStat_Level(int32 level);
	int32 GetStatTableSize();
private:
	UPROPERTY()
	class UDataTable* _statTable;
};
