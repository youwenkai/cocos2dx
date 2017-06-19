#ifndef _Entity_H_
#define _Entity_H_

#include "cocos2d.h"
USING_NS_CC;

class Entity :public Node{
public:
	Entity();
	~Entity();


	void bindSprite(Sprite* sprite);
	Sprite* getSprite();

	void hurtMe(int iHurtValue);
	bool isDead();

protected:
	virtual void onDead();
	virtual void onBindSprite();
	virtual void onHurt(int iHurtValue);

private:
	Sprite* m_sprite;

	CC_SYNTHESIZE(int, m_id, ID);
	CC_SYNTHESIZE(int, m_iModelID, iModeID);
	CC_SYNTHESIZE(std::string, m_sName, sName);
	CC_SYNTHESIZE(int, m_iHP, iHP);
	CC_SYNTHESIZE(int, m_iDefense, iDefense);
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);
	CC_SYNTHESIZE(int, m_iLevel, iLevel);
	bool m_isDead;

};
#endif