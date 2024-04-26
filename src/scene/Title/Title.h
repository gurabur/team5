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
	int TitleImgHndl;	// �^�C�g���摜�p�̃n���h�� << ���ɉf���������̂���������K�X���₵�Ă�������
	bool BreakFlg;		// ���̃t���O��true�ɂȂ��Step�������I��������
};