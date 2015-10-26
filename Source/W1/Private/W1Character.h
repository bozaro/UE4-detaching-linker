// Mail.ru Games LLC

#pragma once

#include "GameFramework/Character.h"
#include "W1ResourceComponent.h"
#include "W1Character.generated.h"

UCLASS()
class AW1Character : public ACharacter
{
	GENERATED_UCLASS_BODY()

	// Begin UObject interface
	virtual void PostLoad();
	// End UObject interface
public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Character)
	UW1ResourceComponent* Energy;
};
