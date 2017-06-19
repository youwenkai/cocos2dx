#include "TowerBorder.h"


TowerBorder::TowerBorder(){
	m_iLevel = 1;
}
TowerBorder::~TowerBorder(){

}
bool TowerBorder::init(){
	return true;
}

void TowerBorder::upgrade(){
	if (getSprite() != NULL){
		getSprite()->stopAllActions();
	}

	std::string sFilePath = StringUtils::format("sprite/hero/border_%d.png", m_iLevel);
	Sprite* sprite = Sprite::create(sFilePath.c_str());

	bindSprite(sprite);

	m_iLevel++;

	if (m_iLevel == 2){
		auto rotateBy = RotateBy::create(25.0f, 360, 360);
		auto repeat = RepeatForever::create(rotateBy);

		sFilePath = StringUtils::format("sprite/hero/border_%d.png", m_iLevel);
		sprite = Sprite::create(sFilePath.c_str());
		sprite->setOpacity(80);
		sprite->runAction(repeat);
		this->addChild(sprite, 10);
	}
}