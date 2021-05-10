// Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciseVisualizer.h"
#include "ConstructorHelpers.h"
#include "Engine/Engine.h"

// Sets default values
AExerciseVisualizer::AExerciseVisualizer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Exercise = TArray<FString>();
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (StaticMeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(StaticMeshAsset.Object);
		StaticMesh->SetWorldScale3D(FVector(0.1f, 5.f, 2.f));
	}

	ExerciseTextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Exercise"));
	ExerciseTextComponent->AttachToComponent(StaticMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	ExerciseTextComponent->SetWorldScale3D(FVector(2.f, 2.f, 2.f));
	ExerciseTextComponent->SetWorldLocation(StaticMesh->GetComponentLocation() + FVector(10.f, 0.f, 0.f));

	//ExerciseTextComponent->SetText(AElement::GetExercise().top().c_str());

}

// Called when the game starts or when spawned
void AExerciseVisualizer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExerciseVisualizer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

	if (Exercise.end() != Exercise.begin())
		ExerciseTextComponent->SetText(Exercise[Exercise.Num() - 1]);
}

TArray<FString> AExerciseVisualizer::GetExercise()
{
	return Exercise;
}

void AExerciseVisualizer::ExerciseAdd(FString sign)
{
	//if (Exercise.end() != Exercise.begin())
	Exercise.Add(sign);
}

void AExerciseVisualizer::ExerciseAddToEnd(FString sign)
{
	if (Exercise.end() != Exercise.begin())
		Exercise[Exercise.Num() - 1].Append(sign);
	
}

void AExerciseVisualizer::ExerciseChangeLastTo(FString sign)
{
	if (Exercise.end() != Exercise.begin())
		Exercise[Exercise.Num() - 1] = sign;

}



bool Maintenance::isCharacterBelongsTo(TypeToCheck group, FString character)
{
	auto m = Map.find(group);

	if (m != Map.end())
		for (int i = 0; i < m->second.Num(); i++)
			if (character == m->second[i])
				return true;

	return false;
}

bool Maintenance::isCharacterBelongsTo(TypeToCheck group, TCHAR character)
{
	FString fcharacter = "";

	fcharacter = fcharacter.AppendChar(character);

	return isCharacterBelongsTo(group, fcharacter);
}

Maintenance::TypeToCheck Maintenance::GetCharacterType(FString character)
{
	std::map<TypeToCheck, StringStack>::const_iterator it;

	for (it = Map.cbegin(); it != Map.cend(); it++)
	{
		StringStack strstack = it->second;

			for (int i = 0; i < strstack.Num(); i++)
				if (strstack[i] == character)
					return it->first;
	}

	return TypeToCheck::None;
}

