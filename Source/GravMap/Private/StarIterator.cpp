// Fill out your copyright notice in the Description page of Project Settings.


#include "StarIterator.h"

// Sets default values
AStarIterator::AStarIterator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStarIterator::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("Star Iterator Begin Play"), "\n");
	LoadCSV();
	
}

// Called every frame
void AStarIterator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStarIterator::LoadCSV()
{	
	//FPaths::ProjectContentDir() This delivers the drive path to the /GameDir/Contents folder
	FString fPath = FPaths::ProjectContentDir() + "/Misc/Stars.csv";

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, fPath);

	TArray<TArray<FString>> parsedCSV;

	if (FPaths::FileExists(fPath))
	{
		FString FileContent;

		//Read the csv file
		FFileHelper::LoadFileToString(FileContent, *fPath);
		UE_LOG(LogTemp, Error, TEXT("%s"), *FileContent);

		const TCHAR* Terminators[] = { L"\r", L"\n" }; //LINE_TERMINATOR
		const TCHAR* CSVDelimeters[] = { TEXT(",") };

		TArray<FString> CSVLines;
		FileContent.ParseIntoArray(CSVLines, Terminators, 2);

		TArray<FString> temp_array;
		for (int i = 0; i < CSVLines.Num(); i++) 
		{
			temp_array.Empty();
			CSVLines[i].ParseIntoArray(temp_array, CSVDelimeters, 1);
			parsedCSV.Add(temp_array);
		}

		//TArray<FString> GetCSVDataToString(FString fPath);
		//FCsvParser* csvfiles = new FCsvParser(FileContent); alternate method?
	}

	for (int i = 0; i < parsedCSV.Num(); i++)
	{
		for (int j = 0; j < parsedCSV[i].Num(); j++)
		{
			UE_LOG(LogTemp, Error, TEXT("%s"), *parsedCSV[i][j]);
		}
		UE_LOG(LogTemp, Error, TEXT("%s"), "\n");

		if (i > 0)
		{
			FName starName = FName(*parsedCSV[i][0]);
			float distLy = FCString::Atof(*parsedCSV[i][1]);
			float hoursRA = FCString::Atof(*parsedCSV[i][2]);
			float minRA = FCString::Atof(*parsedCSV[i][3]);
			float secRA = FCString::Atof(*parsedCSV[i][4]);
			float degDec = FCString::Atof(*parsedCSV[i][5]);
			float minDec = FCString::Atof(*parsedCSV[i][6]);
			float secDec = FCString::Atof(*parsedCSV[i][7]);
			float starMass = FCString::Atof(*parsedCSV[i][8]);
			FVector rightAscension = FVector(hoursRA, minRA, secRA);
			FVector declination = FVector(degDec, minDec, secDec);

			UE_LOG(LogTemp, Warning, TEXT("New Star! %s,Distance from Sol: %fLy Right Ascension: %fH %fM %fS, Declination %fDeg %fM %fS, Mass: %f"),  "\n", *starName.ToString(), distLy, hoursRA, minRA, secRA, degDec, minDec,secDec,starMass);


		}


		
	}
}

void SpawnStar(FName designation, FVector rightAscension, FVector declination, float distance, float starMass)
{
	FActorSpawnParameters StarSpawn;
	StarBlueprint.AStar::WriteStarInfo(designation, rightAscension, declination, distance, starMass);
	GetWorld()->SpawnActor<AStar>(newStar, FVector::ZeroVector, FRotator::ZeroRotator, &StarSpawn);
}



