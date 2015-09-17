#pragma once

#include "cocos2d.h"
#include "WayPoint.h"
#include "Wave.h"

USING_NS_CC;

class DataModel : public Ref
{
public:
	~DataModel();
	static DataModel* getInstance();

	void initDataModel();
public:
	int curPassCount;//ͨ����
	bool isHardMode;//�Ƿ�ר��ģʽ

	Layer* _gameLayer;//��Ϸ��
	Layer* _gameHUDLayer;//����

	static Vector<WayPoint*> m_wayPoints;
	static Vector<Wave*> m_waves;

	static int maxUnlock;
	static bool isMusic;
	static bool isSound;

	static bool isShowTeaching;
	static bool isFirstGame;
	static bool isActivatingGame;

	int propsMedalCount,propsDoubleCount,propsLightningcount,propsBlizzardCount;//����

private:
	DataModel();
	static DataModel* m_pInstance;
};