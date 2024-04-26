#pragma once
#include "DxLib.h"
#include "../../Common.h"

class c_Title
{
public:
	c_Title();
	~c_Title();

	void Init();
	void Step();
	void Draw();
	void Exit();

	inline bool GetBreakFlg() { return BreakFlg; }

private:
	int TitleImgHndl;	// タイトル画像用のハンドル << 他に映したいものがあったら適宜増やしてください
	bool BreakFlg;		// このフラグがtrueになるとStep処理を終了させる
};