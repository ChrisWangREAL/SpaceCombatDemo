// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipBase.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
ASpaceshipBase::ASpaceshipBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisonComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionRoot"));
	SetRootComponent(CollisonComp);

	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComp"));
	ArrowComp->SetupAttachment(RootComponent);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	SpringArmFollow = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmFollow"));
	SpringArmFollow->SetupAttachment(RootComponent);

	CameraFollow = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraFollow"));
	CameraFollow->SetupAttachment(SpringArmFollow);

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("SpaceshipMovement"));
	
}

// Called when the game starts or when spawned
void ASpaceshipBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceshipBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceshipBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpaceshipBase::MoveForward);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASpaceshipBase::Look);
		EnhancedInputComponent->BindAction(RollAction, ETriggerEvent::Triggered, this, &ASpaceshipBase::Roll);
	}

}

void ASpaceshipBase::MoveForward(const FInputActionValue& Value)
{

}

void ASpaceshipBase::Look(const FInputActionValue& Value)
{

}

void ASpaceshipBase::Roll(const FInputActionValue& Value)
{

}

