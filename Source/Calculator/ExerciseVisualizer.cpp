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
}

TArray<FString> AExerciseVisualizer::GetExercise()
{
	return Exercise;
}

void AExerciseVisualizer::AddExercise(FString sigh)
{
	
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
