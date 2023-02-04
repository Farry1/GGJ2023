// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

#include "GridObject.h"

FIntPoint AGrid::GetGridPosition_Implementation(FVector WorldPosition)
{
	FVector SnappedPosition = {
		FMath::GridSnap(WorldPosition.X, GLOBAL_GRID_SCALE),
		FMath::GridSnap(WorldPosition.Y, GLOBAL_GRID_SCALE),
		0.0f
	};
	int X = SnappedPosition.X / GLOBAL_GRID_SCALE;
	int Y = SnappedPosition.Y / GLOBAL_GRID_SCALE;
	return {X, Y};
}

FVector AGrid::GetWorldPosition_Implementation(FIntPoint GridCoordinates)
{
	if (!IsValidIndex(GridCoordinates))
	{
		return FVector::Zero();
	}

	float X = GridCoordinates.X * GLOBAL_GRID_SCALE;
	float Y = GridCoordinates.Y * GLOBAL_GRID_SCALE;
	return {X, Y, 0.0f};
}

TArray<AGridObject*> AGrid::GetGridActorsAt(FIntPoint GridCoordinates)
{
	if (!IsValidIndex(GridCoordinates))
	{
		return {};
	}
	return Cells[GridCoordinates].GridObjects;
}

void AGrid::AddGridObject(AGridObject* GridObject)
{
	TArray<FIntPoint> OccupyingCells = GridObject->GetOccupyingCells();
	for (FIntPoint Point : OccupyingCells)
	{
		Cells[Point].GridObjects.Add(GridObject);
	}
}

void AGrid::RemoveGridObject(AGridObject* GridObject)
{
	TArray<FIntPoint> OccupyingCells = GridObject->GetOccupyingCells();
	for (FIntPoint Point : OccupyingCells)
	{
		Cells[Point].GridObjects.Remove(GridObject);
	}
}

bool AGrid::IsValidIndex(FIntPoint GridCoordinates)
{
	return Cells.Contains(GridCoordinates);
}

void AGrid::BeginPlay()
{
	Super::BeginPlay();
	for (int x = 0; x < Width; x++)
	{
		for (int y = 0; y < Height; y++)
		{
			FGridCell Cell;
			Cell.Position = {x, y};
			Cells.Add({x, y}, Cell);
		}
	}
}
