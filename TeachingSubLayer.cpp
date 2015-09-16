#include "TeachingSubLayer.h"

TeachingSubLayer* TeachingSubLayer::optMapLayer = nullptr;
int TeachingSubLayer::helpIndex;
int TeachingSubLayer::helpType;

TeachingSubLayer::TeachingSubLayer()
{

}

TeachingSubLayer::~TeachingSubLayer()
{

}

TeachingSubLayer* TeachingSubLayer::create(int type,int index)
{
	optMapLayer = new TeachingSubLayer();
	//要在初始化之前赋值
	helpType = type;
	helpIndex = index;
	if (optMapLayer && optMapLayer->init())
	{
		optMapLayer->autorelease();
		return optMapLayer;
	}
	else
	{
		delete optMapLayer;
		optMapLayer = nullptr;
	}
	return optMapLayer;
}

bool TeachingSubLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto winSize = Director::getInstance()->getWinSize();
	
	this->setTag(helpIndex);

	char mapName[15];

	switch (helpType)//帮助类型：0，1，2
	{
	case 0:
		sprintf(mapName,"teaching%d.png",helpIndex);
		break;
	case 1:
		sprintf(mapName,"enemy%d.png",helpIndex);
		break;
	case 2:
		sprintf(mapName,"tower%d.png",helpIndex);
		break;
	default:
		break;
	}
	auto bg = Sprite::create(mapName);
	bg->setPosition(Vec2(winSize.width/2,winSize.height/2));

	this->addChild(bg,0,1);

	return true;
}
