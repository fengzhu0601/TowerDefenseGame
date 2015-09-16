#include "GameHUD.h"

GameHUD* GameHUD::m_Instance = nullptr;

GameHUD::GameHUD()
{

}

GameHUD::~GameHUD()
{

}

GameHUD* GameHUD::getInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new GameHUD();
		m_Instance->init();

		return m_Instance;
	}
	return m_Instance;
}

bool GameHUD::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}