#ifndef _PositionLoadUtil_H_
#define _PositionLoadUtil_H_

#include "cocos2d.h"
#include "TowerPosition.h"
#include "MonsterPosition.h"
#include "Common.h"
USING_NS_CC;

class PositionLoadUtil :public Node{
public:
	static PositionLoadUtil* getInstance();
	virtual bool init();


	Vector<BasePosition*> loadPositionWithFile(
		const char* sFilePath,
		EnumPositionType posType,
		Node* container,
		int iLevel,
		bool isDebug);

private:
	static PositionLoadUtil* m_positionLoadUtil;
};


#endif