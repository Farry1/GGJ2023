// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacementRuleConfig.h"

#include "GGJ2023/Core/StaticHelpers.h"

bool UPlacementRuleConfig::CanBePlaced(const UObject* WorldContext, TArray<FIntPoint>& ValidTilesOut, TArray<FIntPoint>& ValidNeigbouringTiles)
{
	UWorld* World = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull);
	AGrid* Grid = UStaticHelpers::GetGridInstance(WorldContext);
	return GetValidTilesFromArea(ValidTilesOut, ValidNeigbouringTiles, Grid);
}

UWorld* UPlacementRuleConfig::GetWorld() const
{
	return TemporaryWorld;
}

bool UPlacementRuleConfig::GetValidTilesFromArea_Implementation(TArray<FIntPoint>& ValidTilesOut, TArray<FIntPoint>& ValidNeighbouringTiles, AGrid* GridInstance)
{
	return false;
}
