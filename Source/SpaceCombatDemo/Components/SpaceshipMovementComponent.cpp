// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipMovementComponent.h"


USpaceshipMovementComponent::USpaceshipMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void USpaceshipMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USpaceshipMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// skip if we don't want component updated when not rendered or if updated component can't move
	if (ShouldSkipUpdate(DeltaTime)) 
		return;

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//nothing needs to be done if this is zero anyway
	if (DeltaTime == 0.f) 
		return; 

	if ((!IsValid(UpdatedComponent)) || (!IsValid(GetOwner()))) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Actor or Root Component"));
		return;
	}

	int StepsPerFrame = FMath::Clamp(FMath::CeilToInt(DeltaTime * MinFrameRate), 1, MaxStepsPerFrame);
	for (int i = 0; i < StepsPerFrame; i++) 
	{
		SimulationStep(DeltaTime / float(StepsPerFrame));
	}

	ErrorCatchUp(DeltaTime);
	BroadcastMovement(DeltaTime);
	BroadcastInput(DeltaTime);
	
}

void USpaceshipMovementComponent::SimulationStep(float DeltaTime)
{

}

void USpaceshipMovementComponent::SetForwardInput(float Input)
{
	ClientForwardInput = Input;

	if (GetOwner()->GetLocalRole() == ROLE_Authority)
	{
		ForwardInput = Input;
	}
}

void USpaceshipMovementComponent::SetRightInput(float Input)
{
	ClientRightInput = Input;

	if (GetOwner()->GetLocalRole() == ROLE_Authority)
	{
		RightInput = Input;
	}
}

void USpaceshipMovementComponent::SetUpInput(float Input)
{
	ClientUpInput = Input;

	if (GetOwner()->GetLocalRole() == ROLE_Authority)
	{
		UpInput = Input;
	}
}

void USpaceshipMovementComponent::SetPitchInput(float Input)
{
	ClientPitchInput = Input;

	if (GetOwner()->GetLocalRole() == ROLE_Authority)
	{
		PitchInput = Input;
	}
}

void USpaceshipMovementComponent::SetYawInput(float Input)
{
	ClientYawInput = Input;

	if (GetOwner()->GetLocalRole() == ROLE_Authority)
	{
		YawInput = Input;
	}
}

void USpaceshipMovementComponent::SetRollInput(float Input)
{
	ClientRollInput = Input;

	if (GetOwner()->GetLocalRole() == ROLE_Authority)
	{
		RollInput = Input;
	}
}