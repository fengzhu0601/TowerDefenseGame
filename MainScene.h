#pragma once

#include "cocos2d.h"
#include "GameHUD.h"
#include "WaveEnemy.h"
#include "Wave.h"
#include "BaseAttributes.h"
#include "Creep.h"

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

	void stopSchedule();
	void startSchedule();
private:
	int currentLevel;
	int currentWaveEnemy;
	BaseAttributes* baseAttributes;
private:
	void createSpriteAnimation(const char* name, Vec2 point,Node* node,int frameNum,float time,int tag);

	void addWaypoint();
	void addWaves();//当前关卡所有波次
	//添加敌人到一个波次中，参数有敌人类型和个数
	//!!!这里的容器参数一定要是引用
	void addEnemyToWave(Vector<WaveEnemy*>& enemys,int type,int count);
	WaveEnemy* getWaveEnemy();//获取当前波的类型数量
	Wave* getCurrentWave();
	//添加一波
	void addWave(Vector<WaveEnemy*>& waveArray);
	//添加一个敌人到地图上
	void addTarget();

	void followPath(Ref* sender);

	//游戏循环
	void update(float df);
	void gameLogic(float df);
};
