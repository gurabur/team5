#pragma once
#include "DxLib.h"
#include "../../../Common.h"

#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32
#define PLAYER_RECT 16

static VECTOR DEFAULT_PLAYER_POS = { 100.0f,400.0f,0.0f };
static VECTOR ARROW_VEC_NOAM = { 0.0f,3.14f,0.0f };//���K�����ꂽ���̏��������̃x�N�g��
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
	VECTOR v_CMouseBuf;	//�}�E�X�̍��W�o�b�t�@(�N���b�N�n�_)
	VECTOR v_NMouseBuf;	//�}�E�X�̍��W�o�b�t�@(�����[�X�n�_)
	VECTOR m_v_CPos;	// ���݂̍��W
	VECTOR m_v_NPos;	// ���̍��W
	VECTOR m_vSpeed;	// �p���[�Əd�͂���v�Z���ꂽ�ړ�����
	VECTOR m_vPower;	// �p���[�ۑ��p << �ˏo����x�N�g��
	float m_f_SizePow;	//�p���[�̑傫��
	float m_f_RadPow;	//�p���[�̊p�x

	int PlayerImgHndl;	//�v���C���[�̉摜�n���h��
	int ArrowImgHndl;	//�Ə��̉摜�n���h��

	int MouseButton;	//�}�E�X�̑��삳�ꂽ�{�^����ۑ�
	int MousePosX;
	int MousePosY;
	int Mouse_CLog;	//�{�^���������ꂽ�������ꂽ���̏���ۑ�����current
	int Mouse_NLog;	//�{�^���������ꂽ�������ꂽ���̏���ۑ�����next

	bool RandingFlg;	//�ݒu�t���O
};