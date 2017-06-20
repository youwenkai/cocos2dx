#include "HeroManager.h"
#include "Common.h"
#include "PositionLoadUtil.h"
#include "Hero.h"

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

	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [](Touch* t, Event* e){
		return true;
	};
	listener->onTouchEnded = [&](Touch* t, Event* e){
		Point pos = t->getLocation();

		TowerBorder* clickBorder = findClickTowerBorder(pos);

		if (clickBorder == NULL){
			return;
		}
		if (clickBorder->getHero() == NULL){
			Hero* hero = Hero::createFromCsvFileByID(1);
			hero->setPosition(clickBorder->getPosition());
			this->addChild(hero, TOWER_POS_LAYER_LVL);

			clickBorder->bindHero(hero);
		}
	};


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

void HeroManager::createTowerBorder(int iCurLevel){
	for (auto tPos : m_towerPositionList){
		TowerBorder* border = TowerBorder::create();
		border->upgrade();
		//border->upgrade();
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
TowerBorder* HeroManager::findClickTowerBorder(Point pos){
	for (auto tBorder : m_towerBorderList){
		if (tBorder->isClickMe(pos)){
			return tBorder;
		}
	}

	return NULL;
}
