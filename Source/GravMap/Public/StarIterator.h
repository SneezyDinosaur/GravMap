// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tasks/GameplayTask_SpawnActor.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"
#include "StarIterator.generated.h"




/**
 * 
 */
UCLASS()
class GRAVMAP_API UStarIterator : public UGameplayTask_SpawnActor
{
	GENERATED_BODY()

public:

protected:

	//Function to handle parsing CSV file
	void ReadStarDataFromFile();

	//returns a double that is a conversion from HMS Right ascension to radians
	double EquitorialToCartesian(int hours, int minutes, double seconds);

	//Variable to which simulation will be scaled, used in compbination with Star struct distanceFromSol && mass
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Unknown, meta = (AllowPrivateAccess = true))
	float scaleFactor;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Unknown, meta = (AllowPrivateAccess = true))
	class AActor* Star;




private:
	
};
