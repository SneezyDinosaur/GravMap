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

void WriteStarData(FVector position, float mass, FString designation)
{
	//AActor::SetActorLocation(position, false);

}