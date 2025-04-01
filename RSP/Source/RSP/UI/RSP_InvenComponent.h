// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/RSP_Item.h"
#include "RSP_InvenComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_ThreeParams(FSetitemTextureEvent, int32, FRSP_ItemInfo , AActor*);
DECLARE_MULTICAST_DELEGATE_TwoParams(FItemAddEvent, int32, FRSP_ItemInfo);
DECLARE_MULTICAST_DELEGATE_OneParam(FItemDrop, int32);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RSP_API URSP_InvenComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URSP_InvenComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION()
	void SetArraySize(int32 num) { _itemArraySize = num; }
	int32 GetEmptyArraySize();
	int32 GetEmptyIndex();

	void AddItem(ARSP_Item* item);
	void AddItem_Store(ARSP_Item* item , AActor* actor);
	ARSP_Item* DropItem(ARSP_Item* item , int32 index);
	void UseInventoryItem(int32 index);
	void SellThisItem(int32 index);

	const TArray<ARSP_Item*>& GetItemArray_Inven() { return _invenItems; }
	void SetItemArray_Inven(const TArray<ARSP_Item*>& items) { _invenItems = items; }

	void UpdateInven(AActor* actor);
	FItemAddEvent itemAddEvent;
	FSetitemTextureEvent setitemTextureEvent;
	FItemDrop itemDropEvent;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta = (AllowPrivateAccess = "true"))
	TArray<ARSP_Item*> _invenItems;
	UPROPERTY()
	int32 _itemArraySize = 0;

};
