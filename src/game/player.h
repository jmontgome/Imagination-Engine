#ifndef PLAYER_H
#define PLAYER_H

#include "././internal/types.h"

typedef struct Player {
	u8 Health;
	u8 MaxHealth;

	s16 x;
	s16 y;
} Player;

s16 Player_GetX();
s16 Player_GetY();

void Player_MoveUp();
void Player_MoveDown();
void Player_MoveRight();
void Player_MoveLeft();

void Player_Init();
void Player_Main();

#endif