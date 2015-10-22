// Mail.ru Games LLC

#include "W1.h"
#include "W1Character.h"

AW1Character::AW1Character(const FObjectInitializer& ObjectInitializer)
{
	Energy = CreateDefaultSubobject<UW1ResourceComponent>(TEXT("EnergyComponent"));
}
