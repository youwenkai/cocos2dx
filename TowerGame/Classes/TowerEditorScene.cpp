#include "TowerEditorScene.h"
#include "TowerEditorLayer.h"
#include "TowerEditorOperateLayer.h"


TowerEditorScene::TowerEditorScene(){

}
TowerEditorScene::~TowerEditorScene(){

}

Scene* TowerEditorScene::createScene(){
	auto scene = Scene::create();

	//auto editorLayer = TowerEditorScene::create();
	//scene->addChild(editorLayer);

	auto layer = TowerEditorLayer::create();

	auto oprLayer = TowerEditorOperateLayer::create(layer);

	scene->addChild(layer,1);
	scene->addChild(oprLayer, 2);
	return scene;
}

bool TowerEditorScene::init(){
	if (!Layer::init()){
		return false;
	}

	return true;
}