// Mail.ru Games LLC

#include "W1.h"
#include "W1ResourceComponent.h"

UW1ResourceComponent::UW1ResourceComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UW1ResourceComponent::PostLoad()
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
	UE_LOG(LogTemp, Warning, TEXT("UW1ResourceComponent::PostLoad: %s"), *Hierarhy);
}
