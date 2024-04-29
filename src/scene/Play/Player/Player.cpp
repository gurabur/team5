#include "Player.h"

c_Player::c_Player()
{
	v_CMouseBuf = VGet(0.0f, 0.0f, 0.0f);
	v_NMouseBuf = VGet(0.0f, 0.0f, 0.0f);
	m_v_CPos = VGet(0.0f, 0.0f, 0.0f);
	m_v_NPos = VGet(0.0f, 0.0f, 0.0f);
	m_vSpeed = VGet(0.0f, 0.0f, 0.0f);
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

	RandingFlg = false;
}
c_Player::~c_Player()
{

}

void c_Player::Init()
{
	m_v_CPos = DEFAULT_PLAYER_POS;
	m_v_NPos = DEFAULT_PLAYER_POS;
	PlayerImgHndl = LoadGraph("data/PlayScene/Player/tekitou.png");
	ArrowImgHndl = LoadGraph("data/PlayScene/_arrow.png");
}
void c_Player::Step(float x, float y, float w, float h, bool hit)
{
	// �}�E�X�֘A--------------------------------------

	if (GetMouseInputLog2(&MouseButton, &MousePosX, &MousePosY, &Mouse_NLog,true) == 0) {
		if (Mouse_NLog == MOUSE_INPUT_LOG_DOWN,Mouse_CLog == MOUSE_INPUT_LOG_UP) {			//�N���b�N�����u�Ԃ̍��W��ۑ�
			v_CMouseBuf.x = (float)MousePosX;
			v_CMouseBuf.y = (float)MousePosY;
		}
		else if (Mouse_NLog == MOUSE_INPUT_LOG_UP, Mouse_CLog == MOUSE_INPUT_LOG_DOWN) {	//�����[�X�����u�ԃv���C���[�̈ړ����������߂�
			m_vSpeed = MyMath::VecScale(m_vPower, m_f_SizePow/10);	//���K�����ꂽ�p���[�x�N�g���ɁA�C�����ꂽ�p���[�X�J���[����Z
			m_vSpeed = VGet(-m_vSpeed.x, -m_vSpeed.y, 0.0f);	//�p���[�x�N�g���̓N���b�N�n�_���烊���[�X�n�_�̃x�N�g���Ȃ̂ŁA������m_vSpeed�𔽓]�����邱�ƂŃX�����O�V���b�g����������
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
	m_vPower = MyMath::VecNormalize(m_vPower);						//�p���[�𐳋K�� << m_vPower�͍ŏI�I�ɂ����ɋA������
	m_f_RadPow = acosf(m_vPower.x);									//�p���[�̊p�x���擾
	if (asinf(m_vPower.y) <= 0) {
		m_f_RadPow = -m_f_RadPow;
	}
	if (Mouse_NLog == MOUSE_INPUT_LOG_DOWN, Mouse_CLog == MOUSE_INPUT_LOG_DOWN) { Sleep(20); }
	//-------------------------------------------------


	// PL�̈ړ��֘A------------------------------------
	if (hit == true && m_v_NPos.x + PLAYER_SIZE_X > x)
	{
		m_v_NPos.x = x - PLAYER_SIZE_X;
		Turnm_SpeedX();
	}
	//	Y���֘A�̌v�Z
	RandingFlg = false;	//��U�ڒn�t���O��false�ɂ���

	m_v_NPos.y += m_vSpeed.y;	//Y���W���v�Z

	if (m_v_NPos.y + PLAYER_RECT >= FIELD_HEIGHT){	//�ڒn������Ƃ�
		RandingFlg = true;
		m_vSpeed = VGet(0.0f, 0.0f, 0.0f);
		m_v_NPos.y = FIELD_HEIGHT - PLAYER_RECT;	//�v���C���[���߂荞�܂Ȃ��ʒu�ɒ���
	}

	if (hit == true && m_v_NPos.y + PLAYER_SIZE_Y > y && m_v_NPos.x + PLAYER_SIZE_X > x)
	{
		m_v_NPos.y = y - PLAYER_SIZE_Y;
		Turnm_SpeedY();
	}
	m_vSpeed.y += GRAVITY_POWER;	//��Ɍ������͂��d�͂ŗ}��

	//	X���֘A�̌v�Z

	if (!RandingFlg) {	// �ڒn���Ȃ�ړ����s��Ȃ�
		m_v_NPos.x += m_vSpeed.x;	//X���W���v�Z
	}
	

	if (m_v_NPos.x < 0) {
		m_v_NPos.x = 0;
		Turnm_SpeedX();
	}
	if (m_v_NPos.x > SCREEN_SIZE_X) {
		m_v_NPos.x = SCREEN_SIZE_X;
		Turnm_SpeedX();
	}

	//-------------------------------------------------

	//current��next���X�V
	Mouse_CLog = Mouse_NLog;
	m_v_CPos = m_v_NPos;
}
void c_Player::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "MouseLog %d\nRadPow %f", Mouse_CLog, m_f_RadPow);
	DrawRotaGraph(m_v_CPos.x, m_v_CPos.y, 1.0, 0.0, PlayerImgHndl, true);
	DrawLine(v_CMouseBuf.x, v_CMouseBuf.y, v_NMouseBuf.x, v_NMouseBuf.y, GetColor(127, 127, 255),4);
	if (Mouse_NLog == MOUSE_INPUT_LOG_DOWN, Mouse_CLog == MOUSE_INPUT_LOG_DOWN) {
		DrawRotaGraph(m_v_CPos.x, m_v_CPos.y, 0.01 * m_f_SizePow,m_f_RadPow, ArrowImgHndl, true);
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