#include "MainClass.h"
#include "engine/World.h"
#include "TowerMenu.h"
#include "Tower4.h" 

namespace engine
{
    namespace towers
    {
		Tower4_mc::Tower4_mc() :Tower3_mc("tower/", "Tower4_mc", "Tower4_mc")
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

			//sphere3_1 = this->createMovieClipSub("sphere3_1");
			//sphere3_1Bullet = (BulletSphereTower_mc*)sphere3_1->createMovieClip("bullet", new BulletSphereTower_mc());
			//sphere3_1BulletCont = sphere3_1Bullet->createMovieClipSub("cont");
			//sphere3_2 = this->createMovieClipSub("sphere3_2");
			//sphere3_2Bullet = (BulletSphereTower_mc*)sphere3_2->createMovieClip("bullet", new BulletSphereTower_mc());
			//sphere3_2BulletCont = sphere3_2Bullet->createMovieClipSub("cont");
			//sphere3_3 = this->createMovieClipSub("sphere3_3");
			//sphere3_3Bullet = (BulletSphereTower_mc*)sphere3_3->createMovieClip("bullet", new BulletSphereTower_mc());
			//sphere3_3BulletCont = sphere3_3Bullet->createMovieClipSub("cont");
			init();

		}
		bool Tower4_mc::init() {
			Tower3_mc::init();
			SET_NODETYPENAME();
			sphere4_1 = this->createMovieClipSub("sphere4_1");
			sphere4_1Bullet = (BulletSphereTower_mc*)sphere4_1->createMovieClip("bullet", new BulletSphereTower_mc());
			sphere4_1BulletCont = sphere4_1Bullet->cont;//createMovieClipSub("cont", true);
			sphere4_2 = this->createMovieClipSub("sphere4_2");
			sphere4_2Bullet = (BulletSphereTower_mc*)sphere4_2->createMovieClip("bullet", new BulletSphereTower_mc());
			sphere4_2BulletCont = sphere4_2Bullet->cont;//createMovieClipSub("cont", true);
			sphere4_3 = this->createMovieClipSub("sphere4_3");
			sphere4_3Bullet = (BulletSphereTower_mc*)sphere4_3->createMovieClip("bullet", new BulletSphereTower_mc());
			sphere4_3BulletCont = sphere4_3Bullet->cont;//createMovieClipSub("cont", true);
			sphere4_4 = this->createMovieClipSub("sphere4_4");
			sphere4_4Bullet = (BulletSphereTower_mc*)sphere4_4->createMovieClip("bullet", new BulletSphereTower_mc());
			sphere4_4BulletCont = sphere4_4Bullet->cont;//createMovieClipSub("cont", true);
			sphere4_1Bullet->gotoAndStop(5);
			sphere4_2Bullet->gotoAndStop(5);
			sphere4_3Bullet->gotoAndStop(5);
			sphere4_4Bullet->gotoAndStop(5);
			return true;
		}

		 
        Tower4::Tower4()
        {
            return;
        }// end function

        bool Tower4::init() 
        {
            towerType = 4;
            correctYGrPos = -15;
            radius = Main::mainClass->readXMLClass.listOfSpheresRadius[3];
            slotsStack[0]=0;
            slotsStack[0]=0;
            slotsStack[0]=0;
            slotsStack[0]=0;
            container = new Tower4_mc();
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
            Tower::init();
            if (!autoBuild)
            {
                AudioUtil::playSoundWithVol("Snd_tower_build1.mp3", 0.9f);
            }
            return true;
        }// end function

