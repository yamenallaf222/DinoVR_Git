// Copyright Epic Games, Inc. All Rights Reserved.

#include "DinoVRGameMode.h"
#include "DinoVRCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADinoVRGameMode::ADinoVRGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
