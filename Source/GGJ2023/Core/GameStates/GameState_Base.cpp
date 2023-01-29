// Fill out your copyright notice in the Description page of Project Settings.


#include "GameState_Base.h"

void UGameState_Base::EnterState()
{
	EnterStateEvent();
}

void UGameState_Base::ExitState()
{
	ExitStateEvent();
}

void UGameState_Base::Tick(float DeltaTime)
{
	TickStateEvent(DeltaTime);
}

void UGameState_Base::PrimaryAction()
{
	OnPrimaryAction();
}

void UGameState_Base::SecondaryAction()
{
	OnSecondaryAction();
}

void UGameState_Base::Cancel()
{
	OnCancel();
}

UWorld* UGameState_Base::GetWorld() const
{
	if (!HasAnyFlags(RF_ClassDefaultObject) && !GetOuter()->HasAnyFlags(RF_BeginDestroyed) && !GetOuter()->
		IsUnreachable())
	{
		AActor* Outer = GetTypedOuter<AActor>();
		if (Outer != nullptr)
		{
			return Outer->GetWorld();
		}
	}
	return nullptr;
}
