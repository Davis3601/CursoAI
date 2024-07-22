// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_GetPatrolPoint.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UETC_IA_API UBTTask_GetPatrolPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTTask_GetPatrolPoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
	FVector TargetLocation;

	// Number of patrol targets
	int32 NumPatrolTargets;

protected:

	// AI Controller reference
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Navigation")
	class AAIController* EnemyController;

	// Patrol targets array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Navigation")
	TArray<AActor*> PatrolTargets;

	// Current patrol target
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Navigation")
	AActor* PatrolTarget;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector TargetPointKey;

	UBlackboardComponent* BlackboardComp;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
