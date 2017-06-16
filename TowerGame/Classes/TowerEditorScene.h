#ifndef _TowerEditorScene_H_
#define _TowerEditorScene_H_


#include "cocos2d.h"
USING_NS_CC;

class TowerEditorScene :public Layer{
public:
	TowerEditorScene();
	~TowerEditorScene();

	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(TowerEditorScene);
};
#endif