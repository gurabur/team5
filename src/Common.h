#pragma once

// include <<必要と思われる物はすべてここにまとめてある
#include "My_Math/My_Math.h"		// ベクトル計算用
#include "Collision/Collision.h"	// 当たり判定用
#include "Input/Input.h"			// キーボード入力ができる

// define
#define	SCREEN_SIZE_X	1080	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	720	// Y方向の画面サイズを指定
#define GRAVITY_POWER	0.2f	// 重力の強さ
#define FIELD_HEIGHT	650	//地面とするY座標