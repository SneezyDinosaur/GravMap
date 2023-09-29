// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Star.generated.h"

UCLASS()
class GRAVMAP_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStar();

	void SetStarPosition(FVector position);

	void WriteStarInfo(FName designation, FVector rightAscension, FVector declination, float distance, float starMass);

	void UpdateCartesianPosition(FVector rightAscension, FVector declination, float distance);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float RightAscensiontoRadians(float hour, float minute, float seconds);

	float DegreesMinSectoRadians(float degrees, float minute, float seconds);

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**Name of the star using FName  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	FName StarName;

	/** Star Location Right Ascension where Hours(X), Minutes(Y), Seconds(Z)*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	FVector RightAscension;

	/** Star Location Declination- where Degrees(X), Minutes(Y), Seconds(Z)*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	FVector Declination;

	/** Star Mass in Solar Masses*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float Mass;

	/*Star Distance from Sol, in Lightyears*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float DistFromSol;

	/*Scale factor to determine scaled down distance, mass, etc. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float ScaleFactor; // It may not be a bad idea to use a long or long long since the scale from lightyears to 1 meter is gonna be wack as fuck

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	FVector cartesianPosition;
};
