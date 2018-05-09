#ifndef UNITS_UNIT_MC_H
#define UNITS_UNIT_MC_H
#include "BaseHeaders.h"
#include "HealthBar.h"

namespace engine
{
	class World;
	namespace units
	{
		class Unit;
		class Unit_mc:public BaseNode {
		public:
			Common::HashTable2<string, int> attrFlag;
			Unit * unit;
			int typeUnit;
			string contName;
			//////////////////////////////////////////////////////////////////////////
			//airshock��ЧЧ�� �ظ���
			MovieClip * airShock;// airshock;//public var airShock : MovieClip;

			//��Ѫbuff��ЧЧ�� ��25֡
			MovieClip * buffHP;// buffhp;//public var buffHP : MovieClip;
			//����buff��ЧЧ�� �ظ���
			MovieClip * buffSpeed;// buffspeed;//public var buffSpeed : MovieClip;
			//��ͨ�����Ч�� ֻ��һ��
			MovieClip * fireAttack;// fireattack; public var fireAttack : MovieClip;
			//����𹥻�Ч�� ����������������ʼ:begin(ֻ��һ��)  ��������:continue(�ظ��� ��ʼ�������ظ�����������ʼ��Ӧǰ19֡��
			MovieClip  * fireEffect;// fireeffect; //public var fireEffect : MovieClip;
			//���������Ч�� ����������������ʼ:begin(ֻ��һ��)  ��������:continue(�ظ��� ��ʼ�������ظ�����������ʼ��Ӧǰ15֡��
			MovieClip * iceEffect;// iceeffect;//public var iceEffect : MovieClip;
			//������Ч��
			MovieClip *iceAttack;// iceattack; // public var iceAttack : MovieClip;
			//�����������Ч�� �ؼ���6֡��ǣ�aa
			MovieClip * levinDeath;// levindeath; public var levinDeath : MovieClip;
			//ʯͷ��������Ч�� �ؼ���3֡��ǣ�aa
			MovieClip * stoneDeath;// stonedeath;//public var stoneDeath : MovieClip;
			//����������Ч�� �ؼ���9֡��ǣ�aa
			MovieClip * iceDeath;// icedeath; public var iceDeath : MovieClip;
			int iceDeathFlag;
			int stoneDeathFlag;
			int levinDeathFlag;
			//�ظ���
			MovieClip * dust1;
			MovieClip * dust2;
			MovieClip * dust3;
			MovieClip * dust4;
			//�������Ч��
			MovieClip * levinAttack;// levinattack;//public var levinAttack : MovieClip;
			//�����ܱ��˹���Ч��  ����������iceman����:icemanlive  iceman����:icemandead  �����Ŷ�Ӧǰ45֡��
			MovieClip * iceFreez;// icefreeze; public var iceFreez : MovieClip;

			//Ѫ�� ������healthbar_cont ��ǰ���ȣ�healthbar_getdamage
			HealthBar * healthBar;// healthbar; // public var healthBar : MovieClip;
			 
			cocos2d::Sprite * selectUnit;// selectunit; //public var selectUnit : MovieClip;

			MovieClip *cont;// public var cont : MovieClip;


			MovieClip * unitCase;// public var unitCase : MovieClip;
			//MovieClip * shadow;//public var shadow : MovieClip; �ϲ���cont����
			MovieClip * armor;//public var armor : MovieClip;
			// 18 19
			MovieClip * signal;
			
			//28
			MovieClip * giveHealth1;
			MovieClip * giveHealth2;
			MovieClip * giveHealth3;
			
			//29 30
			MovieClip * dustAnima;
			
			//25
			MovieClip * maskCont;

			cocos2d::Point myFirstPoint;
            void onExit();
            MovieClipSub * contMcs;
            
			Unit_mc(Unit* unit,string contName, int typeUnit);
			void mcHandler(cocos2d::EventCustom *event);
			bool init();
			void stop();
 		};

	}
}
#endif
