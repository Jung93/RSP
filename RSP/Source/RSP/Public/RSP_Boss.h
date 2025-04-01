// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RSP_Enemy.h"
#include "RSP_Boss.generated.h"


USTRUCT()
struct FAggroTable 
{
	GENERATED_BODY()

	UPROPERTY()
	class ARSP_Character* character;

	UPROPERTY()
	float totalDamage;

	bool operator>(const FAggroTable& b) const
	{
		if (totalDamage > b.totalDamage)
			return true;
		return false;
	}
};

UCLASS()
class RSP_API ARSP_Boss : public ARSP_Enemy
{
	GENERATED_BODY()
	

public:
	ARSP_Boss();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void SetAggroTable(class ARSP_Character* damageCauser, float damage);


	void SortAggroTable();

	TArray<FAggroTable>& GetAggroTable() { return _aggroTable; }

private:
	TArray<FAggroTable> _aggroTable;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> aggroUIClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Aggro", meta = (AllowprivateAccess = "true"))
	class URSP_AggroTableUI* _aggroUI;

};
