#include "Player.h"

c_Player::c_Player()
{
	v_CMouseBuf = VGet(0.0f, 0.0f, 0.0f);
	v_NMouseBuf = VGet(0.0f, 0.0f, 0.0f);
	m_v_CPos = VGet(0.0f, 0.0f, 0.0f);
	m_v_NPos = VGet(0.0f, 0.0f, 0.0f);
	m_vSpeed = VGet(0.0f, 0.0f, 0.0f);
	m_vPower = VGet(0.0f, 0.0f, 0.0f);
	m_f_SizePow = 0.0f;//パワーの大きさ
	m_f_RadPow = 0.0f;	//パワーの角度

	PlayerImgHndl = -1;
	ArrowImgHndl = -1;

	MouseButton = 0;	//マウスの操作されたボタンを保存
	MousePosX = 0;
	MousePosY = 0;
	Mouse_CLog = 1;	//ボタンが押されたか離されたかの情報を保存するcurrent
	Mouse_NLog = 1;	//ボタンが押されたか離されたかの情報を保存するnext

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
	// マウス関連--------------------------------------

	if (GetMouseInputLog2(&MouseButton, &MousePosX, &MousePosY, &Mouse_NLog,true) == 0) {
		if (Mouse_NLog == MOUSE_INPUT_LOG_DOWN,Mouse_CLog == MOUSE_INPUT_LOG_UP) {			//クリックした瞬間の座標を保存
			v_CMouseBuf.x = (float)MousePosX;
			v_CMouseBuf.y = (float)MousePosY;
		}
		else if (Mouse_NLog == MOUSE_INPUT_LOG_UP, Mouse_CLog == MOUSE_INPUT_LOG_DOWN) {	//リリースした瞬間プレイヤーの移動方向を決める
			m_vSpeed = MyMath::VecScale(m_vPower, m_f_SizePow/10);	//正規化されたパワーベクトルに、修正されたパワースカラーを乗算
			m_vSpeed = VGet(-m_vSpeed.x, -m_vSpeed.y, 0.0f);	//パワーベクトルはクリック地点からリリース地点のベクトルなので、ここでm_vSpeedを反転させることでスリングショットを実現する
		}
	}

	GetMousePoint(&MousePosX, &MousePosY);
	v_NMouseBuf.x = (float)MousePosX;
	v_NMouseBuf.y = (float)MousePosY;

	m_vPower = MyMath::VecCreate(v_CMouseBuf, v_NMouseBuf);			//マウスを動かした始点と終点でベクトル化
	m_f_SizePow = MyMath::VecLong(m_vPower);						//ベクトルから大きさを抽出
	if (m_f_SizePow >= MAX_SHOT_POWER) {
		m_f_SizePow = MAX_SHOT_POWER;								//上限値の突破を抑制
	}
	m_vPower = MyMath::VecNormalize(m_vPower);						//パワーを正規化 << m_vPowerは最終的にここに帰結する
	m_f_RadPow = acosf(m_vPower.x);									//パワーの角度を取得
	if (asinf(m_vPower.y) <= 0) {
		m_f_RadPow = -m_f_RadPow;
	}
	if (Mouse_NLog == MOUSE_INPUT_LOG_DOWN, Mouse_CLog == MOUSE_INPUT_LOG_DOWN) { Sleep(20); }
	//-------------------------------------------------


	// PLの移動関連------------------------------------
	if (hit == true && m_v_NPos.x + PLAYER_SIZE_X > x)
	{
		m_v_NPos.x = x - PLAYER_SIZE_X;
		Turnm_SpeedX();
	}
	//	Y軸関連の計算
	RandingFlg = false;	//一旦接地フラグをfalseにする

	m_v_NPos.y += m_vSpeed.y;	//Y座標を計算

	if (m_v_NPos.y + PLAYER_RECT >= FIELD_HEIGHT){	//接地判定をとる
		RandingFlg = true;
		m_vSpeed = VGet(0.0f, 0.0f, 0.0f);
		m_v_NPos.y = FIELD_HEIGHT - PLAYER_RECT;	//プレイヤーをめり込まない位置に調整
	}

	if (hit == true && m_v_NPos.y + PLAYER_SIZE_Y > y && m_v_NPos.x + PLAYER_SIZE_X > x)
	{
		m_v_NPos.y = y - PLAYER_SIZE_Y;
		Turnm_SpeedY();
	}
	m_vSpeed.y += GRAVITY_POWER;	//上に向かう力を重力で抑制

	//	X軸関連の計算

	if (!RandingFlg) {	// 接地中なら移動を行わない
		m_v_NPos.x += m_vSpeed.x;	//X座標を計算
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

	//currentとnextを更新
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