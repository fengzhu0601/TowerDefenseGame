#pragma once

#include "cocos2d.h"

USING_NS_CC;

class AnimScene : public Layer
{
public:
	AnimScene();
	~AnimScene();
    static Scene* createScene();

	virtual bool init();
	CREATE_FUNC(AnimScene);

	void callAnimationComplete(Ref* ref);

	void readArchive();//��ȡ�ĵ�
	bool isHaveSaveFile();//�ж��Ƿ��д浵

public:
	Vector<Sprite*> m_pages;

	int animIndex;

	void goToMenuScene();
};