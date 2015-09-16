#pragma once

#include "cocos2d.h"
#include "ui/UIPageView.h"

USING_NS_CC;
using namespace cocos2d::ui;

class TeachingLayer : public Layer
{
public:
	TeachingLayer();
	~TeachingLayer();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TeachingLayer);

	void pageViewEvent(Ref* sender,PageView::EventType type);
private:
	void addRadioMenu();
	void addLayer(int index);
	void menuJump();
	void testPageView();

	void menuSelect(Ref* pSender);
private:
	int curPage;
	PageView* pageView;
};