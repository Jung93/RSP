// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RSP_Item.generated.h"

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
	void OnOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
protected:
	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, Category = "Collider")
	class UCapsuleComponent* _collider;
};

/*
아이템id
아이템 이름
가격(되팔때가격은 곱하기0.5)
효과

플레이어 아래

*/
