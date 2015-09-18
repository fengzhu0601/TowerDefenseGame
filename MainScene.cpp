#include "MainScene.h"
#include "DataModel.h"
#include "Tools.h"
#include "BaseAttributes.h"
#include "WayPoint.h"
#include "Creep.h"
#include "GameConfig.h"

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

	//����
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
	baseAttributes = BaseAttributes::getInstance();

	//=====����
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

	//-----��ͼ
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
	//==���ж���
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

	//���ó涴����
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
	
	//��������λ��
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

	//���·����
	addWaypoint();
	//��Ӳ���
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
		//����·��
		m->m_wayPoints.pushBack(wp);
	}
}

void MainScene::addWaves()//��ǰ�ؿ����в���
{
	auto m = DataModel::getInstance();
	char xmlName[15];
	//boolת���Σ�false<->0, true<->1
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
			//�����ר��ģʽ
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

//��Ϸѭ��
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
	//log("update");
}
//ÿ0.6s���һ������
void MainScene::gameLogic(float df)
{
	//log("gameLogic");
	this->addTarget();
}

//���һ�����˵���ͼ��
void MainScene::addTarget()
{
	auto m = DataModel::getInstance();
	WaveEnemy* wEnemy = this->getWaveEnemy();
	if (wEnemy == nullptr)
	{
		return;
	}

	//��������
	if (wEnemy->m_count > 0)
	{
		Creep* target = Creep::create(wEnemy->m_type);
		wEnemy->m_count--;
		//��������
		float tempScaleHP = baseAttributes->scaleHP;
		//ר��ģʽ������������1��
		if (m->isHardMode)
		{
			tempScaleHP += 1.0f;
		}
		target->m_curHp += currentLevel * target->m_curHp * tempScaleHP;
		target->m_totalHp = target->m_curHp;
		//���ó�ʼ����
		WayPoint* waypoint = target->getCurrentWaypoint();
		Vec2 tempWaypoint = waypoint->getPosition();
		if (target->getTag() >= Creep::boos1)
		{
			tempWaypoint+=Vec2(0,20);
		}
		target->setPosition(tempWaypoint);
		//ȡ����һ��·������
		waypoint = target->getNextWaypoint();
		Vec2 nextPint = waypoint->getPosition();
		if (target->getTag() >= Creep::boos1)
		{
			nextPint += Vec2(0,20);
		}
		tileMap->addChild(target,200);

		//����Ѫ��
		target->healthBar = ProgressTimer::create(Sprite::create("health_bar_red.png"));
		target->healthBar->setType(ProgressTimer::Type::BAR);
		target->healthBar->setPercentage(100);
		target->healthBar->setPosition(Vec2(target->getContentSize().width/2,target->getContentSize().height+22));
		//tileMap->addChild(target->healthBar,3);
		target->addChild(target->healthBar);
		//���ﱬ��ͼ
		target->explosionSprite = Sprite::create("explosion.png");
		target->explosionSprite->setPosition(target->getPosition());
		target->explosionSprite->setVisible(false);
		tileMap->addChild(target->explosionSprite);

		//��ת����
		float moveDuration = target->moveDurScale();
		WayPoint* curWaypoint = target->getCurrentWaypoint();
		//Vec2 waypointVector = curWaypoint->getPosition() - target->getPosition();
		float waypointAngle = Vec2::angle(curWaypoint->getPosition(),target->getPosition());
		float cocosAngle = CC_RADIANS_TO_DEGREES(-1*waypointAngle)+90;
		float rotateSpeed = 0.05 / M_PI;
		float rotateDuration = fabs(waypointAngle * rotateSpeed);
		auto rotateTo = RotateTo::create(rotateDuration,cocosAngle);

		auto actionMove = MoveTo::create(moveDuration,nextPint);
		auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(MainScene::followPath,this));

		auto speedAction = Speed::create(Sequence::create(actionMove,actionMoveDone,nullptr),1.0f);
		target->previousSpeed = 1.0f;
		speedAction->setTag(kTagSpeed);
		target->runAction(speedAction);
	}

}

void MainScene::followPath(Ref* sender)
{
	Creep* creep = dynamic_cast<Creep*>(sender);
	WayPoint* curWaypoint = creep->getCurrentWaypoint();
	WayPoint* waypoint = creep->getNextWaypoint();
	//log("%f,%f",curWaypoint->getPositionX(),curWaypoint->getPositionY());
	//log("%f,%f",waypoint->getPositionX(),waypoint->getPositionY());

	if (waypoint != nullptr)
	{
		Vec2 tempWayPoint = waypoint->getPosition();
		//�����boos
		if (creep->getTag() >= Creep::boos1)
		{
		}
		float moveDuration = creep->moveDurScale();
		auto moveto = MoveTo::create(moveDuration,tempWayPoint);
		auto moveDone = CallFuncN::create(CC_CALLBACK_1(MainScene::followPath,this));
		creep->stopAllActions();
		//��ת����
		float waypointAngle = Vec2::angle(curWaypoint->getPosition(),creep->getPosition());
		float cocosAngle = CC_RADIANS_TO_DEGREES(-1 * waypointAngle)+90;
		float rotateSpeed = 0.05 / M_PI;
		float rotateDuration = fabs(waypointAngle * rotateSpeed);

		auto speedAction = Speed::create(Sequence::create(moveto,moveDone,nullptr),1.0f);
		speedAction->setTag(kTagSpeed);
		creep->runAction(speedAction);
	}
}

WaveEnemy* MainScene::getWaveEnemy()//��ȡ��ǰ������������
{
	Wave* wave = this->getCurrentWave();
	WaveEnemy* waveEnemy = wave->wavesArray.at(currentWaveEnemy);
	if (waveEnemy->m_count <= 0)//��һ�����͵Ĺֽ���
	{
		if (currentWaveEnemy >= wave->wavesArray.size() - 1)//������һ����
		{
			return nullptr;
		}
		else//����������һ��֣������һ���
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
