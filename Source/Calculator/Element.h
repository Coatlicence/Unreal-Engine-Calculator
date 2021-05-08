// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "ExerciseVisualizer.h"
#include "Element.generated.h"

using namespace std;

UCLASS(abstract)
class CALCULATOR_API AElement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElement();

	UStaticMeshComponent* StaticMesh;

	UTextRenderComponent* AppointmentTextComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "React with")
	AExerciseVisualizer* ExerciseVisualizer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION()
	virtual void React() PURE_VIRTUAL(AElement::React, );
	
};
