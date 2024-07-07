// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceshipBase.generated.h"

class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UInputAction;
class UEnhancedInputComponent;
struct FInputActionValue;
class UArrowComponent;
class UInputMappingContext;
class UFloatingPawnMovement;

UCLASS()
class SPACECOMBATDEMO_API ASpaceshipBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceshipBase();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Roll(const FInputActionValue& Value);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UBoxComponent> CollisonComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UArrowComponent> ArrowComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArmFollow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> CameraFollow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> RollAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	TObjectPtr<UFloatingPawnMovement> FloatingMovement;
	
};
