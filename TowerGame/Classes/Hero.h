#ifndef _Hero_H_
#define _Hero_H_

#include "Entity.h"

class Hero :public Entity{
public:
	Hero();
	~Hero();


	static Hero* create(Sprite* sprite);

	virtual bool init(Sprite* sprite);

	/**����Ӣ��ID,�������ļ��ж�ȡӢ������*/
	static Hero* createFromCsvFileByID(int iHeroID);
	bool initFromCsvFileByID(int iHeroID);

	//����������
	CC_SYNTHESIZE(int, m_iBaseAtk, iBaseAtk);
	//��ǰ������
	CC_SYNTHESIZE(int, m_iCurAtk, iCurAtk);
	//�������
	CC_SYNTHESIZE(int, m_iAtkSpeed, iAtkSpeed);
	//������Χ
	CC_SYNTHESIZE(int, m_iAthRange, iAtkRange);
	//�������Ļ���ֵ
	CC_SYNTHESIZE(int, m_iUpgradeCostBase, iUpgradeCostBase);
	//���������ӳ�ϵ��
	CC_SYNTHESIZE(int, m_fUpgradeAtkBase, fUpgradeAtkBase);

	//����Ӣ��
	void upGrade();
};

#endif
