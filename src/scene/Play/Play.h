#pragma once
#include "DxLib.h"
#include "../../Common.h"

class c_Play
{
public:
	c_Play();
	~c_Play();

	void Init();
	void Step();
	void Draw();
	void Exit();

private:
	int StageIndex;	//�X�e�[�W��ۑ�
	bool BreakFlg;	// ���̃t���O��true�ɂȂ�ƁAStep�������I��������
};