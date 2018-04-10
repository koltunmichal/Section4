// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();
	if (ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Posses %s"), *(ControlledTank->GetName()));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("No TANK"))
	}
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("Vector %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector LookDirection;

	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Vector %s"), *LookDirection.ToString());
	}

	
	HitLocation = FVector(1.0);
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector CameraWorldLocation;
	return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection));
}