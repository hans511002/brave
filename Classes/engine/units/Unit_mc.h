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
			dragonBones::DBCCArmatureNode * airShock;// airshock;//public var airShock : MovieClip;

			//��Ѫbuff��ЧЧ�� ��25֡
			dragonBones::DBCCArmatureNode * buffHP;// buffhp;//public var buffHP : MovieClip;
			//����buff��ЧЧ�� �ظ���
			dragonBones::DBCCArmatureNode * buffSpeed;// buffspeed;//public var buffSpeed : MovieClip;
			//��ͨ�����Ч�� ֻ��һ��
			dragonBones::DBCCArmatureNode * fireAttack;// fireattack; public var fireAttack : MovieClip;
			//����𹥻�Ч�� ����������������ʼ:begin(ֻ��һ��)  ��������:continue(�ظ��� ��ʼ�������ظ�����������ʼ��Ӧǰ19֡��
			dragonBones::DBCCArmatureNode * fireEffect;// fireeffect; //public var fireEffect : MovieClip;
			//���������Ч�� ����������������ʼ:begin(ֻ��һ��)  ��������:continue(�ظ��� ��ʼ�������ظ�����������ʼ��Ӧǰ15֡��
			dragonBones::DBCCArmatureNode * iceEffect;// iceeffect;//public var iceEffect : MovieClip;
			//������Ч��
			dragonBones::DBCCArmatureNode *iceAttack;// iceattack; // public var iceAttack : MovieClip;
			//�����������Ч�� �ؼ���6֡��ǣ�aa
			dragonBones::DBCCArmatureNode * levinDeath;// levindeath; public var levinDeath : MovieClip;
			//ʯͷ��������Ч�� �ؼ���3֡��ǣ�aa
			dragonBones::DBCCArmatureNode * stoneDeath;// stonedeath;//public var stoneDeath : MovieClip;
			//����������Ч�� �ؼ���9֡��ǣ�aa
			dragonBones::DBCCArmatureNode * iceDeath;// icedeath; public var iceDeath : MovieClip;
			int iceDeathFlag;
			int stoneDeathFlag;
			int levinDeathFlag;
			//�ظ���
			dragonBones::DBCCArmatureNode * dust1;
			dragonBones::DBCCArmatureNode * dust2;
			dragonBones::DBCCArmatureNode * dust3;
			dragonBones::DBCCArmatureNode * dust4;
			//�������Ч��
			dragonBones::DBCCArmatureNode * levinAttack;// levinattack;//public var levinAttack : MovieClip;
			//�����ܱ��˹���Ч��  ����������iceman����:icemanlive  iceman����:icemandead  �����Ŷ�Ӧǰ45֡��
			dragonBones::DBCCArmatureNode * iceFreez;// icefreeze; public var iceFreez : MovieClip;

			//Ѫ�� ������healthbar_cont ��ǰ���ȣ�healthbar_getdamage
			HealthBar * healthBar;// healthbar; // public var healthBar : MovieClip;
			 
			cocos2d::Sprite * selectUnit;// selectunit; //public var selectUnit : MovieClip;

			dragonBones::DBCCArmatureNode *cont;// public var cont : MovieClip;


			dragonBones::DBCCArmatureNode * unitCase;// public var unitCase : MovieClip;
			dragonBones::DBCCArmatureNode * shadow;//public var shadow : MovieClip;
			dragonBones::DBCCArmatureNode * armor;//public var armor : MovieClip;
			dragonBones::DBCCArmatureNode * signal;
			dragonBones::DBCCArmatureNode * giveHealth1;
			dragonBones::DBCCArmatureNode * giveHealth2;
			dragonBones::DBCCArmatureNode * giveHealth3;
			dragonBones::DBCCArmatureNode * dustAnima;
			
			

			Unit_mc(Unit* unit,string contName, int typeUnit);
			void mcHandler(cocos2d::EventCustom *event);
			bool init();
			void stop();
		};

	}
}
#endif
