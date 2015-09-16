#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Tools : public Ref
{
public:
	//�浵-��ǰ��
	static int getCurPass(int mode);
	static void saveCurPass(int mode,int pass);

	//�浵-ģʽ
	static bool getMode();
	static void saveMode(bool isHard);

	//�浵-����
	static bool getMusic();
	static void setMusic(bool isMusic);

	//�浵-��Ч
	static bool getSound();
	static void setSound(bool isSound);

	//ѫ��
	static void saveMedal(int medal);
	static int getMedal();
	//����˫������
	static void saveDoubleCount(int count);
	static int getDouleCount();
	//����˫����������
	static void saveLightningCount(int count);
	static int getLightningCount();
	//���߱���ѩ
	static void saveBlizzardCount(int count);
	static int getBlizzardCount();

	//��ѧ
	static void saveTeaching(bool isTeaching);
	static bool getTeaching();
	//�Ƿ��һ����Ϸ
	static void saveFirstGame(bool isFirst);
	static bool getFirstGame();
	//�Ƿ񼤻���Ϸ
	static void saveActivatingGame(bool isFirst);
	static bool getActivatingGame();

	//�����ؿ�
	static void saveMaxUnlock(int mode,int max);
	static int getMaxUnlock(int mode);

	//�ɼ�
	static void saveScore(int pass,int star,bool mode);
	static int getScore(int pass,bool mode);

	//=====================����=============
	//static void loadMusicMenu();
	static void preloadMusic();

};