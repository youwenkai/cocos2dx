#include "TowerEditorOperateLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

TowerEditorOperateLayer::TowerEditorOperateLayer(){

}
TowerEditorOperateLayer::~TowerEditorOperateLayer(){

}

TowerEditorOperateLayer* TowerEditorOperateLayer::create(TowerEditorLayer* layer){
	TowerEditorOperateLayer* oprLayer = new TowerEditorOperateLayer();
	if (oprLayer && oprLayer->init(layer)){
		oprLayer->autorelease();
	}
	else{
		CC_SAFE_DELETE(oprLayer);
	}
	return oprLayer;
}

bool TowerEditorOperateLayer::init(TowerEditorLayer* layer){
	if (!Layer::init()){
		return false;
	}

	this->m_editorLayer = layer;

	auto view = CSLoader::createNode("TowerOperateLayer.csb");

	this->addChild(view);

	
	auto outputBtn = (ui::Button*)view->getChildByName("outputBtn");

	outputBtn->addTouchEventListener(this, toucheventselector(TowerEditorOperateLayer::outputBtnOnClick));

	return true;
}

void TowerEditorOperateLayer::outputBtnOnClick(Ref*, ui::TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		m_editorLayer->outputPositionToPlistFile();
	}
}