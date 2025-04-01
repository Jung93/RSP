// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_Boss.h"
#include "RSP_Character.h"

#include "UI/RSP_AggroTableUI.h"



ARSP_Boss::ARSP_Boss()
{

	static ConstructorHelpers::FClassFinder<URSP_AggroTableUI> aggroClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_RSP_AggroTableUI.BP_RSP_AggroTableUI_C'"));
	if (aggroClass.Succeeded()) {
		aggroUIClass = aggroClass.Class;
	}

}

void ARSP_Boss::BeginPlay()
{
	Super::BeginPlay();

	_aggroUI = CreateWidget<URSP_AggroTableUI>(GetWorld(), aggroUIClass);

	_aggroUI->AddToViewport();
	_aggroUI->aggroEvent.AddUObject(_aggroUI, &URSP_AggroTableUI::SetAggroTableInfo);
}

void ARSP_Boss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARSP_Boss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ARSP_Boss::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	auto attacker = Cast<ARSP_Character>(DamageCauser);

	if (!attacker->IsValidLowLevel())
		return 0.0f;

	SetAggroTable(attacker, Damage);

	_aggroUI->aggroEvent.Broadcast(_aggroTable);

	return Damage;
}

void ARSP_Boss::SetAggroTable(ARSP_Character* damageCauser, float damage)
{
	if (_aggroTable.IsEmpty())
	{
		FAggroTable attackerInfo;
		attackerInfo.character = damageCauser;
		attackerInfo.totalDamage = damage;

		_aggroTable.Push(attackerInfo);
	}
	else
	{
		auto existing = _aggroTable.FindByPredicate([damageCauser](const FAggroTable attackerinfo)->bool
			{
				if (attackerinfo.character == damageCauser)
					return true;
				return false;
			});

		if (existing != nullptr)
		{
			existing->totalDamage += damage;
		}
		else
		{
			FAggroTable attackerInfo;
			attackerInfo.character = damageCauser;
			attackerInfo.totalDamage = damage;

			_aggroTable.Push(attackerInfo);
		}

	}
}



void ARSP_Boss::SortAggroTable()
{
	if (_aggroTable.Num() < 2)
		return;

	_aggroTable.Sort([](const FAggroTable a, const FAggroTable b)->bool
		{
			if (a.totalDamage > b.totalDamage)
				return true;
			return false;
		});
}
