#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Tools : public Ref
{
public:
	//存档-当前关
	static int getCurPass(int mode);
	static void saveCurPass(int mode,int pass);

	//存档-模式
	static bool getMode();
	static void saveMode(bool isHard);

	//存档-声音
	static bool getMusic();
	static void setMusic(bool isMusic);

	//存档-音效
	static bool getSound();
	static void setSound(bool isSound);

	//勋章
	static void saveMedal(int medal);
	static int getMedal();
	//道具双倍数量
	static void saveDoubleCount(int count);
	static int getDouleCount();
	//道具双倍闪电数量
	static void saveLightningCount(int count);
	static int getLightningCount();
	//道具暴风雪
	static void saveBlizzardCount(int count);
	static int getBlizzardCount();

	//教学
	static void saveTeaching(bool isTeaching);
	static bool getTeaching();
	//是否第一次游戏
	static void saveFirstGame(bool isFirst);
	static bool getFirstGame();
	//是否激活游戏
	static void saveActivatingGame(bool isFirst);
	static bool getActivatingGame();

	//锁定关卡
	static void saveMaxUnlock(int mode,int max);
	static int getMaxUnlock(int mode);

	//成绩
	static void saveScore(int pass,int star,bool mode);
	static int getScore(int pass,bool mode);

	//=====================音乐=============
	//static void loadMusicMenu();
	static void preloadMusic();

};