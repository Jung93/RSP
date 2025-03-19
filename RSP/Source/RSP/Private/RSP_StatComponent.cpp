// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_StatComponent.h"

// Sets default values for this component's properties
URSP_StatComponent::URSP_StatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void URSP_StatComponent::BeginPlay()
{
	Super::BeginPlay();

	//게임인스턴스 불러오기 , 게임인스턴스에서 현재레벨 정보 불러오기
	/*auto gameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	auto character = Cast<AMyCharacter>(GetOwner());
	_level = character->GetLevel();
	auto statInfo = gameInstance->GetStat_Level(_level);
	_maxHp = statInfo.hp;
	_curHp = statInfo.hp;
	_atk = statInfo.atk;
	_EXP = statInfo.EXP;
	_maxEXP = statInfo.maxEXP;
	_curEXP = 0;*/
}


// Called every frame
void URSP_StatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

