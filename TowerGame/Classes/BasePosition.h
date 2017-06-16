#ifndef _BasePosition_H_
#define _BasePosition_H_


#include "cocos2d.h"
USING_NS_CC;

class BasePosition :public Layer{
public:
	BasePosition();
	~BasePosition();

	static BasePosition* create(Point pos);
	static BasePosition* create(Point pos, bool Debug);

	bool init(Point pos);
	bool init(Point pos, bool Debug);

	CC_SYNTHESIZE(Point, m_pos, Pos);

	virtual bool isClickMe(Point pos);

	void setDebug(bool isDebug);
protected:
	bool m_isDebug;
};
#endif