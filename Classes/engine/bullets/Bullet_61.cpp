#include "engine/World.h" 
#include "Bullet_61.h" 
#include "engine/units/Unit.h"

namespace engine
{
	namespace bullets
	{
		Bullet_61::Bullet_61()
		{
			SET_NODETYPENAME();
			return;
		}// end function

		bool Bullet_61::init()
		{
			bulletType = 61;
			this->setPosition(enemyTarget->getPosition());
			//this->x = enemyTarget.x;
			//this->y = enemyTarget.y;
			container = new BulletTower61_mc();
			container->stop();
			this->addChild(container);
			Bullet::init();
			AudioUtil::playSoundWithVol("Snd_tower_shootUltraAdd2.mp3", 0.9f);
			return true;
		}// end function

		void Bullet_61::update(float dt)
		{
            if(this->dead){
                this->remove();
                return;
            }
			Bullet::update();
			if (container->currentFrame < container->totalFrames)
			{
				container->tryPlay();
				//container->gotoAndStop((container->currentFrame + 1));
				if (container->currentFrame == 4)
				{
					i = world->listOfUnits.size() - 1;
					while (i >= 0)
					{
						Unit * unit = world->listOfUnits[i];
						if (unit->atStaged && unit->readyDamage && !unit->icemanFlag && !unit->teleportFlag)
						{
							if (this_pt.distance(unit->shoot_pt) < Main::mainClass->readXMLClass.ultraAddIceLevinDamageRadiusXML)
							{
								Unit * tempObject = unit;
								tempObject->getHit(damage / 2, "ice", 2, false, bulletType, whoShoot);
								if (!tempObject->dead && tempObject->readyDamage)
								{
									tempObject->getHit(damage / 2, "levin", 2, false, bulletType, whoShoot);
									if (tempObject->health > 0)
										tempObject->icemanFlag = true;
								}
							}
						}
						i--;
					}
				}
			}
			else
			{
				kill();
			}
			return;
		}// end function

	}
}

