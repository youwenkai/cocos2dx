#include "PositionLoadUtil.h"

PositionLoadUtil* PositionLoadUtil::m_positionLoadUtil = NULL;

PositionLoadUtil* PositionLoadUtil::getInstance(){
	if (m_positionLoadUtil == NULL){
		m_positionLoadUtil = new PositionLoadUtil;
		if (m_positionLoadUtil && m_positionLoadUtil->init()){
			m_positionLoadUtil->autorelease();
		}
		else{
			CC_SAFE_DELETE(m_positionLoadUtil);
		}
	}
	return m_positionLoadUtil;
}
bool PositionLoadUtil::init(){
	return true;
}
Vector<BasePosition*> PositionLoadUtil::loadPositionWithFile(const char* sFilePath, EnumPositionType posType, Node* container, int iLevel, bool isDebug){
	Vector<BasePosition*> pList;

	ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sFilePath);

	int size = fileDataMap.size();

	for (int i = 1; i < size; i++){
		Value value = fileDataMap.at(StringUtils::toString(i));

		ValueMap data = value.asValueMap();


		BasePosition* basePos = NULL; 

		switch (posType)
		{
		case enTowerPosition:
			basePos = TowerPosition::create(Point(data["x"].asInt(), data["y"].asInt()), isDebug);
			break;
		case enMonsterPosition:
			basePos = MonsterPosition::create(Point(data["x"].asInt(), data["y"].asInt()), isDebug);
			break;
		default:
			break;
		}
		
		pList.pushBack(basePos);

		if (container != NULL){
			container->addChild(basePos,iLevel);
		}
	}

	return pList;
}