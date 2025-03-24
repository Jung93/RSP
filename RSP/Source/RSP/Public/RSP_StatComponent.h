// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RSP_StatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FHpChanged, float);
DECLARE_MULTICAST_DELEGATE_OneParam(FLevelChanged, int32);

USTRUCT() 
struct FRSP_StatData : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 maxHp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 atk;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 levelUpExp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 dropExp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 dropGold;	
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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
	int32 GetCurHp() { return _curHp; }
	int32 GetAtk() { return _atk; }
	int32 GetlevelUpExp() { return _levelUpExp; }
	int32 GetCurExp() { return _curExp; }

	bool IsDead() { return _curHp <= 0; }
	int32 GetDropExp() { return _dropExp; }
	int32 GetDropGold() { return _dropGold; }

	void AddCurHp(float amount);
	void AddCurHp(int32 amount);
	void AddExp(int32 value);
	void AddGold(int32 value);

	FLevelChanged levelChanged;
	FHpChanged hpChanged;
private:
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _level = 1;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _curHp;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _maxHp;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _atk;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _curExp = 0;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _curGold;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _levelUpExp;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _dropExp;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	int32 _dropGold;
};
