// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementEqual.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "Kismet/KismetStringLibrary.h"

#define debugMessage(x) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 20.f, FColor::Magenta, x)

AElementEqual::AElementEqual()
{
	AppointmentTextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	AppointmentTextComponent->SetText(TEXT("="));
	AppointmentTextComponent->SetWorldLocation(StaticMesh->GetComponentLocation() + FVector(10.f, 0.f, 0.f));
}

void AElementEqual::React()
{
	StringStack ex = ExerciseVisualizer->GetExercise();

	if ((ex.end() != ex.begin()) && (ex.Num() >= 3))
	{
		float repeatTimes = ex.Num() / 2;

		int Counter = 0;

		while (Counter < repeatTimes)
		{
			Counter++;
			int i = 0;

			FString FirstNum, SecondNum;

			FirstNum = ex[i];
			SecondNum = (ex.Num() > (i + 2)) ? ex[i + 2] : "0";

			/// symbol(+ or -) of expression
			FString Sign = ex[i + 1];

			if ((isCharacterBelongsTo(TypeToCheck::Number, FirstNum[FirstNum.Len() - 1])) &&
				(isCharacterBelongsTo(TypeToCheck::Number, SecondNum[SecondNum.Len() - 1])) &&
				(isCharacterBelongsTo(TypeToCheck::Sign, Sign)))
			{
				int First = UKismetStringLibrary::Conv_StringToInt(FirstNum);
				int Second = UKismetStringLibrary::Conv_StringToInt(SecondNum);

				int result = SignAct.at(Sign)(First, Second);

				ExerciseVisualizer->ExerciseSetAt(i + 2, UKismetStringLibrary::Conv_IntToString(result));

				ex = ExerciseVisualizer->GetExercise();
			}
		}
	}
}