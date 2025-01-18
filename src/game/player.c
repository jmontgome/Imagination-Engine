#include "player.h"

Player PlayerActor;

s16 Player_GetX() {
	return PlayerActor.x;
}
s16 Player_GetY() {
	return PlayerActor.y;
}

void Player_MoveUp() {
	PlayerActor.y += 1;
}
void Player_MoveDown() {
	PlayerActor.y -= 1;
}
void Player_MoveRight() {
	PlayerActor.x += 1;
}
void Player_MoveLeft() {
	PlayerActor.x -= 1;
}

void Player_Init() {
	Player build = {
		.Health = 3,
		.MaxHealth = 3,
		.x = 0,
		.y = 0
	};
}
void Player_Main() {

}