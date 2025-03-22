// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	virtual void OnOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	
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

