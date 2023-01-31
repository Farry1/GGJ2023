// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "ProgressionTierData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GGJ2023_API UProgressionTierData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 PointsNeeded;
};
