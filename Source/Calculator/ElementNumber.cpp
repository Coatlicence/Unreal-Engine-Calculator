// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementNumber.h"
#include "Engine/Engine.h"
#include "Kismet/KismetStringLibrary.h"

#define debugMessage(x) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 20.f, FColor::Magenta, x)


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
		StringStack ex = ExerciseVisualizer->GetExercise();
		
		if (ex.begin() != ex.end())
		{
			FString element = ex[ex.Num() - 1];
			
			/// checking last symbol of exercie
			FString Fcharacter = "";

			Fcharacter = Fcharacter.AppendChar(element[element.Len() - 1]);

			TypeToCheck TypeOfCharacter = GetCharacterType(Fcharacter);
			
			/// reacting on last symbol
			switch (TypeOfCharacter)
			{
			case TypeToCheck::None:
				return;


			case TypeToCheck::Number:
				ExerciseVisualizer->ExerciseAddToEnd(Number);
				break;

			case TypeToCheck::Sign:
				ExerciseVisualizer->ExerciseAdd(Number);
				break;
			}
		}
		else
		{
			ExerciseVisualizer->ExerciseAdd(Number);
		}
	}
}
