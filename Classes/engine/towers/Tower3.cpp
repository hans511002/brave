#include "MainClass.h"
#include "engine/World.h"
#include "TowerMenu.h"
#include "Tower3.h" 

namespace engine
{
    namespace towers
    { 
		Tower3_mc::Tower3_mc() :Tower2_mc("tower/", "Tower3_mc", "Tower3_mc")
		{
            SET_NODETYPENAME();
            //blockTower = this->createMovieClip("blockTower", "tower/", "blockTower", "TowerBlockBone");
			//boneBlock = this->createMovieClip("boneBlock", "tower/", "boneBlock", "TowerBlockBone");
			//selectTower = this->createMovieClipSub("selectTower");
			//towerCase = this->createCase("towerCase");

			//sphere1 = this->createMovieClipSub("sphere1");
			//sphere1Bullet = (BulletSphereTower_mc*)sphere1->createMovieClip("bullet", new BulletSphereTower_mc());
			//sphere1BulletCont = sphere1Bullet->createMovieClipSub("cont");

			//sphere2_1 = this->createMovieClipSub("sphere2_1");
			//sphere2_1Bullet = (BulletSphereTower_mc*)sphere2_1->createMovieClip("bullet", new BulletSphereTower_mc());
			//sphere2_1BulletCont = sphere2_1Bullet->createMovieClipSub("cont");
			//sphere2_2 = this->createMovieClipSub("sphere2_2");
			//sphere2_2Bullet = (BulletSphereTower_mc*)sphere2_2->createMovieClip("bullet", new BulletSphereTower_mc());
			//sphere2_2BulletCont = sphere2_2Bullet->createMovieClipSub("cont");

			sphere3_1 = this->createMovieClipSub("sphere3_1");
			sphere3_1Bullet = (BulletSphereTower_mc*)sphere3_1->createMovieClip("bullet", new BulletSphereTower_mc());
			sphere3_1BulletCont = sphere3_1Bullet->createMovieClipSub("cont");
			sphere3_2 = this->createMovieClipSub("sphere3_2");
			sphere3_2Bullet = (BulletSphereTower_mc*)sphere3_2->createMovieClip("bullet", new BulletSphereTower_mc());
			sphere3_2BulletCont = sphere3_2Bullet->createMovieClipSub("cont");
			sphere3_3 = this->createMovieClipSub("sphere3_3");
			sphere3_3Bullet = (BulletSphereTower_mc*)sphere3_3->createMovieClip("bullet", new BulletSphereTower_mc());
			sphere3_3BulletCont = sphere3_3Bullet->createMovieClipSub("cont");
		}
        Tower3::Tower3()
        {
            SET_NODETYPENAME();
            return;
        }// end function
 
        bool Tower3::init()
        {
            towerType = 3;
            correctYGrPos = -15;
            radius = Main::mainClass->readXMLClass.listOfSpheresRadius[2];
            //slotsStack = [0, 0, 0, 1];
            slotsStack[0]=0;
            slotsStack[1]=0;
            slotsStack[2]=0;
            slotsStack[3]=1;
            container = new Tower3_mc();
            container->stop();
            //container->towerCase->stop();
            container->blockTower->stop();
            container->boneBlock->stop();
            //container->selectTower->stop();
            container->towerCase->setMouseEnabled(true);
            container->blockTower->setVisible(false);
            container->boneBlock->setVisible(false);
            container->selectTower->setVisible(false);
            this->addChild(container);
            Tower::init( );
            if (!autoBuild)
            {
                //Sounds.instance.playSoundWithVol("snd_tower_build1", 0.9);
            }
            return true;
        }// end function

