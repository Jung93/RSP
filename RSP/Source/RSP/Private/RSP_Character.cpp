// Fill out your copyright notice in the Description page of Project Settings.


#include "RSP_Character.h"
#include "Animation/RSP_AnimInstance.h"
#include "RSP_StatComponent.h"
#include "RSP_PlayerController.h"

#include "UI/RSP_HpBar.h"
#include "Components/WidgetComponent.h"

#include "Kismet/KismetMathLibrary.h"
// Sets default values
ARSP_Character::ARSP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	_statComponent = CreateDefaultSubobject<URSP_StatComponent>(TEXT("StatComponent"));

	_hpBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HpBar"));
	_hpBarWidget->SetupAttachment(GetMesh());
	_hpBarWidget->SetWidgetSpace(EWidgetSpace::World);

	_hpBarWidget->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 300.0f),FRotator::ZeroRotator);
	
	static ConstructorHelpers::FClassFinder<URSP_HpBar> hpBarClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/BP_RSP_HpBar.BP_RSP_HpBar_C'"));
	if (hpBarClass.Succeeded())
	{
		_hpBarWidget->SetWidgetClass(hpBarClass.Class);
	}
}

void ARSP_Character::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	_animInstance = Cast<URSP_AnimInstance>(GetMesh()->GetAnimInstance());
	if (_animInstance)
		_animInstance->_deadEvent.AddUObject(this, &ARSP_Character::DeadEvent);
	
}

// Called when the game starts or when spawned
void ARSP_Character::BeginPlay()
{
	Super::BeginPlay();

	auto widget = _hpBarWidget->GetWidget();
	auto hpBar = Cast<URSP_HpBar>(widget);
	if (hpBar) {
		_statComponent->levelChanged.AddUObject(hpBar, &URSP_HpBar::SetLevelText);
		_statComponent->hpChanged.AddUObject(hpBar, &URSP_HpBar::SetHpBarValue);
	}
}

// Called every frame
void ARSP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto playerCameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	if (playerCameraManager)
	{
		FVector hpBarLocation = _hpBarWidget->GetComponentLocation();
		FVector cameraLocation = playerCameraManager->GetCameraLocation();
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(hpBarLocation, cameraLocation);
		_hpBarWidget->SetWorldRotation(rotation);
	}
}

// Called to bind functionality to input
void ARSP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARSP_Character::AttackEnd(UAnimMontage* Montage, bool bInterrupted)
{
	_isAttack = false;
}

void ARSP_Character::Attack_Hit()
{
}

void ARSP_Character::DeadEvent()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	Controller->UnPossess();
}

void ARSP_Character::AddHp(float amount)
{
	_statComponent->AddCurHp(amount);
}

float ARSP_Character::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	_statComponent->AddCurHp(-Damage);

	auto attackerController = Cast<ARSP_PlayerController>(EventInstigator);
	if (attackerController)
	{
		if (IsDead())
		{
			UE_LOG(LogTemp, Error, TEXT("Be Dead by Player"));
		}
	}
	
	return Damage;
}

bool ARSP_Character::IsDead()
{
	return _statComponent->IsDead();
}

