// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CalculatorGameMode.h"
#include "CalculatorHUD.h"
#include "CalculatorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACalculatorGameMode::ACalculatorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACalculatorHUD::StaticClass();
}
