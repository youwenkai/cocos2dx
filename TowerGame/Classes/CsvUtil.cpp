#include "CsvUtil.h"
#include "StringUtil.h"

CsvUtil* CsvUtil::m_CsvUtil = NULL;

CsvUtil* CsvUtil::getInstance(){
	if (m_CsvUtil == NULL){
		m_CsvUtil = new CsvUtil();
		if (m_CsvUtil && m_CsvUtil->init()){
			m_CsvUtil->autorelease();
			m_CsvUtil->retain();
		}
		else{
			CC_SAFE_DELETE(m_CsvUtil);
			m_CsvUtil = NULL;
		}
	}
	return m_CsvUtil;
}

void CsvUtil::loadFile(const char* sPath){
	//���һ��csv�ļ�����
	CsvData* csvdata = CsvData::create();

	//��ȡ���ݣ����б��浽�б���
	std::string str = FileUtils::getInstance()->getStringFromFile(sPath);
	ValueVector lineData = StringUtil::getInstance()->split(str.c_str(), "\n");

	for (auto value : lineData){
		ValueVector tArr = StringUtil::getInstance()->split(value.asString().c_str(), ",");
		csvdata->addLineData(tArr);
	}

	mCsvMap.insert(sPath, csvdata);
}

const Size CsvUtil::getFileRowColNum(const char* csvFilePath){
	auto csvData = mCsvMap.at(csvFilePath);


	if (csvData == nullptr){
		loadFile(csvFilePath);
		csvData = mCsvMap.at(csvFilePath);
	}

	Size size = csvData->getRowColNum();

	return size;
}

Value CsvUtil::getValue(int iRow, int iCol, const char* csvFilePath){
	auto csvData = mCsvMap.at(csvFilePath);

	if (csvData == nullptr){
		loadFile(csvFilePath);
		csvData = mCsvMap.at(csvFilePath);
	}

	ValueVector rowVector = csvData->getSingleLineData(iRow);
	Value colValue = rowVector.at(iCol);

	return colValue;
}
bool CsvUtil::init(){
	return true;
}
const std::string CsvUtil::get(int iRow, int iCol, const char* cvsFilePath){
	Value colValue = getValue(iRow, iCol, cvsFilePath);

	return colValue.asString();
}

const int CsvUtil::getInt(int iRow, int iCol, const char* cvsFilePath){
	Value colValue = getValue(iRow, iCol, cvsFilePath);
	return colValue.asInt();
}
const int CsvUtil::getFloat(int iRow, int iCol, const char* cvsFilePath){
	Value colValue = getValue(iRow, iCol, cvsFilePath);
	return colValue.asFloat();
}
const int CsvUtil::getBool(int iRow, int iCol, const char* cvsFilePath){
	Value colValue = getValue(iRow, iCol, cvsFilePath);
	return colValue.asBool();
}
const int CsvUtil::findValueInWithLine(const char* chValue, int iValueCol, const char* sFilePath){
	auto csvData = mCsvMap.at(sFilePath);
	
	if (csvData == NULL){
		loadFile(sFilePath);
		csvData = mCsvMap.at(sFilePath);
	}
	int size = csvData->getRowColNum().width;
	for (int i = 0; i < size;i++)
	{
		auto line = csvData->getSingleLineData(i);
		for (auto prop : line){
			if (prop.asString() == chValue){
				return line.at(iValueCol).asInt();
			}
		}
	}
	return -1;
}