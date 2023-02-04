// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGJ2023/PlacementRules/PlacementRuleConfig.h"
#include "GridObjectData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GGJ2023_API UGridObjectData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* DisplayIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* RootTypeIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> BuildableClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText RuleText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UPlacementRuleConfig>> PlacementRules;
};
