#include "Title.h"

c_Title::c_Title()
{
	TitleImgHndl = -1;//初期化

	//透過点滅
	fade = 0;
}
c_Title::~c_Title()
{

}

void c_Title::Init()
{
	BreakFlg = false;
	TitleImgHndl = LoadGraph("data/TitleScene/Title.png");

	BGMHandle = LoadSoundMem("data/BGM/TitleBGM.mp3");

	PlaySoundMem(BGMHandle, DX_PLAYTYPE_LOOP, true);
}
void c_Title::Step()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	fade++;

	if (IsKeyPush(KEY_INPUT_RETURN)) {	//エンターキーで画面遷移する処理
		BreakFlg = true;
	}
}
void c_Title::Draw()
{
	DrawGraph(0, 0, TitleImgHndl, true);// << 描画方法はお任せします
}
void c_Title::Exit()
{
	StopSoundMem(BGMHandle);
	DeleteSoundMem(BGMHandle);
	DeleteGraph(TitleImgHndl);
}