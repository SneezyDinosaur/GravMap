// Fill out your copyright notice in the Description page of Project Settings.


#include "Star.h"

// Sets default values
AStar::AStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStar::BeginPlay()
{
	Super::BeginPlay();

	UpdateCartesianPosition(RightAscension, Declination, DistFromSol);

	
}

// Called every frame
void AStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStar::SetStarPosition(FVector position)
{
	K2_TeleportTo(position, FRotator::ZeroRotator);

}

void AStar::WriteStarInfo(FName designation, FVector rightAscension, FVector declination, float distance, float starMass)
{
	StarName = designation;
	RightAscension = rightAscension;
	Declination = declination;
	DistFromSol = distance;
	Mass = starMass;
}


void AStar::UpdateCartesianPosition(FVector rightAscension, FVector declination, float distance)
{
	float rightAscensionRadians = RightAscensiontoRadians((float)rightAscension.X, (float)rightAscension.Y, (float)rightAscension.Z);

	float declinationRadians = DegreesMinSectoRadians((float)declination.X, (float)declination.Y, (float)declination.Z);

	cartesianPosition.X = distance * FMath::Sin(rightAscensionRadians) * FMath::Cos(declinationRadians);
	cartesianPosition.Y = distance * FMath::Sin(rightAscensionRadians) * FMath::Sin(declinationRadians);
	cartesianPosition.Z = distance * FMath::Cos(rightAscensionRadians);

	SetStarPosition(cartesianPosition);	
}


float AStar::RightAscensiontoRadians(float hour, float minute, float seconds) //These functions don't use FVectors to make them a bit easier to read.
{
	//1 hour = 15 degrees
	float stor = hour * 15;

	//Convert minutes to degrees by dividing by 60, add to stor
	stor = stor + (minute / 60);

	//Convert seconds, divide by 60 and add to stor
	stor = stor + (seconds / 60);

	//return stor as converted value in radians
	return stor;
}

float AStar::DegreesMinSectoRadians(float degrees, float minute, float seconds) //These functions don't use FVectors to make them a bit easier to read.
{
	//Convert float degrees into radians, hold ongoing calculation in stor
	float stor = FMath::DegreesToRadians(degrees);

	//Convert minutes to degrees by dividing by 60, add to stor
	stor = stor + (minute / 60);

	//Convert seconds, divide by 60 and add to stor
	stor = stor + (seconds / 60);

	//return stor as converted value in radians
	return stor;
}


