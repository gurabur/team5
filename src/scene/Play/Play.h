#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "Player/Player.h"

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
	int StageIndex;	//ステージを保存
	bool PlayerTurn;//trueならプレイヤーのターン
	c_Player cPlayer;

	bool BreakFlg;	// このフラグがtrueになると、Step処理を終了させる
};