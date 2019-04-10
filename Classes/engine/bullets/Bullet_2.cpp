
#include "engine/World.h"
#include "Bullet_2.h"
#include "engine/units/Unit.h"
#include "MainClass.h"


namespace engine
{
	namespace bullets
	{
		bool Bullet_2::init()
		{
			bulletType = 2;
			liveTimer = 6;
			liveCounter = 6;
			this->setPosition(this_pt.x, this_pt.y);
			//this->x = this_pt.x;
			//this->y = this_pt.y;
			container = new BulletIceTower_mc();
			//container->stop();
			this->addChild(container);
			whoShoot->iceBulletCounter++;
			Bullet::init();
			AudioUtil::playSoundWithVol("Snd_tower_shootIce.mp3", 0.83f);
			return true;
		}// end function

		void Bullet_2::update(float dt)
		{
            if(this->dead){
                this->remove();
                return;
            }
			Bullet::update();
			if(container->currentFrame < container->totalFrames)
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
				units::Unit* unit = NULL;
				if (!enemyTarget || enemyTarget->dead)
				{
					i = 0;
					while (i < world->listOfUnits.size())
					{
						float distLen = this_pt.distance(world->listOfUnits[i]->shoot_pt);// Point.distance(this_pt, world->listOfUnits[i]->shoot_pt);
						if (distLen < 50)
						{
							if (!unit)
								unit = world->listOfUnits[i];
							else if (this_pt.distance(unit->shoot_pt) > distLen)
								unit = world->listOfUnits[i];
						}
						i++;
					}
					if (!unit) {
						kill();
						return;
					}
					enemyTarget = unit;
				}
				distanceX = enemyTarget->getPosition().x - this_pt.x;
				distanceY = enemyTarget->getPosition().y - this_pt.y;
				this->setPosition(this->getPosition().x + distanceX / liveCounter, this->getPosition().y + distanceY / liveCounter);
				//this->x = this->x + distanceX / liveCounter;
				//this->y = this->y + distanceY / liveCounter;
				this_pt = this->getPosition();// new Point(this->x, this->y);
				liveCounter--;
			}
			else
			{
				if(enemyTarget && enemyTarget->atStaged && enemyTarget->readyDamage)
				{
					if(whoShoot->iceBulletCounter >= Main::mainClass->readXMLClass.listOfIceProbability[(spherePower - 1)])
					{
						whoShoot->iceBulletCounter = 0;
						enemyTarget->getHit(damage, "ice", spherePower, true, bulletType);
					}
					else
					{
						enemyTarget->getHit(damage, "ice", spherePower, false, bulletType);
					}
				}
				kill();
			}
			return;
		}// end function

	}
}
