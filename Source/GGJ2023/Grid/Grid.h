// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grid.generated.h"
class AGridObject;
/**
 * 
 */

const float GLOBAL_GRID_SCALE = 50.0f;

USTRUCT(BlueprintType)
struct GGJ2023_API FGridCell
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FIntPoint Position;

	UPROPERTY()
	TArray<AGridObject*> GridObjects;
};

UCLASS(BlueprintType, Blueprintable)
class GGJ2023_API AGrid : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
	FIntPoint GetGridPosition(FVector WorldPosition);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
	FVector GetWorldPosition(FIntPoint GridCoordinates);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<AGridObject*> GetGridActorsAt(FIntPoint GridCoordinates);

	UFUNCTION(BlueprintCallable)
	void AddGridObject(AGridObject* GridObject);

	UFUNCTION(BlueprintCallable)
	void RemoveGridObject(AGridObject* GridObject);

protected:
	TMap<FIntPoint, FGridCell> Cells;

	int Width = 100;
	int Height = 100;

	bool IsValidIndex(FIntPoint GridCoordinates);

	virtual void BeginPlay() override;
};
