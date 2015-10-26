#include "W1.h"

class FW1Module : public FDefaultGameModuleImpl
{
};

IMPLEMENT_PRIMARY_GAME_MODULE(FW1Module, W1, "W1");

void DebugHierarhy(const FString &Prefix, const UObject *Object)
{
	FString Hierarhy;
	while (Object != nullptr)
	{
		if (!Hierarhy.IsEmpty())
		{
			Hierarhy.Append(TEXT(" >> "));
		}
		Hierarhy
			.Append(FString::Printf(TEXT("[%p]"), Object))
			.Append(TEXT(" "))
			.Append(Object->GetName())
			.Append(TEXT(" ("))
			.Append(Object->GetClass()->GetName())
			.Append(TEXT(")"));
		Object = Object->GetOuter();
	}
	UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *Prefix, *Hierarhy);
}