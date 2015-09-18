#include "Creep.h"
#include "DataModel.h"

Creep::Creep()
{
	m_curHp = 0;//当前血量
	m_moveSpeed = 0;//移动速度
	m_curWaypoint = 0;//当前点
}

Creep::~Creep()
{

}

Creep* Creep::create(int type)
{
	Creep* creep = new Creep();
	if (creep && creep->init(type))
	{
		creep->autorelease();
		return creep;
	}
	else
	{
		delete creep;
		creep = nullptr;
	}
	return creep;
}

bool Creep::init(int type)
{
	if (!Sprite::init())
	{
		return false;
	}
	Texture2D* texture;
	SpriteFrame* frame;
	switch (type)
	{
	case Creep::grasshopper1:
		m_curHp = m_totalHp = 10;
		m_curWaypoint = 0;
		m_moveSpeed = 2;

		texture = Director::getInstance()->getTextureCache()->addImage("enemy_grasshopper1.png");
		frame = SpriteFrame::createWithTexture(texture,Rect(0,0,texture->getContentSize().width/2,texture->getContentSize().height));
		this->addChild(Sprite::createWithSpriteFrame(frame),10,grasshopper1);

		break;
	case Creep::grasshopper2:
		break;
	case Creep::grasshopper3:
		break;
	case Creep::beetle1:
		break;
	case Creep::beetle2:
		break;
	case Creep::beetle3:
		break;
	case Creep::ant1:
		break;
	case Creep::ant2:
		break;
	case Creep::ant3:
		break;
	case Creep::bee1:
		break;
	case Creep::bee2:
		break;
	case Creep::boos1:
		break;
	case Creep::boos2:
		break;
	case Creep::boos3:
		break;
	case Creep::boos4:
		break;
	case Creep::boos5:
		break;
	case Creep::boos6:
		break;
	case Creep::boos7:
		break;
	case Creep::boos8:
		break;
	case Creep::boos9:
		break;
	default:
		break;
	}

	return true;
}

WayPoint* Creep::getCurrentWaypoint()
{
	auto m = DataModel::getInstance();
	WayPoint* waypoint = m->m_wayPoints.at(m_curWaypoint);
	return waypoint;
}

WayPoint* Creep::getNextWaypoint()
{
	auto m = DataModel::getInstance();
	m_curWaypoint++;

	//如果没有下一个路点
	if (m_curWaypoint >= m->m_wayPoints.size())
	{
		return nullptr;
	}

	WayPoint* waypoint = m->m_wayPoints.at(m_curWaypoint);
	return waypoint;
}

float Creep::moveDurScale()
{
	auto m = DataModel::getInstance();
	float firstDistance = 100;

	WayPoint* waypoint2 = m->m_wayPoints.at(m_curWaypoint-1);
	WayPoint* waypoint3 = m->m_wayPoints.at(m_curWaypoint);
	float thisDistance = waypoint2->getPosition().distance(waypoint3->getPosition());
	float moveScale = thisDistance/firstDistance;
	return (m_moveSpeed * moveScale);
}
