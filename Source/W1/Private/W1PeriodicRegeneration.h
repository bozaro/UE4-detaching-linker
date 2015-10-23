#pragma once

#include "Object.h"
#include "W1PeriodicRegeneration.generated.h"

UCLASS(Within = W1ResourceComponent, DefaultToInstanced, editinlinenew)
class UW1PeriodicRegeneration : public UObject
{
	GENERATED_BODY()

	UW1PeriodicRegeneration(const FObjectInitializer& ObjectInitializer);
};
