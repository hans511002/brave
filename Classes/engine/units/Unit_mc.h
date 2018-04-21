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
			dragonBones::CCArmatureDisplay * airShock;// airshock;//public var airShock : MovieClip;

			//��Ѫbuff��ЧЧ�� ��25֡
			dragonBones::CCArmatureDisplay * buffHP;// buffhp;//public var buffHP : MovieClip;
			//����buff��ЧЧ�� �ظ���
			dragonBones::CCArmatureDisplay * buffSpeed;// buffspeed;//public var buffSpeed : MovieClip;
			//��ͨ�����Ч�� ֻ��һ��
			dragonBones::CCArmatureDisplay * fireAttack;// fireattack; public var fireAttack : MovieClip;
			//����𹥻�Ч�� ����������������ʼ:begin(ֻ��һ��)  ��������:continue(�ظ��� ��ʼ�������ظ�����������ʼ��Ӧǰ19֡��
			dragonBones::CCArmatureDisplay * fireEffect;// fireeffect; //public var fireEffect : MovieClip;
			//���������Ч�� ����������������ʼ:begin(ֻ��һ��)  ��������:continue(�ظ��� ��ʼ�������ظ�����������ʼ��Ӧǰ15֡��
			dragonBones::CCArmatureDisplay * iceEffect;// iceeffect;//public var iceEffect : MovieClip;
			//������Ч��
			dragonBones::CCArmatureDisplay *iceAttack;// iceattack; // public var iceAttack : MovieClip;
			//�����������Ч�� �ؼ���6֡��ǣ�aa
			dragonBones::CCArmatureDisplay * levinDeath;// levindeath; public var levinDeath : MovieClip;
			//ʯͷ��������Ч�� �ؼ���3֡��ǣ�aa
			dragonBones::CCArmatureDisplay * stoneDeath;// stonedeath;//public var stoneDeath : MovieClip;
			//����������Ч�� �ؼ���9֡��ǣ�aa
			dragonBones::CCArmatureDisplay * iceDeath;// icedeath; public var iceDeath : MovieClip;
			int iceDeathFlag;
			int stoneDeathFlag;
			int levinDeathFlag;
			//�ظ���
			dragonBones::CCArmatureDisplay * dust1;
			dragonBones::CCArmatureDisplay * dust2;
			dragonBones::CCArmatureDisplay * dust3;
			dragonBones::CCArmatureDisplay * dust4;
			//�������Ч��
			dragonBones::CCArmatureDisplay * levinAttack;// levinattack;//public var levinAttack : MovieClip;
			//�����ܱ��˹���Ч��  ����������iceman����:icemanlive  iceman����:icemandead  �����Ŷ�Ӧǰ45֡��
			dragonBones::CCArmatureDisplay * iceFreez;// icefreeze; public var iceFreez : MovieClip;

			//Ѫ�� ������healthbar_cont ��ǰ���ȣ�healthbar_getdamage
			HealthBar * healthBar;// healthbar; // public var healthBar : MovieClip;
			 
			cocos2d::Sprite * selectUnit;// selectunit; //public var selectUnit : MovieClip;

			dragonBones::CCArmatureDisplay *cont;// public var cont : MovieClip;


			dragonBones::CCArmatureDisplay * unitCase;// public var unitCase : MovieClip;
			dragonBones::CCArmatureDisplay * shadow;//public var shadow : MovieClip;
			dragonBones::CCArmatureDisplay * armor;//public var armor : MovieClip;
			dragonBones::CCArmatureDisplay * signal;
			dragonBones::CCArmatureDisplay * giveHealth1;
			dragonBones::CCArmatureDisplay * giveHealth2;
			dragonBones::CCArmatureDisplay * giveHealth3;
			dragonBones::CCArmatureDisplay * dustAnima;
			
			

			Unit_mc(Unit* unit,string contName, int typeUnit);
			void mcHandler(cocos2d::EventCustom *event);
			bool init();
			void stop();
		};

	}
}
#endif
