#include "pp.h"
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#define INITIAL_BALL_VELOCITY (Vector2){200.0f, 200.0f}
typedef struct{
	Pad player1;
	Pad player2;
	Ball ball;
}GameData;
void Draw(GameData* data);
void Loop(GameData* data);
void Update(GameData* data);
int main(){
	int s_width=800;
	int s_height=450;
	InitWindow(s_width,s_height,"PING_PONG");
	SetTargetFPS(60);
	int ht=GetScreenHeight();
	int wd=GetScreenWidth();
	GameData data;
	Vector2 ballpos={.x=wd/2,.y=ht/2};
	Vector2 ballvec={.x=150,.y=50};
	data.ball.Position=ballpos;
	data.ball.Velocity=ballvec;
	Vector2 padSize={.x=10,.y=100};
	InputScheme player1Input={
		.upB=KEY_W,
		.downB=KEY_S};
	Vector2 player1pos={.x=(20),
		.y=(ht/2.f)};
	data.player1.Position=player1pos;
	data.player1.Size=padSize;
	data.player1.speed=220;
	data.player1.score=0;
	data.player1.scheme=player1Input;
	InputScheme player2Input={
		.upB=KEY_O,
		.downB=KEY_L
	};
	Vector2 player2pos={
	.x=(wd-20.f-padSize.x),
	.y=(ht/2.f)
	};
	data.player2.Position=player2pos;
	data.player2.Size=padSize;
	data.player2.speed=220;
	data.player2.score=0;
	data.player2.scheme=player2Input;
	Loop(&data);

	return 0;	
}
void Draw(GameData* data){
	BeginDrawing();
	ClearBackground(BLACK);
	Vector2 from ={.x=(GetScreenWidth()/2.f),.y=5};
	Vector2 to ={.x=(GetScreenWidth()/2.f),.y=(GetScreenHeight()-5.f)};
	DrawLineEx(from,to,2,RED);
	const char* scoreL=TextFormat("%d",data->player1.score);
	int scoreSizeL=MeasureText(scoreL,20);
	DrawText(
			scoreL,
			(GetScreenWidth()/2)-10-scoreSizeL,
			10,
			20,
			WHITE);
	const char* scoreR=TextFormat("%d",data->player2.score);
	DrawText(
			scoreR,
			(GetScreenWidth()/2)+10,
			10,
			20,
			WHITE);
	//OTHER CELLS
	DrawBall(&data->ball);
	DrawPad(&data->player1);
	DrawPad(&data->player2);
	EndDrawing();
}
void Update(GameData* data){
	UpdatePad(&data->player1);
	UpdatePad(&data->player2);
	UpdateBall(&data->ball);
	int ht=GetScreenHeight();
	int wd=GetScreenWidth();
	//RULES
	if (DetectBallTouchesPad(&data->ball, &data->player1) || DetectBallTouchesPad(&data->ball, &data->player2))
	{
   	 	data->ball.Velocity.x *= -1;
	}

	if (data->ball.Position.y>ht||data->ball.Position.y < 0)
	{
    	data->ball.Velocity.y *= -1;
	}

	if (data->ball.Position.x > wd)
	{
	    data->player1.score += 1;
	    Vector2 ballPosition = {.x = wd / 2, .y = ht / 2};
    	data->ball.Position = ballPosition;
   		data->ball.Velocity = INITIAL_BALL_VELOCITY;
	}

	if (data->ball.Position.x < 0)
	{
	    data->player2.score += 1;
    	Vector2 ballPosition = {.x = wd / 2, .y = ht / 2};
	    data->ball.Position = ballPosition;
    	data->ball.Velocity = INITIAL_BALL_VELOCITY;
	}
}

void Loop(GameData* data){
	while(!WindowShouldClose()){
		Update(data);
		//Draw bi***h
		Draw(data);

	}
}
