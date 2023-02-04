// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGJ2023/Data/GridObjectData.h"
#include "GridObject.generated.h"

/**
 * 
 */
UCLASS()
class GGJ2023_API AGridObject : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<FIntPoint> GetOccupyingCells();

	UFUNCTION(BlueprintCallable)
	void AddToGrid();

	UFUNCTION(BlueprintCallable)
	void RemoveFromGrid();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanBePlaced(TArray<FIntPoint>& ValidTiles, TArray<FIntPoint>& InvalidTiles);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UGridObjectData* GridObjectData;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
