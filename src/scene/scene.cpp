#include "scene.h"

c_SceneManager::c_SceneManager() 
{

}
c_SceneManager::~c_SceneManager()
{

}
void c_SceneManager::Init()
{
	SceneID = SCENE_INIT_PLAY;	//起動後最初に実行するシーンはここを変更 << focus
}
void c_SceneManager::Step()
{
	switch (SceneID)
	{
	case SCENE_INIT_TITLE:
		break;
	case SCENE_LOOP_TITLE:
		break;
	case SCENE_FIN_TITLE:
		break;
	case SCENE_INIT_PLAY:
		break;
	case SCENE_LOOP_PLAY:
		break;
	case SCENE_FIN_PLAY:
		break;
	case SCENE_INIT_RESULT:
		break;
	case SCENE_LOOP_RESULT:
		break;
	case SCENE_FIN_RESULT:
		break;

	default:
		break;
	}
}
void c_SceneManager::fin()
{

}