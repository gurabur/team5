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
	cEnemy.Init();
}
void c_Play::Step()
{
	cPlayer.Step(cEnemy.Getm_PosX(), cEnemy.Getm_PosY(), ENEMY_SIZE_X, ENEMY_SIZE_Y, cEnemy.GetDamageReaction());
	cEnemy.Step(cPlayer.Getm_PosX(), cPlayer.Getm_PosY(), PLAYER_SIZE_X, PLAYER_SIZE_Y, cPlayer.Getm_f_SizePow());
}
void c_Play::Draw()
{
	cPlayer.Draw();
	cEnemy.Draw();
}
void c_Play::Exit()
{
	cPlayer.Exit();
	cEnemy.Exit();
}