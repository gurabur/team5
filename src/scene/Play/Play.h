#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"

#define STAGE_MAX_NUM 3

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
	int StageIndex;	//���݂̃X�e�[�W��ۑ�
	int PlayerTurn;//�v���C���[�̃^�[��
	c_Player cPlayer;
	c_Enemy cEnemy;

	bool BreakFlg;	// ���̃t���O��true�ɂȂ�ƁAStep�������I��������
};