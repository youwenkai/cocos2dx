#ifndef _TowerEditorOperateLayer_H_
#define _TowerEditorOperateLayer_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "TowerEditorLayer.h"

USING_NS_CC;
using namespace ui;


class TowerEditorOperateLayer :public Layer{
public:
	TowerEditorOperateLayer();
	~TowerEditorOperateLayer();

	static TowerEditorOperateLayer* create(TowerEditorLayer* layer);
	virtual bool init(TowerEditorLayer* layer);

private:
	TowerEditorLayer* m_editorLayer;

private:
	void outputBtnOnClick(Ref*, ui::TouchEventType type);
};
#endif