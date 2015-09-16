#include "GameMenu.h"
#include "DataModel.h"
#include "OptMap.h"
#include "SimpleAudioEngine.h"
#include "Tools.h"

GameMenu::GameMenu()
{
	systemBg = nullptr;
	isShowSystem = false;
}

GameMenu::~GameMenu()
{

}

Scene* GameMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = GameMenu::create();
	scene->addChild(layer);
	return scene;
}

bool GameMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//加载音效
	Tools::preloadMusic();
	
	if (DataModel::isMusic)
	{
		if (!CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("music_menu.mp3",true);
		}
	}

	auto winSize = Director::getInstance()->getWinSize();
	auto pSprite = Sprite::create("menu_bg.png");
	pSprite->setPosition(Vec2(winSize.width/2,winSize.height/2));
	this->addChild(pSprite);

	//主菜单
	//--普通模式
	auto newgameNormal = Sprite::create("menu_newgame.png");
	auto newgamePressed = Sprite::create("menu_newgame.png");
	newgamePressed->setScale(1.2f);

	auto pNewGameItem = MenuItemSprite::create(
		newgameNormal,
		newgamePressed,
		nullptr,
		CC_CALLBACK_1(GameMenu::menuNewGame,this));
	pNewGameItem->setPosition(Vec2(winSize.width-250,winSize.height/2));
	pNewGameItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);

	//--专家模式
	auto expertNormal = Sprite::create("menu_expert.png");
	auto expertPressed = Sprite::create("menu_expert.png");
	expertPressed->setScale(1.2f);

	auto pExpertItem = MenuItemSprite::create(
		expertNormal,
		expertPressed,
		nullptr,
		CC_CALLBACK_1(GameMenu::menuExpertGame,this));
	pExpertItem->setPosition(Vec2(winSize.width-250,winSize.height/2 - 75));
	pExpertItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);

	//--商店
	auto pStoreNormal = Sprite::create("menu_store.png");
	auto pStorePressed = Sprite::create("menu_store.png");
	pStorePressed->setScale(1.2f);
	auto pStoreItem = MenuItemSprite::create(
		pStoreNormal,
		pStorePressed,
		nullptr,
		CC_CALLBACK_1(GameMenu::menuStore,this));
	pStoreItem->setPosition(Vec2(winSize.width-250,winSize.height/2 -75*2));
	pStoreItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);

	//--其他
	auto pOtherNormal = Sprite::create("menu_setting.png");
	auto pOtherPressed = Sprite::create("menu_setting.png");
	pOtherPressed->setScale(1.2f);
	auto pOtherItem = MenuItemSprite::create(
		pOtherNormal,
		pOtherPressed,
		nullptr,
		CC_CALLBACK_1(GameMenu::menuSystem,this));
	pOtherItem->setPosition(Vec2(80,winSize.height-10));
	pOtherItem->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);


	pMenu = Menu::create(pNewGameItem,pExpertItem,pStoreItem,pOtherItem,nullptr);
	pMenu->setPosition(Vec2::ZERO);
	this->addChild(pMenu,1);
	//--系统
	systemBg = Sprite::create("system_bg.png");
	systemBg->setPosition(Vec2(
		pOtherItem->getPositionX()-pOtherItem->getContentSize().width/2,
		pOtherItem->getPositionY()-pOtherItem->getContentSize().height));
	systemBg->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	this->addChild(systemBg);
		//先隐藏起来
	isShowSystem = false;
	systemBg->setScale(0);

	//--声音选项
	auto soundOff = Sprite::create("sound.png");
	auto ban = Sprite::create("ban.png");
	ban->setPosition(Vec2(soundOff->getContentSize().width/2,soundOff->getContentSize().height/2));
	soundOff->addChild(ban);
	auto pSubSoundOffItem = MenuItemSprite::create(soundOff,nullptr);
	auto pSubSoundOpenItem = MenuItemSprite::create(Sprite::create("sound.png"),nullptr);
	auto pSoundItem = MenuItemToggle::createWithCallback(CC_CALLBACK_0(GameMenu::menuSetSound,this),pSubSoundOffItem,pSubSoundOpenItem,nullptr);
	pSoundItem->setSelectedIndex(DataModel::isSound);
	//--音乐开关子选项
	auto musicOff = Sprite::create("music.png");
	auto musicban = Sprite::create("ban.png");
	musicban->setPosition(Vec2(musicOff->getContentSize().width/2,musicOff->getContentSize().height/2));
	musicOff->addChild(musicban);
	auto pSubMusicOffItem = MenuItemSprite::create(musicOff,nullptr);
	auto pSubMusicOpenItem = MenuItemSprite::create(Sprite::create("music.png"),nullptr);
	auto pMusicItem = MenuItemToggle::createWithCallback(CC_CALLBACK_0(GameMenu::menuSetMusic,this),pSubMusicOffItem,pSubMusicOpenItem,nullptr);
	pMusicItem->setSelectedIndex(DataModel::isMusic);
	//--帮助
	auto helpNormalSprite = Sprite::create("menu_help.png");
	auto helpPressedSprite = Sprite::create("menu_help.png");
	helpPressedSprite->setScale(1.2f);
	auto pHelpItem = MenuItemSprite::create(helpNormalSprite,helpPressedSprite,CC_CALLBACK_0(GameMenu::menuHelp,this));
	//--关于
	auto aboutNormal = Sprite::create("menu_about.png");
	auto aboutPressed = Sprite::create("menu_about.png");
	aboutPressed->setScale(1.2f);
	auto pAboutItem = MenuItemSprite::create(aboutNormal,aboutPressed,CC_CALLBACK_0(GameMenu::menuAbout,this));

	auto pSettingMenu = Menu::create(pSoundItem,pMusicItem,pHelpItem,pAboutItem,nullptr);
	//排列菜单项
	pSettingMenu->alignItemsVerticallyWithPadding(10);
	pSettingMenu->setPosition(Vec2(
		systemBg->getContentSize().width/2,
		systemBg->getContentSize().height/2));
	systemBg->addChild(pSettingMenu);

	return true;
}

