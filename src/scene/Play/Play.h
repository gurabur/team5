#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"

#define STAGE_MAX_NUM 3

class c_Play
{
public:
	c_Play();
	~c_Play();

	void Init();
	void Step();
	void Draw();
	void Exit();

	inline bool GetBreakFlg() { return BreakFlg; }

private:
	int StageIndex;	//現在のステージを保存
	int PlayerTurn;//プレイヤーのターン
	c_Player cPlayer;
	c_Enemy cEnemy;

	bool BreakFlg;	// このフラグがtrueになると、Step処理を終了させる
};