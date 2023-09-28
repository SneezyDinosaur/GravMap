// Fill out your copyright notice in the Description page of Project Settings.


#include "StarIterator.h"
#include "Star.h"
#include "Engine/World.h"



void StarIterator()
{

}

void ReadStarDataFromFile()
{/*
    
    // Read and parse the CSV file
    


    FFileHelper::LoadANSITextFileToStrings(*path, NULL, take);
    // Loop through each line in the CSV file
    while (ReadLineFromCSV(file, line))
    {
        // Parse the CSV data
        FString Star;
        float Distance;
        int hours, minutes, degrees, decSeconds, raSeconds;
        float Mass;

        // Parse Star, Distance, Hours, Minutes, Degrees, Seconds, Mass from the line

        // Convert HMS and DMS to radians
        float rightAscensionRadians = hmsToRadians(hours, minutes, raSeconds);
        float declinationRadians = dmsToRadians(degrees, minutes, decSeconds);

        // Create a StarData object and add it to the array
        StarData NewStarData;
        NewStarData.StarName = Star;
        NewStarData.distanceFromSol = Distance;
        NewStarData.rightAscensionRadians = rightAscensionRadians;
        NewStarData.declinationRadians = declinationRadians;
        NewStarData.mass = Mass;

        StarDataArray.Add(NewStarData);
    }
    */
    /*
    
    	FString fPath = "C:\\test_data.csv";
	TArray<TArray<FString>> parsedCSV;

	if (FPaths::FileExists(fPath))
	{
		FString FileContent;
		//Read the csv file
		FFileHelper::LoadFileToString(FileContent, *fPath);
		//UE_LOG(LogTemp, Error, TEXT("%s"), *FileContent);
		
		const TCHAR* Terminators[] = { L"\r", L"\n" }; //LINE_TERMINATOR
		const TCHAR* CSVDelimeters[] = {TEXT(",")};

		TArray<FString> CSVLines;
		FileContent.ParseIntoArray(CSVLines, Terminators, 2);

		TArray<FString> temp_array;
		for (int i = 0; i < CSVLines.Num(); i++) {
			temp_array.Empty();
			CSVLines[i].ParseIntoArray(temp_array, CSVDelimeters, 1);
			parsedCSV.Add(temp_array);
		}

		//TArray<FString> GetCSVDataToString(FString fPath);
		//FCsvParser* csvfiles = new FCsvParser(FileContent); alternate method?
	}


	for (int i = 0; i < parsedCSV.Num(); i++) {
		for (int j = 0; j < parsedCSV[i].Num(); j++) {
			UE_LOG(LogTemp, Error, TEXT("%s"), *parsedCSV[i][j]);
		}
		UE_LOG(LogTemp, Error, TEXT("%s"), "\n");
	}

    // Close the file
    file.close();

    AStar* NewStar = GetWorld()->SpawnActor<AStar>(AStar::StaticClass());
    */
    

}

//Converts Equitorial Coordinates to standard Cartesian. Units: dist m, rA rad, dec rad
FVector EquitorialToCartesian(float distance, float rightAcension, float declination)
{
    float x;
    float y;
    float z;

    x = distance * FMath::Cos(rightAcension) * FMath::Cos(declination);
    y = distance * FMath::Sin(rightAcension) * FMath::Cos(declination);
    z = distance * FMath::Sin(declination);

    FVector newPosition(x, y, z);
    return newPosition;
}

double hmsToRadians(int hours, int minutes, double seconds)
{
    double degrees;
    double radians;

    degrees = (double)hours + ((double)minutes / 60) + (seconds / 3600);

        radians = FMath::DegreesToRadians(degrees);

    return radians;
}

double dmsToRadians(int degrees, int minutes, double seconds)
{
    double decimaldegrees;
    double radians;

    decimaldegrees = (double)degrees + ((double)minutes / 60) + (seconds / 3600);

    radians = FMath::DegreesToRadians(decimaldegrees);

    return radians;
}



/*
This is the outline, to plan what is to come

ReadFromFile

Interpret File Data

Ly to AU conversion

HMS -> Radians

DMS -> radians

Polar (Equitorial) (RA, Dec, d) -> xyz Converter

Scale data so that it's not the size of a galaxy

Instantiate Star Object
*/