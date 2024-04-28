#include "Result.h"

c_Result::c_Result()
{
	ResultImgHndl = -1;//初期化
}
c_Result::~c_Result()
{

}

void c_Result::Init()
{
	BreakFlg = false;
	ResultImgHndl = LoadGraph("data/ResultScene/TentativeClearBG");
}
void c_Result::Step()
{
	if (IsKeyPush(KEY_INPUT_RETURN)) {	//エンターキーで画面遷移する処理
		BreakFlg = true;
	}
}
void c_Result::Draw()
{
	DrawGraph(0,0,ResultImgHndl,true); // << 描画方法はお任せします
}
void c_Result::Exit()
{
	DeleteGraph(ResultImgHndl);
}