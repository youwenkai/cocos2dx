#ifndef _TollgateScene_H_
#define _TollgateScene_H_

#define TAG_MAP_LAYER 1  //�ؿ���ͼͼ��TAG
#define TAG_MAP_LAYER 2  //�ؿ���ͼͼ��TAG

#include "cocos2d.h"
USING_NS_CC;

class TollgateScene :Layer{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(TollgateScene);
};

#endif