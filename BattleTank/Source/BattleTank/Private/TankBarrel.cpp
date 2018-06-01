// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Math/UnrealMathUtility.h"

void UTankBarrel::Elevate(float Speed)
{
	auto ElevationChange = FMath::Clamp<float>(Speed, -1, 1)  * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0,0));
}



