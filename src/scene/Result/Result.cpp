#include "Result.h"

c_Result::c_Result()
{
	ResultImgHndl = -1;//������
}
c_Result::~c_Result()
{

}

void c_Result::Init()
{
	BreakFlg = false;
	ResultImgHndl = LoadGraph("");
}
void c_Result::Step()
{
	if (IsKeyPush(KEY_INPUT_RETURN)) {	//�G���^�[�L�[�ŉ�ʑJ�ڂ��鏈��
		BreakFlg = true;
	}
}
void c_Result::Draw()
{
	// << �`����@�͂��C�����܂�
}
void c_Result::Exit()
{
	DeleteGraph(ResultImgHndl);
}