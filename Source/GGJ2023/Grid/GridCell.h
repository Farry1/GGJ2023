// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridObject.h"
#include "UObject/Object.h"
#include "GridCell.generated.h"

/**
 * 
 */
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
