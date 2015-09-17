#include "MainScene.h"
#include "DataModel.h"
#include "Tools.h"
#include "BaseAttributes.h"
#include "WayPoint.h"
#include "Creep.h"

MainScene::MainScene()
{
	currentLevel = 0;
	currentWaveEnemy = 0;
}

MainScene::~MainScene()
{

}

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer,1);

	//面板层
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

	//=====背景
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

	//-----地图
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
	//==漩涡动画
	auto sprite = Sprite::create("wormhole0.png");
	tileMap->addChild(sprite);

	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("wormhole0.png");
	animation->addSpriteFrameWithFile("wormhole1.png");
	animation->setDelayPerUnit(0.2f);

	auto animate = Animate::create(animation);
	auto sequence = Sequence::create(animate,animate->reverse(),nullptr);
	auto repeatForever = RepeatForever::create(sequence);
	sprite->runAction(repeatForever);

	//设置虫洞坐标
	if (m->isHardMode)
	{
	}
	else
	{
		if (m->curPassCount == 0)
		{
			sprite->setPosition(Vec2(
				tileMap->getTileSize().width*12-tileMap->getTileSize().width/2,
				tileMap->getTileSize().height*7-tileMap->getTileSize().height/2));
		}
		else if (m->curPassCount == 2)
		{
			sprite->setPosition(Vec2(
				tileMap->getTileSize().width*2-tileMap->getTileSize().width/2,
				tileMap->getTileSize().height*8-tileMap->getTileSize().height/2));
		}
		else
		{
			sprite->setPosition(Vec2(
				tileMap->getTileSize().width*2-tileMap->getTileSize().width/2,
				tileMap->getTileSize().height*7-tileMap->getTileSize().height/2));
		}
	}
	
	//设置人物位置
	if (m->isHardMode)
	{
	}
	else
	{
		if (m->curPassCount == 0)
		{
			this->createSpriteAnimation("base_state0.png",
				Vec2(tileMap->getTileSize().width*1,tileMap->getTileSize().height*1+5),tileMap,2,0.5,101);
		}
		else
		{
			this->createSpriteAnimation("base_state0.png",
				Vec2(tileMap->getTileSize().width*12,tileMap->getTileSize().height*1+5),tileMap,2,0.5,101);
		}
	}

	//添加路径点
	addWaypoint();
	//添加波次
	addWaves();
	currentLevel = 0;

	startSchedule();

	return true;
}

void MainScene::createSpriteAnimation(const char* name, Vec2 point,Node* node,int frameNum,float time,int tag)
{
	auto texture = Director::getInstance()->getTextureCache()->addImage(name);
	auto animation = Animation::create();
	Sprite* sprite;
	for (int i=0; i< frameNum;i++)
	{
		auto frame = SpriteFrame::createWithTexture(texture,
			Rect(texture->getContentSize().width/frameNum*i,0,
			texture->getContentSize().width/frameNum,
			texture->getContentSize().height));
		animation->addSpriteFrame(frame);
		if (i==0)
		{
			sprite = Sprite::createWithSpriteFrame(frame);
		}
	}
	animation->setDelayPerUnit(time);

	//auto sprite = Sprite::createWithSpriteFrame( dynamic_cast<SpriteFrame*>(animation->getFrames().at(0)));
	auto m = DataModel::getInstance();
	if (!m->isHardMode)
	{
		if (m->curPassCount == 0)
		{
			//sprite->setFlipX(true);
			//sprite->setFlippedX(true);
		}
	}
	else
	{
		if (m->curPassCount == 6)
		{
			//sprite->setFlippedX(true);
		}
	}

	sprite->setPosition(point);
	sprite->setAnchorPoint(Vec2::ZERO);
	node->addChild(sprite,20,tag);

	auto animate = Animate::create(animation);
	sprite->runAction(RepeatForever::create(animate));
}

void MainScene::addWaypoint()
{
	auto mapObjects = tileMap->getObjectGroup("Objects");
	auto m = DataModel::getInstance();
	
	auto& objects = mapObjects->getObjects();

	for(auto& obj : objects)
	{
		ValueMap& dict = obj.asValueMap();
		float x = dict["x"].asFloat();
		float y = dict["y"].asFloat();
		log("waypoint:%s",dict["name"].asString().c_str());

		WayPoint* wp = WayPoint::create();
		wp->setPosition(Vec2(x,y));
		//保存路点
		m->m_wayPoints.pushBack(wp);
	}
}

