// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RSP_SpawnActor.generated.h"

UCLASS()
class RSP_API ARSP_SpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARSP_SpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnCharacter();
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
protected:
	UPROPERTY(EditAnywhere, Category = "Character Class")
	TSubclassOf<class ARSP_Character> CharacterClass;
	UPROPERTY(VisibleAnywhere, Category = "Character Class")
	class ARSP_Character* _spawnedActor;
	UPROPERTY(EditAnywhere, Category = "Character Class")
	int32 _spawnCount;	
	UPROPERTY(EditAnywhere, Category = "Character Class")
	int32 _level;
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* _triggerBox;
};
