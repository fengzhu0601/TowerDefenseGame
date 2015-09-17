#pragma once

#include "cocos2d.h"
#include "WaveEnemy.h"

USING_NS_CC;

class Wave : public Node
{
public:
	static Wave* create(Vector<WaveEnemy*> waveArray);
	bool init(Vector<WaveEnemy*> waveArray);
	Vector<WaveEnemy*> wavesArray;
};