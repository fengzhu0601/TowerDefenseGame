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

	void readArchive();//读取文档
	bool isHaveSaveFile();//判断是否有存档

public:
	Vector<Sprite*> m_pages;

	int animIndex;

	void goToMenuScene();
};