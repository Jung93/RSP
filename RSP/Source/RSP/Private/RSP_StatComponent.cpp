// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_StatComponent.h"
#include "RSP_Character.h"
#include "RSP_Player.h"
#include "RSP_Companion.h"
#include "RSP_Enemy.h"
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
	_curGold = 0;

	
}


// Called every frame
void URSP_StatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URSP_StatComponent::AddCurHp(float amount)
{
	float before = _curHp;
	auto gameInstance = Cast<URSP_GameInstance>(GetWorld()->GetGameInstance());

	_curHp += amount;
	if (_curHp <= 0) {
		auto enemy = Cast<ARSP_Enemy>(GetOwner());
		if (enemy) {
		
			enemy->DropItem();
			if (gameInstance->enemyDeadEvent.IsBound()) {
				gameInstance->enemyDeadEvent.Broadcast(enemy->GetLevel());
			}
		}
		_curHp = 0;
	}
	if (_curHp > _maxHp) {
		_curHp = _maxHp;
	}
	auto actor = GetOwner();

	UE_LOG(LogTemp, Warning, TEXT("Name : %s , HP : %d"), *actor->GetName(), _curHp);
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Purple, FString::Printf(TEXT("Name : %s , HP : %d"), *actor->GetName(), _curHp));

	float ratio = _curHp / (float)_maxHp;
	if (hpChanged.IsBound()) {
		hpChanged.Broadcast(ratio);
	} 

}

void URSP_StatComponent::AddCurHp(int32 amount)
{
	int32 before = _curHp;
	auto gameInstance = Cast<URSP_GameInstance>(GetWorld()->GetGameInstance());

	_curHp += amount;
	if (_curHp <= 0) {
		auto enemy = Cast<ARSP_Enemy>(GetOwner());
		if (enemy) {
		
			enemy->DropItem();
			if (gameInstance->enemyDeadEvent.IsBound()) {
				gameInstance->enemyDeadEvent.Broadcast(enemy->GetLevel());
			}
		}
		_curHp = 0;
	}
	if (_curHp > _maxHp) {
		_curHp = _maxHp;
	}
	auto actor = GetOwner();
	
	UE_LOG(LogTemp, Warning, TEXT("Name : %s , HP : %d"), *actor->GetName(), _curHp);
	
	float ratio = _curHp / (float)_maxHp;
	if (hpChanged.IsBound()) {
		hpChanged.Broadcast(ratio);
	}
	
}

void URSP_StatComponent::AddExp(int32 value)
{
	auto gameInstance = Cast<URSP_GameInstance>(GetWorld()->GetGameInstance());	
	auto character = Cast<ARSP_Character>(GetOwner());
	auto player = Cast<ARSP_Player>(character);

	_curExp += value;
	if (player) {
		float ratio = _curExp / StaticCast<float>(_levelUpExp);
		if (expChanged.IsBound()) {
			expChanged.Broadcast(ratio);
		}
	}
	if (_curExp >= _levelUpExp && _level < gameInstance->GetStatTableSize()) {
		auto exp = _curExp - _levelUpExp;
		_level++;

		UE_LOG(LogTemp, Error, TEXT("LEVEL changed : %d"), _level);
		if (levelChanged.IsBound()) {
			levelChanged.Broadcast(_level);
			expChanged.Broadcast(0);
		}
		
		auto statInfo = gameInstance->GetStat_Level(_level);
		_maxHp = statInfo.maxHp;
		_curHp = statInfo.maxHp;
		_atk = statInfo.atk;
		_dropGold = statInfo.dropGold;
		_levelUpExp = statInfo.levelUpExp;
		_dropExp = statInfo.dropExp;
		_curExp = exp;
	}

}

void URSP_StatComponent::AddGold(int32 value)
{
	auto player = Cast<ARSP_Player>(GetOwner());
	if (player) {
		_curGold += value;
		UE_LOG(LogTemp, Error, TEXT("Gold : %d"), _curGold);
		player->AdjustGoldEvent(value);
	}
}

void URSP_StatComponent::ExecuteReward(int32 level)
{
	auto pawn = GetOwner();
	auto player = Cast<ARSP_Player>(GetOwner());
	auto companoin = Cast<ARSP_Companion>(GetOwner());

	if (player == nullptr && companoin == nullptr) {
		return;
	}
	else {
		auto gameInstance = Cast<URSP_GameInstance>(GetWorld()->GetGameInstance());
		auto statInfo = gameInstance->GetStat_Level(level);

		int32 companoinCount = gameInstance->GetClassCount(GetWorld(), ARSP_Companion::StaticClass()) + 1;//플레이어와 동료의 합
		
		auto reward_exp = StaticCast<int32>((statInfo.dropExp / StaticCast<float>(companoinCount)));
		auto reward_gold = StaticCast<int32>((statInfo.dropGold / StaticCast<float>(companoinCount)));
		
		AddGold(reward_gold);
		AddExp(reward_exp);
	}
	
}

void URSP_StatComponent::SetLevel(int32 level)
{
	auto gameInstance = Cast<URSP_GameInstance>(GetWorld()->GetGameInstance());
	auto character = Cast<ARSP_Character>(GetOwner());

	auto statInfo = gameInstance->GetStat_Level(level);
	_level = level;
	_maxHp = statInfo.maxHp;
	_curHp = statInfo.maxHp;
	_atk = statInfo.atk;
	_dropGold = statInfo.dropGold;
	_levelUpExp = statInfo.levelUpExp;
	_dropExp = statInfo.dropExp;
	levelChanged.Broadcast(level);
}

void URSP_StatComponent::InitialSetting()
{
	auto player = Cast<ARSP_Player>(GetOwner());
	if (player) {
		player->AdjustGoldEvent(_curGold);
	}
}

