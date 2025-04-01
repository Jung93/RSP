// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RSP_InvenComponent.h"
#include "Item/RSP_ItemShop.h"
#include "Kismet/GameplayStatics.h"
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
	_invenItems.SetNum(18);
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
	for (auto item : _invenItems) {
		if (item == nullptr) {
			count++;
		}
	}
	return count;
}

int32 URSP_InvenComponent::GetEmptyIndex()
{
	int32 index = 0;
	for (auto item : _invenItems) {
		if (item == nullptr) {
			break;
		}
		index++;
	}
	return index;
}

void URSP_InvenComponent::AddItem(ARSP_Item* item)
{
	auto target = _invenItems.FindByPredicate([](ARSP_Item* here) {
		return here == nullptr;
	});
	if (target == nullptr) {
		return;
	}
	int32 index = GetEmptyIndex();
	_invenItems[index] = item;

	if (itemAddEvent.IsBound()) {
		itemAddEvent.Broadcast(index, item->GetInfo());
	}
}

void URSP_InvenComponent::AddItem_Store(ARSP_Item* item, AActor* actor)
{
	auto target = _invenItems.FindByPredicate([](ARSP_Item* here) {
		return here == nullptr;
	});
	if (target == nullptr) {
		return;
	}
	int32 index = GetEmptyIndex();
	_invenItems[index] = item;

	if (setitemTextureEvent.IsBound()) {
		setitemTextureEvent.Broadcast(index, item->GetInfo(),actor);
	}
}

ARSP_Item* URSP_InvenComponent::DropItem(ARSP_Item* item , int32 index)
{
	_invenItems[index] = nullptr;
	itemDropEvent.Broadcast(index);
	return item;
}

void URSP_InvenComponent::UseInventoryItem(int32 index)
{	
	ARSP_ItemShop* ItemShop = Cast<ARSP_ItemShop>(
		UGameplayStatics::GetActorOfClass(GetWorld(), ARSP_ItemShop::StaticClass())
	);

	_invenItems[index] = nullptr;

	if (ItemShop != nullptr)
	{
		UpdateInven(ItemShop);
	}
	
}

void URSP_InvenComponent::SellThisItem(int32 index)
{
	_invenItems[index] = nullptr;
}

void URSP_InvenComponent::UpdateInven(AActor* actor)
{
	for (int32 i = 0; i < _invenItems.Num(); i++) {
		if (_invenItems[i] != nullptr) {
			if (setitemTextureEvent.IsBound()) {				
				setitemTextureEvent.Broadcast(i, _invenItems[i]->GetInfo(),actor);
			}
			
		}	
		else {
			if (setitemTextureEvent.IsBound()) {
				setitemTextureEvent.Broadcast(i, FRSP_ItemInfo(), actor);
			}
		}

	}
}




