// Fill out your copyright notice in the Description page of Project Settings.


#include "Element.h"
#include "ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "Materials/Material.h"

// Sets default values
AElement::AElement()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	if (StaticMeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(StaticMeshAsset.Object);
		StaticMesh->SetWorldScale3D(FVector(0.1f, 1.f, 1.f));		
	}
}

// Called when the game starts or when spawned
void AElement::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElement::React()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 12.f, FColor::Green, TEXT("Reacted"));
}

