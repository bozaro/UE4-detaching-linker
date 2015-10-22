#ifndef __W1_H__

#define __W1_H__

#include "Engine.h"
#include "Runtime/Launch/Resources/Version.h"
#include "SlateBasics.h"
#include "ParticleDefinitions.h"
#include "SoundDefinitions.h"
#include "Net/UnrealNetwork.h"

#define COLLISION_WEAPON ECC_GameTraceChannel1
#define COLLISION_PICKUP ECC_GameTraceChannel2
#define COLLISION_PROJECTILE ECC_GameTraceChannel3
#define TRACE_WEAPON TraceTypeQuery3
static const FName InventoryLog = FName("InventoryLog");
static const FName UILog = FName("UILog");
#endif	// __W1_H__
