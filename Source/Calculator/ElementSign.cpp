// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementSign.h"

AElementSign::AElementSign()
{
	Number = "+";

	StaticMesh->SetWorldScale3D(FVector(0.1f, 1.f, 1.f));

	AppointmentTextComponent->SetText(Number);
	AppointmentTextComponent->SetWorldLocation(StaticMesh->GetComponentLocation() + FVector(10.f, 0.f, 0.f));
}

void AElementSign::React()
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
				ExerciseVisualizer->ExerciseAdd(Number);
				break;

			case TypeToCheck::Sign:
				ExerciseVisualizer->ExerciseChangeLastTo(Number);
				break;
			}
		}
	}
}
