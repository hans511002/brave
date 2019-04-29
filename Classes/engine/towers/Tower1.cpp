#include "MainClass.h"
#include "engine/World.h"
#include "engine/towers/UltraTowerMenu.h"
#include "engine/towers/TowerMenu.h"

namespace engine
{
    namespace towers
    {
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
			sphere1BulletCont = sphere1Bullet->cont;
			sphere1Bullet->gotoAndStop(5);
			sphere1Bullet->setPosition(sphere1Bullet->getPosition() + Vec2(0, -15));
			return true;
		}


        Tower1::Tower1() :firstTowerMenuCounter(8)
        {
            SET_NODETYPENAME();
        }// end function
        bool Tower1::init()
        {
            towerType = 1;
            correctYGrPos = -15;
            radius = Main::mainClass->readXMLClass.listOfSpheresRadius[0];
            slotsStack[0] = 0;// [0, 1, 1, 1];
            slotsStack[1] = 1;
            slotsStack[2] = 1;
            slotsStack[3] = 1;
            //slotsStack[4] = 1;
            Tower1_mc * cont= new Tower1_mc();
			container = cont;
            container->stop();
            //container->towerCase->stop();
            container->blockTower->stop();
            container->boneBlock->stop();
            //container->selectTower->stop();
            container->towerCase->setMouseEnabled(true);
            cont->blockTower->setVisible(false);
            cont->boneBlock->setVisible(false);
            cont->selectTower->setVisible(false);
            this->addChild(cont);
            cont->init();
            Tower::init(); 
            //this->setMouseChildren(false);
            //this->setMouseEnabled(false);
            if (!autoBuild)
            {
                AudioUtil::playSoundWithVol("Snd_tower_build.mp3", 0.95f);
            }
            return true; 
        }// end function
        void Tower1::update(float dt)
        {
            if(this->dead){
                this->remove();
                return;
            }
			Tower1_mc * container = ISTYPE(Tower1_mc,this->container);
            Tower::update();
            if (this->firstTowerMenuCounter > -1)
            {
                if (this->firstTowerMenuCounter > 0)
                {
                    firstTowerMenuCounter--;
                }
                else
                {
                    this->firstTowerMenuCounter = -1;
                    if (world->towerMenu != NULL)
                    {
                        world->towerMenu->closeMenu();
                    }
                    else if (world->ultraTowerMenu)
                    {
                        world->ultraTowerMenu->closeMenu();
                    }
                    world->towerMenu = new TowerMenu(this);
                    world->addChild(world->towerMenu,4);
                    world->towerMenu->init();
                    world->towerMenu->monitor();
                    this->setMouseChildren(true);
                    this->setMouseEnabled(true);
                }
            }
			container->tryPlay(0);
             
            if (spheresStack.size() == 1)
            {
				//container->sphere1Bullet->nextFram();

				container->sphere1->tryPlay(0);
				//if (container->sphere1->currentFrame < container->sphere1->totalFrames)
	//            {
	//                container->sphere1->tryPlay();
	//                //container->sphere1->gotoAndStop((container->sphere1->currentFrame + 1));
	//            }
	//            else
	//            {
	//                container->sphere1->gotoAndStop(1);
	//            }
				container->sphere1BulletCont->tryPlay(0);
                //if (container->sphere1BulletCont->currentFrame < container->sphere1BulletCont->totalFrames)
                //{
                //    container->sphere1BulletCont->tryPlay();
                //    //container->sphere1BulletCont->gotoAndStop((container->sphere1BulletCont->currentFrame + 1));
                //}
                //else
                //{
                //    container->sphere1BulletCont->gotoAndStop(1);
                //}
                
            }
            return;
        }// end function

    }
}
