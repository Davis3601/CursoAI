// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SearchForPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"

UBTTask_SearchForPlayer::UBTTask_SearchForPlayer()
{

	NodeName = "Search for player";
	SearchRadius = 250.0f; 
	TargetLocationKey.SelectedKeyName = "TargetLocation";

}

EBTNodeResult::Type UBTTask_SearchForPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

    BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        return EBTNodeResult::Failed;
    }

    Origin = BlackboardComp->GetValueAsVector(TargetLocationKey.SelectedKeyName);
    

    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
    if (NavSys && NavSys->GetRandomPointInNavigableRadius(Origin, SearchRadius, RandomLocation))
    {
        // Update the blackboard with the new random location
        BlackboardComp->SetValueAsVector(TargetLocationKey.SelectedKeyName, RandomLocation.Location);

        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;

}
