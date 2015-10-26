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
	DebugHierarhy(TEXT("UW1ResourceComponent::PostLoad"), this);
}
