#ifndef PAD_H
#define PAD_H
#include "C:\raylib\raylib\src\raylib.h"
typedef struct{
	int upB;
	int downB;
} InputScheme;

typedef struct{
	InputScheme scheme;
	int score;
	float speed;
	Vector2 Position;
	Vector2 Size;
} Pad;
void UpdatePad(Pad* pad);
void DrawPad(Pad* pad);
#endif