        void Tower3::update(float dt)
        {
            Tower::update();
			Tower3_mc * container = ISTYPE(Tower3_mc, this->container);
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
            else if (spheresStack.size() == 2)
            {
                if (container->sphere2_1->currentFrame < container->sphere2_1->totalFrames)
                {
                    container->sphere2_1->gotoAndStop((container->sphere2_1->currentFrame + 1));
                }
                else
                {
                    container->sphere2_1->gotoAndStop(1);
                }
                if (container->sphere2_1Bullet->currentFrame == 1)
                {
                    if (container->sphere2_1BulletCont->currentFrame < container->sphere2_1BulletCont->totalFrames)
                    {
                        container->sphere2_1BulletCont->gotoAndStop((container->sphere2_1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere2_1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere2_1Bullet->currentFrame == 2)
                {
                    if (container->sphere2_1BulletCont->currentFrame < container->sphere2_1BulletCont->totalFrames)
                    {
                        container->sphere2_1BulletCont->gotoAndStop((container->sphere2_1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere2_1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere2_1Bullet->currentFrame == 3)
                {
                    if (container->sphere2_1BulletCont->currentFrame < container->sphere2_1BulletCont->totalFrames)
                    {
                        container->sphere2_1BulletCont->gotoAndStop((container->sphere2_1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere2_1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere2_1Bullet->currentFrame == 4)
                {
                    if (container->sphere2_1BulletCont->currentFrame < container->sphere2_1BulletCont->totalFrames)
                    {
                        container->sphere2_1BulletCont->gotoAndStop((container->sphere2_1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere2_1BulletCont->gotoAndStop(1);
                    }
                }
                if (container->sphere2_2->currentFrame < container->sphere2_2->totalFrames)
                {
                    container->sphere2_2->gotoAndStop((container->sphere2_2->currentFrame + 1));
                }
                else
                {
                    container->sphere2_2->gotoAndStop(1);
                }
                if (container->sphere2_2Bullet->currentFrame == 1)
                {
                    if (container->sphere2_2BulletCont->currentFrame < container->sphere2_2BulletCont->totalFrames)
                    {
                        container->sphere2_2BulletCont->gotoAndStop((container->sphere2_2BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere2_2BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere2_2Bullet->currentFrame == 2)
                {
                    if (container->sphere2_2BulletCont->currentFrame < container->sphere2_2BulletCont->totalFrames)
                    {
                        container->sphere2_2BulletCont->gotoAndStop((container->sphere2_2BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere2_2BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere2_2Bullet->currentFrame == 3)
                {
                    if (container->sphere2_2BulletCont->currentFrame < container->sphere2_2BulletCont->totalFrames)
                    {
                        container->sphere2_2BulletCont->gotoAndStop((container->sphere2_2BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere2_2BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere2_2Bullet->currentFrame == 4)
                {
                    if (container->sphere2_2BulletCont->currentFrame < container->sphere2_2BulletCont->totalFrames)
                    {
                        container->sphere2_2BulletCont->gotoAndStop((container->sphere2_2BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere2_2BulletCont->gotoAndStop(1);
                    }
                }
            }
            else if (spheresStack.size() == 3)
            {
                if (container->sphere3_1->currentFrame < container->sphere3_1->totalFrames)
                {
                    container->sphere3_1->gotoAndStop((container->sphere3_1->currentFrame + 1));
                }
                else
                {
                    container->sphere3_1->gotoAndStop(1);
                }
                if (container->sphere3_1Bullet->currentFrame == 1)
                {
                    if (container->sphere3_1BulletCont->currentFrame < container->sphere3_1BulletCont->totalFrames)
                    {
                        container->sphere3_1BulletCont->gotoAndStop((container->sphere3_1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_1Bullet->currentFrame == 2)
                {
                    if (container->sphere3_1BulletCont->currentFrame < container->sphere3_1BulletCont->totalFrames)
                    {
                        container->sphere3_1BulletCont->gotoAndStop((container->sphere3_1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_1Bullet->currentFrame == 3)
                {
                    if (container->sphere3_1BulletCont->currentFrame < container->sphere3_1BulletCont->totalFrames)
                    {
                        container->sphere3_1BulletCont->gotoAndStop((container->sphere3_1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_1BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_1Bullet->currentFrame == 4)
                {
                    if (container->sphere3_1BulletCont->currentFrame < container->sphere3_1BulletCont->totalFrames)
                    {
                        container->sphere3_1BulletCont->gotoAndStop((container->sphere3_1BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_1BulletCont->gotoAndStop(1);
                    }
                }
                if (container->sphere3_2->currentFrame < container->sphere3_2->totalFrames)
                {
                    container->sphere3_2->gotoAndStop((container->sphere3_2->currentFrame + 1));
                }
                else
                {
                    container->sphere3_2->gotoAndStop(1);
                }
                if (container->sphere3_2Bullet->currentFrame == 1)
                {
                    if (container->sphere3_2BulletCont->currentFrame < container->sphere3_2BulletCont->totalFrames)
                    {
                        container->sphere3_2BulletCont->gotoAndStop((container->sphere3_2BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_2BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_2Bullet->currentFrame == 2)
                {
                    if (container->sphere3_2BulletCont->currentFrame < container->sphere3_2BulletCont->totalFrames)
                    {
                        container->sphere3_2BulletCont->gotoAndStop((container->sphere3_2BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_2BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_2Bullet->currentFrame == 3)
                {
                    if (container->sphere3_2BulletCont->currentFrame < container->sphere3_2BulletCont->totalFrames)
                    {
                        container->sphere3_2BulletCont->gotoAndStop((container->sphere3_2BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_2BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_2Bullet->currentFrame == 4)
                {
                    if (container->sphere3_2BulletCont->currentFrame < container->sphere3_2BulletCont->totalFrames)
                    {
                        container->sphere3_2BulletCont->gotoAndStop((container->sphere3_2BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_2BulletCont->gotoAndStop(1);
                    }
                }
                if (container->sphere3_3->currentFrame < container->sphere3_3->totalFrames)
                {
                    container->sphere3_3->gotoAndStop((container->sphere3_3->currentFrame + 1));
                }
                else
                {
                    container->sphere3_3->gotoAndStop(1);
                }
                if (container->sphere3_3Bullet->currentFrame == 1)
                {
                    if (container->sphere3_3BulletCont->currentFrame < container->sphere3_3BulletCont->totalFrames)
                    {
                        container->sphere3_3BulletCont->gotoAndStop((container->sphere3_3BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_3BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_3Bullet->currentFrame == 2)
                {
                    if (container->sphere3_3BulletCont->currentFrame < container->sphere3_3BulletCont->totalFrames)
                    {
                        container->sphere3_3BulletCont->gotoAndStop((container->sphere3_3BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_3BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_3Bullet->currentFrame == 3)
                {
                    if (container->sphere3_3BulletCont->currentFrame < container->sphere3_3BulletCont->totalFrames)
                    {
                        container->sphere3_3BulletCont->gotoAndStop((container->sphere3_3BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_3BulletCont->gotoAndStop(1);
                    }
                }
                else if (container->sphere3_3Bullet->currentFrame == 4)
                {
                    if (container->sphere3_3BulletCont->currentFrame < container->sphere3_3BulletCont->totalFrames)
                    {
                        container->sphere3_3BulletCont->gotoAndStop((container->sphere3_3BulletCont->currentFrame + 1));
                    }
                    else
                    {
                        container->sphere3_3BulletCont->gotoAndStop(1);
                    }
                }
            }
            return;
        }// end function
    }
}
