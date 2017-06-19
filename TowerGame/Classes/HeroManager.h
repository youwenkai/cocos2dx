#ifndef _HeroManager_H_
#define _HeroManager_H_

#define TOWER_POS_LAYER_LVL 5      //塔坐标的层次
#define TOWER_BORDER_LAYER_LVL 8   //炮台的层次
#define TOWER_LAYER_LVL 10		   //塔的层次

#include "cocos2d.h"
#include "TowerPosition.h"
#include "TowerBorder.h"
USING_NS_CC;
class HeroManager :public Node{
public:
	HeroManager();
	~HeroManager();

	static HeroManager* createWithLevel(int iCurLevel);
	bool initWithLevel(int iCurLevel);
private:
	Vector<BasePosition*> m_towerPositionList;

	Vector<TowerBorder*> m_towerBorderList;

	void createTowerBorder(int iCurLevel);

	void createTowerPosition(Point pos);
};

#endif