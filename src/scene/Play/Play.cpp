#include "Play.h"

c_Play::c_Play()
{
	BackGroundHndl = -1;
}
c_Play::~c_Play()
{

}

void c_Play::Init()
{
	BreakFlg = false;
	PlayerTurn = false;
	slowcount = 100;
	cPlayer.Init();
	cEnemy.Init();
	BackGroundHndl = LoadGraph("data/PlayScene/BG/BackGround.png");
}
void c_Play::Step()
{
	cPlayer.Step(cEnemy.Getm_PosX(), cEnemy.Getm_PosY(), ENEMY_SIZE_X, ENEMY_SIZE_Y, cEnemy.GetDamageReaction());
	cEnemy.Step(cPlayer.Getm_PosX(), cPlayer.Getm_PosY(), PLAYER_SIZE_X, PLAYER_SIZE_Y, cPlayer.Getm_f_SizePow());
}
void c_Play::Draw()
{
	DrawGraph(0, 0, BackGroundHndl, true);
	cPlayer.Draw();
	cEnemy.Draw();
	if (cEnemy.GetIsUseFlg() == false)
	{
		if (slowcount > 0) {
			slowcount--;
			Sleep(30);
		}
		else {
			BreakFlg = true;
		}
	}
}
void c_Play::Exit()
{
	cPlayer.Exit();
	cEnemy.Exit();
}