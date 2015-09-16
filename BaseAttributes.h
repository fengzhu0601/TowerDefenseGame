#pragma once

#include "cocos2d.h"

USING_NS_CC;

class BaseAttributes : public Ref
{
public:
	BaseAttributes();
	virtual ~BaseAttributes();
	static BaseAttributes* getInstance();
	virtual bool init();
	int towerIndex[10][4];
private:
	static BaseAttributes* m_baseAttributes;
};