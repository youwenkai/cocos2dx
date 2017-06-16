#include "TowerPosition.h"

TowerPosition::TowerPosition(){
	m_pos = Point(0, 0);
	m_isDebug = false;
}
TowerPosition::~TowerPosition(){

}
TowerPosition* TowerPosition::create(Point pos){
	TowerPosition* tPos = new TowerPosition();
	if (tPos && tPos->init(pos)){
		tPos->autorelease();
	}
	else{
		CC_SAFE_DELETE(tPos);
	}
	return tPos;
}
TowerPosition* TowerPosition::create(Point pos,bool isDebug){
	TowerPosition* tPos = new TowerPosition();
	if (tPos && tPos->init(pos,isDebug)){
		tPos->autorelease();
	}
	else{
		CC_SAFE_DELETE(tPos);
	}
	return tPos;
}

bool TowerPosition::init(Point pos){
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!BasePosition::init(pos));
		bRet = true;
	} while (0);

	return bRet;
}

bool TowerPosition::init(Point pos, bool isDebug){
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!BasePosition::init(pos, isDebug));
		bRet = true;
	} while (0);

	return bRet;
}

void TowerPosition::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	//log(">>>>>>>>>>>>>>>>>> func draw()");
	if (m_isDebug){
		_customCommand.init(_globalZOrder);
		_customCommand.func = CC_CALLBACK_0(TowerPosition::onDraw, this, transform, flags);
		renderer->addCommand(&_customCommand);
	}
}

void TowerPosition::onDraw(const Mat4& transform, uint32_t flags){
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);

	glLineWidth(5.0f);

	Point srcPos = Point(m_pos.x - RADIUS, m_pos.y + RADIUS);
	Point destPos = Point(m_pos.x + RADIUS, m_pos.y - RADIUS);

	DrawPrimitives::drawRect(srcPos, destPos);

	glLineWidth(1);
	kmGLPopMatrix();
}

bool TowerPosition::isClickMe(Point pos){
	Point srcPos = Point(m_pos.x - RADIUS, m_pos.y + RADIUS);
	Point destPos = Point(m_pos.x + RADIUS, m_pos.y - RADIUS);

	if (pos.x >= srcPos.x && pos.x <= destPos.x && pos.y <= srcPos.y && pos.y >= destPos.y){
		return true;
	}

	return false;
}