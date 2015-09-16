#pragma once

#include "cocos2d.h"
#include "GameHUD.h"

USING_NS_CC;

class MainScene : public Layer
{
public:
	MainScene();
	~MainScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MainScene);

	TMXTiledMap* tileMap;
	TMXLayer* m_mapLayerTower;
};
