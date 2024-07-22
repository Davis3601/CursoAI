// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_LastPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

UBTTask_LastPlayerLocation::UBTTask_LastPlayerLocation()
{
	NodeName = "Find And Chase Player";

	// Set Target Location Blackboard key
	TargetLocationKey.SelectedKeyName = TEXT("TargetLocation");
}

EBTNodeResult::Type UBTTask_LastPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AIController = OwnerComp.GetAIOwner();
	if (AIController)
	{
		PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		if (PlayerCharacter)
		{
			// Get player character location
			PlayerLocation = PlayerCharacter->GetActorLocation();

			// Update the blackboard with the player's location
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(TargetLocationKey.SelectedKeyName, PlayerLocation);

			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
