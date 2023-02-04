// Fill out your copyright notice in the Description page of Project Settings.


#include "GridObject.h"

#include "GGJ2023/GGJ2023GameModeBase.h"
#include "GGJ2023/Core/StaticHelpers.h"

TArray<FIntPoint> AGridObject::GetOccupyingCells_Implementation()
{
	return {-1, -1};
}

void AGridObject::AddToGrid()
{
	UStaticHelpers::GetGridInstance(this)->AddGridObject(this);
}

void AGridObject::RemoveFromGrid()
{
}

bool AGridObject::CanBePlaced(TArray<FIntPoint>& ValidTiles, TArray<FIntPoint>& InvalidTiles)
{
	ValidTiles = GetOccupyingCells();
	TArray<FIntPoint> AdditionalTiles = {};

	int ValidRulesCount = 0;
	for (TSubclassOf<UPlacementRuleConfig> PlacementRuleConfig : GridObjectData->PlacementRules)
	{
		UPlacementRuleConfig* CurrentRule = Cast<UPlacementRuleConfig>(PlacementRuleConfig->GetDefaultObject(true));
		if (CurrentRule->CanBePlaced(this, ValidTiles, AdditionalTiles))
		{
			ValidRulesCount++;
		}
	}

	for (FIntPoint Point : GetOccupyingCells())
	{
		if (ValidTiles.Contains(Point))
		{
			continue;
		}
		InvalidTiles.Add(Point);
	}


	return ValidRulesCount == GridObjectData->PlacementRules.Num();
}

void AGridObject::BeginPlay()
{
	Super::BeginPlay();
}

void AGridObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
