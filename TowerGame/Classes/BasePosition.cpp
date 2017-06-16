#include "BasePosition.h"

BasePosition::BasePosition(){
	m_isDebug = false;
	m_pos = Point(0, 0);
}
BasePosition::~BasePosition(){

}

BasePosition* BasePosition::create(Point pos){
	BasePosition* tPos = new BasePosition();
	if (tPos && tPos->init(pos)){
		tPos->autorelease();
	}
	else{
		CC_SAFE_DELETE(tPos);
	}
	return tPos;
}
BasePosition* BasePosition::create(Point pos, bool Debug){
	BasePosition* tPos = new BasePosition();
	if (tPos && tPos->init(pos, Debug)){
		tPos->autorelease();
	}
	else{
		CC_SAFE_DELETE(tPos);
	}
	return tPos;
}

bool BasePosition::init(Point pos){
	bool bRet = false;
	do{
		setPos(pos);
		bRet = true;
	} while (0);

	return bRet;
}

bool BasePosition::init(Point pos, bool Debug){
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!init(pos));

		m_isDebug = Debug;

		bRet = true;
	} while (0);

	return bRet;
}

bool BasePosition::isClickMe(Point pos){
	return false;
}
void BasePosition::setDebug(bool isDebug){
	m_isDebug = isDebug;
}

