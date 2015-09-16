#include "Tools.h"
#include "SimpleAudioEngine.h"

//锁定关卡
void Tools::saveMaxUnlock(int mode,int max)
{
	UserDefault::getInstance()->setIntegerForKey("maxUnlock"+mode,max);
	UserDefault::getInstance()->flush();
}
int Tools::getMaxUnlock(int mode)
{
	return UserDefault::getInstance()->getIntegerForKey("maxUnlock"+mode);
}

//存档-当前关
int Tools::getCurPass(int mode)
{
	return UserDefault::getInstance()->getIntegerForKey("passCount"+mode);
}
void Tools::saveCurPass(int mode,int pass)
{
	UserDefault::getInstance()->setIntegerForKey("passCount"+mode, pass);
	UserDefault::getInstance()->flush();
}

//存档-模式
bool Tools::getMode()
{
	return UserDefault::getInstance()->getBoolForKey("isModeHard");
}
void Tools::saveMode(bool isHard)
{
	UserDefault::getInstance()->setBoolForKey("isModeHard",isHard);
	UserDefault::getInstance()->flush();
}

//存档-声音
bool Tools::getMusic()
{
	return UserDefault::getInstance()->getBoolForKey("isMusic");
}
void Tools::setMusic(bool isMusic)
{
	UserDefault::getInstance()->setBoolForKey("isMusic",isMusic);
	UserDefault::getInstance()->flush();
}

//存档-音效
bool Tools::getSound()
{
	return UserDefault::getInstance()->getBoolForKey("isSound");
}
void Tools::setSound(bool isSound)
{
	UserDefault::getInstance()->setBoolForKey("isSound",isSound);
	UserDefault::getInstance()->flush();
}

//勋章
void Tools::saveMedal(int medal)
{
	UserDefault::getInstance()->setIntegerForKey("medal",medal);
	UserDefault::getInstance()->flush();
}
int Tools::getMedal()
{
	return UserDefault::getInstance()->getIntegerForKey("medal");
}

//道具双倍数量
void Tools::saveDoubleCount(int count)
{
	UserDefault::getInstance()->setIntegerForKey("doubleCount",count);
	UserDefault::getInstance()->flush();
}
int Tools::getDouleCount()
{
	return UserDefault::getInstance()->getIntegerForKey("doubleCount");
}
//道具双倍闪电数量
void Tools::saveLightningCount(int count)
{
	UserDefault::getInstance()->setIntegerForKey("lightningCount",count);
	UserDefault::getInstance()->flush();
}
int Tools::getLightningCount()
{
	return UserDefault::getInstance()->getIntegerForKey("lightningCount");
}
//道具暴风雪
void Tools::saveBlizzardCount(int count)
{
	UserDefault::getInstance()->setIntegerForKey("blizzardCount",count);
	UserDefault::getInstance()->flush();
}
int Tools::getBlizzardCount()
{
	return UserDefault::getInstance()->getIntegerForKey("blizzardCount");
}

//教学
void Tools::saveTeaching(bool isTeaching)
{
	UserDefault::getInstance()->setBoolForKey("isTeaching",isTeaching);
	UserDefault::getInstance()->flush();
}
bool Tools::getTeaching()
{
	return UserDefault::getInstance()->getBoolForKey("isTeaching");
}
//是否第一次游戏
void Tools::saveFirstGame(bool isFirst)
{
	UserDefault::getInstance()->setBoolForKey("isFirst",isFirst);
	UserDefault::getInstance()->flush();
}
bool Tools::getFirstGame()
{
	return UserDefault::getInstance()->getBoolForKey("isFirst");
}
//是否激活游戏
void Tools::saveActivatingGame(bool isFirst)
{
	UserDefault::getInstance()->setBoolForKey("isActivatingGame",isFirst);
	UserDefault::getInstance()->flush();
}
bool Tools::getActivatingGame()
{
	return UserDefault::getInstance()->getBoolForKey("isActivatingGame");
}

//成绩
void Tools::saveScore(int pass,int star,bool mode)
{
	char score[10];
	sprintf(score,"star%d_%d",pass,mode);
	UserDefault::getInstance()->setIntegerForKey(score,star);
	UserDefault::getInstance()->flush();
}
int Tools::getScore(int pass,bool mode)
{
	char score[10];
	sprintf(score,"star%d_%d",pass,mode);
	return UserDefault::getInstance()->getIntegerForKey(score);
}

//void Tools::loadMusicMenu()
//{
//	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music_menu.mp3");
//}

void Tools::preloadMusic()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music_menu.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music_common.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music_expert.mp3");

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_blizzard.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_lightning.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_tower.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_enemy_dead0.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_enemy_dead1.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_enemy_dead2.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_enemy_dead3.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_scarecrow0.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_scarecrow1.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_scarecrow2.mp3");

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_success.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_lost.mp3");

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_firing0.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_firing1.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_firing2.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound_firing3.mp3");
}







