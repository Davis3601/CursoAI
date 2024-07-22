// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_SetRunSpeed.generated.h"

/**
 * 
 */
UCLASS()
class UETC_IA_API UBTTask_SetRunSpeed : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTTask_SetRunSpeed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Navigation")
	float MaxWalkSpeed = 300.f;



protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	class AAIController* EnemyController;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
