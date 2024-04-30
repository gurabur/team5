#include "Enemy.h"

c_Enemy::c_Enemy()
{
	m_v_CPos = VGet(0.0f, 0.0f, 0.0f);
	EnemyImgHndl = -1;
	m_HitPoint = 0.0f;
	m_MaxHP = 0.0f;
	HPboxPosX = 0;
	HPboxPosY = 0;
	HPboxLength = 0.0f;
	DamageReaction = false;
	IsUseFlg = true;
}
c_Enemy::~c_Enemy()
{

}

void c_Enemy::Init()
{
	m_v_CPos = VGet(550.0f, 250.0f, 0.0f);
	EnemyImgHndl = LoadGraph("data/PlayScene/Enemy/kamakiri.png");
	m_HitPoint = 2500; //“G‚Ì‘Ì—Í
	m_MaxHP = 2500;
	HPboxPosX = 600;
	HPboxPosY = 100;
	HPboxLength = 200;
	IsUseFlg = true;
}
void c_Enemy::Step(float x, float y, float w, float h,float p)
{
	DamageReaction = false;
	if (Collision::IsHitRect(x - w / 2, y - h / 2, w, h, m_v_CPos.x, m_v_CPos.y, ENEMY_SIZE_X, ENEMY_SIZE_Y))
	{
		m_HitPoint -= p;
		HPboxLength = HPboxLength * (m_HitPoint / m_MaxHP);
		DamageReaction = true;
	}
	if (m_HitPoint <= 0)
	{
		IsUseFlg = false;
	}
}
void c_Enemy::Draw()
{
	DrawGraph(m_v_CPos.x, m_v_CPos.y, EnemyImgHndl, true);
	DrawLine(HPboxPosX, HPboxPosY, HPboxPosX + 200, HPboxPosY, GetColor(255, 64, 64), 64);
	DrawLine(HPboxPosX, HPboxPosY, HPboxPosX + HPboxLength, HPboxPosY, GetColor(64, 255, 64), 64);
}
void c_Enemy::Exit()
{
	DeleteGraph(EnemyImgHndl);
	EnemyImgHndl = -1;
}
