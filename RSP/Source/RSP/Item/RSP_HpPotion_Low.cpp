// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RSP_HpPotion_Low.h"
#include "RSP_Player.h"

void ARSP_HpPotion_Low::BeginPlay()
{
	Super::BeginPlay();

	SetInfomation(name);
}

void ARSP_HpPotion_Low::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto character = Cast<ARSP_Player>(OtherActor);
	if (character == nullptr) {
		return;
	}
	auto temp = this->_itemInfo.itemStat;
	character->AddHp(-_itemInfo.itemStat);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	DrawDebugString(GetWorld(), GetActorLocation(), TEXT("ITEM"), nullptr, FColor::Blue, 5.0f, true);
}
