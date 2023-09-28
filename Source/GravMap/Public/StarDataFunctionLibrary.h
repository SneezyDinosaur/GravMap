// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "StarDataFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GRAVMAP_API UStarDataFunctionLibrary : public UDataTableFunctionLibrary
{
	GENERATED_BODY()
	

public:

	void UStarDataTable()
		:Designation("")//Initialize with a fstring value
		, Distance(0.0f)//Initialize with a float value
		, Hra(0.0f)
		, Mra(0.0f)
		, Sra(0.0f)
		, Ddec(0.0f)
		, Mdec(0.0f)
		, Sdec(0.0f)
		, Mass(0.0f)
	{}

	//Name or Designation of the Star
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	FString Designation;

	//Star's distance from Sol
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	float Distance;

	//Hours (Right Ascension)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	float Hra;

	//Minutes (Right Ascension)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	float Mra;

	//Seconds (Right Ascension)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	float Sra;

	//Degrees (Declination)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	float Ddec;

	//Minutes (Declination)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	float Mdec;
	//Seconds (Declination)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	float Sdec;

	//The star's mass
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarInfo)
	float Mass;

};