void MainScene::addWaves()//当前关卡所有波次
{
	auto m = DataModel::getInstance();
	char xmlName[15];
	//bool转整形，false<->0, true<->1
	sprintf(xmlName,"Waves%d.plist",m->isHardMode);

	ValueMap dic = FileUtils::getInstance()->getValueMapFromFile(xmlName);
	char cPass[10];
	sprintf(cPass,"pass%d",m->curPassCount);
	ValueMap passDic = dic[cPass].asValueMap();
	ValueVector wavesArray = passDic["waves"].asValueVector();
	log("wavesArray->count:%d",wavesArray.size());
	for (int i=0;i < wavesArray.size();i++)
	{
		ValueVector waveArray = wavesArray.at(i).asValueVector();
		//ValueVector tempArray;
		Vector<WaveEnemy*> tempArray;
		for (int j = 0; j < waveArray.size(); j++)
		{
			ValueMap arrayDic = waveArray.at(j).asValueMap();
			int tempType = arrayDic["type"].asInt();
			int tempCount = arrayDic["count"].asInt();
			int creepCount = tempCount;
			//如果是专家模式
			if (m->isHardMode && tempType < 11)
			{
				creepCount += creepCount;
			}
			this->addEnemyToWave(tempArray,tempType,creepCount);
			log("size:%d",tempArray.size());
			//log("m_count:%d,m_type:%d",tempArray.at(j)->m_count,tempArray.at(j)->m_type);
		}
		this->addWave(tempArray);
	}
}

void MainScene::addEnemyToWave(Vector<WaveEnemy*>& enemys,int type,int count)
{
	auto enemy = WaveEnemy::create(type,count);
	log("count:%d,type:%d",enemy->m_count,enemy->m_type);
	enemys.pushBack(enemy);
	log("enemys.size:%d",enemys.size());
	
}

void MainScene::addWave(Vector<WaveEnemy*>& waveArray)
{
	auto m = DataModel::getInstance();
	Wave* wave = Wave::create(waveArray);
	m->m_waves.pushBack(wave);

}

//游戏循环
void MainScene::stopSchedule()
{
	this->unscheduleUpdate();
	this->unschedule(CC_SCHEDULE_SELECTOR(MainScene::gameLogic));
}
void MainScene::startSchedule()
{
	this->scheduleUpdate();
	this->schedule(CC_SCHEDULE_SELECTOR(MainScene::gameLogic),0.6f);
}
void MainScene::update(float df)
{
	log("update");
}
//每0.6s添加一个敌人
void MainScene::gameLogic(float df)
{
	//log("gameLogic");
	this->addTarget();
}

//添加一个敌人到地图上
void MainScene::addTarget()
{
	auto m = DataModel::getInstance();
	WaveEnemy* wEnemy = this->getWaveEnemy();
	if (wEnemy == nullptr)
	{
		return;
	}

	//创建怪物
	if (wEnemy->m_count > 0)
	{
		Creep* target = Creep::create(wEnemy->m_type);
		wEnemy->m_count--;
		WayPoint* waypoint = target->getCurrentWaypoint();
		target->setPosition(waypoint->getPosition());
		tileMap->addChild(target,200);
	}

}
WaveEnemy* MainScene::getWaveEnemy()//获取当前波的类型数量
{
	Wave* wave = this->getCurrentWave();
	WaveEnemy* waveEnemy = wave->wavesArray.at(currentWaveEnemy);
	if (waveEnemy->m_count <= 0)//第一种类型的怪结束
	{
		if (currentWaveEnemy >= wave->wavesArray.size() - 1)//如果最后一个怪
		{
			return nullptr;
		}
		else//如果不是最后一组怪，添加下一组怪
		{
			currentWaveEnemy++;
			waveEnemy = wave->wavesArray.at(currentWaveEnemy);
		}
	}
	return waveEnemy;
}
Wave* MainScene::getCurrentWave()
{
	auto m = DataModel::getInstance();
	Wave* wave = m->m_waves.at(currentLevel);
	return wave;
}
