// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "SpaceshipMovementComponent.generated.h"


UENUM(BlueprintType)
enum class EAccelerationMode : uint8
{
	AM_Exponential UMETA(DisplayName = "Exponential"),
	AM_Linear UMETA(DisplayName = "Linear"),
};

/**
 * 
 */
UCLASS()
class SPACECOMBATDEMO_API USpaceshipMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

public:
	USpaceshipMovementComponent(const FObjectInitializer& ObjectInitializer);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetForwardInput(float Input);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetRightInput(float Input);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetUpInput(float Input);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetPitchInput(float Input);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetYawInput(float Input);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetRollInput(float Input);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = 0))
	float MaxSpeedForward = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = 0))
	float MaxSpeedRight = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = 0))
	float MaxSpeedUp = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	EAccelerationMode MovementAccelMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation", meta = (ClampMin = 0))
	float MaxSpeedPitch = 90.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation", meta = (ClampMin = 0))
	float MaxSpeedYaw = 90.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation", meta = (ClampMin = 0))
	float MaxSpeedRoll = 90.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	EAccelerationMode RotationAccelMode;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replication")
	bool bReplicateMovement = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replication")
	bool bReplicateInputs = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replication")
	bool bLocalInputPrediction = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replication")
	bool bLatencyCompensation = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replication", meta = (ClampMin = 0))
	float MovementReplicationFrequency = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replication", meta = (ClampMin = 0))
	float InputReplicationFrequency = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replication")
	bool PauseReplicationWhenStationary = true;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Replication", meta = (ClampMin = 0))
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Input")
	float PitchInput;
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Input")
	float YawInput;
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Input")
	float RollInput;
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Input")
	float ForwardInput;
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Input")
	float RightInput;
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Input")
	float UpInput;

	UPROPERTY(BlueprintReadWrite, Category = "Velocity")
	FVector AngularVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NonPhysSubstep", meta = (ClampMin = 0, ToolTip = "Lowest framerate for non-physical movement mode")) 
	float MinFrameRate = 60.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NonPhysSubstep", meta = (ClampMin = 1, ToolTip = "Maximum movement steps per frame for non-physical movement mode")) 
	int MaxStepsPerFrame = 12;

private:
	float ClientForwardInput;
	float ClientRightInput;
	float ClientUpInput;
	float ClientPitchInput;
	float ClientYawInput;
	float ClientRollInput;

	void ErrorCatchUp(float DeltaTime);
	void BroadcastMovement(float DeltaTime);
	void BroadcastInput(float DeltaTime);
	void SetPositionAndVelocity(FVector NewLocation, FRotator NewRotation, FVector NewVelocity, FVector NewAngularVelocity);
	void SetPositionAndVelocitySoft(FVector NewLocation, FRotator NewRotation, FVector NewVelocity, FVector NewAngualrVelocity);

	void SimulationStep(float DeltaTime);
};
