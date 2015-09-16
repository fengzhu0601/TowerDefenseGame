#include "OptMap.h"
#include "OptMapLayer.h"
#include "DataModel.h"
#include "Tools.h"
#include "BaseAttributes.h"
#include "GameConfig.h"

using namespace cocos2d::ui;

OptMap::OptMap()
{
	passCount = 1;
	m_curpage = 1;
	m_page = 1;
	scrollview = nullptr;
}

OptMap::~OptMap()
{

}

Scene* OptMap::createScene()
{
	auto scene = Scene::create();
	auto layer = OptMap::create();
	scene->addChild(layer);
	return scene;
}

bool OptMap::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	auto m = DataModel::getInstance();
	if (m->isHardMode)//专家模式
	{
		m_page = 100;
	}
	else//简单模式
	{
		m_page = 10;
	}

	addMenuTitle(0);

	auto winSize = Director::getInstance()->getWinSize();

	auto mapPass = Sprite::create("optmap_pass.png");
	mapPass->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
	mapPass->setPosition(Vec2(winSize.width/2-10,winSize.height-18-80));
	this->addChild(mapPass);

	auto optmapFrame = Sprite::create("optmap_frame.png");
	optmapFrame->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	optmapFrame->setPosition(Vec2(winSize.width/2,winSize.height-18-80));
	this->addChild(optmapFrame);

	//auto pLabel = Label::createWithBMFont("font.fnt","aaa");
    auto pLabel = Label::createWithTTF("", "fonts/Marker Felt.ttf", 26);
	pLabel->setPosition(Vec2(optmapFrame->getPositionX()+optmapFrame->getContentSize().width/2,winSize.height-18-80));
	pLabel->setTag(1);
	this->addChild(pLabel);
	//this->setPassCount(passCount);
	this->setPassCount(m_curpage);

	
	auto mapBg = Sprite::create("optmap_bg.png");
	mapBg->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	mapBg->setPosition(Vec2(0,winSize.height/2-20));
	this->addChild(mapBg);

	m->curPassCount = Tools::getCurPass(m->isHardMode);
	m->maxUnlock = Tools::getMaxUnlock(m->isHardMode);

	//添加返回菜单
	addMenuBack();

	//滚动屏幕
	scrollview = ScrollView::create();
	//scrollview->setBackGroundColor(Color3B::GREEN);
	//scrollview->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
	//scrollview->scrollToPercentHorizontal();
	for (int i=0;i<kMaxPass;++i)
	{
		auto layer = OptMapLayer::create(i);
		//CCLOG("%f,%f",layer->getContentSize().width,layer->getContentSize().height);
		layer->setPosition(Vec2(i*layer->getContentSize().width/2 + winSize.width/2,winSize.height/2 - 80));
		scrollview->addChild(layer);
	}
	scrollview->setDirection(ScrollView::Direction::HORIZONTAL);//水平滚动
	scrollview->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	scrollview->setPosition(Vec2(winSize.width/2,winSize.height/2-20));

	scrollview->setBounceEnabled(true);
	scrollview->setContentSize(mapBg->getContentSize());
	auto innerWidth = scrollview->getContentSize().width + scrollview->getContentSize().width/2 * (10 - 1);
	auto innerHeight = scrollview->getContentSize().height;
	scrollview->setInnerContainerSize(Size(innerWidth,innerHeight));
	//scrollview->scrollToPercentBothDirection(Vec2(10, 0), 1, true);
	scrollview->setTouchEnabled(false);

	//scrollview->addEventListener(CC_CALLBACK_1(OptMap::scrollEvent,this));
	this->addChild(scrollview);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(OptMap::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(OptMap::onTouchMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(OptMap::onTouchEnded,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);

	//Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener.clone(),this);


	initTower(0);

	return true;
}

void OptMap::menuBack(Ref* pSender)
{

}

void OptMap::scrollEvent(Ref* pSender)
{
//	CCLOG("scrollEvent done");
//	int curPage = 1;

//	initTower(curPage);
}

void OptMap::initTower(int tag)
{
	auto winSize = Director::getInstance()->getWinSize();
	auto baseAttributes = BaseAttributes::getInstance();

	const char* images[] = {
		"tower_persimmon.png",
		"tower_pineapple.png",
		"tower_pear.png",
		"tower_durian.png",
		"tower_mushrooms.png",
		"tower_monster.png",
		"tower_more.png",
		"tower_rocket.png",
		"tower_unkown.png",
	};
	int size = sizeof(baseAttributes->towerIndex[tag])/sizeof(baseAttributes->towerIndex[tag][0]);
	CCLOG("size:%d",size);
	CCLOG("tag:%d",tag);

	for (int i=0;i< size;i++)
	{
		auto mapBg = Sprite::create("optmap_tower_bg.png");
		mapBg->setPosition(Vec2(
			winSize.width/2-115+75*i,
			mapBg->getContentSize().height/2+20));

		auto texture = Director::getInstance()->getTextureCache()->addImage(images[baseAttributes->towerIndex[tag][i]]);
		auto frame0 = SpriteFrame::createWithTexture(texture,
			Rect(0,0,
			(tag==kMaxPass-1)?texture->getContentSize().width:texture->getContentSize().width/2,//最后一张?要取整张
			texture->getContentSize().height));
		auto sprite = Sprite::createWithSpriteFrame(frame0);
		sprite->setScale(mapBg->getContentSize().height / sprite->getContentSize().height);
		sprite->setAnchorPoint(Vec2::ZERO);
		mapBg->addChild(sprite);

		this->addChild(mapBg);
	}
}

void OptMap::setPassCount(int count)
{
	Value cPass(count);
	auto pLabel = (Label*)this->getChildByTag(1);
	pLabel->setString(cPass.asString());
}

bool OptMap::onTouchBegan(Touch *touch, Event *unused_event)
{
	CCLOG("touchbegan");
	beginTouchPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
	return true;
}
void OptMap::onTouchMoved(Touch *touch, Event *unused_event)
{

}
void OptMap::onTouchEnded(Touch *touch, Event *unused_event)
{
	CCLOG("touchend");
	auto endPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
	float distance = endPoint.x - beginTouchPoint.x;
	if (fabs(distance) > TOUCH_DISTANCE)
	{
		CCLOG("adjust");
		adjustScrollView(distance);
	}
}

void OptMap::adjustScrollView(float offset)
{
	auto winSize = Director::getInstance()->getWinSize();
	if (offset < 0)
	{
		m_curpage++;
	}
	else
	{
		m_curpage--;
	}

	if (m_curpage < 1)
	{
		m_curpage = 1;
	}

	if (m_curpage > m_page)
	{
		m_curpage = m_page;
	}

	//auto adjustPos = Vec2(-(winSize.width/2)*(m_curpage-1),0);
	//auto adjustX = winSize.width/2*(m_curpage-1);
	//scrollview->scrollToPercentHorizontal((adjustX/(scrollview->getInnerContainerSize().width))*100,1.0f,true);
	CCLOG("%d,%d",m_curpage,m_page);
	CCLOG("%d",(m_curpage-1)*100/(m_page-1));
	scrollview->setBounceEnabled(true);
	scrollview->scrollToPercentHorizontal((m_curpage-1)*100/(m_page-1),1.0f,true);
	this->setPassCount(m_curpage);
	this->initTower(m_curpage - 1);
	//scrollview->scrollToPercentHorizontal(40,1.0f,true);
}
