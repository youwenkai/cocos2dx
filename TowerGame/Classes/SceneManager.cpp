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
	case SceneManager::en_TollgateScene:     //�ؿ�����
		pScene = TollgateScene::createScene();
		break;
	case SceneManager::en_TollgateEditorScene: //�ؿ��༭����
		pScene = TowerEditorScene::createScene();
		break;
	case SceneManager::en_WinScene://ʤ������
		break;
	case SceneManager::en_GameOverScene://��������
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