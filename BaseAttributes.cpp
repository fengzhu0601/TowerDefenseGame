#include "BaseAttributes.h"

BaseAttributes* BaseAttributes::m_baseAttributes = nullptr;

BaseAttributes::BaseAttributes()
{

}

BaseAttributes::~BaseAttributes()
{

}

BaseAttributes* BaseAttributes::getInstance()
{
	m_baseAttributes = new BaseAttributes();
	if (m_baseAttributes && m_baseAttributes->init())
	{
		m_baseAttributes->autorelease();
		return m_baseAttributes;
	}
	else
	{
		delete m_baseAttributes;
		m_baseAttributes = nullptr;
	}
	return m_baseAttributes;
}

bool BaseAttributes::init()
{
	towerIndex[0][0] = 0;
	towerIndex[0][1] = 0;
	towerIndex[0][2] = 0;
	towerIndex[0][3] = 0;

	towerIndex[1][0] = 1;
	towerIndex[1][1] = 1;
	towerIndex[1][2] = 1;
	towerIndex[1][3] = 1;

	towerIndex[2][0] = 2;
	towerIndex[2][1] = 2;
	towerIndex[2][2] = 2;
	towerIndex[2][3] = 2;

	towerIndex[3][0] = 3;
	towerIndex[3][1] = 3;
	towerIndex[3][2] = 3;
	towerIndex[3][3] = 3;

	towerIndex[4][0] = 4;
	towerIndex[4][1] = 4;
	towerIndex[4][2] = 4;
	towerIndex[4][3] = 4;

	towerIndex[5][0] = 5;
	towerIndex[5][1] = 5;
	towerIndex[5][2] = 5;
	towerIndex[5][3] = 5;

	towerIndex[6][0] = 6;
	towerIndex[6][1] = 6;
	towerIndex[6][2] = 6;
	towerIndex[6][3] = 6;

	towerIndex[7][0] = 5;
	towerIndex[7][1] = 5;
	towerIndex[7][2] = 5;
	towerIndex[7][3] = 5;

	towerIndex[8][0] = 7;
	towerIndex[8][1] = 7;
	towerIndex[8][2] = 7;
	towerIndex[8][3] = 7;

	towerIndex[9][0] = 8;
	towerIndex[9][1] = 8;
	towerIndex[9][2] = 8;
	towerIndex[9][3] = 8;

	return true;
}