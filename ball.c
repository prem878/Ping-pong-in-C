#include "ball.h"
void UpdateBall(Ball* ball){
	ball->Position.x+=GetFrameTime()*ball->Velocity.x;
	ball->Position.y+=GetFrameTime()*ball->Velocity.y;

}

void DrawBall(Ball* ball){
	DrawRectangle(
			ball->Position.x-5,
			ball->Position.y-5,
			10,
			10,
			WHITE);
}
bool DetectBallTouchesPad(Ball* ball, Pad* pad) {
    // Ball radius is 5 (based on your DrawBall function)
    float ballLeft = ball->Position.x - 5;
    float ballRight = ball->Position.x + 5;
    float ballTop = ball->Position.y - 5;
    float ballBottom = ball->Position.y + 5;
    
    // Pad boundaries
    float padLeft = pad->Position.x;
    float padRight = pad->Position.x + pad->Size.x;
    float padTop = pad->Position.y - (pad->Size.y / 2);
    float padBottom = pad->Position.y + (pad->Size.y / 2);
    
    return ballRight > padLeft && 
           ballLeft < padRight && 
           ballBottom > padTop && 
           ballTop < padBottom;
}
