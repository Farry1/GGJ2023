// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GGJ2023/Grid/Grid.h"
#include "UObject/Object.h"
#include "StaticHelpers.generated.h"

/**
 * 
 */
UCLASS()
class GGJ2023_API UStaticHelpers : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static AGrid* GetGridInstance(const UObject* WorldContext);
};
