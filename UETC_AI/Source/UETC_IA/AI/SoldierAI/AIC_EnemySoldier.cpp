// Fill out your copyright notice in the Description page of Project Settings.


#include "AIC_EnemySoldier.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

AAIC_EnemySoldier::AAIC_EnemySoldier()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));

	// Initialize and configure sight perception
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	if (SightConfig)
	{
		SightConfig->SightRadius = 1000.0f;
		SightConfig->LoseSightRadius = 1200.0f;
		SightConfig->PeripheralVisionAngleDegrees = 90.0f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

		AIPerceptionComponent->ConfigureSense(*SightConfig);
		AIPerceptionComponent->SetDominantSense(UAISense_Sight::StaticClass());
		AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AAIC_EnemySoldier::OnPerceptionUpdated);
	}

	bCanSeePlayer = TEXT("CanSeePlayer");
	bIsPursuingPlayer = TEXT("isPursuingPlayer");

}

void AAIC_EnemySoldier::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTreeAsset && BlackboardAsset)
	{
		if (BlackboardComponent->InitializeBlackboard(*BlackboardAsset))
		{
			UE_LOG(LogTemp, Warning, TEXT("Blackboard initialized"));
			BehaviorTreeComponent->StartTree(*BehaviorTreeAsset);
			UE_LOG(LogTemp, Warning, TEXT("Behavior Tree started"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to initialize Blackboard"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BehaviorTreeAsset or BlackboardAsset is not set"));
	}
}

void AAIC_EnemySoldier::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	// Handle perception update here
	if (Stimulus.WasSuccessfullySensed())
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor %s was sensed"), *Actor->GetName());
		BlackboardComponent->SetValueAsBool(bCanSeePlayer, true);
		BlackboardComponent->SetValueAsBool(bIsPursuingPlayer, true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor %s lost"), *Actor->GetName());
		BlackboardComponent->SetValueAsBool(bCanSeePlayer, false);
	}
}


