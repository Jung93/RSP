// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/RSP_InvenComponent.h"
#include "RSP_StoreComponent.generated.h"

/**
 * 
 */
UCLASS()
class RSP_API URSP_StoreComponent : public URSP_InvenComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	URSP_StoreComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

};

/*
1.상점을 팔기로 연다
2.상점컴포넌트의 그리드 슬롯 안에 플레이어->인벤컴포넌트 그리드 슬롯 항목들을 복사한다
3.복사한 항목들의 이미지와 툴팁을 차례대로 받아와 붙인다
4.판매버튼을 누르면 해당 아이템의 금액 * 0.5만큼 골드가 오른다
5.판매된 아이템의 자리의 이미지는 tex_디폴트 , 설명은 빈칸으로 변경한다
6.판매된 슬롯의 현재 인덱스를 받아와 델리게이트로 쏴주기
7.델리게이트로 받은 슬롯의 인덱스로 가서 상점 컴포넌트의 그리드 슬롯번호에 항목을 nullptr로 만든다
8.상점컴포넌트에 해당 아이템을 추가한다 델리게이트로 인덱스랑 아이템정보 쏴주기
9.델리게이트 받아서 상점의 해당 인덱스에 정보대로 이미지 붙여주기 
*/