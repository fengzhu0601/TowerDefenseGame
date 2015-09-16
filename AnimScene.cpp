#include "AnimScene.h"
#include "GameMenu.h"
#include "DataModel.h"
#include "Tools.h"
#include "SimpleAudioEngine.h"

AnimScene::AnimScene()
{
	animIndex = 0;
}

AnimScene::~AnimScene()
{

}

Scene* AnimScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AnimScene::create();
	scene->addChild(layer);
	return scene;
}

bool AnimScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto winSize = Director::getInstance()->getWinSize();

	auto animbg = Sprite::create("anim_bg.png");
	animbg->setPosition(Vec2(winSize.width/2,winSize.height/2));
	this->addChild(animbg);

	this->readArchive();
	if (DataModel::isMusic)
	{
		if (!CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("music_menu.mp3",true);
		}
		else
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("music_menu.mp3",true);
		}
	}

	auto paper1 = Sprite::create("paper0.png");
	//auto paper1 = Sprite::create("011.png");
	paper1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	paper1->setPosition(paper1->getContentSize().width/2,winSize.height/2);
	this->addChild(paper1);
	paper1->setScale(0);
	m_pages.pushBack(paper1);

	auto paper2 = Sprite::create("paper1.png");
	//auto paper2 = Sprite::create("033.png");
	paper2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	paper2->setPosition(winSize.width/2,winSize.height/2);
	this->addChild(paper2);
	paper2->setScale(0);
	m_pages.pushBack(paper2);

	auto paper3 = Sprite::create("paper2.png");
	//auto paper3 = Sprite::create("011.png");
	paper3->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	paper3->setPosition(winSize.width - paper3->getContentSize().width/2,winSize.height/2);
	this->addChild(paper3);
	paper3->setScale(0);
	m_pages.pushBack(paper3);

	callAnimationComplete(nullptr);
	return true;
}

void AnimScene::callAnimationComplete(Ref* ref)
{
	if (animIndex == 0)
	{
		auto scaleto1 = ScaleTo::create(0.8f,0.6f);
		auto rotateby1 = RotateBy::create(0.8f,220+360*3);
		auto spawn1 = Spawn::create(scaleto1,rotateby1,nullptr);

		auto scaleto2 = ScaleTo::create(0.6f,1.0f);
		auto rotateby2 = RotateBy::create(0.6f,120);
		auto spawn2 = Spawn::create(scaleto2,rotateby2,nullptr);

		auto delaytime = DelayTime::create(0.3f);
		auto actionDone = CallFuncN::create(CC_CALLBACK_1(AnimScene::callAnimationComplete,this));
		auto sequence = Sequence::create(spawn1,spawn2,delaytime,actionDone,nullptr);
		m_pages.at(animIndex)->runAction(sequence);
	}
	else if (animIndex == 1)
	{
		auto scaleto1 = ScaleTo::create(0.8f,0.6f);
		auto rotateby1 = RotateBy::create(0.8f,240+360*3);
		auto spawn1 = Spawn::create(scaleto1,rotateby1,nullptr);

		auto scaleto2 = ScaleTo::create(0.6f,1.0f);
		auto rotateby2 = RotateBy::create(0.6f,140);
		auto spawn2 = Spawn::create(scaleto2,rotateby2,nullptr);

		auto delaytime = DelayTime::create(0.3f);
		auto actionDone = CallFuncN::create(CC_CALLBACK_1(AnimScene::callAnimationComplete,this));
		auto sequence = Sequence::create(spawn1,spawn2,delaytime,actionDone,nullptr);
		m_pages.at(animIndex)->runAction(sequence);
	}
	else if (animIndex == 2)
	{
		auto scaleto1 = ScaleTo::create(0.8f,0.6f);
		auto rotateby1 = RotateBy::create(0.8f,280+360*3);
		auto spawn1 = Spawn::create(scaleto1,rotateby1,nullptr);

		auto scaleto2 = ScaleTo::create(0.6f,1.0f);
		auto rotateby2 = RotateBy::create(0.6f,80);
		auto spawn2 = Spawn::create(scaleto2,rotateby2,nullptr);

		auto delaytime = DelayTime::create(0.3f);
		auto actionDone = CallFuncN::create(CC_CALLBACK_0(AnimScene::goToMenuScene,this));
		auto sequence = Sequence::create(spawn1,spawn2,delaytime,actionDone,nullptr);
		m_pages.at(animIndex)->runAction(sequence);
	}
	animIndex++;
}

void AnimScene::goToMenuScene()
{
	//Director::getInstance()->replaceScene(HelloWorld::createScene());
	Director::getInstance()->replaceScene(GameMenu::createScene());
}

void AnimScene::readArchive()//读取文档
{
	auto m = DataModel::getInstance();

	if (isHaveSaveFile())
	{
		bool isMode = Tools::getMode();//是什么模式

		DataModel::isMusic = Tools::getMusic();
		DataModel::isSound = Tools::getSound();

		m->propsMedalCount = Tools::getMedal();
		m->propsDoubleCount = Tools::getDouleCount();
		m->propsLightningcount = Tools::getLightningCount();
		m->propsBlizzardCount = Tools::getBlizzardCount();

		m->isShowTeaching = Tools::getTeaching();
		m->isFirstGame = Tools::getFirstGame();
		m->isActivatingGame = Tools::getActivatingGame();
	}
	else
	{
		CCLOG("first");
		Tools::setMusic(DataModel::isMusic);
		Tools::setSound(DataModel::isSound);

		Tools::saveMaxUnlock(0,1);
		Tools::saveMaxUnlock(1,1);

		Tools::saveMedal(m->propsMedalCount);
		Tools::saveDoubleCount(m->propsDoubleCount);
		Tools::saveLightningCount(m->propsLightningcount);
		Tools::saveBlizzardCount(m->propsBlizzardCount);

		Tools::saveTeaching(true);
		Tools::saveFirstGame(true);
		Tools::saveActivatingGame(false);
	}
}

bool AnimScene::isHaveSaveFile()//判断是否有存档
{
	if (!UserDefault::getInstance()->getBoolForKey("isHaveSaveFileXml"))
	{
		UserDefault::getInstance()->setBoolForKey("isHaveSaveFileXml",true);
		UserDefault::getInstance()->flush();//提交
		return false;
	}
	return true;
}
