#ifndef _TowerBorder_H_
#define _TowerBorder_H_

#include "Entity.h"


class TowerBorder :public Entity{
public:
	TowerBorder();
	~TowerBorder();
	CREATE_FUNC(TowerBorder);
	virtual bool init();

	/**����*/
	void upgrade();
};
#endif