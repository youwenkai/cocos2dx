#ifndef _TowerEditorLayer_H_
#define _TowerEditorLayer_H_

#include "cocos2d.h"
#include "TowerPosition.h"
USING_NS_CC;

class TowerEditorLayer :public Layer{
public:
	TowerEditorLayer();
	~TowerEditorLayer();

	CREATE_FUNC(TowerEditorLayer);
	virtual bool init();

	void outputPositionToPlistFile();

private:
	Vector<BasePosition*> m_towerPosition;

	int m_iCurLevel;
	
	void editorTowerPosition(Point pos);

	BasePosition* findExistTowerPosition(Point pos);

	void createTowerPosition(Point pos);

	void deleteTowerPosition(BasePosition* existPos);

	void deleteAllPosition();
};
#endif