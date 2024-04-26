#pragma once
#include "DxLib.h"
#include "../../Common.h"

class c_Result
{
public:
	c_Result();
	~c_Result();

	void Init();
	void Step();
	void Draw();
	void Exit();

	inline bool GetBreakFlg() { return BreakFlg; }

private:
	int ResultImgHndl;	// タイトル画像用のハンドル << 他に映したいものがあったら適宜増やしてください
	bool BreakFlg;		// このフラグがtrueになると、Step処理を終了させる
};