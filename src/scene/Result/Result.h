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
	int ResultImgHndl;	// �^�C�g���摜�p�̃n���h�� << ���ɉf���������̂���������K�X���₵�Ă�������
	bool BreakFlg;		// ���̃t���O��true�ɂȂ�ƁAStep�������I��������
};