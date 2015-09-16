#pragma once

#include "cocos2d.h"

USING_NS_CC;

class GameMenu : public Layer
{
public:
	GameMenu();
	~GameMenu();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameMenu);

	virtual void menuNewGame(Ref* pSender);
	virtual void menuStore(Ref* pSender);
	virtual void menuExpertGame(Ref* pSender);
	virtual void menuSystem(Ref* pSender);

private:
	Menu* pMenu;
	Sprite* systemBg;
	bool isShowSystem;
private:
	void menuSetSound();
	void menuSetMusic();
	void menuHelp();
	void menuAbout();

	void reSetting(Ref* pSender);

};