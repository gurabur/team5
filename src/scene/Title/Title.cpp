#include "Title.h"

c_Title::c_Title()
{
	TitleImgHndl = -1;//������
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
	if (IsKeyPush(KEY_INPUT_RETURN)) {	//�G���^�[�L�[�ŉ�ʑJ�ڂ��鏈��
		BreakFlg = true;
	}
}
void c_Title::Draw()
{
	// << �`����@�͂��C�����܂�
}
void c_Title::Exit()
{
	DeleteGraph(TitleImgHndl);
}