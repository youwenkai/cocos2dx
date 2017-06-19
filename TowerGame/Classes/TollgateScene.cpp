#include "TollgateScene.h"

Scene* TollgateScene::createScene(){
	auto scene = Scene::create();
	
	auto tgLayer = TollgateScene::create();

	scene->addChild(tgLayer, 3);


	return scene;
}
bool TollgateScene::init(){
	if (!Layer::init()){
		return false;
	}
	return true;
}