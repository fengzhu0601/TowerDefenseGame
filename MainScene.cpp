#include "MainScene.h"
#include "DataModel.h"
#include "Tools.h"
#include "BaseAttributes.h"

MainScene::MainScene()
{

}

MainScene::~MainScene()
{

}

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer,1);

	//Ãæ°å²ã
	auto mGameHUD = GameHUD::getInstance();
	scene->addChild(mGameHUD,2);

	auto m = DataModel::getInstance();
	m->_gameLayer = layer;
	m->_gameHUDLayer = mGameHUD;

	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto m = DataModel::getInstance();
	Tools::saveCurPass(m->isHardMode,m->curPassCount);
	Tools::saveMode(m->isHardMode);
	Tools::saveFirstGame(false);
	auto baseAttributes = BaseAttributes::getInstance();

	//=====±³¾°
	Sprite* gameBg;
	if (m->isHardMode)
	{
		gameBg = Sprite::create("common_bg.png");
	}
	else
	{
		gameBg = Sprite::create("game_bg0.png");
	}
	gameBg->setAnchorPoint(Vec2::ZERO);
	this->addChild(gameBg,-11);

	//-----µØÍ¼
	char mapName[14];
	if (m->isHardMode)
	{
		sprintf(mapName,"TileMap%d.tmx",m->curPassCount+1);
	}
	else
	{
		sprintf(mapName,"TileMap%d.tmx",m->curPassCount+1);
	}
	tileMap = TMXTiledMap::create(mapName);
	m_mapLayerTower = tileMap->getLayer("Tower");
	m_mapLayerTower->setAnchorPoint(Vec2::ZERO);
	this->addChild(tileMap,-10);
	tileMap->setPosition(70,10);
	//==¶¯»­
	


	return true;
}