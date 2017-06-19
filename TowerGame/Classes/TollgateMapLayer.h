#ifndef _TollgateMapLayer_H_
#define _TollgateMapLayer_H_

#include "cocos2d.h"
USING_NS_CC;

class TollgateMapLayer :public Layer{
public:
	TollgateMapLayer();
	~TollgateMapLayer();

	CREATE_FUNC(TollgateMapLayer);

	virtual bool init();

private:
	int m_iCurLevel;

	void loadConfig();
};

#endif