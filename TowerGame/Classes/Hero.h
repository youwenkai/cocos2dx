#ifndef _Hero_H_
#define _Hero_H_

#include "Entity.h"

class Hero :public Entity{
public:
	Hero();
	~Hero();


	static Hero* create(Sprite* sprite);

	virtual bool init(Sprite* sprite);

	/**给定英雄ID,从配置文件中读取英雄数据*/
	static Hero* createFromCsvFileByID(int iHeroID);
	bool initFromCsvFileByID(int iHeroID);

	//基础攻击力
	CC_SYNTHESIZE(int, m_iBaseAtk, iBaseAtk);
	//当前攻击力
	CC_SYNTHESIZE(int, m_iCurAtk, iCurAtk);
	//攻击间隔
	CC_SYNTHESIZE(int, m_iAtkSpeed, iAtkSpeed);
	//攻击范围
	CC_SYNTHESIZE(int, m_iAthRange, iAtkRange);
	//升级消耗基础值
	CC_SYNTHESIZE(int, m_iUpgradeCostBase, iUpgradeCostBase);
	//升级攻击加成系数
	CC_SYNTHESIZE(int, m_fUpgradeAtkBase, fUpgradeAtkBase);

	//升级英雄
	void upGrade();
};

#endif
