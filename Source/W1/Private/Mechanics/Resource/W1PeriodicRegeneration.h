#pragma once

#include "Object.h"
#include "W1ResourceRegeneration.h"
#include "W1PeriodicRegeneration.generated.h"

UCLASS()
class UW1PeriodicRegeneration : public UW1ResourceRegeneration
{
	GENERATED_BODY()

	UW1PeriodicRegeneration(const FObjectInitializer& ObjectInitializer);

	FTimerHandle RegenTimerHandle;
	
	UPROPERTY(EditDefaultsOnly, Category = "Resource", meta = (ClampMin = "0.0"))
	float TickLength;

	UPROPERTY(EditDefaultsOnly, Category = "Resource", meta = (ClampMin = "0.0"))
	float RegenPerSecond;
};
