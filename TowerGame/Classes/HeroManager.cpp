#include "HeroManager.h"
#include "Common.h"
#include "PositionLoadUtil.h"

HeroManager::HeroManager(){

}
HeroManager::~HeroManager(){

}
HeroManager* HeroManager::createWithLevel(int iCurLevel){
	HeroManager* heroMgr = new HeroManager();
	if (heroMgr && heroMgr->initWithLevel(iCurLevel)){
		heroMgr->autorelease();
	}
	else{
		CC_SAFE_DELETE(heroMgr);
	}
	return heroMgr;
}
bool HeroManager::initWithLevel(int iCurLevel){
	std::string sTowerPositionPath = StringUtils::format(TOWERFILEPATH, iCurLevel);

	Vector<BasePosition*> posList = PositionLoadUtil::getInstance()->loadPositionWithFile(
		sTowerPositionPath.c_str(), enTowerPosition, this, 10, false);

	m_towerPositionList.pushBack(posList);

	createTowerBorder(iCurLevel);

	return true;
}

void HeroManager::createTowerBorder(int iCurLevel){
	for (auto tPos : m_towerPositionList){
		TowerBorder* border = TowerBorder::create();
		border->upgrade();
		border->upgrade();
		border->setPosition(tPos->getPos());
		this->addChild(border);

		m_towerBorderList.pushBack(border);
	}
}
void HeroManager::createTowerPosition(Point pos){
	TowerPosition* tPos = TowerPosition::create(pos, true);
	this->addChild(tPos, TOWER_POS_LAYER_LVL);
	m_towerPositionList.pushBack(tPos);
}