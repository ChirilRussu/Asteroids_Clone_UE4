// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Asteroids_CloneGameMode.h"
#include "Asteroids_ClonePawn.h"

AAsteroids_CloneGameMode::AAsteroids_CloneGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAsteroids_ClonePawn::StaticClass();
}

