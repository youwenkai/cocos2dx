#include "TollgateMapLayer.h"
#include "SimpleAudioEngine.h"
#include "Common.h"


#define HOME_LAYER_LVL 3     //���ݵĲ��
#define HERO_LAYER_LVL 10    //Ӣ�۵Ĳ��
#define MONSTER_LAYER_LVL 15 //����Ĳ��
#define BULLET_LAYER_LVL 20  //�ӵ��Ĳ��

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

	/**����Ӣ�۹�����*/
	m_heroMgr = HeroManager::createWithLevel(m_iCurLevel);
	this->addChild(m_heroMgr, HERO_LAYER_LVL);
	

	return true;
}
void TollgateMapLayer::loadConfig(){
	Size size = Director::getInstance()->getVisibleSize();

	//��ӱ�������
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(
		StringUtils::format("music/tollgate_%d.mp3", m_iCurLevel).c_str(), true);

	std::string sBg = StringUtils::format(BGPATH, m_iCurLevel);
	Sprite* map = Sprite::create(sBg.c_str());
	map->setPosition(size.width / 2, size.height / 2);
	this->addChild(map, 1);
}