// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_StatComponent.h"
#include "RSP_Character.h"
// Sets default values for this component's properties
URSP_StatComponent::URSP_StatComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void URSP_StatComponent::BeginPlay()
{
	Super::BeginPlay();

	////게임인스턴스 불러오기 , 게임인스턴스에서 현재레벨 정보 불러오기
	////auto gameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	//auto character = Cast<ARSP_Character>(GetOwner());
	////auto statInfo = gameInstance->GetStat_Level(_level);
	//_maxHp = statInfo.maxHp;
	//_curHp = statInfo.maxHp;
	//_atk = statInfo.atk;
	//
	//_maxEXP = statInfo.maxEXP;
	//_curEXP = 0;
}


// Called every frame
void URSP_StatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

