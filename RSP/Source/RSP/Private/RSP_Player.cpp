// Fill out your copyright notice in the Description page of Project Settings.

#include "RSP_Player.h"
#include "RSP_Character.h"
#include "RSP_Enemy.h"
#include "RSP_StatComponent.h"
#include "UI/RSP_InvenUI.h"
#include "UI/RSP_InvenComponent.h"
#include "UI/RSP_HpBar.h"
#include "RSP_PlayerController.h"
#include "UI/RSP_PlayerHpBar.h"
#include "Item/RSP_ItemShop.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Engine/DamageEvents.h"
#include "Components/CapsuleComponent.h"
#include "Components/Button.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"

#include "Animation/RSP_AnimInstance.h"


ARSP_Player::ARSP_Player()
{
	PrimaryActorTick.bCanEverTick = true;

	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));
	_springArm->SetRelativeLocation(FVector(-50, 0, 88));

	_springArm->bUsePawnControlRotation = true;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("RSP_Player"));

	_level = 1;

	static ConstructorHelpers::FClassFinder<URSP_InvenUI> invenClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_RSP_InvenUI.BP_RSP_InvenUI_C'"));
	if (invenClass.Succeeded()) {
		_invenWidget = CreateWidget<URSP_InvenUI>(GetWorld(), invenClass.Class);		
	}
	
	_invenComponent = CreateDefaultSubobject<URSP_InvenComponent>(TEXT("InvenComponent"));
	
	static ConstructorHelpers::FClassFinder<URSP_PlayerHpBar> playerHpBar(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_RSP_PlayerHpBar.BP_RSP_PlayerHpBar_C'"));
	if (playerHpBar.Succeeded()) {
		_playerHpBarWidget = CreateWidget<URSP_PlayerHpBar>(GetWorld(), playerHpBar.Class);
	}

}

void ARSP_Player::Attack_Hit()
{
	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	FVector forward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);


	float attackRadius = 100.0f;

	FVector Center = GetActorLocation() + forward * _attackRange * 0.5f;
	FVector Start = GetActorLocation() + forward * _attackRange * 0.5f;
	FVector End = GetActorLocation() + forward * _attackRange * 0.5f;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT hitResult,
		Start,
		End,
		quat,
		ECC_GameTraceChannel1,
		FCollisionShape::MakeCapsule(attackRadius, _attackRange * 0.5f),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		drawColor = FColor::Red;
		ARSP_Enemy* victim = Cast<ARSP_Enemy>(hitResult.GetActor());
		if (victim) {
			FDamageEvent damageEvent = FDamageEvent();
			FVector hitPoint = hitResult.ImpactPoint;
			//EFFECT_M->PlayEffect("BigFire", hitPoint);
			victim->TakeDamage(_statComponent->GetAtk(), damageEvent, GetController(), this);
			if (victim->IsDead()) {
				TakeExp(victim);
			}
		}
	}

	DrawDebugCapsule(
		GetWorld(),
		Center,
		_attackRange * 0.5f,
		attackRadius,
		quat,
		drawColor,
		false,
		3.0f
	);
}

void ARSP_Player::AdjustGoldEvent(int32 value)
{
	_invenWidget->gainGold.Broadcast(value);
}

void ARSP_Player::BeginPlay()
{
	Super::BeginPlay();

	_animInstance->OnMontageEnded.AddDynamic(this, &ARSP_Character::AttackEnd);
	_animInstance->_attackEvent.AddUObject(this, &ARSP_Player::Attack_Hit);
	//_animInstance->_deadEvent.AddUObject(this, &ARSP_Player::DeadEvent);

	_invenWidget->RSP_ExitButton->OnClicked.AddDynamic(this, &ARSP_Player::Inven_Close);
	_invenWidget->AddToViewport();
	_invenWidget->SetVisibility(ESlateVisibility::Collapsed);

	_invenComponent->itemAddEvent.AddUObject(_invenWidget, &URSP_InvenUI::SetItemTexture);
	_invenComponent->itemDropEvent.AddUObject(_invenWidget, &URSP_InvenUI::SetDropTexture);

	_invenWidget->hpPotionUsed.AddUObject(_invenWidget, &URSP_InvenUI::SendHealValue);
	_invenWidget->hpPotionUsed.AddUObject(_invenWidget, &URSP_InvenUI::UseInventoryItem);
	_invenWidget->hpPotionUsed.AddUObject(_invenComponent, &URSP_InvenComponent::UseInventoryItem);

	_invenWidget->healValue.AddUObject(_statComponent, &URSP_StatComponent::AddCurHp);
	_invenWidget->gainGold.AddUObject(_invenWidget, &URSP_InvenUI::AddGold);

	_hpBarWidget->SetWidget(nullptr);

	_statComponent->levelChanged.AddUObject(_playerHpBarWidget, &URSP_PlayerHpBar::SetLevelText);
	_statComponent->hpChanged.AddUObject(_playerHpBarWidget, &URSP_PlayerHpBar::SetHpBarValue);
	_statComponent->printName.AddUObject(_playerHpBarWidget, &URSP_PlayerHpBar::SetOwnerName);
	_statComponent->levelChanged.Broadcast(_level);
	_statComponent->printName.Broadcast(GetName());

	_playerHpBarWidget->AddToViewport();
}

void ARSP_Player::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	_invenComponent->SetArraySize(_invenWidget->GetSlotSize());
}

