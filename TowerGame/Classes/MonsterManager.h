#ifndef _MonsterManager_H_
#define _MonsterManager_H_

#include "cocos2d.h"
USING_NS_CC;
class MonsterPosition;
class Monster;
class BasePosition;

class MonsterManager :public Node{
public:
	MonsterManager();
	~MonsterManager();

	static MonsterManager* createWithLevel(int iCurLevel);

	bool initWithLevel(int iCurLevel);

	void createMonster(int iCurLevel);
	int getNotShowMonsterCount();
	MonsterPosition* getMonsterStartPosition();
	MonsterPosition* getMonsterEndPosition();
	Vector<Monster*> getMonsterList();

private:
	Vector<Monster*> m_monsterList;
	Vector<Monster*> m_notShowMonsterList;
	Vector<MonsterPosition*> m_monsterPositionList;
	float m_fShowTimeCount;
	void showMonster(float dt);
};


#endif