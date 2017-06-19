#ifndef _TollgateScene_H_
#define _TollgateScene_H_

#define TAG_MAP_LAYER 1  //关卡地图图层TAG
#define TAG_MAP_LAYER 2  //关卡地图图层TAG

#include "cocos2d.h"
USING_NS_CC;

class TollgateScene :Layer{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(TollgateScene);
};

#endif