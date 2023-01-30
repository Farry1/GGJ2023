// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlaceableObjectData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GGJ2023_API UPlaceableObjectData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* DisplayIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> BuildableClass;
};
