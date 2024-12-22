#include "pad.h"
void UpdatePad(Pad* pad){
	int ht=GetScreenHeight();
	if(IsKeyDown(pad->scheme.downB)){
		pad->Position.y+=GetFrameTime()*pad->speed;
		if(pad->Position.y+pad->Size.y/2>ht){
			pad->Position.y=ht-pad->Size.y/2;
		}
	}
	if(IsKeyDown(pad->scheme.upB))
	{
		pad->Position.y-=GetFrameTime()*pad->speed;
		if(pad->Position.y - pad->Size.y/2<0)
			pad->Position.y= pad->Size.y/2;
	}
}
void DrawPad(Pad* pad){
	DrawRectangle(
			pad->Position.x,
			pad->Position.y-(pad->Size.y/2),
			pad->Size.x,
			pad->Size.y,
			GREEN);
}
