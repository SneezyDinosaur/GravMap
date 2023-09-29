// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Star.h"
#include "Misc/Paths.h"
#include "Engine/World.h"
#include "StarIterator.generated.h"

UCLASS()
class GRAVMAP_API AStarIterator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStarIterator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void LoadCSV();

	TArray <AStar> localCluster;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stars, meta = (AllowPrivateAccess = true))
	class AStar* StarBlueprint;

};
