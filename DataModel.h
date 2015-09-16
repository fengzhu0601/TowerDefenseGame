#pragma once

#include "cocos2d.h"

USING_NS_CC;

class DataModel : public Ref
{
public:
	~DataModel();
	static DataModel* getInstance();

	void initDataModel();
public:
	int curPassCount;//通关数
	bool isHardMode;//是否专家模式

	Layer* _gameLayer;//游戏层
	Layer* _gameHUDLayer;//面板层

	static int maxUnlock;
	static bool isMusic;
	static bool isSound;

	static bool isShowTeaching;
	static bool isFirstGame;
	static bool isActivatingGame;

	int propsMedalCount,propsDoubleCount,propsLightningcount,propsBlizzardCount;//道具

private:
	DataModel();
	static DataModel* m_pInstance;
};