// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlacementRule.generated.h"

UENUM(BlueprintType)
enum EPlacementRuleResult
{
	Fail UMETA(DisplayName = "Fail"),
	Passed UMETA(DisplayName = "Passed"),
	Perfect UMETA(DisplayName = "Perfect"),
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GGJ2023_API UPlacementRule : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	EPlacementRuleResult CanBePlaced(AActor* OwningActor);
};
