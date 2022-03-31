// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIGuard.generated.h"

UENUM(BlueprintType)
enum class EAIState : uint8
{
	Idle,
	Sus,
	Alert
};

class UPawnSensingComponent;
UCLASS()
class STEALTH_API AAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "components")
	UPawnSensingComponent* PawnSensingComp;
	FRotator OriginalRotation;
	FTimerHandle TimerHandle_ResetOrientation;
	EAIState GuardState;
	UPROPERTY(EditInstanceOnly, Category = "AI")
		bool bPatrol;
	UPROPERTY(EditInstanceOnly, Category = "AI")
	AActor* FirstPatrolPoint;
	UPROPERTY(EditInstanceOnly, Category = "AI")
		AActor* SecondPatrolPoint;

	AActor* CurrentPatrolPoint;

	void MoveToNextPatrolPoint();


	void SetGuardState(EAIState NewState);
	
	UFUNCTION(BlueprintImplementableEvent, Category="AI")
	void OnStateChanged(EAIState NewState);
	//busted! game over
	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

	//turns guard toward the direction of the noise
	UFUNCTION()
	void OnNoiseHeard(APawn* NoiseInstigator, const FVector& Location, float Volume);

	//returns to original orientation after 5 s
	UFUNCTION()
	void ResetOrientation();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
