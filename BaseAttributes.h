/************************************************************************/
/*          //����������                                                   */ 
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

	//����
	int baseHealth;//����������
	int baseStartingMoney;//�ҵ��ܽ��

	int rewardMedal;

	int baseMoneyDropped;//�Զ��ӽ��

	//-------------------������̨
    int basePersimmonCost;//������̨��Ǯ
    int basePersimmonDamage;//������С�˺�ֵ
    int basePersimmonDamageRandom;//������������˺�ֵ
    float basePersimmonFireRate;
    int basePersimmonRange;
    int basePersimmonlvlupCost1;
    int basePersimmonlvlupCost2;
    //-------------------Ģ����̨
    int baseMushroomsCost;
    int baseMushroomsDamage;
    int baseMushroomsDamageRandom;
    float baseMushroomsFireRate;
    int baseMushroomsRange;
    int baseMushroomslvlupCost1;
    int baseMushroomslvlupCost2;
    float baseMushroomsSplashDist;
    //-------------------������̨
    int basePineappleCost;
    int basePineappleDamage;
    int basePineappleDamageRandom;
    float basePineappleFireRate;
    int basePineappleRange;
    int basePineapplelvlupCost1;
    int basePineapplelvlupCost2;
    float basePineappleSpeedScale;//���ٱ���
    float basePineappleFreezeDur;//����ʱ��
    //-------------------�����̨
    int baseRocketCost;
    int baseRocketDamage;
    int baseRocketDamageRandom;
    float baseRocketFireRate;
    int baseRocketRange;
    int baseRocketlvlupCost1;
    int baseRocketlvlupCost2;
    //-------------------������̨
    int basePearCost;
    int basePearDamage;
    int basePearDamageRandom;
    float basePearFireRate;
    int basePearRange;
    int basePearlvlupCost1;
    int basePearlvlupCost2;
    float basePearPoisoningHarm;//�ж��˺�
    int basePearPoisonTimeMin;//�ж����ʱ��
	//    int basePearPoisonTimeRandom;//�ж�ʱ���������
    //-------------------���ؼ���̨
    int baseMoreCost;
    int baseMoreDamage;
    int baseMoreDamageRandom;
    float baseMoreFireRate;
    int baseMoreRange;
    int baseMorelvlupCost1;
    int baseMorelvlupCost2;
    float baseMorePoisoningHarm;//�ж��˺�
    int baseMorePoisonTimeMin;//�ж����ʱ��
    //    int basePearPoisonTimeRandom;//�ж�ʱ���������
    
    //-------------------������̨
    int baseDurianCost;
    int baseDurianDamage;
    int baseDurianDamageRandom;
    float baseDurianFireRate;
    int baseDurianRange;
    int baseDurianlvlupCost1;
    int baseDurianlvlupCost2;
    //-------------------ˮ����̨
    int baseMonsterCost;
    int baseMonsterDamage;
    int baseMonsterDamageRandom;
    float baseMonsterFireRate;
    int baseMonsterRange;
    int baseMonsterlvlupCost1;
    int baseMonsterlvlupCost2;
    float baseMonsterSplashDist;


    //============��===================
    //---����1
    int baseGrasshopper1CreepHealth;//�ֵ�Ѫ
    float baseGrasshopper1CreepMoveDur;//�ƶ��ٶ�
    int baseGrasshopper1CreepKilledScore;//�����ֺ�Ľ�ҽ���
    int baseGrasshopper1CreepDamage;//�ֶԻ��ص��˺�ֵ
    //---����2
    int baseGrasshopper2CreepHealth;
    float baseGrasshopper2CreepMoveDur;
    int baseGrasshopper2CreepKilledScore;
    int baseGrasshopper2CreepDamage;
    //---����3
    int baseGrasshopper3CreepHealth;
    float baseGrasshopper3CreepMoveDur;
    int baseGrasshopper3CreepKilledScore;
    int baseGrasshopper3CreepDamage;
    //---�׿ǳ�1
    int baseBeetle1CreepHealth;
    float baseBeetle1CreepMoveDur;
    int baseBeetle1CreepKilledScore;
    int baseBeetle1CreepDamage;
    //---�׿ǳ�2
    int baseBeetle2CreepHealth;
    float baseBeetle2CreepMoveDur;
    int baseBeetle2CreepKilledScore;
    int baseBeetle2CreepDamage;
    //---�׿ǳ�1
    int baseBeetle3CreepHealth;
    float baseBeetle3CreepMoveDur;
    int baseBeetle3CreepKilledScore;
    int baseBeetle3CreepDamage;
    //---����1
    int baseAnt1CreepHealth;
    float baseAnt1CreepMoveDur;
    int baseAnt1CreepKilledScore;
    int baseAnt1CreepDamage;
    //---����2
    int baseAnt2CreepHealth;
    float baseAnt2CreepMoveDur;
    int baseAnt2CreepKilledScore;
    int baseAnt2CreepDamage;
    //---����3
    int baseAnt3CreepHealth;
    float baseAnt3CreepMoveDur;
    int baseAnt3CreepKilledScore;
    int baseAnt3CreepDamage;
    //---�۷�1
    int baseBee1CreepHealth;
    float baseBee1CreepMoveDur;
    int baseBee1CreepKilledScore;
    int baseBee1CreepDamage;
    //---�۷�2
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

    //==========���߳�ʼ����==========
    int basePropsMedalCount,basePropsDoubleCount,basePropsLightningCount,basePropsBlizzardCount;
    int propsDoubleCost;
    int propsLightningCost;
    int propsBlizzardCost;
private:
	static BaseAttributes* m_baseAttributes;
};