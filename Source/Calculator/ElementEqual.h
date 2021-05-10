// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Element.h"
#include "ElementEqual.generated.h"

/**
 * 
 */
UCLASS()
class CALCULATOR_API AElementEqual : public AElement
{
	GENERATED_BODY()
	
public:
	AElementEqual();

	virtual void React() override;
};
