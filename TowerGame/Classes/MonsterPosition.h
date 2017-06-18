#ifndef _MonsterPosition_H_
#define _MonsterPosition_H_

#include "BasePosition.h"


#define MONSTER_RADIUS 10
class MonsterPosition :public BasePosition{
public:
	MonsterPosition();
	~MonsterPosition();

	static MonsterPosition* create(Point pos);
	static MonsterPosition* create(Point pos, bool Debug);


    bool init(Point pos);
	bool init(Point pos, bool isDebug);


	virtual bool isClickMe(Point pos);

	void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);

private:
	void onDraw(const Mat4& transform, uint32_t flags);
	CustomCommand _customCommand;
};


#endif
