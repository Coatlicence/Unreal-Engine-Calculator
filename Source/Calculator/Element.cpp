// Fill out your copyright notice in the Description page of Project Settings.


#include "Element.h"
#include "ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "Materials/Material.h"

// Sets default values
AElement::AElement()
{
	PrimaryActorTick.bCanEverTick = false;
	
	ExerciseVisualizer = nullptr;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (StaticMeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(StaticMeshAsset.Object);
		StaticMesh->SetWorldScale3D(FVector(0.1f, 1.f, 1.f));		
	}

	AppointmentTextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Appointment"));
	AppointmentTextComponent->AttachTo(StaticMesh);
	AppointmentTextComponent->SetWorldScale3D(FVector(2.f, 2.f, 2.f));
	AppointmentTextComponent->SetText(TEXT("A"));
	
}

// Called when the game starts or when spawned
void AElement::BeginPlay()
{
	Super::BeginPlay();	
}
