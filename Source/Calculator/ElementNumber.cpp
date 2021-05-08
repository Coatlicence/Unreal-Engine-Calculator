// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementNumber.h"
#include "Engine/Engine.h"
#include "Kismet/KismetStringLibrary.h"


AElementNumber::AElementNumber()
{
	Number = "0";

	StaticMesh->SetWorldScale3D(FVector(0.1f, 1.f, 1.f));

	AppointmentTextComponent->SetText(Number);
	AppointmentTextComponent->SetWorldLocation(StaticMesh->GetComponentLocation() + FVector(10.f, 0.f, 0.f));
}

void AElementNumber::React()
{
	if (ExerciseVisualizer != nullptr)
	{
		auto ex = ExerciseVisualizer->GetExercise();

		//if 
	}
}
