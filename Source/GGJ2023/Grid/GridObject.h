// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
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


protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
