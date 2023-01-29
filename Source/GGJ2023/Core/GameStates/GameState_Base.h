// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameState_Base.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GGJ2023_API UGameState_Base : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void EnterState();

	UFUNCTION(BlueprintCallable)
	virtual void ExitState();

	UFUNCTION(BlueprintCallable)
	virtual void Tick(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void PrimaryAction();

	UFUNCTION(BlueprintCallable)
	void SecondaryAction();

	UFUNCTION(BlueprintCallable)
	void Cancel();


protected:
	UPROPERTY(BlueprintReadOnly, meta=(ExposeOnSpawn))
	APlayerController* PlayerController = nullptr;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrimaryAction();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSecondaryAction();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCancel();

	UFUNCTION(BlueprintImplementableEvent)
	void EnterStateEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void ExitStateEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void TickStateEvent(float DeltaTime);
};
