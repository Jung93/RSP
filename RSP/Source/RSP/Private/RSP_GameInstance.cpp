// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_GameInstance.h"
#include "Engine/DataTable.h"
URSP_GameInstance::URSP_GameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> statTable(TEXT("/Script/Engine.DataTable'/Game/Data/RSP_StatData.RSP_StatData'"));

	if (statTable.Succeeded()) {
		_statTable = statTable.Object;
	}
	static ConstructorHelpers::FObjectFinder<UDataTable> itemTable(TEXT("/Script/Engine.DataTable'/Game/Data/RSP_ItemInfo.RSP_ItemInfo'"));

	if (itemTable.Succeeded()) {
		_itemTable = itemTable.Object;
	}
}

FRSP_StatData URSP_GameInstance::GetStat_Level(int32 level)
{
	FString LevelName = "Level_" + FString::FromInt(level);
	auto row = _statTable->FindRow<FRSP_StatData>(*LevelName, TEXT(""));
	return *row;
}

FRSP_ItemInfo URSP_GameInstance::GetItemInfo(FString name)
{
	FRSP_ItemInfo* row = _itemTable->FindRow<FRSP_ItemInfo>(*name, TEXT(""));
	if (row == nullptr)
	{		
		return FRSP_ItemInfo(); 
	}

	return *row;
}

int32 URSP_GameInstance::GetStatTableSize()
{
	int32 size = (_statTable->GetRowNames()).Num();
	return size;
}
