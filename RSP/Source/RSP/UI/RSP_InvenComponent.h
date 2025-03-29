// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/RSP_Item.h"
#include "RSP_InvenComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FItemAdd, int32, FRSP_ItemInfo);
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
	ARSP_Item* DropItem(ARSP_Item* item , int32 index);
	void UseInventoryItem(int32 index);

	TArray<ARSP_Item*> GetItemArray() { return _items; }

	FItemAdd itemAddEvent;
	FItemDrop itemDropEvent;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta = (AllowprivateAccess = "true"))
	TArray<ARSP_Item*> _items;
	UPROPERTY()
	int32 _itemArraySize = 0;

};
/*
1.상점을 연다 
2.상점컴포넌트의 그리드 슬롯 안에 플레이어->인벤컴포넌트 그리드 슬롯 항목들을 복사한다
3.복사한 항목들의 이미지와 툴팁을 차례대로 받아와 붙인다
4.판매버튼을 누르면 해당 아이템의 금액 * 0.5만큼 골드가 오른다
5.판매된 아이템의 자리의 이미지는 tex_디폴트 , 설명은 빈칸으로 변경한다
6.판매된 슬롯의 현재 인덱스를 받아와 델리게이트로 쏴주기
7.델리게이트로 받은 슬롯의 인덱스로 가서 상점 컴포넌트의 그리드 슬롯번호에 항목을 nullptr로 만든다
8.상점컴포넌트에 해당 아이템을 추가한다 델리게이트로 인덱스랑 아이템정보 쏴주기
9.델리게이트 받아서 상점의 해당 인덱스에 정보대로 이미지 붙여주기
*/