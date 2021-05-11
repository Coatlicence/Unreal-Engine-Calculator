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
	ExerciseTextComponent->SetWorldLocation(StaticMesh->GetComponentLocation() + FVector(10.f, 200.f, 0.f));	
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

	if (GetExerciseInitialized())
	{
		FString ex = "";

		for (int i = 0; i < Exercise.Num(); i++)
		{
			ex = ex.Append(Exercise[i]);
			ex = ex.Append(" ");
		}

		ExerciseTextComponent->SetText(ex);
	}
}



TArray<FString> AExerciseVisualizer::GetExercise()
{
	return Exercise;
}



bool AExerciseVisualizer::GetExerciseInitialized()
{
	return (Exercise.end() != Exercise.begin());
}



void AExerciseVisualizer::ExerciseAdd(FString sign)
{
	bool NoInit = !GetExerciseInitialized();

	bool characterIsSign = Maintenance::isCharacterBelongsTo(Maintenance::TypeToCheck::Sign, sign);

	if ((NoInit) && (characterIsSign))
		return;

	Exercise.Add(sign);
}



void AExerciseVisualizer::ExerciseAddToEnd(FString sign)
{
	if (GetExerciseInitialized())
	{
		Exercise[Exercise.Num() - 1].Append(sign);
	}
}



void AExerciseVisualizer::ExerciseChangeLastTo(FString sign)
{
	if (GetExerciseInitialized())
		Exercise[Exercise.Num() - 1] = sign;

}



void AExerciseVisualizer::ExerciseSetAt(int INDEX, FString sign)
{
	if (((INDEX >= 0) && (INDEX < Exercise.Num())) && (GetExerciseInitialized()))
	{
		TCHAR character = Exercise[INDEX][Exercise[INDEX].Len() - 1];

		if (Maintenance::GetCharacterType(character) == Maintenance::GetCharacterType(sign[sign.Len() - 1]))
		{
			Exercise[INDEX] = sign;
			
			ExerciseRemoveAt(INDEX - 1, false);
		}
	}
}

void AExerciseVisualizer::ExerciseRemoveAt(int INDEX, bool ForwardRemove)
{
	int INDEXoffset = ForwardRemove ? (1) : (-1);

	if ((INDEX + INDEXoffset) < 0)
		INDEXoffset = 1;
		
	if ((INDEX + INDEXoffset) > Exercise.Num())
		INDEXoffset = -1;

	Exercise.RemoveAt(INDEX);
	Exercise.RemoveAt(INDEX + INDEXoffset);
}

/// Maintenance namespace

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



Maintenance::TypeToCheck Maintenance::GetCharacterType(TCHAR character)
{
	FString fcharacter = "";
	fcharacter = fcharacter.AppendChar(character);

	return GetCharacterType(fcharacter);
}

