// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameState_Base.h"
#include "GameState_Default.generated.h"

/**
 * 
 */
UCLASS()
class GGJ2023_API UGameState_Default : public UGameState_Base
{
	GENERATED_BODY()

public:
	virtual void EnterState() override;
	virtual void ExitState() override;
};
