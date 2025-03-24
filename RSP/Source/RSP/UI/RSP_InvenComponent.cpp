// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_InvenComponent.h"

// Sets default values for this component's properties
URSP_InvenComponent::URSP_InvenComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URSP_InvenComponent::BeginPlay()
{
	Super::BeginPlay();
	//_items.SetNum(_itemArraySize);
	_items.SetNum(18);
}


// Called every frame
void URSP_InvenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 URSP_InvenComponent::GetEmptyArraySize()
{
	int32 count = 0;
	for (auto item : _items) {
		if (item == nullptr) {
			count++;
		}
	}
	return count;
}

int32 URSP_InvenComponent::GetEmptyIndex()
{
	int32 index = 0;
	for (auto item : _items) {
		if (item == nullptr) {
			break;
		}
		index++;
	}
	return index;
}

void URSP_InvenComponent::AddItem(ARSP_Item* item)
{
	auto target = _items.FindByPredicate([](ARSP_Item* here) {
		return here == nullptr;
	});
	if (target == nullptr) {
		return;
	}
	int32 index = GetEmptyIndex();
	_items[index] = item;
	itemAddEvent.Broadcast(index, item->GetInfo());
}

ARSP_Item* URSP_InvenComponent::DropItem(ARSP_Item* item , int32 index)
{
	_items[index] = nullptr;
	itemDropEvent.Broadcast(index);
	return item;
}

void URSP_InvenComponent::UseInventoryItem(int32 index)
{
	_items[index] = nullptr;
	auto items = _items;
}


