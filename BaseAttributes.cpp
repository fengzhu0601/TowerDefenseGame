#include "BaseAttributes.h"

BaseAttributes* BaseAttributes::m_baseAttributes = nullptr;

BaseAttributes::BaseAttributes()
{

}

BaseAttributes::~BaseAttributes()
{

}

BaseAttributes* BaseAttributes::getInstance()
{
	m_baseAttributes = new BaseAttributes();
	if (m_baseAttributes && m_baseAttributes->init())
	{
		m_baseAttributes->autorelease();
		return m_baseAttributes;
	}
	else
	{
		delete m_baseAttributes;
		m_baseAttributes = nullptr;
	}
	return m_baseAttributes;
}

bool BaseAttributes::init()
{
	towerIndex[0][0] = 0;
	towerIndex[0][1] = 0;
	towerIndex[0][2] = 0;
	towerIndex[0][3] = 0;

	towerIndex[1][0] = 1;
	towerIndex[1][1] = 1;
	towerIndex[1][2] = 1;
	towerIndex[1][3] = 1;

	towerIndex[2][0] = 2;
	towerIndex[2][1] = 2;
	towerIndex[2][2] = 2;
	towerIndex[2][3] = 2;

	towerIndex[3][0] = 3;
	towerIndex[3][1] = 3;
	towerIndex[3][2] = 3;
	towerIndex[3][3] = 3;

	towerIndex[4][0] = 4;
	towerIndex[4][1] = 4;
	towerIndex[4][2] = 4;
	towerIndex[4][3] = 4;

	towerIndex[5][0] = 5;
	towerIndex[5][1] = 5;
	towerIndex[5][2] = 5;
	towerIndex[5][3] = 5;

	towerIndex[6][0] = 6;
	towerIndex[6][1] = 6;
	towerIndex[6][2] = 6;
	towerIndex[6][3] = 6;

	towerIndex[7][0] = 5;
	towerIndex[7][1] = 5;
	towerIndex[7][2] = 5;
	towerIndex[7][3] = 5;

	towerIndex[8][0] = 7;
	towerIndex[8][1] = 7;
	towerIndex[8][2] = 7;
	towerIndex[8][3] = 7;

	towerIndex[9][0] = 8;
	towerIndex[9][1] = 8;
	towerIndex[9][2] = 8;
	towerIndex[9][3] = 8;


    scaleHP=0.4f;
    
    baseHealth = 10;//基地血条
    baseStartingMoney = 500;//初始总金币
    rewardMedal=2;//奖励勋章
//    baseMoneyRegen = 25;//自动加时第次加多少钱
//    baseMoneyRegenRate = 5.0; //多长时间加一次
    baseMoneyDropped = 8;//Affects how much money is dropped by a creep (maximum +1)
//    baseTowerCostPercentage = 1; //炮台*倍数=新炮台钱
    //=========炮台===========
    //-------------柿子炮台（普通功击）----------------------------------------
    basePersimmonCost = 100;//柿子炮台价钱
    basePersimmonlvlupCost1 = 150;//升级所需的钱
    basePersimmonlvlupCost2 = 180;
    basePersimmonDamage = 15;//最小伤害值
    basePersimmonDamageRandom = 5;//随机增加伤害值范围
    basePersimmonFireRate = 0.6f;//炮台发射间隔
    basePersimmonRange = 120;//炮台攻击范围
    //-------------菠萝炮台(可以穿透攻击，可攻击直线上的多个怪物)----------------------------------------
    basePineappleCost = 130;//菠萝炮台钱
    basePineapplelvlupCost1 = 150;//升级所需的钱
    basePineapplelvlupCost2 = 200;
    basePineappleDamage = 5;//最小功击(穿刺会多次伤害功击力要减少)
    basePineappleDamageRandom = 1;//随机增加伤害值范围
    basePineappleFireRate = 2.0;//炮台发射间隔
    basePineappleRange = 140;//炮台攻击范围
    //-------------梨子炮台(单体目标受到攻击伤害的同时，持续伤害2-5秒)----------------------------------------
    basePearCost = 175;//梨钱
    basePearlvlupCost1 = 225;//升级所需的钱
    basePearlvlupCost2 = 275;
    basePearDamage = 15;//最小功击
    basePearDamageRandom = 5;//随机增加伤害值范围
    basePearFireRate = 1.7f;//炮台发射间隔
    basePearRange = 150;//炮台攻击范围
    basePearPoisonTimeMin=5;//最小中毒时间
    basePearPoisoningHarm = 10;//中毒伤害
    //------------榴莲炮台(范围攻击目标的同时，使目标减速)----------------------------------------
    baseDurianCost=350;//榴莲炮台钱
    baseDurianlvlupCost1=400;//升级所需的钱
    baseDurianlvlupCost2=480;
    baseDurianDamage=10;//最小功击
    baseDurianDamageRandom=5;//随机增加伤害值范围
    baseDurianFireRate=3.5;//炮台发射间隔
    baseDurianRange=150;//炮台攻击范围
    basePineappleSpeedScale=0.50;//减速多少
    basePineappleFreezeDur = 1;//减速效果时长
    //-------------------蘑菇炮台(溅射伤害)----------------------------------------
    baseMushroomsCost=250;
    baseMushroomsDamage=20;
    baseMushroomsDamageRandom=5;
    baseMushroomsFireRate=2.5;
    baseMushroomsRange=110;
    baseMushroomslvlupCost1=250;
    baseMushroomslvlupCost2=300;
    baseMushroomsSplashDist=80;
    //-------------水怪炮台(攻击范围内的怪物进行冰冻攻击，使其无法动弹)
    baseMonsterCost=300;
    baseMonsterDamage=10;
    baseMonsterDamageRandom=10;
    baseMonsterFireRate=3.5;
    baseMonsterRange=160;
    baseMonsterlvlupCost1=350;
    baseMonsterlvlupCost2=450;
    baseMonsterSplashDist=70;
    //------------多重箭炮台(攻击多个敌人，使目标受毒气伤害持续2-5秒)----------------------------------------
    baseMoreCost=350;
    baseMoreDamage=30;
    baseMoreDamageRandom=10;
    baseMoreFireRate=2.5;
    baseMoreRange=160;
    baseMorelvlupCost1=400;
    baseMorelvlupCost2=520;
    baseMorePoisoningHarm=12;//中毒伤害
    baseMorePoisonTimeMin=5;//中毒最短时间
    //-------------火箭炮台(在穿透攻击的最后一刻爆炸，使目标受到多重伤害)----------------------------------------
    baseRocketCost=450;
    baseRocketDamage=15;
    baseRocketDamageRandom=5;
    baseRocketFireRate=4.5;
    baseRocketRange=200;
    baseRocketlvlupCost1=550;
    baseRocketlvlupCost2=600;



    
    //==============怪===============
    baseGrasshopper1CreepHealth = 10; //红怪的血
    baseGrasshopper1CreepMoveDur = 0.8f;//移动速度
    baseGrasshopper1CreepKilledScore = 15;//打死怪后的金币奖励
    baseGrasshopper1CreepDamage=1;//怪对基地的伤害值
    
    baseGrasshopper2CreepHealth = 80;
    baseGrasshopper2CreepMoveDur = 1.5;
    baseGrasshopper2CreepKilledScore = 20;
    baseGrasshopper2CreepDamage=1;
    
    baseGrasshopper3CreepHealth = 100;
    baseGrasshopper3CreepMoveDur = 1.8f;
    baseGrasshopper3CreepKilledScore = 20;
    baseGrasshopper3CreepDamage=1;
    //----------甲壳虫-----------
    baseBeetle1CreepHealth=120;
    baseBeetle1CreepMoveDur=1.2f;
    baseBeetle1CreepKilledScore=22;
    baseBeetle1CreepDamage=1;
    
    baseBeetle2CreepHealth=130;
    baseBeetle2CreepMoveDur=1.1f;
    baseBeetle2CreepKilledScore=25;
    baseBeetle2CreepDamage=1;
    
    baseBeetle3CreepHealth=140;
    baseBeetle3CreepMoveDur=1.2f;
    baseBeetle3CreepKilledScore=28;
    baseBeetle3CreepDamage=1;
    //----------蚂蚁-----------
    baseAnt1CreepHealth=140;
    baseAnt1CreepMoveDur=1.0;
    baseAnt1CreepKilledScore=25;
    baseAnt1CreepDamage=1;
    
    baseAnt2CreepHealth=150;
    baseAnt2CreepMoveDur=1.1f;
    baseAnt2CreepKilledScore=70;
    baseAnt2CreepDamage=1;
    
    baseAnt3CreepHealth=160;
    baseAnt3CreepMoveDur=1.2f;
    baseAnt3CreepKilledScore=25;
    baseAnt3CreepDamage=1;
    //----------蜜蜂-----------
    baseBee1CreepHealth=70;
    baseBee1CreepMoveDur=0.5;
    baseBee1CreepKilledScore=10;
    baseBee1CreepDamage=1;
    
    baseBee2CreepHealth=175;
    baseBee2CreepMoveDur=0.5;
    baseBee2CreepKilledScore=12;
    baseBee2CreepDamage=1;
    //----------BOSS-----------
    baseBoss1CreepHealth=2000;
    baseBoss1CreepMoveDur=3;
    baseBoss1CreepKilledScore=500;
    baseBoss1CreepDamage=2;
    
    baseBoss2CreepHealth=2500;
    baseBoss2CreepMoveDur=3;
    baseBoss2CreepKilledScore=600;
    baseBoss2CreepDamage=2;
    
    baseBoss3CreepHealth=3000;
    baseBoss3CreepMoveDur=3;
    baseBoss3CreepKilledScore=700;
    baseBoss3CreepDamage=2;
    
    baseBoss4CreepHealth=3500;
    baseBoss4CreepMoveDur=2.5;
    baseBoss4CreepKilledScore=800;
    baseBoss4CreepDamage=2;
    
    baseBoss5CreepHealth=3500;
    baseBoss5CreepMoveDur=2;
    baseBoss5CreepKilledScore=1000;
    baseBoss5CreepDamage=2;
    
    baseBoss6CreepHealth=3800;
    baseBoss6CreepMoveDur=3;
    baseBoss6CreepKilledScore=1200;
    baseBoss6CreepDamage=2;
    
    baseBoss7CreepHealth=3800;
    baseBoss7CreepMoveDur=2.8f;
    baseBoss7CreepKilledScore=1400;
    baseBoss7CreepDamage=2;
    

    baseBoss8CreepHealth=4000;
    baseBoss8CreepMoveDur=2.8f;
    baseBoss8CreepKilledScore=1600;
    baseBoss8CreepDamage=2;


    baseBoss9CreepHealth=4200;
    baseBoss9CreepMoveDur=2.8f;
    baseBoss9CreepKilledScore=1800;
    baseBoss9CreepDamage=2;

//    baseCreepDamage = 20; // The Ammount a creep hurts your base.
    
    //========道具数量=============
    basePropsMedalCount=500;//勋章数
    basePropsDoubleCount=3;
     propsDoubleCost=50;
    basePropsLightningCount=3;
    propsLightningCost=100;
    basePropsBlizzardCount=3;
    propsBlizzardCost=100;
	return true;
}