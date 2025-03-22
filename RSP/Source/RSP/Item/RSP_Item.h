// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RSP_Player.h"
#include "RSP_GameInstance.h"
#include "Components/CapsuleComponent.h"
#include "RSP_Item.generated.h"

USTRUCT(BlueprintType)
struct FRSP_ItemInfo : public FTableRowBase {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString itemName = TEXT("Void");
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemPrice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString itemToolTip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemStat = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemMaxCount = 9;	
};

UCLASS()
class RSP_API ARSP_Item : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARSP_Item();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	virtual void OnOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	
	/*
	* 문제 : 
	추상클래스이고 자식에서 반드시 재정의해야하는 함수 OnOverlap
	하지만 순수가상함수로 정의할경우 UFUNCTION을 붙일수없음
	OnOVerlap함수는 다이나믹 델리게이트를 위한 함수로 반드시 UFUNCTION을 붙여야함

	* 해결 :
	UFUNCTION을 같은함수에 다시 사용할수없으므로 부모에서 빈함수 구현하고 UFUNCTION 사용
	자식에서 UFUNCTION을 안붙이고 override로 해결
	*/
	FRSP_ItemInfo GetInfo() { return _info; }
protected:
	
	void SetInfomation(FString name);

	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, Category = "Collider")
	class UCapsuleComponent* _collider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _itemId = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString _itemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _itemPrice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString _itemToolTip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _itemStat = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _itemMaxCount = 9;

	UPROPERTY()
	FRSP_ItemInfo _info;
};

