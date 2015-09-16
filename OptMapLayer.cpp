#include "OptMapLayer.h"
#include "DataModel.h"
#include "GameConfig.h"
#include "Tools.h"
#include "TeachingLayer.h"

OptMapLayer* OptMapLayer::optMapLayer = nullptr;
int OptMapLayer::mapIndex = 0;

OptMapLayer::OptMapLayer()
{

}

OptMapLayer::~OptMapLayer()
{

}

Layer* OptMapLayer::create(int index)
{
	mapIndex = index;
	optMapLayer = new OptMapLayer();
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
	return nullptr;
}

bool OptMapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->setTag(mapIndex);

	auto m = DataModel::getInstance();
	int maxUnlock = m->maxUnlock;

	CCLOG("maxunlock:%d",maxUnlock);
	CCLOG("mapIndex:%d",mapIndex);
	char mapName[9];
	Sprite* bg;

	if (m->isHardMode)//专家模式
	{
		sprintf(mapName,"map%d.png",mapIndex+10);
		bg = Sprite::create(mapName);
	}
	else//普通模式
	{
		if ((mapIndex+1)<maxUnlock)//已经通关的
		{
			sprintf(mapName,"map%d.png",20);
			bg = Sprite::create(mapName);
		}
		else if ((mapIndex+1) == maxUnlock)//当前关
		{
			sprintf(mapName,"map%d.png",mapIndex);
			bg = Sprite::create(mapName);
		}
		else//未通关
		{
			sprintf(mapName,"map%d.png",mapIndex);
			bg = Sprite::create(mapName);
			//如果不是最后一张图就梦黑
			if (mapIndex != kMaxPass - 1 )
			{
				bg->setColor(Color3B(0,0,0));
			}
		}
	}
	this->addChild(bg,0,1);

	this->addScore(bg);
	//this->setContentSize(bg->getContentSize());
	//如果是专家模式添加梦黑层
	if (m->isHardMode)
	{

	}
	auto lock = Sprite::create("optmap_lock.png");
	lock->setPosition(Vec2(bg->getContentSize().width/2,bg->getContentSize().height/2));
	bg->addChild(lock,0,2);

	if (getTag() < DataModel::getInstance()->maxUnlock)
	{
		lock->setVisible(false);
	}

	//触摸相应
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(false);
	listener->onTouchBegan = CC_CALLBACK_2(OptMapLayer::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(OptMapLayer::onTouchMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(OptMapLayer::onTouchEnded,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,bg);
	CCLOG("bg::%f,%f",bg->getContentSize().width,bg->getContentSize().height);

	return true;
}

//添加初试成绩
void OptMapLayer::addScore(Sprite* bg)
{
	auto m = DataModel::getInstance();
	int fScore = Tools::getScore(getTag(),m->isHardMode);
	CCLOG("fScore:%d",fScore);//0

	//--银杯
	Sprite* fScoreSprite;
	Texture2D* texture;
	SpriteFrame* frame;
	Sprite* starSprite;

	if (!m->isHardMode)
	{
		if (fScore == 4)
		{
			fScoreSprite = Sprite::create("score_silver1.png");
		}
		else
		{
			fScoreSprite = Sprite::create("score_silver0.png");
		}
		fScoreSprite->setAnchorPoint(Vec2::ZERO);
		fScoreSprite->setPosition(Vec2(10,10));
		texture = Director::getInstance()->getTextureCache()->addImage("star.png");
		frame = SpriteFrame::createWithTexture(texture,
			Rect((texture->getContentSize().width/4)*(fScore),0,
			texture->getContentSize().width/4,
			texture->getContentSize().height));
		starSprite = Sprite::createWithSpriteFrame(frame);
		starSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		starSprite->setPosition(Vec2(fScoreSprite->getContentSize().width/2,6));
		fScoreSprite->addChild(starSprite);
		bg->addChild(fScoreSprite);
	}
	else
	{
		if (fScore == 4)
		{
			fScoreSprite = Sprite::create("score_gold1.png");
		}
		else
		{
			fScoreSprite = Sprite::create("score_gold0.png");
		}
		fScoreSprite->setAnchorPoint(Vec2::ZERO);
		fScoreSprite->setPosition(Vec2(10,10));
		texture = Director::getInstance()->getTextureCache()->addImage("star.png");
		frame = SpriteFrame::createWithTexture(texture,
			Rect((texture->getContentSize().width/4)*(fScore),0,
			texture->getContentSize().width/4,
			texture->getContentSize().height));
		starSprite = Sprite::createWithSpriteFrame(frame);
		starSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		starSprite->setPosition(Vec2(fScoreSprite->getContentSize().width/2,6));
		fScoreSprite->addChild(starSprite);
		bg->addChild(fScoreSprite);
	}
}

bool OptMapLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	auto target = static_cast<Sprite*>(unused_event->getCurrentTarget());
	auto lock = static_cast<Sprite*>(target->getChildByTag(2));

	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	if (rect.containsPoint(locationInNode))
	{
		if (lock->isVisible())
		{
			CCLOG("lock");
		}
		else
		{
			CCLOG("unlock");
			auto m = DataModel::getInstance();
			m->curPassCount = getTag();
			if (m->curPassCount == 0)
			{
				//教学
				auto scene = TeachingLayer::createScene();
				Director::getInstance()->replaceScene(scene);
			}
			else
			{
				//跳过教学
			}
		}

		return true;
	}
	return false;
}
void OptMapLayer::onTouchMoved(Touch *touch, Event *unused_event)
{

}
void OptMapLayer::onTouchEnded(Touch *touch, Event *unused_event)
{

}
