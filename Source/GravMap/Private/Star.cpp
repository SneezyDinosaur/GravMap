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

	
}

// Called every frame
void AStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStar::SetStarPosition(FVector position, float starMass, FString designation)
{
	

}

void AStar::WriteStarInfo(FString designation, float hourRightAscension, float minuteRightAscension, float secondRightAscension, float degreeDeclination, float minuteDeclination, float secondsDeclination, float distance, float starMass)
{
	StarName = designation;
	Hra = hourRightAscension;
	Mra = minuteRightAscension;
	Sra = secondRightAscension;
	Ddec = degreeDeclination;
	Mdec = minuteDeclination;
	Sdec = secondsDeclination;

}


FVector AStar::UpdateCartesianPosition(float hourRightAscension, float minuteRightAscension, float secondRightAscension, float degreeDeclination, float minuteDeclination, float secondsDeclination, float distance)
{



}


float AStar::RightAscensiontoRadians(float hour, float minute, float seconds)
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

float AStar::DegreesMinSectoRadians(float degrees, float minute, float seconds)
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


