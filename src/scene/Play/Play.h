#pragma once
#include "DxLib.h"
#include "../../Common.h"

class c_Play
{
public:
	c_Play();
	~c_Play();

	void Init();
	void Step();
	void Draw();
	void Exit();

private:
	int StageIndex;	//ステージを保存
	bool BreakFlg;	// このフラグがtrueになると、Step処理を終了させる
};