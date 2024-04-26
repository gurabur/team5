#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "Player/Player.h"

class c_Play
{
public:
	c_Play();
	~c_Play();

	void Init();
	void Step();
	void Draw();
	void Exit();

	inline bool GetBreakFlg() { return BreakFlg; }

private:
	int StageIndex;	//�X�e�[�W��ۑ�
	bool PlayerTurn;//true�Ȃ�v���C���[�̃^�[��
	c_Player cPlayer;

	bool BreakFlg;	// ���̃t���O��true�ɂȂ�ƁAStep�������I��������
};