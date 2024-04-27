#pragma once
#include "DxLib.h"
#include "../../../Common.h"

#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32
#define PLAYER_RECT 16

static VECTOR DEFAULT_PLAYER_POS = { 100.0f,400.0f,0.0f };
static VECTOR ARROW_VEC_NOAM = { 0.0f,3.14f,0.0f };//正規化された矢印の初期方向のベクトル
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
	VECTOR v_CMouseBuf;	//マウスの座標バッファ(クリック地点)
	VECTOR v_NMouseBuf;	//マウスの座標バッファ(リリース地点)
	VECTOR m_v_CPos;	// 現在の座標
	VECTOR m_v_NPos;	// 次の座標
	VECTOR m_vSpeed;	// パワーと重力から計算された移動方向
	VECTOR m_vPower;	// パワー保存用 << 射出するベクトル
	float m_f_SizePow;	//パワーの大きさ
	float m_f_RadPow;	//パワーの角度

	int PlayerImgHndl;	//プレイヤーの画像ハンドル
	int ArrowImgHndl;	//照準の画像ハンドル

	int MouseButton;	//マウスの操作されたボタンを保存
	int MousePosX;
	int MousePosY;
	int Mouse_CLog;	//ボタンが押されたか離されたかの情報を保存するcurrent
	int Mouse_NLog;	//ボタンが押されたか離されたかの情報を保存するnext

	bool RandingFlg;	//設置フラグ
};