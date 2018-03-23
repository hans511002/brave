#ifndef XML_READXML_H
#define XML_READXML_H
#include "BaseHeaders.h"
#include <math.h>  
#include "XmlConfigParser.h"

namespace engine
{
	class ReadXML
	{
	public:
		int i, j, n, m;
		int tempObject;
		int tempObject1 ;
		int tempObject2 ;
	protected:
		XMLConfigParser *xmlData;
		//protected var xmlLoaderData:URLLoader;
		XMLConfigParser *xmlDataLevels;
		//protected var xmlLoaderLevels : URLLoader;
	public:
		bool bezierBuildXML;
		int bezierRoadXML, bezierWayXML;
		float listOfEnemiesXML[40][40];
		int assasinVisTrueTimer1XML;
		int assasinVisTrueTimer2XML;
		int assasinVisFalseTimer1XML;
		int assasinVisFalseTimer2XML;
		int creationOfNewUnits1XML;
		int creationOfNewUnits2XML;
		int intervalTimerGolemXML;
		int intervalTimerIcemanXML;
		int intervalTimerAirXML;
		float castGolemHealthXML;
		float castGolemSpeedXML;
		float castIcemanSpeedXML;
		int castIcemanFreezTimerXML;
		int castIcemanLifeTimerXML;
		int castIcemanDamageXML;
		float  airPowerXML;
		float  airRadiusXML;
		int airLifeSecXML;
		float airSpacingXML;
		int airWaitTimerXML;
		int costTowerXML;
		int costTowerPlusXML;
		int costSlot2XML;
		int costSlot3XML;
		int costSlot4XML;
		Common::Array<int> listOfFirePriceXML;
		Common::Array<int>  listOfIcePriceXML;
		Common::Array<int>  listOfStonePriceXML;
		Common::Array<int>  listOfLevinPriceXML;
		float fireEffectDamageXML;
		float iceEffectSlowdown1XML;
		float iceEffectSlowdown2XML;
		float iceEffectSlowdown3XML;
		float iceEffectSlowdown4XML;
		float iceEffectSlowdown1TimerXML;
		float iceEffectSlowdown2TimerXML;
		float iceEffectSlowdown3TimerXML;
		float iceEffectSlowdown4TimerXML;
		float stoneEffectRadiusXML;
		float levinEffectDamageXML;
		float levinEffectRadiusXML;
		int listOfMoveFireXML[5];
		int listOfMoveIceXML[5];
		int listOfMoveStoneXML[5];
		int listOfMoveLevinXML[5];

		float listOfFireTowerDamageXML[4];
		float listOfIceTowerDamageXML[4];
		float listOfStoneTowerDamageXML[4];
		float listOfLevinTowerDamageXML[4];

