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
	void addWaves();//��ǰ�ؿ����в���
	//��ӵ��˵�һ�������У������е������ͺ͸���
	//!!!�������������һ��Ҫ������
	void addEnemyToWave(Vector<WaveEnemy*>& enemys,int type,int count);
	WaveEnemy* getWaveEnemy();//��ȡ��ǰ������������
	Wave* getCurrentWave();
	//���һ��
	void addWave(Vector<WaveEnemy*>& waveArray);
	//���һ�����˵���ͼ��
	void addTarget();

	void followPath(Ref* sender);

	//��Ϸѭ��
	void update(float df);
	void gameLogic(float df);
};
