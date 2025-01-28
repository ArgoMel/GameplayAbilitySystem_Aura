// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"

#define CUSTOM_DEPTH_RED 250
#define CUSTOM_DEPTH_BLUE 251
#define CUSTOM_DEPTH_TAN 252

#define ECC_Projectile ECollisionChannel::ECC_GameTraceChannel1
#define ECC_Target ECollisionChannel::ECC_GameTraceChannel2
#define ECC_ExcludePlayers ECollisionChannel::ECC_GameTraceChannel3

namespace Aura_Socket
{
	const FName WeaponHandSocket=FName("WeaponHandSocket");
}

namespace Aura_Tag
{
	const FName Player=FName("Player");
	const FName Enemy=FName("Enemy");
}
