// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetIsPursuing.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTTask_SetIsPursuing::UBTTask_SetIsPursuing()
{
	NodeName = "Set IsPursuing";

	// Set Target Location Blackboard key
	bIsPursuingPlayer = TEXT("isPursuingPlayer");
}

EBTNodeResult::Type UBTTask_SetIsPursuing::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController)
	{
		// Update the blackboard with the player's location
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(bIsPursuingPlayer, false);

		return EBTNodeResult::Succeeded;
		
	}

	return EBTNodeResult::Failed;
}
