#pragma once
#include "BaseNode.h"
namespace engine
{
	

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
