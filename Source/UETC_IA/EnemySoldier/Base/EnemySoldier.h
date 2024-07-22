// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemySoldier.generated.h"

UCLASS()
class UETC_IA_API AEnemySoldier : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemySoldier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// AI Controller reference
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	class AAIController* EnemyController;

	// Patrol targets array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TArray<AActor*> PatrolTargets;

	// Current patrol target
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	AActor* PatrolTarget;

	// Number of patrol targets
	int32 NumPatrolTargets;

	// Patrol radius to switch targets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float PatrolRadius = 300.f;

	// Combat target
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	AActor* CombatTarget;

	// Combat radius to engage targets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float CombatRadius = 200.f;

	// Function to check if a target is within a given range
	bool InTargetRange(AActor* Target, double Radius);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
