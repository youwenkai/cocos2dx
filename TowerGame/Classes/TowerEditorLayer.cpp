#include "TowerEditorLayer.h"

TowerEditorLayer::TowerEditorLayer(){
	m_iCurLevel = 1;
}

TowerEditorLayer::~TowerEditorLayer(){

}

bool TowerEditorLayer::init(){
	if (!Layer::init()){
		return false;
	}

	EventListenerTouchOneByOne* listenter = EventListenerTouchOneByOne::create();

	listenter->onTouchBegan = [](Touch* t,Event* e){
		return true;
	};

	listenter->onTouchEnded = [&](Touch* t, Event* e){
		Point pos = t->getLocation();
		editorTowerPosition(pos);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenter, this);

	return true;
}

void TowerEditorLayer::editorTowerPosition(Point pos){
	BasePosition* exist = findExistTowerPosition(pos);
	if (exist){
		deleteTowerPosition(exist);
	}
	else{
		createTowerPosition(pos);
	}
}

BasePosition* TowerEditorLayer::findExistTowerPosition(Point pos){
	for (auto basePos : m_towerPosition){
		if (basePos->isClickMe(pos)){
			return basePos;
		}
	}
	return NULL;
}

void TowerEditorLayer::createTowerPosition(Point pos){
	TowerPosition*  tPos = TowerPosition::create(pos, true);
	this->addChild(tPos, 10);

	m_towerPosition.pushBack(tPos);

	log(">>>>>>>>>>>>>>>>>>>>>>>>length= %d", m_towerPosition.size());
}

void TowerEditorLayer::deleteTowerPosition(BasePosition* existPos){
	this->removeChild(existPos);
	m_towerPosition.eraseObject(existPos);
}
void TowerEditorLayer::deleteAllPosition(){
	this->removeAllChildren();
	m_towerPosition.clear();
}
void TowerEditorLayer::outputPositionToPlistFile(){
	ValueMap fileDataMap;
	log(">>>>>>>>>>>>>>>>>>>>>>output func()");
	int index = 1;
	for (auto basePos : m_towerPosition){
		ValueMap data;
		log("x = %f,y=%f", basePos->getPos().x, basePos->getPos().y);
		data["x"] = basePos->getPos().x;
		data["y"] = basePos->getPos().y;

		fileDataMap[StringUtils::toString(index)] = Value(data);

		index++;
	}
	FileUtils::getInstance()->writeToFile(fileDataMap,StringUtils::format(sFilePath.c_str(),m_iCurLevel));
}