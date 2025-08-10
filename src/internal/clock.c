#include "././internal/types.h"

u128 TickTime;

u128 Clock_GetTick() {
	return TickTime;
}

void Clock_Main() {
	TickTime++;
}