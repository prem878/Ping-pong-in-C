#include "C:\raylib\raylib\src\raylib.h"

#include "pad.h"

typedef struct{
	Vector2 Position;
	Vector2 Velocity;
}Ball;

void UpdateBall(Ball* ball);
void DrawBall(Ball* ball);
bool DetectBallTouchesPad(Ball* ball,Pad* pad);
