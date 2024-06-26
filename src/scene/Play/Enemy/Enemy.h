#pragma once
#include "DxLib.h"
#include "../../../Common.h"

#define ENEMY_SIZE_X 500
#define ENEMY_SIZE_Y 500

class c_Enemy
{
public:
	c_Enemy();
	~c_Enemy();

	void Init();
	void Step(float x,float y,float w,float h, float p);
	void Draw();
	void Exit();

	inline float Getm_PosX() { return m_v_CPos.x; }
	inline float Getm_PosY() { return m_v_CPos.y; }

	inline bool GetDamageReaction() { return DamageReaction; }
	inline bool GetIsUseFlg() { return IsUseFlg; }
protected:
	VECTOR m_v_CPos;	// 現在の座標
	int EnemyImgHndl;
	float m_HitPoint;
	float m_MaxHP;
	int HPboxPosX;
	int HPboxPosY;
	float HPboxLength;
	bool DamageReaction;
	bool IsUseFlg;
};