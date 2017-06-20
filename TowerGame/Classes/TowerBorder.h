#ifndef _TowerBorder_H_
#define _TowerBorder_H_

#include "Entity.h"

class Hero;

class TowerBorder :public Entity{
public:
	TowerBorder();
	~TowerBorder();
	CREATE_FUNC(TowerBorder);
	virtual bool init();

	/**Éý¼¶*/
	void upgrade();


	bool isClickMe(Point pos);
	void bindHero(Hero* hero);
	Hero* getHero();
	void deleteHero();

private:
	Hero* m_hero;

};
#endif