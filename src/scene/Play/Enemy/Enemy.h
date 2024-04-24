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
	VECTOR m_v_CPos;	// 現在の座標
	VECTOR m_v_NPos;	// 次の座標
	VECTOR m_vPower;	// パワー保存用 << 射出するベクトル
};