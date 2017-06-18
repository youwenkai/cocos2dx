#include "MonsterPosition.h"

MonsterPosition::MonsterPosition(){
	m_pos = Point(0, 0);
	m_isDebug = false;
}
MonsterPosition::~MonsterPosition(){

}
MonsterPosition* MonsterPosition::create(Point pos){
	MonsterPosition* tPos = new MonsterPosition();
	if (tPos && tPos->init(pos)){
		tPos->autorelease();
	}
	else{
		CC_SAFE_DELETE(tPos);
	}

	return tPos;
}
MonsterPosition* MonsterPosition::create(Point pos, bool Debug){
	MonsterPosition* tPos = new MonsterPosition();
	if (tPos && tPos->init(pos, Debug)){
		tPos->autorelease();
	}
	else{
		CC_SAFE_DELETE(tPos);
	}

	return tPos;
}

bool MonsterPosition::init(Point pos){
	bool bRet = false;
	do 
	{
		setPos(pos);
		bRet = true;

	} while (0);

	return bRet;
}
bool MonsterPosition::init(Point pos, bool isDebug){
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!init(pos));
		m_isDebug = isDebug;

		bRet = true;


	} while (0);


	return bRet;
}

void MonsterPosition::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	if (m_isDebug)
	{
		_customCommand.init(_globalZOrder);
		_customCommand.func = CC_CALLBACK_0(MonsterPosition::onDraw, this, transform, flags);
		renderer->addCommand(&_customCommand);
	}
}

void MonsterPosition::onDraw(const Mat4& transform, uint32_t flags){
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);

	glLineWidth(4);


	DrawPrimitives::drawCircle(m_pos, MONSTER_RADIUS, 360, 20, false);
	glLineWidth(1);

	kmGLPopMatrix();
}

bool MonsterPosition::isClickMe(Point pos){
	Point srcPos = Point(m_pos.x - MONSTER_RADIUS, m_pos.y + MONSTER_RADIUS);
	Point destPos = Point(m_pos.x + MONSTER_RADIUS, m_pos.y - MONSTER_RADIUS);

	if (pos.x >= srcPos.x && pos.x <= destPos.x && pos.y <= srcPos.y && pos.y >= destPos.y){
		return true;
	}

	return false;
}