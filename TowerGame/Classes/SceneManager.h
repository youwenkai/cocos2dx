#ifndef _SceneManager_H_
#define _SceneManager_H_



#include "cocos2d.h"
USING_NS_CC;

class SceneManager :public Ref{
public:
	enum EnumSceneType
	{
		en_TollgateScene,
		en_TollgateEditorScene,
		en_WinScene,
		en_GameOverScene
	};

	static SceneManager* getInstance();

	virtual bool init();

	void changeScene(EnumSceneType enSceneType);

private:
	static SceneManager* instance;
};
#endif
