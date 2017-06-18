#ifndef _TowerEditorLayer_H_
#define _TowerEditorLayer_H_

#include "cocos2d.h"
#include "TowerPosition.h"
#include "MonsterPosition.h"
#include "Common.h"
USING_NS_CC;

class TowerEditorLayer :public Layer{
public:
	TowerEditorLayer();
	~TowerEditorLayer();

	CREATE_FUNC(TowerEditorLayer);
	virtual bool init();

	void outputPositionToPlistFile();
	void outputPositionToPlistFile(Vector<BasePosition*> pList, const char * sPath);


	void changeMode();

	int nextLevel();
	int preLevel();

	Vector<BasePosition*> getMonsterPositionList(){ return m_monsterPositionList; };
private:
	Vector<BasePosition*> m_towerPosition;

	int m_iCurLevel;


private:
	void editorTowerPosition(Point pos);

	BasePosition* findExistTowerPosition(Point pos);

	void createTowerPosition(Point pos);

	void deleteTowerPosition(BasePosition* existPos);

	void deleteAllPosition();

	void loadConfigerFile();

	
private:


	EnumPositionType m_enMode;

	Vector<BasePosition*> m_monsterPositionList;

	void editorMonsterPosition(Point pos);

	BasePosition* findExistMonsterPosition(Point pos);

	void createMonsterPosition(Point pos);

	void deleteMonsterPosition(BasePosition* exist);
};
#endif