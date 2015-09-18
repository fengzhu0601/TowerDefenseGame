#pragma once

#include "cocos2d.h"
#include "WayPoint.h"

USING_NS_CC;

class Creep : public Sprite
{
public:
	enum Tag
	{
		grasshopper1 =0,//蛐蛐
		grasshopper2,
		grasshopper3,
		beetle1,//甲壳虫
		beetle2,
		beetle3,
		ant1,//蚂蚁
		ant2,
		ant3,
		bee1,//蜜蜂
		bee2,
		boos1,
		boos2,
		boos3,
		boos4,
		boos5,
		boos6,
		boos7,
		boos8,
		boos9,
	}creepTag;
public:
	Creep();
	~Creep();
	static Creep* create(int type);
	bool init(int type);
public:
	int m_curHp;//当前血量
	int m_totalHp;
	float m_moveSpeed;//移动速度
	int m_curWaypoint;//当前点
	ProgressTimer* healthBar;//敌人血条
	Sprite* explosionSprite;
	float previousSpeed;//上一次的移动速度
public:
	//获取当前点
	WayPoint* getCurrentWaypoint();
	WayPoint* getNextWaypoint();

	//得到移动时间
	float moveDurScale();
};
