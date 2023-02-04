// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticHelpers.h"

#include "Kismet/GameplayStatics.h"


AGrid* UStaticHelpers::GetGridInstance(const UObject* WorldContext)
{
	return Cast<AGrid>(UGameplayStatics::GetActorOfClass(WorldContext, AGrid::StaticClass()));
}
