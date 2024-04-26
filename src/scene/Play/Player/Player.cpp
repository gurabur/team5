#include "Player.h"

c_Player::c_Player()
{
	v_CMouseBuf = VGet(0.0f, 0.0f, 0.0f);
	v_NMouseBuf = VGet(0.0f, 0.0f, 0.0f);
	m_v_CPos = VGet(0.0f, 0.0f, 0.0f);
	m_v_NPos = VGet(0.0f, 0.0f, 0.0f);
	m_vPower = VGet(0.0f, 0.0f, 0.0f);
	m_f_SizePow = 0.0f;//�p���[�̑傫��
	m_f_RadPow = 0.0f;	//�p���[�̊p�x

	PlayerImgHndl = -1;
	ArrowImgHndl = -1;

	MouseButton = 0;	//�}�E�X�̑��삳�ꂽ�{�^����ۑ�
	MousePosX = 0;
	MousePosY = 0;
	Mouse_CLog = 1;	//�{�^���������ꂽ�������ꂽ���̏���ۑ�����current
	Mouse_NLog = 1;	//�{�^���������ꂽ�������ꂽ���̏���ۑ�����next
}
c_Player::~c_Player()
{

}

void c_Player::Init()
{
	m_v_CPos = DEFAULT_PLAYER_POS;
	m_v_NPos = DEFAULT_PLAYER_POS;
	PlayerImgHndl = LoadGraph("data/PlayScene/Player/tekitou.png");
	ArrowImgHndl = LoadGraph("data/PlayScene/arrow.png");
}
void c_Player::Step()
{
	if (GetMouseInputLog2(&MouseButton, &MousePosX, &MousePosY, &Mouse_NLog,true) == 0) {
		if (Mouse_NLog == MOUSE_INPUT_LOG_DOWN,Mouse_CLog == MOUSE_INPUT_LOG_UP)
		{
			v_CMouseBuf.x = (float)MousePosX;
			v_CMouseBuf.y = (float)MousePosY;
		}
		else if (Mouse_NLog == MOUSE_INPUT_LOG_UP, Mouse_CLog == MOUSE_INPUT_LOG_DOWN) {
			
		}
	}

	GetMousePoint(&MousePosX, &MousePosY);
	v_NMouseBuf.x = (float)MousePosX;
	v_NMouseBuf.y = (float)MousePosY;

	m_vPower = MyMath::VecCreate(v_CMouseBuf, v_NMouseBuf);			//�}�E�X�𓮂������n�_�ƏI�_�Ńx�N�g����
	m_f_SizePow = MyMath::VecLong(m_vPower);						//�x�N�g������傫���𒊏o
	if (m_f_SizePow >= MAX_SHOT_POWER) {
		m_f_SizePow = MAX_SHOT_POWER;								//����l�̓˔j��}��
	}
	m_vPower = MyMath::VecNormalize(m_vPower);						//�p���[�𐳋K��
	m_f_RadPow = acosf(m_vPower.x);									//�p���[�̊p�x���擾
	if (asinf(m_vPower.y) <= 0) {
		m_f_RadPow = -m_f_RadPow;
	}


	Mouse_CLog = Mouse_NLog;//current��next���X�V
}
void c_Player::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "MouseLog %d\nRadPow %f", Mouse_CLog, m_f_RadPow);
	DrawRotaGraph(m_v_CPos.x, m_v_CPos.y, 1.0, 0.0, PlayerImgHndl, true);
	DrawLine(v_CMouseBuf.x, v_CMouseBuf.y, v_NMouseBuf.x, v_NMouseBuf.y, GetColor(127, 127, 255),4);
	if (Mouse_NLog == MOUSE_INPUT_LOG_DOWN, Mouse_CLog == MOUSE_INPUT_LOG_DOWN) {
		DrawRotaGraph(m_v_CPos.x, m_v_CPos.y, 0.002 * m_f_SizePow,m_f_RadPow, ArrowImgHndl, true);
	}
}
void c_Player::Exit()
{
	if (PlayerImgHndl != -1) {
		DeleteGraph(PlayerImgHndl);
	}
	if (ArrowImgHndl != -1) {
		DeleteGraph(ArrowImgHndl);
	}
}