// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include <map>
#include "ExerciseVisualizer.generated.h"

typedef TArray<FString> StringStack;

UCLASS()
class CALCULATOR_API AExerciseVisualizer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExerciseVisualizer();

	UPROPERTY()
	UStaticMeshComponent* StaticMesh;

	UPROPERTY()
	UTextRenderComponent* ExerciseTextComponent;

private:
	/// this var has the next structure
	/// [["11"], ["+"], ["150"], ["-"], ["2"]] 
	StringStack Exercise;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	StringStack GetExercise();

	void AddExercise(FString sigh);
};


namespace Maintenance
{
	const enum class TypeToCheck
	{
		Sign,
		Number
	};

	bool isCharacterBelongsTo(TypeToCheck group, FString character);

	namespace
	{ 
		StringStack Sign =
		{
			"+",
			"-"
		};

		StringStack Number =
		{
			"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
		};

		const std::map<TypeToCheck, StringStack> Map =
		{
			std::make_pair(TypeToCheck::Sign, Sign),
			std::make_pair(TypeToCheck::Number, Number)
		};
	}
}