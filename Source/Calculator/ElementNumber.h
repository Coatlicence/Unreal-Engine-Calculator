// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Element.h"
#include "ElementNumber.generated.h"

/**
 * 
 */
UCLASS()
class CALCULATOR_API AElementNumber: public AElement
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "Main property")
	FString Number;

public:
	AElementNumber();

	virtual void React() override;
};
