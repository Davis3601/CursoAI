// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySoldier.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIController.h"
#include "Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemySoldier::AEnemySoldier()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set collision settings for the mesh
	GetMesh()->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);

	// Set collision settings for the capsule component
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	// Character movement settings
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Initialize patrol target to nullptr
	PatrolTarget = nullptr;
}

// Called when the game starts or when spawned
void AEnemySoldier::BeginPlay()
{
	Super::BeginPlay();

}



// Utility method to check if a target is within a given radius
bool AEnemySoldier::InTargetRange(AActor* Target, double Radius)
{
	const double DistanceToTarget = (Target->GetActorLocation() - GetActorLocation()).Size();
	return DistanceToTarget <= Radius;
}

// Called every frame
void AEnemySoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	* // Handle patrol logic
	if (PatrolTarget && EnemyController)
	{
		FString PatrolTargetName = PatrolTarget->GetName();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("PatrolTarget: %s"), *PatrolTargetName));
		}

		if (InTargetRange(PatrolTarget, PatrolRadius))
		{
			// Select a new patrol target
			TArray<AActor*> ValidTargets;
			for (AActor* Target : PatrolTargets)
			{
				if (Target != PatrolTarget)
				{
					ValidTargets.AddUnique(Target);
				}
			}

			const int32 NumValidTargets = ValidTargets.Num();
			if (NumValidTargets > 0)
			{
				const int32 TargetSelection = FMath::RandRange(0, NumValidTargets - 1);
				PatrolTarget = ValidTargets[TargetSelection];

				// Move to the new patrol target
				//MoveToPatrolTarget();
			}
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("PatrolTarget is not set"));
		}
	}
	*/
	

	// Handle combat logic (uncomment and complete this section as needed)
	/*
	if (CombatTarget)
	{
		const double DistanceToTarget = (CombatTarget->GetActorLocation() - GetActorLocation()).Size();
		if (!InTargetRange(CombatTarget, CombatRadius))
		{
			CombatTarget = nullptr;
		}
	}
	*/
}

// Called to bind functionality to input
void AEnemySoldier::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

