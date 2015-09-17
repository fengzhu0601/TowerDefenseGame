#pragma once

#include "cocos2d.h"

USING_NS_CC;

class WaveEnemy : public Node
{
public:
	int m_type;
	int m_count;
	static WaveEnemy* create(int type,int count);
	virtual bool init(int type,int count);
};