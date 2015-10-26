// Mail.ru Games LLC

#include "W1.h"
#include "W1Character.h"

AW1Character::AW1Character(const FObjectInitializer& ObjectInitializer)
{
	Energy = CreateDefaultSubobject<UW1ResourceComponent>(TEXT("EnergyComponent"));
}

void AW1Character::PostLoad()
{
	Super::PostLoad();
	DebugHierarhy(TEXT("AW1Character::PostLoad"), this);
	UE_LOG(LogTemp, Warning, TEXT("AW1Character::PostLoad: Energy = %p"), Energy);
}
