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
