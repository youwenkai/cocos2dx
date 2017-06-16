#include "TowerEditorScene.h"
#include "TowerPosition.h"
#include "TowerEditorLayer.h";

TowerEditorScene::TowerEditorScene(){

}
TowerEditorScene::~TowerEditorScene(){

}

Scene* TowerEditorScene::createScene(){
	auto scene = Scene::create();

	//auto editorLayer = TowerEditorScene::create();
	//scene->addChild(editorLayer);

	auto layer = TowerEditorLayer::create();

	scene->addChild(layer,1);
	return scene;
}

bool TowerEditorScene::init(){
	if (!Layer::init()){
		return false;
	}

	return true;
}