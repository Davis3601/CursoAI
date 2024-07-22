// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindAndChasePlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

UBTTask_FindAndChasePlayer::UBTTask_FindAndChasePlayer()
{
	NodeName = "Find And Chase Player";

	// Set Target Location Blackboard key
	TargetLocationKey.SelectedKeyName = TEXT("TargetLocation");
}

EBTNodeResult::Type UBTTask_FindAndChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

			// Issue a move command to the AI
			AIController->MoveToLocation(PlayerLocation, -1.0f, true, true, false, true, 0, true);

			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
