#include "Hero.h"
#include "CsvUtil.h"

Hero::Hero(){

}
Hero::~Hero(){

}

Hero* Hero::create(Sprite* sprite){
	Hero* hero = new Hero();
	if (hero && hero->init(sprite)){
		hero->autorelease();
	}
	else{
		CC_SAFE_DELETE(hero);
	}

	return hero;
}
bool Hero::init(Sprite* sprite){
	bool bRet = false;

	do 
	{
		CC_BREAK_IF(!sprite);
		bindSprite(sprite);
		bRet = true;

	} while (0);

	return bRet;
}

Hero* Hero::createFromCsvFileByID(int iHeroID){
	Hero* hero = new Hero();
	if (hero && hero->initFromCsvFileByID(iHeroID)){
		hero->autorelease();
	}
	else{
		CC_SAFE_DELETE(hero);
	}

	return hero;
}
bool Hero::initFromCsvFileByID(int iHeroID){
	bool bRet = false;

	do 
	{
		CsvUtil* csvUtil = CsvUtil::getInstance();

		std::string sHeroId = StringUtils::toString(iHeroID);
		
		//寻找id所在的行
		//int iLine = csvUtil->findValueInWithLine()
	} while (0);
}