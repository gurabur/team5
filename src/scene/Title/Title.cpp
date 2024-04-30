#include "Title.h"

c_Title::c_Title()
{
	TitleImgHndl = -1;//������

	//���ߓ_��
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

	if (IsKeyPush(KEY_INPUT_RETURN)) {	//�G���^�[�L�[�ŉ�ʑJ�ڂ��鏈��
		BreakFlg = true;
	}
}
void c_Title::Draw()
{
	DrawGraph(0, 0, TitleImgHndl, true);// << �`����@�͂��C�����܂�
}
void c_Title::Exit()
{
	StopSoundMem(BGMHandle);
	DeleteSoundMem(BGMHandle);
	DeleteGraph(TitleImgHndl);
}