void ARSP_Player::TakeExp(ARSP_Enemy* enemy)
{
	auto exp = enemy->GetExp();
	auto gold = enemy->GetGold();
	_statComponent->AddExp(exp);
	_statComponent->AddGold(gold);
}

void ARSP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARSP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent) {
		enhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &ARSP_Player::Move);
		enhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &ARSP_Player::Look);
		enhancedInputComponent->BindAction(_attackAction, ETriggerEvent::Triggered, this, &ARSP_Player::Attack);
		enhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Triggered, this, &ARSP_Player::JumpA);
		enhancedInputComponent->BindAction(_invenOpenAction, ETriggerEvent::Started, this, &ARSP_Player::Inven_Open);
		enhancedInputComponent->BindAction(_interactionAction, ETriggerEvent::Started, this, &ARSP_Player::Interaction_Item);
	}
}

void ARSP_Player::Move(const FInputActionValue& value)
{
	//if (_isAttack) { return; }

	FVector2D moveVector = value.Get<FVector2D>();
	auto controller = Cast<ARSP_PlayerController>(GetController());
	if (controller != nullptr) {
		if (moveVector.Length() > 0.01f) {
			FVector forWard = GetActorForwardVector();
			FVector right = GetActorRightVector();

			_vertical = moveVector.Y;
			_horizontal = moveVector.X;

			AddMovementInput(forWard, moveVector.Y * 10);
			AddMovementInput(right, moveVector.X * 10); //10은 임시값 스탯컴포넌트에서 받아와야함 
		}
	}
}

void ARSP_Player::Look(const FInputActionValue& value)
{
	//if (_isInvenOpen) { return; }
	FVector2D lookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		AddControllerYawInput(lookAxisVector.X);
		AddControllerPitchInput(-lookAxisVector.Y);
	}
}

void ARSP_Player::JumpA(const FInputActionValue& value)
{
	//if (_isAttack) return;

	bool isPress = value.Get<bool>();

	if (isPress)
	{
		ACharacter::Jump();
	}
}

void ARSP_Player::Attack(const FInputActionValue& value)
{
	if (_isAttack || _interaction ||_isInvenOpen)
		return;

	bool isPress = value.Get<bool>();

	if (isPress)
	{
		_isAttack = true;

		_curAttackSection = (_curAttackSection) % 3 + 1;

		_animInstance->PlayAnimMontage();
		_animInstance->JumpToSection(_curAttackSection);
	}

}

void ARSP_Player::Inven_Open(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();
	auto controller = Cast<ARSP_PlayerController>(GetController());
	if (controller != nullptr && isPressed) {
		if (_isInvenOpen) {
			if (controller) {
				controller->HideUI();
			}
			_invenWidget->SetVisibility(ESlateVisibility::Collapsed);
		}
		else {
			if (controller) {
				controller->ShowUI();
			}
			_invenWidget->SetVisibility(ESlateVisibility::Visible);
		}
		_isInvenOpen = !_isInvenOpen;

	}
}

void ARSP_Player::Interaction_Item(const FInputActionValue& value)
{
	FVector2D viewportSize;
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(viewportSize);
	}

	bool isPressed = value.Get<bool>();
	auto controller = Cast<ARSP_PlayerController>(GetController());
	if (controller != nullptr && isPressed) {
		auto screenX = viewportSize.X / 2.0f;
		auto screenY = viewportSize.Y / 2.0f;

		FVector WorldLocation;
		FVector WorldDirection;
	
		if (controller->DeprojectScreenPositionToWorld(screenX, screenY, WorldLocation, WorldDirection)) {
			FVector Start = WorldLocation;
			FVector End = Start + (WorldDirection * 1000.0f);

			FHitResult HitResult;
			FCollisionQueryParams TraceParams(FName(TEXT("RSP_line")), true, this);
			TraceParams.bTraceComplex = true;
			TraceParams.bReturnPhysicalMaterial = false;

			bool bHit = GetWorld()->LineTraceSingleByChannel(
				HitResult,
				Start,
				End,
				ECC_GameTraceChannel6,
				TraceParams
			);
			if (bHit)
			{
				AActor* HitActor = HitResult.GetActor();
				if (HitActor)
				{
					auto RSP_itemShop = Cast<ARSP_ItemShop>(HitActor);
					auto RSP_item = Cast<ARSP_Item>(HitActor);
					if (RSP_itemShop) {
						if (RSP_itemShop->bCanInteraction)
						{
							RSP_itemShop->bCanInteraction = false;
							RSP_itemShop->OpenShopUI(this);
						}
					}
					if (RSP_item) {
						if (RSP_item->bCanInteraction) {							
							RSP_item->bCanInteraction = false;
							RSP_item->ActivateItemEffect(this);
						}
					}
				}
			}
		}

	}
	
}

void ARSP_Player::Inven_Close()
{
	if (_isAttack) { return; }

	auto controller = Cast<ARSP_PlayerController>(GetController());

	if (controller) {
		controller->HideUI();
		_invenWidget->SetVisibility(ESlateVisibility::Collapsed);
		_isInvenOpen = false;
	}
}

int32 ARSP_Player::GetEmptyArraySize()
{
	return _invenComponent->GetEmptyArraySize();
}


void ARSP_Player::AddItem(ARSP_Item* item)
{
	_invenComponent->AddItem(item);
}
