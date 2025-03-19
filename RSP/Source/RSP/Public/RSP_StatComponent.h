// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RSP_StatComponent.generated.h"

USTRUCT() 
struct FStatData : public FTableRowBase {
	GENERATED_BODY()

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 atk;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 maxEXP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 EXP;*/


};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RSP_API URSP_StatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URSP_StatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
/*
스탯컴포넌트에 들어가야 할 것
- 레벨에 따라 성장해야하는 능력치들 
- 조건에 따라 변동이 필요한 능력치들
1. 레벨
2. 체력 (현재체력 , 최대체력)
3. 공격력 
4. 현재 경험치 
5. 이동속도?
6.

스탯 데이터에 들어가야 할 것
- 레벨에 따라 성장해야하는 능력치와 조건
1. 레벨
2. 최대체력
3. 공격력
4. 레벨업에 필요한 경험치량

*/