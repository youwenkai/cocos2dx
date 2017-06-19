#include "TollgateScene.h"
#include "TollgateMapLayer.h"

Scene* TollgateScene::createScene(){
	auto scene = Scene::create();
	
	auto tgLayer = TollgateScene::create();

	auto mapLayer = TollgateMapLayer::create();

	scene->addChild(mapLayer, 1, TAG_MAP_LAYER);
	scene->addChild(tgLayer, 3);


	return scene;
}
bool TollgateScene::init(){
	if (!Layer::init()){
		return false;
	}
	return true;
}