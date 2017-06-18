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

	auto changeBtn = (ui::Button*)view->getChildByName("changeBtn");
	changeBtn->addTouchEventListener(this, toucheventselector(TowerEditorOperateLayer::changeEditorPositionType));

	auto nextBtn = (ui::Button*)view->getChildByName("nextLevelBtn");
	nextBtn->addTouchEventListener(this, toucheventselector(TowerEditorOperateLayer::nextLevel));

	auto preBtn = (ui::Button*)view->getChildByName("preLevelBtn");
	preBtn->addTouchEventListener(this, toucheventselector(TowerEditorOperateLayer::preLevel));

	return true;
}

void TowerEditorOperateLayer::outputBtnOnClick(Ref*, ui::TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		m_editorLayer->outputPositionToPlistFile();
	}
}
void TowerEditorOperateLayer::changeEditorPositionType(Ref*, ui::TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		m_editorLayer->changeMode();
	}
}
void TowerEditorOperateLayer::nextLevel(Ref*, ui::TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		m_editorLayer->nextLevel();
	}
}
void TowerEditorOperateLayer::preLevel(Ref*, ui::TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		m_editorLayer->preLevel();
	}
}

void TowerEditorOperateLayer::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(TowerEditorOperateLayer::onDraw, this, transform, flags);

	renderer->addCommand(&_customCommand);
}

void TowerEditorOperateLayer::onDraw(const Mat4& transform, uint32_t flags){
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);

	Vector<BasePosition*> m_monsterPositionList = m_editorLayer->getMonsterPositionList();

	BasePosition* prePos = NULL;
	for (auto basePos : m_monsterPositionList){
		if (prePos != NULL){
			DrawPrimitives::drawLine(prePos->getPos(), basePos->getPos());
		}
		prePos = basePos;
	}

	kmGLPopMatrix();
}