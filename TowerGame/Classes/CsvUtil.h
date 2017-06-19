#ifndef _CsvUtil_H_
#define _CsvUtil_H_

#include "cocos2d.h"
#include "CsvData.h"
using namespace cocos2d;

class CsvUtil :public Ref{
public:
	static CsvUtil* getInstance();
	virtual bool init();

	void loadFile(const char* sPath);

	Value getValue(int iRow, int iCol, const char* csvFilePath);
	const std::string get(int iRow, int iCol, const char* cvsFilePath);
	const int getInt(int iRow, int iCol, const char* cvsFilePath);
	const int getFloat(int iRow, int iCol, const char* cvsFilePath);
	const int getBool(int iRow, int iCol, const char* cvsFilePath);
	const Size getFileRowColNum(const char* csvFilePath);

	const int findValueInWithLine(const char* chValue, int iValueCol, const char* sFilePath);

private:
	static CsvUtil* m_CsvUtil;
	Map<std::string, CsvData*> mCsvMap;
};

#endif