        void Tower4::update(float dt)
        {
            Tower::update();
			Tower4_mc * container = ISTYPE(Tower4_mc, this->container);
			if (world->frameCounter % 2)
            {
                if (container->currentFrame < container->totalFrames)
                {
                    container->tryPlay();
                    //container->gotoAndStop((container->currentFrame + 1));
                }
                else
                {
                    container->gotoAndStop(1);
                }
            }
            if (spheresStack.size() == 1)
            {
                container->sphere1->tryPlay();
                container->sphere1BulletCont->tryPlay();
                //if (container->sphere1->currentFrame < container->sphere1->totalFrames)
                //{
                //    container->sphere1->tryPlay();
                //    //container->sphere1->gotoAndStop((container->sphere1->currentFrame + 1));
                //}
                //else
                //{
                //    container->sphere1->gotoAndStop(1);
                //} 
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
            else if (spheresStack.size() == 2)
            {
                if (container->sphere2_1->currentFrame < container->sphere2_1->totalFrames)
                {
                    container->sphere2_1->tryPlay();
                    //container->sphere2_1->gotoAndStop((container->sphere2_1->currentFrame + 1));
                }
                else
                {
                    container->sphere2_1->gotoAndStop(1);
                } 
                if (container->sphere2_1BulletCont->currentFrame < container->sphere2_1BulletCont->totalFrames)
                {
                    container->sphere2_1BulletCont->tryPlay();
                    //container->sphere2_1BulletCont->gotoAndStop((container->sphere2_1BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere2_1BulletCont->gotoAndStop(1);
                } 
                if (container->sphere2_2->currentFrame < container->sphere2_2->totalFrames)
                {
                    container->sphere2_2->tryPlay();
                    //container->sphere2_2->gotoAndStop((container->sphere2_2->currentFrame + 1));
                }
                else
                {
                    container->sphere2_2->gotoAndStop(1);
                } 
                if (container->sphere2_2BulletCont->currentFrame < container->sphere2_2BulletCont->totalFrames)
                {
                    container->sphere2_2BulletCont->tryPlay();
                    //container->sphere2_2BulletCont->gotoAndStop((container->sphere2_2BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere2_2BulletCont->gotoAndStop(1);
                } 
            }
            else if (spheresStack.size() == 3)
            {
                if (container->sphere3_1->currentFrame < container->sphere3_1->totalFrames)
                {
                    container->sphere3_1->tryPlay();
                    //container->sphere3_1->gotoAndStop((container->sphere3_1->currentFrame + 1));
                }
                else
                {
                    container->sphere3_1->gotoAndStop(1);
                } 
                if (container->sphere3_1BulletCont->currentFrame < container->sphere3_1BulletCont->totalFrames)
                {
                    container->sphere3_1BulletCont->tryPlay();
                    //container->sphere3_1BulletCont->gotoAndStop((container->sphere3_1BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere3_1BulletCont->gotoAndStop(1);
                } 
                if (container->sphere3_2->currentFrame < container->sphere3_2->totalFrames)
                {
                    container->sphere3_2->tryPlay();
                    //container->sphere3_2->gotoAndStop((container->sphere3_2->currentFrame + 1));
                }
                else
                {
                    container->sphere3_2->gotoAndStop(1);
                } 
                if (container->sphere3_2BulletCont->currentFrame < container->sphere3_2BulletCont->totalFrames)
                {
                    container->sphere3_2BulletCont->tryPlay();
                    //container->sphere3_2BulletCont->gotoAndStop((container->sphere3_2BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere3_2BulletCont->gotoAndStop(1);
                } 
                if (container->sphere3_3->currentFrame < container->sphere3_3->totalFrames)
                {
                    container->sphere3_3->tryPlay();
                    //container->sphere3_3->gotoAndStop((container->sphere3_3->currentFrame + 1));
                }
                else
                {
                    container->sphere3_3->gotoAndStop(1);
                } 
                if (container->sphere3_3BulletCont->currentFrame < container->sphere3_3BulletCont->totalFrames)
                {
                    container->sphere3_3BulletCont->tryPlay();
                    //container->sphere3_3BulletCont->gotoAndStop((container->sphere3_3BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere3_3BulletCont->gotoAndStop(1);
                } 
            }
            else if (spheresStack.size() == 4)
            {
                if (container->sphere4_1->currentFrame < container->sphere4_1->totalFrames)
                {
                    container->sphere4_1->tryPlay();
                    //container->sphere4_1->gotoAndStop((container->sphere4_1->currentFrame + 1));
                }
                else
                {
                    container->sphere4_1->gotoAndStop(1);
                } 
                if (container->sphere4_1BulletCont->currentFrame < container->sphere4_1BulletCont->totalFrames)
                {
                    container->sphere4_1BulletCont->tryPlay();
                    //container->sphere4_1BulletCont->gotoAndStop((container->sphere4_1BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere4_1BulletCont->gotoAndStop(1);
                } 
                if (container->sphere4_2->currentFrame < container->sphere4_2->totalFrames)
                {
                    container->sphere4_2->tryPlay();
                    //container->sphere4_2->gotoAndStop((container->sphere4_2->currentFrame + 1));
                }
                else
                {
                    container->sphere4_2->gotoAndStop(1);
                } 
                if (container->sphere4_2BulletCont->currentFrame < container->sphere4_2BulletCont->totalFrames)
                {
                    container->sphere4_2BulletCont->tryPlay();
                    //container->sphere4_2BulletCont->gotoAndStop((container->sphere4_2BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere4_2BulletCont->gotoAndStop(1);
                } 
                if (container->sphere4_3->currentFrame < container->sphere4_3->totalFrames)
                {
                    container->sphere4_3->tryPlay();
                    //container->sphere4_3->gotoAndStop((container->sphere4_3->currentFrame + 1));
                }
                else
                {
                    container->sphere4_3->gotoAndStop(1);
                } 
                if (container->sphere4_3BulletCont->currentFrame < container->sphere4_3BulletCont->totalFrames)
                {
                    container->sphere4_3BulletCont->tryPlay();
                    //container->sphere4_3BulletCont->gotoAndStop((container->sphere4_3BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere4_3BulletCont->gotoAndStop(1);
                } 
                if (container->sphere4_4->currentFrame < container->sphere4_4->totalFrames)
                {
                    container->sphere4_4->tryPlay();
                    //container->sphere4_4->gotoAndStop((container->sphere4_4->currentFrame + 1));
                }
                else
                {
                    container->sphere4_4->gotoAndStop(1);
                } 
                if (container->sphere4_4BulletCont->currentFrame < container->sphere4_4BulletCont->totalFrames)
                {
                    container->sphere4_4BulletCont->tryPlay();
                    //container->sphere4_4BulletCont->gotoAndStop((container->sphere4_4BulletCont->currentFrame + 1));
                }
                else
                {
                    container->sphere4_4BulletCont->gotoAndStop(1);
                } 
            }
            return;
        }// end function

         
    }
}

