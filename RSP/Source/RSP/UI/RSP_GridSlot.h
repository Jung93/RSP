// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GridSlot.h"
#include "RSP_GridSlot.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_GridSlot : public UGridSlot
{
	GENERATED_BODY()
public:
	int32 curIndex;
};
