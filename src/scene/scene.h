#pragma once
#include "Title/Title.h"

class c_SceneManager
{
public:
	c_SceneManager();
	~c_SceneManager();
	void Init();
	void Step();
	void fin();

	enum SCENE_ID
	{
		SCENE_INIT_TITLE = 100,
		SCENE_LOOP_TITLE,
		SCENE_FIN_TITLE,

		SCENE_INIT_PLAY = 200,
		SCENE_LOOP_PLAY,
		SCENE_FIN_PLAY,

		SCENE_INIT_RESULT = 300,
		SCENE_LOOP_RESULT,
		SCENE_FIN_RESULT,
	};

private:
	SCENE_ID SceneID;

	c_Title cTitle;
};
