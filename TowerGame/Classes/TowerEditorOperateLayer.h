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

	void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);

private:
	TowerEditorLayer* m_editorLayer;
	CustomCommand _customCommand;

private:
	void outputBtnOnClick(Ref*, ui::TouchEventType type);

	void changeEditorPositionType(Ref*, ui::TouchEventType type);

	void nextLevel(Ref*, ui::TouchEventType type);

	void preLevel(Ref*, ui::TouchEventType type);

	void onDraw(const Mat4& transform, uint32_t flags);
};
#endif