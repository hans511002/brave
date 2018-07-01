#include "engine/World.h"
#include "Bullet.h"
#include "engine/units/Unit.h"
#include "MainClass.h"
#include "engine/towers/Tower.h"


namespace engine{
    namespace bullets{
		BulletSphereTower_mc::BulletSphereTower_mc() :MovieClip("sphere/", "BulletSphereTower_mc", "BulletSphereTower_mc"), cont(0), counter(0)
        {
			SET_NODETYPENAME();
			//cont=this->createMovieClip("sphere/","cont","BulletSpheresTower_mc");//合并多个在一个db中
        }
        
        void BulletSphereTower_mc::gotoAndStop(int cur)
		{
		    int oldIdx = this->currentFrame;
			MovieClip::gotoAndStop(cur);
			if(oldIdx == this->currentFrame)return;
			if(cont)display->removeChild(cont);
			cont = NULL;
			if(this->currentFrame == 1)
			{
				cont = new MovieClip("sphere/", "BulletFireTower_mc", "BulletFireTower_mc");
			}
			else if(this->currentFrame == 2)
			{
				cont = new MovieClip("sphere/", "BulletIceTower_mc", "BulletIceTower_mc");
			}
			else if(this->currentFrame == 3)
			{
				cont = new MovieClip("sphere/", "BulletStoneTower_mc", "BulletStoneTower_mc");
			}
			else if(this->currentFrame == 4)
			{
				cont = new MovieClip("sphere/", "BulletLevinTower_mc", "BulletLevinTower_mc");
			}
			if(cont)
			    display->addChild(cont);

		};
		BulletFireTower_mc::BulletFireTower_mc() :BulletBase_mc("sphere/", "BulletFireTower_mc", "BulletFireTower_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletIceTower_mc::BulletIceTower_mc() : BulletBase_mc("sphere/", "BulletIceTower_mc", "BulletIceTower_mc")
        {
			SET_NODETYPENAME();
		}
		BulletStoneTower_mc::BulletStoneTower_mc() : BulletBase_mc("sphere/", "BulletStoneTower_mc", "BulletStoneTower_mc")
        {
			SET_NODETYPENAME();
		}
		BulletLevinTower_mc::BulletLevinTower_mc() : BulletBase_mc("sphere/", "BulletLevinTower_mc", "BulletLevinTower_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower5_1_mc::BulletTower5_1_mc() : BulletBase_mc("sphere/", "BulletTower5_1_mc", "BulletTower5_1_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower5_1Bang_mc::BulletTower5_1Bang_mc(World * world) : MovieClip(world, "sphere/", "BulletTower5_1Bang_mc", "BulletTower5_1Bang_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower5_1Smoke1_mc::BulletTower5_1Smoke1_mc(World * world) : MovieClip(world, "sphere/", "BulletTower5_1Smoke1_mc", "BulletTower5_1Smoke1_mc")
        {
			SET_NODETYPENAME();
		};
		BulletTower51_1_mc::BulletTower51_1_mc() :BulletBase_mc("sphere/", "BulletTower51_1_mc", "BulletTower51_1_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower51_2_mc::BulletTower51_2_mc() : BulletBase_mc("sphere/", "BulletTower51_2_mc", "BulletTower51_2_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower6_1_mc::BulletTower6_1_mc() : BulletBase_mc("sphere/", "BulletTower6_1_mc", "BulletTower6_1_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower6_2_mc::BulletTower6_2_mc() : BulletBase_mc("sphere/", "BulletTower6_2_mc", "BulletTower6_2_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower61_mc::BulletTower61_mc() : BulletBase_mc("sphere/", "BulletTower61_mc", "BulletTower61_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower7_smoke_mc::BulletTower7_smoke_mc(World * world) : MovieClip(world, "sphere/", "BulletTower7_smoke_mc", "BulletTower7_smoke_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower71_mc::BulletTower71_mc() : BulletBase_mc("sphere/", "BulletTower71_mc", "BulletTower71_mc")
        {
			SET_NODETYPENAME();
		}
		BulletTower7_mc::BulletTower7_mc() : BulletBase_mc("sphere/", "BulletTower7_mc", "BulletTower7_mc")
        {
			SET_NODETYPENAME();
			////cont=new MovieClip("sphere/","BulletTower7_mc","BulletTower7_mc");
            //ball=new MovieClip("sphere/","ball","BulletTower7_mc");
            //smokeCont1=new MovieClip("sphere/","smokeCont1","BulletTower7_mc");
            //smokeCont2=new MovieClip("sphere/","smokeCont2","BulletTower7_mc");
            
            ball= this->createMovieClipSub("ball");
            smoke= this->createMovieClipSub("smoke");
            smokeCont1= smoke->createMovieClipSub("cont1");
            smokeCont2= smoke->createMovieClip("cont2","sphere/", "BulletTower7_smoke_mc", "BulletTower7_smoke_mc");
        }
       
		BulletTower8_1_mc::BulletTower8_1_mc() :BulletBase_mc("sphere/", "BulletTower8_1_mc", "BulletTower8_1_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower8_2_mc::BulletTower8_2_mc() : BulletBase_mc("sphere/", "BulletTower8_2_mc", "BulletTower8_2_mc")
        { 
			SET_NODETYPENAME();
		}
		BulletTower81_mc::BulletTower81_mc() : BulletBase_mc("sphere/", "BulletTower81_mc", "BulletTower81_mc")
        { 
			SET_NODETYPENAME();
		}
        
        UnitShadow_mc::UnitShadow_mc():BaseSprite("sphere/UnitShadow_mc.png")
        {
			SET_NODETYPENAME();

        }
        
        Bullet::Bullet() :dead(false), world(NULL), container(NULL), enemyTarget(NULL), damage(0), bulletType(0), whoShoot(NULL)
            , liveCounter(0), liveTimer(0), distanceX(0), distanceY(0), spherePower(0), mainCounter(0), changeIndex(0), radius(0)
			,   testTower(NULL), greenFlag(false), effectFlag(false)
        {
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
			SET_NODETYPENAME();
			return;
        }// end function



        bool Bullet::init()
        {
            //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            this->setMouseChildren(false);
            this->setMouseEnabled(false);
            this->world = Main::mainClass->worldClass;
            this->world->listOfBullets.push(this);
            //this->world->listOfIndexes3.push(this);
            this->changeIndex = 10;
            return true;
        }// end function
        void Bullet::update(float dt)
        {
            this->mainCounter++;
            if (this->mainCounter == this->changeIndex)
            {
                if (this->bulletType == 3 || this->bulletType == 5 || this->bulletType == 7)
                {
                    if (this->this_pt.y < this->whoShoot->getPositionY())
                    {
                        if (this->enemyTarget->getPositionY() < this->whoShoot->getPositionY())
                        {
                            this->defaultIndex();
                        }
                        else
                        {
                            this->changeIndex++;
                        }
                    }
                    else
                    {
                        this->defaultIndex();
                    }
                }
                else
                {
                    this->defaultIndex();
                }
            }
            return;
        }// end function

        void Bullet::defaultIndex()
        {
            //this->i = 0;
            //while (this->i < this->world->listOfIndexes3.length)
            //{
            //    
            //    if (this->world->listOfIndexes3[this->i] == this)
            //    {
            //        this->world->listOfIndexes3.splice(this->i, 1);
            //        break;
            //    }
            //    i++;
            //}
            //this->world->listOfIndexes2.push(this);
            return;
        }// end function

        void Bullet::scanAtRadius()
        {
            this->greenFlag = false;
            float tempObject = this->radius - this->radius * (1 - this->world->scaleRadius);
            if ((this->testTarget.x - this->this_pt.x) * (this->testTarget.x - this->this_pt.x) / (this->radius * this->radius)
				+ (this->testTarget.y - this->this_pt.y) * (this->testTarget.y - this->this_pt.y) / (tempObject * tempObject) <= 1)
            {
                this->greenFlag = true;
            }
            return;
        }// end function

        void Bullet::kill()
        {
            if (!this->dead)
            {
                this->dead = true;
                this->i = 0;
                //while (this->i < this->world->listOfBullets.length)
                //{
                //    
                //    if (this->world->listOfBullets[this->i] == this)
                //    {
                //        this->world->listOfBullets.splice(this->i, 1);
                //        break;
                //    }
                //    i++;
                //}
                //this->i = 0;
                //while (this->i < this->world->listOfIndexes2.length)
                //{
                //    
                //    if (this->world->listOfIndexes2[this->i] == this)
                //    {
                //        this->world->listOfIndexes2.splice(this->i, 1);
                //        break;
                //    }
                //    i++;
                //}
                //this->i = 0;
                //while (this->i < this->world->listOfIndexes3.length)
                //{
                //    
                //    if (this->world->listOfIndexes3[this->i] == this)
                //    {
                //        this->world->listOfIndexes3.splice(this->i, 1);
                //        break;
                //    }
                //    i++;
                //}
                this->world->removeChild(this);

            }
            return;
        }// end function

    }
}