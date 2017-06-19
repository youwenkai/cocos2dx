#include "StringUtil.h"

StringUtil* StringUtil::instance = NULL;

StringUtil* StringUtil::getInstance(){
	if (instance == NULL){
		instance = new StringUtil();
		if (instance && instance->init()){
			instance->autorelease();
			instance->retain();
		}
		else{
			CC_SAFE_DELETE(instance);
		}
	}

	return instance;
}

bool StringUtil :: init(){
	return true;
}

ValueVector StringUtil::split(const char* srcStr, const char* sSep){
	ValueVector stringList;

	int size = strlen(srcStr);

	//将数据转换为字符创对象
	Value str = Value(srcStr);

	int startIndex = 0;
	int endIndex = 0;

	endIndex = str.asString().find(sSep);

	std::string lineStr;

	while (endIndex > 0){
		lineStr = str.asString().substr(startIndex, endIndex);
		stringList.push_back(Value(lineStr));
		str = Value(str.asString().substr(endIndex + 1, size));

		endIndex = str.asString().find(sSep);
	}

	if (str.asString().compare("") != 0){
		stringList.push_back(Value(str.asString()));
	}

	return stringList;
}