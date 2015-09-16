#include "TeachingLayer.h"
#include "ui/UIScrollView.h"
#include "TeachingSubLayer.h"
#include "GameConfig.h"
#include "MainScene.h"

using namespace cocos2d::ui;

TeachingLayer::TeachingLayer()
{
	curPage = 0;
	pageView = nullptr;
}

TeachingLayer::~TeachingLayer()
{

}

Scene* TeachingLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = TeachingLayer::create();
	scene->addChild(layer);
	return scene;
}

bool TeachingLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//testPageView();
	addLayer(0);
	//--添加选项，滚页小圆点
	addRadioMenu();
	return true;
}

void TeachingLayer::addRadioMenu()
{
	auto winSize = Director::getInstance()->getWinSize();
	auto texture = Director::getInstance()->getTextureCache()->addImage("teaching_page.png");
	auto spriteFrameNormal = SpriteFrame::createWithTexture(texture,
		Rect(0,0,texture->getContentSize().width/2,texture->getContentSize().height));
	auto spriteFramePressed = SpriteFrame::createWithTexture(texture,
		Rect(texture->getContentSize().width/2,0,texture->getContentSize().width/2,texture->getContentSize().height));
	//auto pMenuItem0 = MenuItemSprite::create(Sprite::createWithSpriteFrame(spriteFrameNormal),
	//	Sprite::createWithSpriteFrame(spriteFramePressed),
	//	CC_CALLBACK_1(TeachingLayer::menuSelect,this));
	//pMenuItem0->setTag(0);

	auto radioMenu = Menu::create();
	for (int i=0;i<4;i++)
	{
		auto pMenuItem = MenuItemSprite::create(Sprite::createWithSpriteFrame(spriteFrameNormal),
			Sprite::createWithSpriteFrame(spriteFramePressed),
			CC_CALLBACK_1(TeachingLayer::menuSelect,this));
		pMenuItem->setTag(i);
		//pMenuItem->setPosition(Vec2(winSize.width/2+pMenuItem->getContentSize().width*i,16));
		radioMenu->addChild(pMenuItem);
	}
	//radioMenu->setAnchorPoint(Vec2::ZERO);
	//radioMenu->setPosition(Vec2::ZERO);
	radioMenu->setPosition(Vec2(winSize.width/2,16));
	radioMenu->alignItemsHorizontallyWithPadding(40);
	this->addChild(radioMenu,2,kTagRadioMenu);

	dynamic_cast<MenuItemSprite*>(radioMenu->getChildByTag(0))->selected();
}

//pageview的用法
void TeachingLayer::addLayer(int index)
{
	auto winSize = Director::getInstance()->getWinSize();
	pageView = PageView::create();
	//一定要设置大小，不然看不见
	pageView->setContentSize(winSize);
	pageView->setBackGroundColor(Color3B::GREEN);
	pageView->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
	pageView->removeAllPages();
	pageView->setPosition(Vec2::ZERO);
	if (index == 0)
	{
		for (int i=0;i<4;++i)
		{
			//pageview一定要配合layout使用
			Layout* layout = Layout::create();
			layout->setContentSize(winSize);
			auto layer = TeachingSubLayer::create(index,i);
			//layer->setPosition(Vec2(winSize.width/2,winSize.height/2));
			layout->addChild(layer);
			//----按钮
			MenuItemSprite* pJumpItem;
			if (i<=2)
			{
				auto nextNormal = Sprite::create("teaching_next.png");
				auto nextPressed = Sprite::create("teaching_next.png");
				nextPressed->setScale(1.4f);
				pJumpItem = MenuItemSprite::create(nextNormal,nextPressed,CC_CALLBACK_0(TeachingLayer::menuJump,this));
				//pJumpItem->setPosition(Vec2(winSize.width/2 - 60,35-winSize.height/2));
				pJumpItem->setPosition(Vec2(winSize.width - pJumpItem->getContentSize().width,
					pJumpItem->getContentSize().height));
			}
			else//最后一步
			{
				auto nextNormal = Sprite::create("teaching_enter.png");
				auto nextPressed = Sprite::create("teaching_enter.png");
				nextPressed->setScale(1.4f);
				pJumpItem = MenuItemSprite::create(nextNormal,nextPressed,CC_CALLBACK_0(TeachingLayer::menuJump,this));
				pJumpItem->setPosition(Vec2(winSize.width - pJumpItem->getContentSize().width,
					pJumpItem->getContentSize().height));
			}
			pJumpItem->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);

			auto pMenu = Menu::create(pJumpItem,nullptr);
			pMenu->setPosition(Vec2::ZERO);
			layer->addChild(pMenu,3);

			pageView->insertPage(layout,i);
		}
	}

	curPage = 0;
	pageView->scrollToPage(curPage);
	pageView->addEventListener(CC_CALLBACK_2(TeachingLayer::pageViewEvent, this));

	this->addChild(pageView);
}

