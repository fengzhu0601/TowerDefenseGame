#include "Wave.h"

Wave* Wave::create(Vector<WaveEnemy*> waveArray)
{
	Wave* myWave = new Wave();
	if (myWave && myWave->init(waveArray))
	{
		myWave->autorelease();
		return myWave;
	}
	else
	{
		delete myWave;
		myWave = nullptr;
	}
	return myWave;
}

bool Wave::init(Vector<WaveEnemy*> waveArray)
{
	if (!Node::init())
	{
		return false;
	}
	wavesArray = waveArray;
	return true;
}