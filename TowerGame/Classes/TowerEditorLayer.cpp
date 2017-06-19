#include "TowerEditorLayer.h"
#include "PositionLoadUtil.h"

#include "CsvUtil.h"

TowerEditorLayer::TowerEditorLayer(){
	m_iCurLevel = 1;
	m_enMode = enMonsterPosition;
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

		switch (m_enMode)
		{
		case enTowerPosition:
			editorTowerPosition(pos);
			break;
		case enMonsterPosition:
			editorMonsterPosition(pos);
			break;
		default:
			break;
		}

		
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenter, this);


	
	loadConfigerFile();

	const char* sPath = "Monster.csv";
	CsvUtil::getInstance()->loadFile(sPath);

	Value firstMonsterName = CsvUtil::getInstance()->getValue(2, 1, sPath);

	Value secMonsterHP = CsvUtil::getInstance()->getValue(3, 3, sPath);

	log("firstMonsterName=%s", firstMonsterName.asString().c_str());
	log("secMonsterHP=%s", secMonsterHP.asString().c_str());

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

	//log(">>>>>>>>>>>>>>>>>>>>>>>>length= %d", m_towerPosition.size());
}

void TowerEditorLayer::deleteTowerPosition(BasePosition* existPos){
	this->removeChild(existPos);
	m_towerPosition.eraseObject(existPos);
}
void TowerEditorLayer::deleteAllPosition(){
	this->removeAllChildren();
	m_towerPosition.clear();
	m_monsterPositionList.clear();
}
void TowerEditorLayer::outputPositionToPlistFile(){
	std::string sTowerPositionPath = StringUtils::format(TOWERFILEPATH,m_iCurLevel);
	outputPositionToPlistFile(m_towerPosition, sTowerPositionPath.c_str());

	std::string sMonsterPositionPath = StringUtils::format(MONSTERFILEPATH, m_iCurLevel);
	outputPositionToPlistFile(m_monsterPositionList, sMonsterPositionPath.c_str());
}
void TowerEditorLayer::outputPositionToPlistFile(Vector<BasePosition *> pList, const char * sPath){
	ValueMap fileDataMap;
	int index = 1;
	for (auto basePos : pList){
		ValueMap data;
		log("x = %f,y=%f", basePos->getPos().x, basePos->getPos().y);
		data["x"] = basePos->getPos().x;
		data["y"] = basePos->getPos().y;

		fileDataMap[StringUtils::toString(index)] = Value(data);

		index++;
	}
	FileUtils::getInstance()->writeToFile(fileDataMap, sPath);
}
void TowerEditorLayer::loadConfigerFile(){
	Size visiableSize = Director::getInstance()->getVisibleSize();

	

	/**添加地图背景*/
	std::string sBG = StringUtils::format(BGPATH, m_iCurLevel);

	Sprite* map = Sprite::create(sBG.c_str());

	map->setPosition(visiableSize.width / 2, visiableSize.height / 2);

	this->addChild(map, 1);

	/**加载塔坐标对象*/
	std::string sTowerPositionPath = StringUtils::format(TOWERFILEPATH, m_iCurLevel);

	Vector<BasePosition*> towerList = PositionLoadUtil::getInstance()->loadPositionWithFile(sTowerPositionPath.c_str(), enTowerPosition ,this, m_iCurLevel, true);

	m_towerPosition.pushBack(towerList);

	
	/**加载怪物坐标对象*/
	std::string sMonsterPositionPath = StringUtils::format(MONSTERFILEPATH, m_iCurLevel);

	Vector<BasePosition*> monsterList = PositionLoadUtil::getInstance()->loadPositionWithFile(sMonsterPositionPath.c_str(),enMonsterPosition ,this, m_iCurLevel, true);
	
	m_monsterPositionList.pushBack(monsterList);
}

void TowerEditorLayer::editorMonsterPosition(Point pos){
	BasePosition* existPos = findExistMonsterPosition(pos);
	if (existPos == NULL){
		createMonsterPosition(pos);
	}
	else{
		deleteMonsterPosition(existPos);
	}
}
BasePosition* TowerEditorLayer::findExistMonsterPosition(Point pos){
	for (auto basePos : m_monsterPositionList){
		if (basePos->isClickMe(pos)){
			return basePos;
		}
	}
	return NULL;
}
void TowerEditorLayer::createMonsterPosition(Point pos){
	MonsterPosition* tPos = MonsterPosition::create(pos, true);
	this->addChild(tPos, 10);
	m_monsterPositionList.pushBack(tPos);
}
void TowerEditorLayer::deleteMonsterPosition(BasePosition* exist){
	this->removeChild(exist);
	m_monsterPositionList.eraseObject(exist);
}
void TowerEditorLayer::changeMode(){
	if (m_enMode == enTowerPosition){
		m_enMode = enMonsterPosition;
	}
	else{
		m_enMode = enTowerPosition;
	}
}
int TowerEditorLayer::nextLevel(){
	deleteAllPosition();
	m_iCurLevel++;
	loadConfigerFile();

	return m_iCurLevel;
}
int TowerEditorLayer::preLevel(){
	deleteAllPosition();
	m_iCurLevel--;
	loadConfigerFile();

	return m_iCurLevel;
}