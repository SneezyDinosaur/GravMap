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

	void SetStarPosition(FVector position, float mass, FString designation);

	void WriteStarInfo(FString designation, float hourRightAscension, float minuteRightAscension, float secondRightAscension, float degreeDeclination, float minuteDeclination, float secondsDeclination, float distance, float starMass);

	FVector UpdateCartesianPosition(float hourRightAscension, float minuteRightAscension, float secondRightAscension, float degreeDeclination, float minuteDeclination, float secondsDeclination, float distance);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float RightAscensiontoRadians(float hour, float minute, float seconds);

	float DegreesMinSectoRadians(float degrees, float minute, float seconds);

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	FString StarName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float Hra;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float Mra;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float Sra;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float Ddec;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float Mdec;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float Sdec;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float mass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float distFromSol;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float scaleFactor;
};
