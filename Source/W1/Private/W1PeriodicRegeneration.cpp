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
	FString Hierarhy;
	const UObject *Object = this;
	while (Object != nullptr)
	{
		if (!Hierarhy.IsEmpty())
		{
			Hierarhy.Append(TEXT(" >> "));
		}
		Hierarhy.Append(Object->GetName()).Append(TEXT(" (")).Append(Object->GetClass()->GetName()).Append(TEXT(")"));
		Object = Object->GetOuter();
	}
	UE_LOG(LogTemp, Warning, TEXT("UW1PeriodicRegeneration::PostLoad: %s"), *Hierarhy);
}
