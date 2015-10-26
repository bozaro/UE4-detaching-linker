#include "W1.h"
#include "W1PeriodicRegeneration.h"
#include "W1ResourceComponent.h"
 

UW1PeriodicRegeneration::UW1PeriodicRegeneration(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UW1PeriodicRegeneration::PostLoad()
{
	Super::PostLoad();
	DebugHierarhy(TEXT("UW1PeriodicRegeneration::PostLoad"), this);
}
