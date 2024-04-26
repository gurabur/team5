#include "Play.h"

c_Play::c_Play()
{

}
c_Play::~c_Play()
{

}

void c_Play::Init()
{
	BreakFlg = false;
	PlayerTurn = false;
	cPlayer.Init();
}
void c_Play::Step()
{
	cPlayer.Step();
}
void c_Play::Draw()
{
	cPlayer.Draw();
}
void c_Play::Exit()
{
	cPlayer.Exit();
}