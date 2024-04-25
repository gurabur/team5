#pragma once
#include "DxLib.h"
#include "../../../Common.h"

#define PLAYER_SIZE_X 64
#define PLAYER_SIZE_Y 64

static VECTOR DEFAULT_PLAYER_POS = { 0.0f,0.0f,0.0f };
static float MAX_SHOT_POWER = 200.0f;

class c_Player
{
public:
	c_Player();
	~c_Player();

	void Init();
	void Step();
	void Draw();
	void Exit();

private:
	VECTOR m_v_CPos;	// ���݂̍��W
	VECTOR m_v_NPos;	// ���̍��W
	VECTOR m_vPower;	// �p���[�ۑ��p << �ˏo����x�N�g��

	int PlayerImgHndl;	//�v���C���[�̉摜�n���h��
};