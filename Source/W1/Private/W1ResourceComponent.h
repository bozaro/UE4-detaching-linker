// Mail.ru Games LLC

#pragma once

#include "Components/ActorComponent.h"
#include "W1PeriodicRegeneration.h"
#include "W1ResourceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FResourceChangedSugnature, float, NewValue);

UCLASS()
class UW1ResourceComponent : public UActorComponent
{
	GENERATED_UCLASS_BODY()

	// Begin UObject interface
	virtual void PostLoad();
	// End UObject interface
public:
	UPROPERTY(EditDefaultsOnly, Instanced, Category = "Resource")
	UW1PeriodicRegeneration* Regeneration;
};
