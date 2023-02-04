// Fill out your copyright notice in the Description page of Project Settings.


#include "GridObject.h"

#include "GGJ2023/GGJ2023GameModeBase.h"
#include "GGJ2023/Core/StaticHelpers.h"

TArray<FIntPoint> AGridObject::GetOccupyingCells_Implementation()
{
	return {-1000, -1000};
}

TArray<FIntPoint> AGridObject::GetNeighbouringCells_Implementation()
{
	return {-1000, -1000};
}

void AGridObject::AddToGrid()
{
	UStaticHelpers::GetGridInstance(this)->AddGridObject(this);
}

void AGridObject::RemoveFromGrid()
{
}

bool AGridObject::CanBePlaced(TArray<FIntPoint>& ValidTiles, TArray<FIntPoint>& InvalidTiles, TArray<FIntPoint>& ValidNeighbourTiles)
{
	ValidTiles = GetOccupyingCells();
	ValidNeighbourTiles = GetNeighbouringCells();

	int ValidRulesCount = 0;
	for (TSubclassOf<UPlacementRuleConfig> PlacementRuleConfig : GridObjectData->PlacementRules)
	{
		UPlacementRuleConfig* CurrentRule = Cast<UPlacementRuleConfig>(PlacementRuleConfig->GetDefaultObject(true));
		if (CurrentRule->CanBePlaced(this, ValidTiles, ValidNeighbourTiles))
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

	if (ValidTiles.Num() == 0)
	{
		InvalidTiles = GetOccupyingCells();
		ValidRulesCount = -1;
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
