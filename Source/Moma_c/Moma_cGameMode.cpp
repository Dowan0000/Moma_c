// Copyright Epic Games, Inc. All Rights Reserved.

#include "Moma_cGameMode.h"
#include "Moma_cCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMoma_cGameMode::AMoma_cGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