void TeachingLayer::pageViewEvent(Ref* sender,PageView::EventType type)
{
	switch (type)
	{
		case cocos2d::ui::PageView::EventType::TURNING:
		{
			PageView* pageView = dynamic_cast<PageView*>(sender);
			CCLOG("curpage:%d",pageView->getCurPageIndex());
			for (int i = 0;i<4;i++)
			{
				dynamic_cast<MenuItemSprite*>(this->getChildByTag(kTagRadioMenu)->getChildByTag(i))->unselected();
			}
			curPage = pageView->getCurPageIndex();
			dynamic_cast<MenuItemSprite*>(this->getChildByTag(kTagRadioMenu)->getChildByTag(curPage))->selected();

		}
			break;
		default:
			break;
	}
}

void TeachingLayer::menuJump()
{
	if (curPage<=2)
	{
		auto rMenu = dynamic_cast<Menu*>(this->getChildByTag(kTagRadioMenu));
		auto backItem = dynamic_cast<MenuItemSprite*>(rMenu->getChildByTag(curPage));
		backItem->unselected();
		curPage++;
		auto item = dynamic_cast<MenuItemSprite*>(rMenu->getChildByTag(curPage));
		item->selected();
		CCLOG("xx,curpage:%d",curPage);
		pageView->scrollToPage(curPage);

	}
	else
	{
		//进入游戏
		CCLOG("enter game");
		Director::getInstance()->replaceScene(MainScene::createScene());
	}
}

void TeachingLayer::testPageView()
{
	// Create the page view
	PageView* pageView = PageView::create();
	auto winSize = Director::getInstance()->getWinSize();
	pageView->setContentSize(winSize);
	pageView->setPosition(Vec2::ZERO);
	pageView->setBackGroundColor(Color3B::GREEN);
	pageView->setBackGroundColorType(Layout::BackGroundColorType::SOLID);

	pageView->removeAllPages();

	int pageCount = 4;
	for (int i = 0; i < pageCount; ++i)
	{
		Layout* layout = Layout::create();
		layout->setContentSize(winSize);
		auto bg = Sprite::create("teaching0.png");
		bg->setPosition(Vec2(layout->getContentSize().width/2,layout->getContentSize().height/2));
		layout->addChild(bg);
		
		pageView->insertPage(layout,i);
	}

	//pageView->removePageAtIndex(0);
	//pageView->scrollToPage(pageCount-2);

	//pageView->addEventListener(CC_CALLBACK_2(UIPageViewTest::pageViewEvent, this));

	this->addChild(pageView);
}

void TeachingLayer::menuSelect(Ref* pSender)
{
	MenuItemSprite* pItem = dynamic_cast<MenuItemSprite*>(pSender);
	curPage = pItem->getTag();
	for (int i = 0;i<4;i++)
	{
		dynamic_cast<MenuItemSprite*>(pItem->getParent()->getChildByTag(i))->unselected();
	}
	pItem->selected();
	pageView->scrollToPage(curPage);
}
