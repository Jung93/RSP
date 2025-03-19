// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_GameInstance.h"
#include "Engine/DataTable.h"
URSP_GameInstance::URSP_GameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> dataTable(TEXT("/Script/Engine.DataTable'/Game/Data/RSP_StatData.RSP_StatData'"));

	if (dataTable.Succeeded()) {
		_statTable = dataTable.Object;
	}
}

FRSP_StatData URSP_GameInstance::GetStat_Level(int32 level)
{
	FString LevelName = "Level_" + FString::FromInt(level);
	auto row = _statTable->FindRow<FRSP_StatData>(*LevelName, TEXT(""));
	return *row;
}

int32 URSP_GameInstance::GetStatTableSize()
{
	int32 size = (_statTable->GetRowNames()).Num();
	return size;
}
