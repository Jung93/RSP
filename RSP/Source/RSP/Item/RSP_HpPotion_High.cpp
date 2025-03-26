// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/RSP_HpPotion_High.h"
#include "RSP_Player.h"

void ARSP_HpPotion_High::BeginPlay()
{
	Super::BeginPlay();

	SetInfomation(name);
}

void ARSP_HpPotion_High::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	//auto character = Cast<ARSP_Player>(OtherActor);
	//
	//if (character == nullptr) {
	//	return;
	//}
	//if (character->GetEmptyArraySize() == 0) {
	//	return;
	//}
	//character->AddItem(this);
	//SetActorHiddenInGame(true);
	//SetActorEnableCollision(false);
}
