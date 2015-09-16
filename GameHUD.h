#pragma once

#include "cocos2d.h"

USING_NS_CC;

class GameHUD : public Layer
{
public:
	static GameHUD* getInstance();
	virtual bool init();
private:
	GameHUD();
	~GameHUD();
	static GameHUD* m_Instance;
};