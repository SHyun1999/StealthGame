// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Objective.generated.h"

UCLASS()
class STEALTH_API AObjective : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjective();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "meshes")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "meshes")
	class USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category="fx")
	UParticleSystem* PickupFX;

	void PlayEffects();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
