// Copyright Epic Games, Inc. All Rights Reserved.


#include "GGJ2023GameModeBase.h"

#include "Kismet/GameplayStatics.h"

AGrid* AGGJ2023GameModeBase::GetGridInstance(UObject* WorldContext)
{
	return Cast<AGrid>(UGameplayStatics::GetActorOfClass(WorldContext, AGrid::StaticClass()));
}
