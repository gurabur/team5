#include "Title.h"

c_Title::c_Title()
{
	TitleImgHndl = -1;//初期化
}
c_Title::~c_Title()
{

}

void c_Title::Init()
{
	BreakFlg = false;
	TitleImgHndl = LoadGraph("");
}
void c_Title::Step()
{
	if (IsKeyPush(KEY_INPUT_RETURN)) {	//エンターキーで画面遷移する処理
		BreakFlg = true;
	}
}
void c_Title::Draw()
{
	// << 描画方法はお任せします
}
void c_Title::Exit()
{
	DeleteGraph(TitleImgHndl);
}