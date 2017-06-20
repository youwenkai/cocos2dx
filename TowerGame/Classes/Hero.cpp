#include "Hero.h"
#include "CsvUtil.h"
#include "EnumHeroPropConfType.h"
#include "Common.h"

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
		int iLine = csvUtil->findValueInWithLine(sHeroId.c_str(),
			enHeroPropConf_ID, PATH_CSV_HERO_CONF);

		CC_BREAK_IF(iLine < 0);

		setID(iHeroID);
		setiModeID(csvUtil->getInt(iLine, enHeroPropConf_ModelID, PATH_CSV_HERO_CONF));
		setiBaseAtk(csvUtil->getInt(iLine, enHeroPropConf_BaseAtk, PATH_CSV_HERO_CONF));
		setiCurAtk(getiBaseAtk());
		setiAtkSpeed(csvUtil->getInt(iLine, enHeroPropConf_AtkSpeed, PATH_CSV_HERO_CONF));
		setiAtkRange(csvUtil->getInt(iLine, enHeroPropConf_AtkRange, PATH_CSV_HERO_CONF));
		setiUpgradeCostBase(csvUtil->getInt(iLine, enHeroPropConf_UpgradeAtkBase, PATH_CSV_HERO_CONF));
		setfUpgradeAtkBase(csvUtil->getInt(iLine, enHeroPropConf_UpgradeAtkBase, PATH_CSV_HERO_CONF));

		Sprite* sprite = Sprite::create(StringUtils::format(HERO_SPRITESRC_PATH, iHeroID).c_str());
		CC_BREAK_IF(!sprite);
		CC_BREAK_IF(!init(sprite));
		bRet = true;

	} while (0);

	return bRet;
}