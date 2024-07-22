// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetRunSpeed.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTTask_SetRunSpeed::UBTTask_SetRunSpeed()
{
	NodeName = "SetRunSpeed";
}

EBTNodeResult::Type UBTTask_SetRunSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EnemyController = OwnerComp.GetAIOwner();
	if (!EnemyController)
	{
		return EBTNodeResult::Failed;
	}

	// Get the pawn controlled by the AI controller
	APawn* AIPawn = EnemyController->GetPawn();
	if (!AIPawn)
	{
		return EBTNodeResult::Failed;
	}

	// Cast the pawn to ACharacter to access the CharacterMovementComponent
	ACharacter* AICharacter = Cast<ACharacter>(AIPawn);
	if (!AICharacter)
	{
		return EBTNodeResult::Failed;
	}

	// Set the maximum walk speed
	AICharacter->GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;

	// Return success
	return EBTNodeResult::Succeeded;
}
