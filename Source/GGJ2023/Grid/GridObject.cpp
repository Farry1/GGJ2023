// Fill out your copyright notice in the Description page of Project Settings.


#include "GridObject.h"

#include "GGJ2023/GGJ2023GameModeBase.h"

TArray<FIntPoint> AGridObject::GetOccupyingCells_Implementation()
{
	return {-1, -1};
}

void AGridObject::AddToGrid()
{
	AGGJ2023GameModeBase::GetGridInstance(this)->AddGridObject(this);
}

void AGridObject::RemoveFromGrid()
{
}

void AGridObject::BeginPlay()
{
	Super::BeginPlay();

}

void AGridObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
