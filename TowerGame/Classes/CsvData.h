#ifndef _CsvData_H_
#define _CsvData_H_

#include "cocos2d.h"
USING_NS_CC;

class CsvData :public Ref{
public:
	CREATE_FUNC(CsvData);

	virtual bool init();

	void addLineData(ValueVector lineData);
	ValueVector getSingleLineData(int iLine);
	Size getRowColNum();

private:
	ValueVector m_allLineVec;
	int m_iColNum;
};

#endif