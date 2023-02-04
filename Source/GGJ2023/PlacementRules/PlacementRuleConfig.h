// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGJ2023/Grid/Grid.h"
#include "PlacementRuleConfig.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GGJ2023_API UPlacementRuleConfig : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanBePlaced(const UObject* WorldContext, TArray<FIntPoint>& ValidTilesOut, TArray<FIntPoint>& ValidNeigbouringTiles);

protected:
	virtual UWorld* GetWorld() const override;

	UFUNCTION(BlueprintNativeEvent)
	bool GetValidTilesFromArea(UPARAM(ref) TArray<FIntPoint>& ValidTilesOut, UPARAM(ref) TArray<FIntPoint>& ValidNeighbouringTiles, AGrid* GridInstance);

	UPROPERTY()
	UWorld* TemporaryWorld;
};
