// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetPatrolPoint.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

UBTTask_GetPatrolPoint::UBTTask_GetPatrolPoint()
{
	NodeName = "GetPatrolPoint";
	
	// Initialize patrol target to nullptr
	PatrolTarget = nullptr;
}

EBTNodeResult::Type UBTTask_GetPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp)
	{
		return EBTNodeResult::Failed;
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), PatrolTargets);

	NumPatrolTargets = PatrolTargets.Num();
	if (NumPatrolTargets == 0)
	{
		return EBTNodeResult::Failed;
	}

	// Select a random target point from the list
	PatrolTarget = PatrolTargets[FMath::RandRange(0, NumPatrolTargets - 1)];
	if (PatrolTarget)
	{
		FString PatrolTargetName = PatrolTarget->GetName();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("PatrolTarget: %s"), *PatrolTargetName));
		}
		TargetLocation = PatrolTarget->GetActorLocation();
		// Set the location of the selected target point in the blackboard
		BlackboardComp->SetValueAsVector(TargetPointKey.SelectedKeyName, TargetLocation);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
