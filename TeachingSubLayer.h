#pragma once

#include "cocos2d.h"

USING_NS_CC;

class TeachingSubLayer : public Layer
{
public:
	TeachingSubLayer();
	~TeachingSubLayer();

	static TeachingSubLayer* create(int type,int index);//type����0:teaching,1:enemy,2:tower
	virtual bool init();
private:
	static TeachingSubLayer* optMapLayer;
	static int helpType,helpIndex;
};