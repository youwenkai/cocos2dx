#include "TollgateMapLayer.h"
#include "SimpleAudioEngine.h"
#include "Common.h"


#define HOME_LAYER_LVL 3     //堡垒的层次
#define HERO_LAYER_LVL 10    //英雄的层次
#define MONSTER_LAYER_LVL 15 //怪物的层次
#define BULLET_LAYER_LVL 20  //子弹的层次

TollgateMapLayer::TollgateMapLayer(){
	m_iCurLevel = 1;
}
TollgateMapLayer::~TollgateMapLayer(){

}

bool TollgateMapLayer::init(){
	if (!Layer::init()){
		return false;
	}
	loadConfig();

	/**创建英雄管理器*/
	m_heroMgr = HeroManager::createWithLevel(m_iCurLevel);
	this->addChild(m_heroMgr, HERO_LAYER_LVL);
	

	return true;
}
void TollgateMapLayer::loadConfig(){
	Size size = Director::getInstance()->getVisibleSize();

	//添加背景音乐
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(
		StringUtils::format("music/tollgate_%d.mp3", m_iCurLevel).c_str(), true);

	std::string sBg = StringUtils::format(BGPATH, m_iCurLevel);
	Sprite* map = Sprite::create(sBg.c_str());
	map->setPosition(size.width / 2, size.height / 2);
	this->addChild(map, 1);
}