#include "Player.h"

c_Player::c_Player()
{

}
c_Player::~c_Player()
{

}

void c_Player::Init()
{

}
void c_Player::Step()
{

}
void c_Player::Draw()
{
	DrawBox(m_v_CPos.x, m_v_CPos.y, m_v_CPos.x + PLAYER_SIZE_X, m_v_CPos.x + PLAYER_SIZE_Y, GetColor(255, 255, 0), false);
}
void c_Player::Exit()
{

}