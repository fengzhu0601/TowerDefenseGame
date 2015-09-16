#include "SuperclassScene.h"

void SuperclassScene::addMenuTitle(int index)
{
	auto winSize = Director::getInstance()->getWinSize();
	
	auto bg = Sprite::create("gate_bg.png");
	bg->setAnchorPoint(Vec2::ZERO);
	bg->setPosition(Vec2::ZERO);
	this->addChild(bg);

	auto title_bg = Sprite::create("title_bg.png");
	title_bg->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	title_bg->setPosition(Vec2(winSize.width/2,winSize.height));
	this->addChild(title_bg);

	auto title_name = Sprite::create("title_name.png");
	title_name->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	title_name->setPosition(Vec2(winSize.width/2,winSize.height-18));
	this->addChild(title_name);
}

void SuperclassScene::addMenuBack()
{
	auto backNormal = Sprite::create("button_back.png");
	auto backPressed = Sprite::create("button_back.png");
	backPressed->setScale(1.2f);

	auto pBackItem = MenuItemSprite::create(
		backNormal,
		backPressed,
		nullptr,
		CC_CALLBACK_1(SuperclassScene::menuBack,this));
	pBackItem->setPosition(Vec2(20,20));
	pBackItem->setAnchorPoint(Vec2::ZERO);

	auto pMenu = Menu::create(pBackItem,nullptr);
	pMenu->setPosition(Vec2::ZERO);
	this->addChild(pMenu);
}

void SuperclassScene::menuBack(Ref* pSender)
{
	CCLOG("¸¸ÀàµÄmenuBack-------");
}
