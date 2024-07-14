#include "SpaceshipMovementComponent.h"
#include "Net/UnrealNetwork.h"

void USpaceshipMovementComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const 
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(USpaceshipMovementComponent, PitchInput, COND_Custom);
	DOREPLIFETIME_CONDITION(USpaceshipMovementComponent, YawInput, COND_Custom);
	DOREPLIFETIME_CONDITION(USpaceshipMovementComponent, RollInput, COND_Custom);

	DOREPLIFETIME_CONDITION(USpaceshipMovementComponent, ForwardInput, COND_Custom);
	DOREPLIFETIME_CONDITION(USpaceshipMovementComponent, RightInput, COND_Custom);
	DOREPLIFETIME_CONDITION(USpaceshipMovementComponent, UpInput, COND_Custom);
}

void USpaceshipMovementComponent::ErrorCatchUp(float DeltaTime)
{

}

void USpaceshipMovementComponent::BroadcastMovement(float DeltaTime)
{

}

void USpaceshipMovementComponent::BroadcastInput(float DeltaTime)
{

}