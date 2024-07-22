// Copyright Epic Games, Inc. All Rights Reserved.

#include "UETC_IAGameMode.h"
#include "Player/Base/UETC_IACharacter.h"
#include "UObject/ConstructorHelpers.h"

AUETC_IAGameMode::AUETC_IAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
