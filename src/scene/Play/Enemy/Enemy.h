#pragma once
#include "DxLib.h"

class c_Enemy
{
public:
	c_Enemy();
	~c_Enemy();

	void Init();
	void Step();
	void Draw();
	void Exit();

private:
	VECTOR m_v_CPos;	// ���݂̍��W
	VECTOR m_v_NPos;	// ���̍��W
	VECTOR m_vPower;	// �p���[�ۑ��p << �ˏo����x�N�g��
};