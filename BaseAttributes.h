/************************************************************************/
/*          //属性数据类                                                   */ 
/************************************************************************/
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class BaseAttributes : public Ref
{
public:
	BaseAttributes();
	virtual ~BaseAttributes();
	static BaseAttributes* getInstance();
	virtual bool init();
public:
	int towerIndex[10][4];
	float scaleHP;

	//属性
	int baseHealth;//基地总生命
	int baseStartingMoney;//我的总金币

	int rewardMedal;

	int baseMoneyDropped;//自动加金币

	//-------------------柿子炮台
    int basePersimmonCost;//柿子炮台价钱
    int basePersimmonDamage;//柿子最小伤害值
    int basePersimmonDamageRandom;//柿子随机附加伤害值
    float basePersimmonFireRate;
    int basePersimmonRange;
    int basePersimmonlvlupCost1;
    int basePersimmonlvlupCost2;
    //-------------------蘑菇炮台
    int baseMushroomsCost;
    int baseMushroomsDamage;
    int baseMushroomsDamageRandom;
    float baseMushroomsFireRate;
    int baseMushroomsRange;
    int baseMushroomslvlupCost1;
    int baseMushroomslvlupCost2;
    float baseMushroomsSplashDist;
    //-------------------菠萝炮台
    int basePineappleCost;
    int basePineappleDamage;
    int basePineappleDamageRandom;
    float basePineappleFireRate;
    int basePineappleRange;
    int basePineapplelvlupCost1;
    int basePineapplelvlupCost2;
    float basePineappleSpeedScale;//降速比例
    float basePineappleFreezeDur;//冰冻时间
    //-------------------火箭炮台
    int baseRocketCost;
    int baseRocketDamage;
    int baseRocketDamageRandom;
    float baseRocketFireRate;
    int baseRocketRange;
    int baseRocketlvlupCost1;
    int baseRocketlvlupCost2;
    //-------------------梨子炮台
    int basePearCost;
    int basePearDamage;
    int basePearDamageRandom;
    float basePearFireRate;
    int basePearRange;
    int basePearlvlupCost1;
    int basePearlvlupCost2;
    float basePearPoisoningHarm;//中毒伤害
    int basePearPoisonTimeMin;//中毒最短时间
	//    int basePearPoisonTimeRandom;//中毒时间随机增加
    //-------------------多重箭炮台
    int baseMoreCost;
    int baseMoreDamage;
    int baseMoreDamageRandom;
    float baseMoreFireRate;
    int baseMoreRange;
    int baseMorelvlupCost1;
    int baseMorelvlupCost2;
    float baseMorePoisoningHarm;//中毒伤害
    int baseMorePoisonTimeMin;//中毒最短时间
    //    int basePearPoisonTimeRandom;//中毒时间随机增加
    
    //-------------------榴莲炮台
    int baseDurianCost;
    int baseDurianDamage;
    int baseDurianDamageRandom;
    float baseDurianFireRate;
    int baseDurianRange;
    int baseDurianlvlupCost1;
    int baseDurianlvlupCost2;
    //-------------------水怪炮台
    int baseMonsterCost;
    int baseMonsterDamage;
    int baseMonsterDamageRandom;
    float baseMonsterFireRate;
    int baseMonsterRange;
    int baseMonsterlvlupCost1;
    int baseMonsterlvlupCost2;
    float baseMonsterSplashDist;


    //============怪===================
    //---蛐蛐1
    int baseGrasshopper1CreepHealth;//怪的血
    float baseGrasshopper1CreepMoveDur;//移动速度
    int baseGrasshopper1CreepKilledScore;//打死怪后的金币奖励
    int baseGrasshopper1CreepDamage;//怪对基地的伤害值
    //---蛐蛐2
    int baseGrasshopper2CreepHealth;
    float baseGrasshopper2CreepMoveDur;
    int baseGrasshopper2CreepKilledScore;
    int baseGrasshopper2CreepDamage;
    //---蛐蛐3
    int baseGrasshopper3CreepHealth;
    float baseGrasshopper3CreepMoveDur;
    int baseGrasshopper3CreepKilledScore;
    int baseGrasshopper3CreepDamage;
    //---甲壳虫1
    int baseBeetle1CreepHealth;
    float baseBeetle1CreepMoveDur;
    int baseBeetle1CreepKilledScore;
    int baseBeetle1CreepDamage;
    //---甲壳虫2
    int baseBeetle2CreepHealth;
    float baseBeetle2CreepMoveDur;
    int baseBeetle2CreepKilledScore;
    int baseBeetle2CreepDamage;
    //---甲壳虫1
    int baseBeetle3CreepHealth;
    float baseBeetle3CreepMoveDur;
    int baseBeetle3CreepKilledScore;
    int baseBeetle3CreepDamage;
    //---蚂蚁1
    int baseAnt1CreepHealth;
    float baseAnt1CreepMoveDur;
    int baseAnt1CreepKilledScore;
    int baseAnt1CreepDamage;
    //---蚂蚁2
    int baseAnt2CreepHealth;
    float baseAnt2CreepMoveDur;
    int baseAnt2CreepKilledScore;
    int baseAnt2CreepDamage;
    //---蚂蚁3
    int baseAnt3CreepHealth;
    float baseAnt3CreepMoveDur;
    int baseAnt3CreepKilledScore;
    int baseAnt3CreepDamage;
    //---蜜蜂1
    int baseBee1CreepHealth;
    float baseBee1CreepMoveDur;
    int baseBee1CreepKilledScore;
    int baseBee1CreepDamage;
    //---蜜蜂2
    int baseBee2CreepHealth;
    float baseBee2CreepMoveDur;
    int baseBee2CreepKilledScore;
    int baseBee2CreepDamage;
    //---BOSS1
    int baseBoss1CreepHealth;
  float baseBoss1CreepMoveDur;
    int baseBoss1CreepKilledScore;
    int baseBoss1CreepDamage;
    //---BOSS2
    int baseBoss2CreepHealth;
    float baseBoss2CreepMoveDur;
    int baseBoss2CreepKilledScore;
    int baseBoss2CreepDamage;
    //---BOSS3
    int baseBoss3CreepHealth;
    float baseBoss3CreepMoveDur;
    int baseBoss3CreepKilledScore;
    int baseBoss3CreepDamage;
    //---BOSS4
    int baseBoss4CreepHealth;
    float baseBoss4CreepMoveDur;
    int baseBoss4CreepKilledScore;
    int baseBoss4CreepDamage;
    //---BOSS5
    int baseBoss5CreepHealth;
    float baseBoss5CreepMoveDur;
    int baseBoss5CreepKilledScore;
    int baseBoss5CreepDamage;
    //---BOSS6
    int baseBoss6CreepHealth;
    float baseBoss6CreepMoveDur;
    int baseBoss6CreepKilledScore;
    int baseBoss6CreepDamage;
    //---BOSS7
    int baseBoss7CreepHealth;
    float baseBoss7CreepMoveDur;
    int baseBoss7CreepKilledScore;
    int baseBoss7CreepDamage;
    //----Boss 8
    int baseBoss8CreepHealth;
    float baseBoss8CreepMoveDur;
    int baseBoss8CreepKilledScore;
    int baseBoss8CreepDamage;

    //----Boss 9
    int baseBoss9CreepHealth;
    float baseBoss9CreepMoveDur;
    int baseBoss9CreepKilledScore;
    int baseBoss9CreepDamage;

    //==========道具初始数量==========
    int basePropsMedalCount,basePropsDoubleCount,basePropsLightningCount,basePropsBlizzardCount;
    int propsDoubleCost;
    int propsLightningCost;
    int propsBlizzardCost;
private:
	static BaseAttributes* m_baseAttributes;
};