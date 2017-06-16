#ifndef _TowerPosition_H_
#define _TowerPosition_H_

#include "BasePosition.h"

#define RADIUS 32
class TowerPosition :public BasePosition{
public:
	TowerPosition();
	~TowerPosition();

	static TowerPosition* create(Point pos);
	static TowerPosition* create(Point pos, bool isDebug);

	bool init(Point pos);
	bool init(Point pos, bool isDebug);

	virtual bool isClickMe(Point pos)override;

	void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);


private:

	void onDraw(const Mat4& transform, uint32_t flags);

	CustomCommand _customCommand;
};

#endif