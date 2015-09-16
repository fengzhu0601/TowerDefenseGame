#pragma once

#include "cocos2d.h"
#include "SuperclassScene.h"
#include "ui/UIScrollView.h"

USING_NS_CC;
using namespace cocos2d::ui;

const int TOUCH_DISTANCE = 50;

class OptMap : public SuperclassScene
{
public:
	OptMap();
	~OptMap();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(OptMap);

	virtual void menuBack(Ref* pSender);

private:
	int passCount;
	Vec2 beginTouchPoint;
	int m_curpage;
	int m_page;//总共个数
	ScrollView* scrollview;
private:
	void initTower(int tag);
	void setPassCount(int count);//设置关卡数

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	void scrollEvent(Ref* pSender);
	void adjustScrollView(float offset);
};

