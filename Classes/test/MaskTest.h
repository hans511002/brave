#pragma once
#include "BaseNode.h"
namespace engine
{
	class LevelPointer :public MovieClip
	{
	public:
		MCCase * pointerCase;
		MovieClipSub * fireAnima;
		MovieClipSub * eyesAnima;
		MCMask * mask1;
		MCMask * mask2;
		Sprite * arrow;
		MCMask * mask3;//1
		MCMask * mask4;//2
		Sprite * mask5;//1 2
		MCCase * tcase1;
		MCCase * tcase2;

		LevelPointer();
		float counter;
		int timer;
		Vec2 myPoint;
		int statusAnima;
	};
	LevelPointer::LevelPointer() :MovieClip("worldinterface/", "pointer", "LevelBase"), statusAnima(0), timer(0), counter(0)
	{
		SET_NODETYPENAME();
		pointerCase = this->createCase("pointerCase");
		fireAnima = this->createMovieClipSub("fireAnima",false);
		eyesAnima = this->createMovieClipSub("eyesAnima");
		mask1 = this->createMask("mask1");
		mask2 = this->createMask("mask2");
		//mask1 = (Sprite*)this->getArmature()->getSlot("mask1")->getDisplay();
		//mask2 = (Sprite*)this->getArmature()->getSlot("mask2")->getDisplay();
		arrow = (Sprite*)this->getArmature()->getSlot("arrow")->getDisplay();
		mask3 = this->createMask("mask3");
		mask4 = this->createMask("mask4");
		mask5 = (Sprite*)this->getArmature()->getSlot("mask5")->getDisplay();
		tcase1 = fireAnima->createCase("Layer 1");
		tcase2 = eyesAnima->createCase("Layer 1");
	};


	struct TowerBase_mc :public MovieClip
	{
		MovieClip * blockTower;
		MovieClip * boneBlock;
		MCCase * towerCase;
		Tower * myParent;
		MCMask * selectTower;
		TowerBase_mc(const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "") :towerCase(0)
			, MovieClip(rootPath, armName, dbName, defAniName), myParent(0)
		{
			blockTower = this->createMovieClip("blockTower", "tower/", "blockTower", "TowerBlockBone");
			boneBlock = this->createMovieClip("boneBlock", "tower/", "boneBlock", "TowerBlockBone");
			towerCase = this->createCase("towerCase");
		};

	};
	struct BulletSphereTower_mc : public MovieClip
	{
		MovieClip * cont;
		int counter;
		BulletSphereTower_mc();
	};
	BulletSphereTower_mc::BulletSphereTower_mc() :MovieClip("sphere/", "BulletSphereTower_mc", "BulletSphereTower_mc"), cont(0), counter(0)
	{
		SET_NODETYPENAME();
		//cont=this->createMovieClip("sphere/","cont","BulletSpheresTower_mc");//合并多个在一个db中
	}
	struct Tower1_mc :public TowerBase_mc
	{
	public:
		MovieClipSub * sphere1;
		BulletSphereTower_mc * sphere1Bullet;
		MovieClipSub * sphere1BulletCont;
		Tower1_mc(const string &  rootPath, const string &  armName, const string &  dbName, const string &  defAniName = "");
		Tower1_mc();
		virtual bool init();
	};
	Tower1_mc::Tower1_mc(const string &  rootPath, const string &  armName, const string &  dbName, const string & defAniName) : TowerBase_mc(rootPath, armName, dbName, defAniName)
	{
		init();
	};

	Tower1_mc::Tower1_mc() :TowerBase_mc("tower/", "Tower1_mc", "Tower1_mc")
	{
		init();
	}
	bool Tower1_mc::init() {
		TowerBase_mc::init();
		SET_NODETYPENAME();
		selectTower = this->createMask("selectTower");
		sphere1 = this->createMovieClipSub("sphere1");
		sphere1Bullet = (BulletSphereTower_mc*)sphere1->createMovieClip("bullet", new BulletSphereTower_mc());
		sphere1BulletCont = sphere1Bullet->createMovieClipSub("cont", true);
		return true;
	}
}
