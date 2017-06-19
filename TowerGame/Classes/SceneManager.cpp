#include "SceneManager.h"
#include "TowerEditorScene.h"
#include "TollgateScene.h"

SceneManager* SceneManager::instance = NULL; 

SceneManager* SceneManager::getInstance(){
	if (instance == NULL){
		instance = new SceneManager();
		if (instance && instance->init()){
			instance->autorelease();
			instance->retain();
		}
		else{
			CC_SAFE_DELETE(instance);
			instance = NULL;
		}
	}
	return instance;
}
bool SceneManager::init(){
	return true;
}

void SceneManager::changeScene(EnumSceneType enSceneType){
	Scene* pScene = NULL;

	switch (enSceneType)
	{
	case SceneManager::en_TollgateScene:     //关卡场景
		pScene = TollgateScene::createScene();
		break;
	case SceneManager::en_TollgateEditorScene: //关卡编辑场景
		pScene = TowerEditorScene::createScene();
		break;
	case SceneManager::en_WinScene://胜利场景
		break;
	case SceneManager::en_GameOverScene://结束场景
		break;
	default:
		break;
	}

	if (pScene == NULL){
		return;
	}

	Director* pDirector = Director::getInstance();

	Scene* curScene = pDirector->getRunningScene();

	if (curScene == NULL){
		pDirector->runWithScene(pScene);
	}
	else{
		pDirector->replaceScene(pScene);
	}
}