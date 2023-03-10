// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGJ2023/PlacementRules/PlacementRuleConfig.h"
#include "GridObjectData.generated.h"

UENUM(BlueprintType)
enum EGridObjectGroup
{
	Round UMETA(DisplayName = "Round"),
	Triangle UMETA(DisplayName = "Triangle"),
	Rectangle UMETA(DisplayName = "Rectangle"),
};

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
	UTexture2D* ShapeRuleIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* TreeTypeIcon1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* TreeTypeIcon2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* TreeTypeIcon3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* AdditionalRuleIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> BuildableClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText RuleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BaseScore = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<TEnumAsByte<EGridObjectGroup>, int> GroupAndCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TEnumAsByte<EGridObjectGroup>> MyGridObjectGroups;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UPlacementRuleConfig>> PlacementRules;
};
