#include "scene.h"

c_SceneManager::c_SceneManager() 
{

}
c_SceneManager::~c_SceneManager()
{

}
void c_SceneManager::Init()
{
	SceneID = SCENE_INIT_TITLE;	//起動後最初に実行するシーンはここを変更 << focus
}
void c_SceneManager::Step()
{
	switch (SceneID)
	{
	case SCENE_INIT_TITLE:

		cTitle.Init();
		SceneID = SCENE_LOOP_TITLE;

		break;

	case SCENE_LOOP_TITLE:

		cTitle.Step();
		cTitle.Draw();
		if (cTitle.GetBreakFlg()) {
			SceneID = SCENE_FIN_TITLE;
		}

		break;

	case SCENE_FIN_TITLE:

		cTitle.Exit();
		SceneID = SCENE_INIT_PLAY;

		break;

	case SCENE_INIT_PLAY:

		cPlay.Init();
		SceneID = SCENE_LOOP_PLAY;

		break;

	case SCENE_LOOP_PLAY:

		cPlay.Step();
		cPlay.Draw();
		if (cPlay.GetBreakFlg()) {
			SceneID = SCENE_FIN_PLAY;
		}

		break;

	case SCENE_FIN_PLAY:

		cPlay.Exit();
		SceneID = SCENE_INIT_RESULT;

		break;

	case SCENE_INIT_RESULT:

		cResult.Init();
		SceneID = SCENE_LOOP_RESULT;

		break;

	case SCENE_LOOP_RESULT:

		cResult.Step();
		cResult.Draw();
		if (cPlay.GetBreakFlg()) {
			SceneID = SCENE_FIN_RESULT;
		}

		break;

	case SCENE_FIN_RESULT:

		cResult.Exit();
		SceneID = SCENE_INIT_TITLE;

		break;

	default:
		break;
	}
}
void c_SceneManager::fin()
{

}