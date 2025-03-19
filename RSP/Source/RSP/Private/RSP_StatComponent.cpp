// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_StatComponent.h"
#include "RSP_Character.h"
#include "RSP_GameInstance.h"
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

	//게임인스턴스 불러오기 , 게임인스턴스에서 현재레벨 정보 불러오기
	auto gameInstance = Cast<URSP_GameInstance>(GetWorld()->GetGameInstance());
	auto character = Cast<ARSP_Character>(GetOwner());
	_level = character->GetLevel();
	auto statInfo = gameInstance->GetStat_Level(_level);
	_maxHp = statInfo.maxHp;
	_curHp = statInfo.maxHp;
	_atk = statInfo.atk;
	_dropGold = statInfo.dropGold;
	_levelUpExp = statInfo.levelUpExp;
	_dropExp = statInfo.dropExp;
	_curExp = 0;
}


// Called every frame
void URSP_StatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URSP_StatComponent::AddCurHp(float amount)
{
	int32 before = _curHp;

	_curHp += amount;
	if (_curHp <= 0) {
		//PlayDeadMotion.Broadcast(); 사망애니메이션 만들때 사용
		_curHp = 0;
	}
	if (_curHp > _maxHp) {
		_curHp = _maxHp;
	}
	auto actor = GetOwner();

	UE_LOG(LogTemp, Warning, TEXT("Name : %s , HP : %d"), *actor->GetName(), _curHp);

	float ratio = _curHp / (float)_maxHp;
	//if (_hpChanged.IsBound()) {
	//	_hpChanged.Broadcast(ratio);
	//} hp바 위젯 만들때 사용
	
}

void URSP_StatComponent::AddEXP(int32 value)
{
	auto gameInstance = Cast<URSP_GameInstance>(GetWorld()->GetGameInstance());
	if (_level > gameInstance->GetStatTableSize()) {

		return;
	}
	_curExp += value;
	if (_curExp >= _levelUpExp) {
		auto exp = _curExp - _levelUpExp;
		_level++;

		UE_LOG(LogTemp, Error, TEXT("LEVEL changed : %d"), _level);

		auto character = Cast<ARSP_Character>(GetOwner());
		auto statInfo = gameInstance->GetStat_Level(_level);
		_maxHp = statInfo.maxHp;
		_curHp = statInfo.maxHp;
		_atk = statInfo.atk;
		_dropGold = statInfo.dropGold;
		_levelUpExp = statInfo.levelUpExp;
		_dropExp = statInfo.dropExp;
		_curExp = exp;
	}
	UE_LOG(LogTemp, Error, TEXT("Level : %d  ,  Cur EXP :  % d  , Level UP EXP : %d"), _level, _curExp, _levelUpExp);

}

