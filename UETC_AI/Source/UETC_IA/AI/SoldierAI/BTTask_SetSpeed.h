// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_SetSpeed.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UETC_IA_API UBTTask_SetSpeed : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:

	UBTTask_SetSpeed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Navigation")
	float MaxWalkSpeed = 125.f;



protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	class AAIController* EnemyController;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	

};
