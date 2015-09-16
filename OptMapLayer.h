#pragma once

#include "cocos2d.h"

USING_NS_CC;

class OptMapLayer : public Layer
{
public:
	OptMapLayer();
	~OptMapLayer();
	static Layer* create(int index);
	virtual bool init();

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
private:
	static OptMapLayer* optMapLayer;
	static int mapIndex;

	void addScore(Sprite* bg);
};