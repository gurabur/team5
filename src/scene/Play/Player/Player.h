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
	VECTOR m_v_CPos;	// 現在の座標
	VECTOR m_v_NPos;	// 次の座標
	VECTOR m_vPower;	// パワー保存用 << 射出するベクトル

	int PlayerImgHndl;	//プレイヤーの画像ハンドル
};