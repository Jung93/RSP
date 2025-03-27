// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RSP_ItemShop.generated.h"

UCLASS()
class RSP_API ARSP_ItemShop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARSP_ItemShop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ColliderBeginOverlapped(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	UFUNCTION()
	void ColliderEndOverlapped(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	bool bCanInteraction = false;

	void OpenShopUI(class AActor* actor);
	UFUNCTION()
	void CloseShopUI();
protected:
	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, Category = "Collider")
	class USphereComponent* _itemCollider;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* _shopEnterWidget;
	UPROPERTY()
	class UTexture2D* _keyTexture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowprivateAccess = "true"))
	class URSP_StoreUI* _storeWidget;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowprivateAccess = "true"))
	//class URSP_StoreComponent* _storeComponent;
};
