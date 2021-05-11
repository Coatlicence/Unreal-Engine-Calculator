// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include <map>
#include <functional>
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

	///----------------------------------------
	// Getters

	/// return copy of Exercise
	StringStack GetExercise();

	/// (Exercise.end() != Exercise.begin())
	inline bool GetExerciseInitialized();

	///---------------------------
	// Setters


	/// <summary>Adds new element with given sign</summary>
	/// <param name="sign to add"></param>
	void ExerciseAdd(FString sign);

	/// <summary>Adds sign to last element</summary>
	/// <param name="sign to add"></param>
	void ExerciseAddToEnd(FString sign);

	/// Changes last element to sign
	void ExerciseChangeLastTo(FString sign);

	/// <param name="INDEX">Element to change</param>
	/// <param name="sign">sign to set</param>
	void ExerciseSetAt(int INDEX, FString sign);

	/// <summary>Removes element by index
	/// it will also remove the next or previous element by ForwardRemove.
	/// Would revert ForwardRemove, if it will goes out of expression</summary>
	/// <param name="INDEX"></param>
	/// <param name="ForwardRemove default is true"></param>
	void ExerciseRemoveAt(int INDEX, bool ForwardRemove = true);
};


namespace Maintenance
{
	const std::map<FString, std::function<int(int, int)>> SignAct =
	{
		std::make_pair("+", [=](int a, int b) { return a + b; }),
		std::make_pair("-", [=](int a, int b) { return a - b; }),
	};

	const enum class TypeToCheck
	{
		None,
		Sign,
		Number
	};

	bool isCharacterBelongsTo(TypeToCheck group, FString character);

	bool isCharacterBelongsTo(TypeToCheck group, TCHAR character);

	TypeToCheck GetCharacterType(FString character);

	TypeToCheck GetCharacterType(TCHAR character);

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

