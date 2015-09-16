#pragma once

#include "cocos2d.h"

USING_NS_CC;

class SuperclassScene : public Layer
{
public:
	void addMenuTitle(int index);
	void addMenuBack();
	virtual void menuBack(Ref* pSender);
};