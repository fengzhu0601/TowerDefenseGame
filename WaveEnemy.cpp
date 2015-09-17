#include "WaveEnemy.h"

WaveEnemy* WaveEnemy::create(int type,int count)
{
	WaveEnemy* myWaveEnemy = new WaveEnemy();
	if (myWaveEnemy && myWaveEnemy->init(type,count))
	{
		myWaveEnemy->autorelease();
		return myWaveEnemy;
	}
	else
	{
		delete myWaveEnemy;
		myWaveEnemy = nullptr;
	}
	return myWaveEnemy;
}

bool WaveEnemy::init(int type,int count)
{
	if (!Node::init())
	{
		return false;
	}
	m_count = count;
	m_type = type;
	return true;
}