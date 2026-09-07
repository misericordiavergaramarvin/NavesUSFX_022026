// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFX_022026GameMode.h"
#include "NavesUSFX_022026Pawn.h"

#include "Enemigo.h"
#include "Engine/World.h"

ANavesUSFX_022026GameMode::ANavesUSFX_022026GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesUSFX_022026Pawn::StaticClass();
}


void ANavesUSFX_022026GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();
	if (World)
	{
		// Generar 10 enemigos esparcidos por diferentes puntos del mapa
		for (int32 i = 0; i < 10; i++)
		{
			// Coordenadas aleatorias para dispersarlos por la pantalla
			float SpawnX = FMath::RandRange(-800.0f, 800.0f);
			float SpawnY = FMath::RandRange(-800.0f, 800.0f);
			float SpawnZ = 150.0f; // Altura fija

			FVector PosicionSpawn = FVector(SpawnX, SpawnY, SpawnZ);
			FRotator RotacionSpawn = FRotator::ZeroRotator;

			World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), PosicionSpawn, RotacionSpawn);
		}
	}
}