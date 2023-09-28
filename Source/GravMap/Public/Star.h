// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Star.generated.h"

UCLASS()
class GRAVMAP_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStar();

	void WriteStarData(FVector position, float mass, FString designation);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	FString StarName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Star Information")
	float mass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
