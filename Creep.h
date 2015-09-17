#pragma once

#include "cocos2d.h"
#include "WayPoint.h"

USING_NS_CC;

class Creep : public Sprite
{
public:
	enum Tag
	{
		grasshopper1 =0,//����
		grasshopper2,
		grasshopper3,
		beetle1,//�׿ǳ�
		beetle2,
		beetle3,
		ant1,//����
		ant2,
		ant3,
		bee1,//�۷�
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
	int m_curHp;//��ǰѪ��
	float m_moveSpeed;//�ƶ��ٶ�
	int m_curWaypoint;//��ǰ��
public:
	//��ȡ��ǰ��
	WayPoint* getCurrentWaypoint();
};
