// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacementRuleConfig.h"

#include "GGJ2023/Core/StaticHelpers.h"

bool UPlacementRuleConfig::CanBePlaced(const UObject* WorldContext, TArray<FIntPoint>& ValidTilesOut, TArray<FIntPoint>& AdditionalTilesOut)
{
	UWorld* World = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull);
	AGrid* Grid = UStaticHelpers::GetGridInstance(WorldContext);
	return GetValidTilesFromArea(ValidTilesOut, AdditionalTilesOut, Grid);
}

UWorld* UPlacementRuleConfig::GetWorld() const
{
	return TemporaryWorld;
}

bool UPlacementRuleConfig::GetValidTilesFromArea_Implementation(TArray<FIntPoint>& ValidTilesOut, TArray<FIntPoint>& AdditionalTilesOut, AGrid* GridInstance)
{
	return false;
}
