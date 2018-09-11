#include "MainClass.h"
#include "engine/World.h"
#include "Bullet_3.h"
#include "engine/CastSphere.h"
#include "engine/units/Unit.h"

namespace engine{
	namespace bullets{
		bool Bullet_3::init()
		{
			bulletType = 3;
			liveTimer = 24;
			liveCounter = 24;
			this->correct = (float)liveCounter / 12;
			this->setPosition(this_pt.x, this_pt.y);
			//this->x = this_pt.x;
			//this->y = this_pt.y;
			container = new BulletStoneTower_mc();
			//container->stop();
			this->addChild(container);
			testTower = ISTYPE(Tower,whoShoot);
			radius = whoShoot->radius;
			Bullet::init();
			this->enemyStartPoint = enemyTarget->this_pt;
			this->enemyRoad = enemyTarget->road;
			this->enemyWay = enemyTarget->way;
			this->enemyPath = enemyTarget->path;
			if (enemyTarget->speedK > 0 || enemyTarget->typeUnit == 34)
			{
				if (enemyTarget->typeUnit != 3 && enemyTarget->typeUnit != 8 && enemyTarget->typeUnit != 13)
				{
					this->enemySpeed = enemyTarget->speedK * 0.5;
				}
				else
				{
					this->enemySpeed = enemyTarget->speedK;
				}
			}
			else
			{
				this->enemySpeed = 0.1f;
			}
			this->shadow = new UnitShadow_mc();// MovieClip("sphere", "UnitShadow_mc", "UnitShadow_mc");//UnitShadow_mc();
			//this->shadow->stop();
			this->shadow->setMouseChildren(false);
			this->shadow->setMouseEnabled(false);
			this->shadow->setPositionX(this_pt.x);
			this->shadow->setPositionY(whoShoot->getPositionY());
			this->shadow->setScale(0.5, 0.5);
			world->addChild(this->shadow, 2);
			world->addIndexes(this->shadow,2);
			return true;
		}// end function

		void Bullet_3::update(float dt)
		{
			Bullet::update();
			if (mainCounter == 11)
			{
				AudioUtil::playSoundWithVol("Snd_tower_shootStone.mp3", 0.8f);
			}
			if (container->currentFrame < container->totalFrames)
			{
				container->tryPlay();
				//container->gotoAndStop((container->currentFrame + 1));
			}
			else
			{
				container->gotoAndStop(1);
			}
			if (liveCounter > 0)
			{
				distanceX = this->enemyStartPoint.x - this_pt.x;
				distanceY = this->enemyStartPoint.y - this_pt.y;
				//testTarget = this->enemyStartPoint;
				scanAtRadius();
				if (greenFlag)
				{
					this->enemyPath = this->enemyPath + this->enemySpeed;
				}
				bezier::PathPoint tempObject = world->bezierClass->getPathPoint(this->enemyPath, this->enemyRoad, this->enemyWay);
				this->enemyStartPoint = tempObject;//new Point(tempObject.x, tempObject.y);
				if (liveCounter > this->correct)
				{
					this->setPosition(this->getPosition().x + distanceX / (liveCounter - this->correct),
						this->getPosition().y + (distanceY / (liveCounter - this->correct) + 12));
					//this->x = this->x + distanceX / (liveCounter - this->correct);
					//this->y = this->y + (distanceY / (liveCounter - this->correct) - 12);  
					Vec2 shpos = this->shadow->getPosition();
					this->shadow->setPosition(shpos .x+ (this->enemyStartPoint.x - shpos.x) / (liveCounter - this->correct),shpos.y+ (this->enemyStartPoint.y - shpos.y) / (liveCounter - this->correct));
					//this->shadow.x = this->shadow.x + (this->enemyStartPoint.x - this->shadow.x) / (liveCounter - this->correct);
					//this->shadow.y = this->shadow.y + (this->enemyStartPoint.y - this->shadow.y) / (liveCounter - this->correct);
				}
				else
				{
					this->setPosition(this->getPosition().x + distanceX / liveCounter, this->getPosition().y + distanceY / liveCounter);
					//this->x = this->x + distanceX / liveCounter;
					//this->y = this->y + distanceY / liveCounter;
					Vec2 shpos = this->shadow->getPosition();
					this->shadow->setPosition(shpos.x + (this->enemyStartPoint.x - shpos.x) / liveCounter,shpos.y + (this->enemyStartPoint.y - shpos.y) / liveCounter);
					//this->shadow.x = this->shadow.x + (this->enemyStartPoint.x - this->shadow.x) / liveCounter;
					//this->shadow.y = this->shadow.y + (this->enemyStartPoint.y - this->shadow.y) / liveCounter;
				}
				this_pt = this->getPosition();// new Point(this->x, this->y);
				liveCounter--;//(liveCounter - 1);
			}
			else
			{
				CastStone_mc* tempObject = new  CastStone_mc();
				tempObject->setOnceMove(this->world);
				tempObject->setScale(0.5, 0.5);
				tempObject->setPosition(this_pt);
				//tempObject.x = this_pt.x;
				//tempObject.y = this_pt.y;
				i = world->listOfUnits.size() - 1;
				float stoneEffectRadiusXML= Main::mainClass->readXMLClass.stoneEffectRadiusXML;
				while (i >= 0)
				{
				    Unit * unit=world->listOfUnits[i];
					if (unit->atStaged && unit->readyDamage && abs(unit->shoot_pt.x -this_pt.x) < stoneEffectRadiusXML && abs(unit->shoot_pt.y -this_pt.y) < stoneEffectRadiusXML)
					{
						//if (Point.distance(this_pt, world->listOfUnits[i]->shoot_pt) < Main::mainClass->readXMLClass.stoneEffectRadiusXML)
						if (this_pt.distance(unit->shoot_pt) < stoneEffectRadiusXML)
						{
							unit->getHit(damage, "stone", spherePower, true, bulletType);
						}
					}
					i--;
				}
				this->kill();
			}
			return;
		}// end function

		void Bullet_3::kill()
		{
			if (this->shadow)
			{
				world->removeIndexes(this,2); 
				world->removeChild(this->shadow);
				this->shadow = NULL;
			}
			Bullet::kill();
			return;
		}// end function
	}
}