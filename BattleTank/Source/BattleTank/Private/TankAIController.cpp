// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("player Possessss %s"), *(PlayerTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No TANK"));
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
	//jjgh
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);	
}


