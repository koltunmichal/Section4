// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Math/UnrealMathUtility.h"

void UTankTurret::Rotate(float Speed)
{
	auto RotationChange = FMath::Clamp<float>(Speed, -1, 1)  * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation= RelativeRotation.Yaw + RotationChange;
	//auto Rotation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}