		float towerFireEffectDamageXML;
		float towerIceEffectSlowdownXML[8];
		float towerStoneEffectRadiusXML;
		float towerLevinEffectDamageXML;
		float towerLevinEffectRadiusXML;
		int fireTowerIntervalXML;
		int iceTowerIntervalXML;
		int stoneTowerIntervalXML;
		int levinTowerIntervalXML;
		int ultraIceTimerXML;
		int ultraIceDurationXML;
		int ultraBallIceDurationXML;
		float ultraPunishFireDamageXML;
		int radiationLiveTimerXML;
		float radiationPercentOfDamageXML;
		float radiationscalingPercentageXML;
		float radiationPercentageOfDecelerationXML;
		float dustPathBeginXML;
		float dustPathEndXML;
		float dustNumberOfTimesXML;
		float dustPercentReductHealthXML;
		float dustTimerSecXML;
		int insiderTowerT1IntervalXML;
		int insiderTowerT1RadiusXML;
		int insiderTowerT1DamageXML;
		int insiderTowerT1AttackRadiusXML;
		int insiderTowerT2IntervalXML;
		int insiderTowerT2DamageXML;
		float insiderTowerT2SlowdownPowerPercentXML;
		int insiderTowerT2SlowdownHalfSecXML;
		int insiderTowerT3IntervalXML;
		int insiderTowerT3RadiusXML;
		int insiderTowerT3DamageXML;
		int insiderTowerT4IntervalXML;
		int insiderTowerT4RadiusXML;
		int insiderTowerT4DamageXML;
		float listOfSpheresRadius[4];
		int costUltraFireStone;
		int costUltraIceLevin;
		int costUltraIceStone;
		int costUltraFireLevin;
		int costUltraAddFireStone;
		int costUltraAddIceLevin;
		int costUltraAddIceStone;
		int costUltraAddFireLevin;
		int getAllLiveTimer;
		float getAllDamagePerSec;
		float getAllLittleMultiply;
		float getAllLittleDoubleMultiply;
		float getAllMultiply;
		float getAllMultiply1;
		float getAllMultiply2;
		int listOfFireProbability[4];
		int listOfIceProbability[4];
		int listOfLevinProbability[4];
		int autoStartCounter;
		int savingOfTimeCast;
		float ultraFireStoneDamageXML;
		float ultraFireStoneDamageRadiusXML;
		int ultraFireStoneIntervalXML;
		float ultraFireStoneRadiusXML;
		float ultraAddFireStoneDamageXML;
		int ultraAddFireStoneIntervalXML;
		float ultraAddFireStoneRadiusXML;
		float ultraAddFireStoneSlowdownTimerXML;
		float ultraIceLevinDamageXML;
		int ultraIceLevinIntervalXML;
		float ultraIceLevinRadiusXML;
		float ultraIceLevinSlowdownPowerXML;
		int ultraIceLevinSlowdownTimerXML;
		float ultraIceLevinLongXML;
		int ultraIceLevinMaxUnitsXML;
		float ultraAddIceLevinDamageXML;
		int ultraAddIceLevinIntervalXML;
		float ultraAddIceLevinDamageRadiusXML;
		int ultraAddIceLevinSlowdownTimerXML;
		float ultraIceStoneDamageXML;
		int ultraIceStoneIntervalXML;
		float ultraIceStoneRadiusXML;
		float ultraIceStoneDamageRadiusXML;
		float ultraIceStoneSlowdownPowerXML;
		int ultraIceStoneSlowdownTimerXML;
		float ultraAddIceStoneDamageXML;
		int ultraAddIceStoneIntervalXML;
		float ultraAddIceStoneRadiusXML;
		float ultraAddIceStoneSpacingXML;
		float ultraAddIceStonePowerXML;
		float ultraAddIceStoneSlowdownTimerXML;
		float ultraFireLevinDamageXML;
		int ultraFireLevinIntervalXML;
		float ultraFireLevinRadiusXML;
		float ultraFireLevinDamageRadiusXML;
		float ultraAddFireLevinDamageXML;
		int ultraAddFireLevinIntervalXML;
		float ultraAddFireLevinRadiusXML;
		int strategies;
		int archiveSphereBlock;
		int towerSlotBlock;
		int ultraTower1Block;
		int ultraTower2Block;
		int ultraTower3Block;
		int ultraTower4Block;
		int ultraTower1UpgrBlock;
		int ultraTower2UpgrBlock;
		int ultraTower3UpgrBlock;
		int ultraTower4UpgrBlock;
		float fireSellTax;
		float iceSellTax;
		float stoneSellTax;
		float levinSellTax;
		int levinCountPlus;

		template <class T = int> struct NUM5{
			T v[5]; 
			inline T & operator[](int i){
				return v[i];
			};
		};
		Common::Array<NUM5<float> > listOfFirePortals;
		Common::Array<NUM5<float> >  listOfIcePortals ;
		Common::Array<NUM5<float> >  listOfStonePortals ;
		Common::Array<NUM5<float> >  listOfLevinPortals ;
		float complexitySettingXML;// = 1;
		int bossArrayPhasePath[2][32];//14
		Common::Array<int> bossArrayOfEnemies0;
		Common::Array<int *> bossArrayOfEnemies1;

		//long long bossArrayOfEnemies[32][2];//[n][1] void * 4Î¬Êý×é

		int bossArrayOfView[32][2];
		int bossArrayOfArmor[16];
		int bossArrayOfCasts[16];
		int testTowerStep;
		int testFireStep;
		int testIceStep;
		int testStoneStep;
		int testLevinStep;

		ReadXML() :complexitySettingXML(1), xmlData(NULL), xmlDataLevels(NULL)
		{
			//for (int i = 0; i < 32; ++i)
			//{
			//	bossArrayOfEnemies[i][0] = 0;
			//	bossArrayOfEnemies[i][1] = 0;
			//}
		};// end function

		void loadXMLLevels(string param1);
		void loadXMLData();
	protected:
		void readXMLData();


		void readXMLLevels();

	};
}


#endif
