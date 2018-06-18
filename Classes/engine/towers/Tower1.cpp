#include "MainClass.h"
#include "engine/World.h"
#include "engine/towers/UltraTowerMenu.h"
#include "engine/towers/TowerMenu.h"

namespace engine
{
    namespace towers
    {
		Tower1_mc::Tower1_mc() :TowerBase_mc("tower/", "Tower1_mc", "Tower1_mc")
		{
			selectTower = this->createMovieClipSub("selectTower");
			sphere1 = this->createMovieClipSub("sphere1");
			sphere1Bullet = (BulletSphereTower_mc*)sphere1->createMovieClip("bullet", new BulletSphereTower_mc());
			sphere1BulletCont = sphere1Bullet->createMovieClipSub("cont");
		}

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
            container->selectTower->stop();
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
                //Sounds.instance.playSoundWithVol("snd_tower_build", 0.95);
            }
            return true; 
        }// end function
        void Tower1::update(float dt)
        {
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
                    world->addChild(world->towerMenu);
                    world->towerMenu->monitor();
                    this->setMouseChildren(true);
                    this->setMouseEnabled(true);
                }
            }
            if (world->frameCounter % 2)
            {
                if (container->currentFrame < container->totalFrames)
                {
                    container->gotoAndStop((container->currentFrame + 1));
                }
                else
                {
                    container->gotoAndStop(1);
                }
            }
            if (spheresStack.size() == 1)
            {
                if (container->sphere1->currentFrame < container->sphere1->totalFrames)
                {
                    container->sphere1->gotoAndStop((container->sphere1->currentFrame + 1));
                }
                else
                {
                    container->sphere1->gotoAndStop(1);
                }
                if (container->sphere1Bullet->currentFrame == 1)
                {
                    if (container->sphere1BulletCont->currentFrame < container->sphere1BulletCont->totalFrames)
                    {
                        container->sphere1BulletCont->gotoAndStop((container->sphere1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere1Bullet->currentFrame == 2)
                {
                    if (container->sphere1BulletCont->currentFrame < container->sphere1BulletCont->totalFrames)
                    {
                        container->sphere1BulletCont->gotoAndStop((container->sphere1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere1Bullet->currentFrame == 3)
                {
                    if (container->sphere1BulletCont->currentFrame < container->sphere1BulletCont->totalFrames)
                    {
                        container->sphere1BulletCont->gotoAndStop((container->sphere1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere1Bullet->currentFrame == 4)
                {
                    if (container->sphere1BulletCont->currentFrame < container->sphere1BulletCont->totalFrames)
                    {
                        container->sphere1BulletCont->gotoAndStop((container->sphere1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere1BulletCont->gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function

    }
}
