// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_LastPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class UETC_IA_API UBTTask_LastPlayerLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTTask_LastPlayerLocation();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:

	struct FBlackboardKeySelector TargetLocationKey;

	AAIController* AIController;

	ACharacter* PlayerCharacter;

	FVector PlayerLocation;
	
};