void GameMenu::menuNewGame(Ref* pSender)
{
	auto m = DataModel::getInstance();
	m->isHardMode = false;

	auto scene = OptMap::createScene();
	Director::getInstance()->replaceScene(scene);
	
}

void GameMenu::menuStore(Ref* pSender)
{

}
void GameMenu::menuExpertGame(Ref* pSender)
{

}
void GameMenu::menuSystem(Ref* pSender)
{
	auto pSettingItem = (MenuItemSprite*)pSender;
	isShowSystem = !isShowSystem;
	if (isShowSystem)
	{
		auto moveto = MoveTo::create(0.2f,Vec2(systemBg->getPositionX(),systemBg->getPositionY()-10));
		auto scaleto = ScaleTo::create(0.2f,1.0f);
		auto spawn = Spawn::create(moveto,scaleto,nullptr);
		auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameMenu::reSetting,this));
		auto sequence = Sequence::create(spawn,actionDone,nullptr);
		systemBg->runAction(sequence);
	}
	else
	{
		auto moveto = MoveTo::create(0.2f,Vec2(systemBg->getPositionX(),systemBg->getPositionY()+10));
		auto scaleto = ScaleTo::create(0.2f,0.0f);
		auto spawn = Spawn::create(moveto,scaleto,nullptr);
		auto actionDone = CallFuncN::create(CC_CALLBACK_1(GameMenu::reSetting,this));
		auto sequence = Sequence::create(spawn,actionDone,nullptr);
		systemBg->runAction(sequence);
	}
}

void GameMenu::reSetting(Ref* pSender)
{
	
}

void GameMenu::menuSetSound()
{
	DataModel::isSound = !DataModel::isSound;
	if (DataModel::isSound)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseAllEffects();
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects();
	}
	Tools::setSound(DataModel::isSound);
}
void GameMenu::menuSetMusic()
{
	DataModel::isMusic = !DataModel::isMusic;
	if (DataModel::isMusic)
	{
		if (!CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("music_menu.mp3",true);
		}
	}
	else
	{
		if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		}
	}
	Tools::setMusic(DataModel::isMusic);
}
void GameMenu::menuHelp()
{
	CCLOG("help");
}
void GameMenu::menuAbout()
{
	CCLOG("about");
}
