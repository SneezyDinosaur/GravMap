// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "StarDataTable.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FStarDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()


public:
	
	FStarDataTable()
		:Designation("")//Initialize with a fstring value
		,Distance(0.0f)//Initialize with a float value
		,Hra(0.0f)
		,Mra(0.0f)
		,Sra(0.0f)
		,Ddec(0.0f)
		,Mdec(0.0f)
		,Sdec(0.0f)
		,Mass(0.0f)
		{}
		
		//Name or Designation of the Star
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		FString Designation;

		//Star's distance from Sol
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		float Distance;

		//Hours (Right Ascension)
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		float Hra;

		//Minutes (Right Ascension)
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		float Mra;

		//Seconds (Right Ascension)
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		float Sra;

		//Degrees (Declination)
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		float Ddec;

		//Minutes (Declination)
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		float Mdec;
		//Seconds (Declination)
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		float Sdec;
		
		//The star's mass
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		float Mass;

};
