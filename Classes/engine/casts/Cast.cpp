#include "Cast.h"
#include "MainClass.h"
#include "engine/World.h"
#include "engine/WorldInterface.h"

namespace engine
{
    CastMask_mc::CastMask_mc() :MovieClip("worldinterface/", "CastMask_mc", "CastMask_mc")
    {
		SET_NODETYPENAME();
		archiveCase = this->createCase("archiveCase", false);
		castAirCase = this->createCase("castAirCase", false);
		castGolemCase = this->createCase("castGolemCase", false);
		castIcemanCase = this->createCase("castIcemanCase", false);
		fireCase = this->createCase("fireCase", false);
		getAllCase = this->createCase("getAllCase", false);
		iceCase = this->createCase("iceCase", false);
		interfaceUpCase = this->createCase("interfaceUpCase", false);
		levinCase = this->createCase("levinCase", false);
		sellCase = this->createCase("sellCase", false);
		stoneCase = this->createCase("stoneCase", false);
        return;
    }// end function	
	namespace    casts
	{
		bool Cast::init()
		{
			//this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
			this->world = Main::mainClass->worldClass;
			this->setPosition(Vec2(this->world->mouseX, this->world->mouseY));
			//this->x = this->world->mouseX;
			//this->y = this->world->mouseY;
			this->setMouseChildren(false);
			this->setMouseEnabled(false);
			this->world->hint->setVisible( false);
			this->world->worldInterface->barInfoManage(this);
			return true;
		}// end function

		void   Cast::update(float dt)
		{
			this->world->feature->scanPointersAtCast();
			this->setPosition(cocos2d::Point(this->world->mouseX, this->world->mouseY));
			//this->x = this->world->mouseX;
			//this->y = this->world->mouseY;
			if(this->container->currentFrame == 3)
			{
				if(this->canselCounter < this->canselTimer)
				{
					this->canselCounter++;
				}
				else
				{
					this->canselCounter = 0;
					this->container->gotoAndStop(2);
				}
			}
			return;
		}// end function
		bool Cast::scanWay()
		{
			tempObject = cocos2d::Point(this->world->mouseX, this->world->mouseY);
			if(this->world->nowLevel == 6)
			{
				if(tempObject.x > 650 && tempObject.y < 320)
				{
					return false;
				} 
			}
			else if(this->world->nowLevel == 11)
			{
				if(tempObject.x > 390 && tempObject.x < 656 && tempObject.y < 190)
				{
					return false;
				}
			}
			else if(this->world->nowLevel == 13)
			{
				if(tempObject.x > 480 && tempObject.x < 550 && tempObject.y > 277)
				{
					return false;
				}
			}
			else if(this->world->nowLevel == 14)
			{
				if(tempObject.x > 645 && tempObject.y > 440)
				{
					return false;
				}
			}
			else if(this->world->nowLevel == 15)
			{
				if(tempObject.x >= 366 && tempObject.x <= 447 && tempObject.y < 296)
				{
					return false;
				}
			}
			auto ab = dynamic_cast<Cast_3*>(this);
			if(ab)
			{
				if(this->world->nowLevel == 9)
				{
					if(tempObject.x >= 370 && tempObject.x <= 470 && tempObject.y >= 240 && tempObject.y <= 390)
					{
						return true;
					}
				}
				if(this->world->nowLevel == 15)
				{
				}
			}
			this->n = 1;
			while(this->n <= Main::mainClass->readXMLClass.strategies)
			{
				if(this->n == 1)
				{
					this->map = &this->world->map->road1;
				}
				else if(this->n == 2)
				{
					this->map = &this->world->map->road2;
				}
				else if(this->n == 3)
				{
					this->map = &this->world->map->road3;
				}
				Common::Array<cocos2d::Point> &map = *this->map;
				this->i = 1;
				while(this->i < map.size())
				{
					if(map[this->i].x == map[(this->i - 1)].x)
					{
						if(map[this->i].y >= map[(this->i - 1)].y)
						{
							this->j = map[(this->i - 1)].y;
							while(this->j < map[this->i].y)
							{
								if(tempObject.distance(cocos2d::Point(map[this->i].x, this->j)) < 30)
								{
									return true;
								}
								this->j = this->j + 10;
							}
						}
						else
						{
							this->j = map[(this->i - 1)].y;
							while(this->j >= map[this->i].y)
							{
								if(tempObject.distance(cocos2d::Point(map[this->i].x, this->j)) < 30)
								{
									return true;
								}
								this->j = this->j - 10;
							}
						}
					}
					else if(map[this->i].y == map[(this->i - 1)].y)
					{
						if(map[this->i].x >= map[(this->i - 1)].x)
						{
							this->j = map[(this->i - 1)].x;
							while(this->j < map[this->i].x)
							{
								if(tempObject.distance(cocos2d::Point(this->j, map[this->i].y)) < 30)
								{
									return true;
								}
								this->j = this->j + 10;
							}
						}
						else
						{
							this->j = map[(this->i - 1)].x;
							while(this->j >= map[this->i].x)
							{
								if(tempObject.distance(cocos2d::Point(this->j, map[this->i].y)) < 30)
								{
									return true;
								}
								this->j = this->j - 10;
							}
						}
					}
					i++;
				}
				n++;
			}
			return false;
		}// end function
		void  Cast::kill()
		{
			if(!this->dead)
			{
				this->dead = true;
				this->world->worldInterface->castRegime("off");
				this->world->worldInterface->autoguidersButtons();
				this->world->cast = NULL;
				if (this->world->selectObject == this)
					this->world->selectObject = NULL;
				this->world->removeClasses(this);
				this->world->removeChild(this);
			}
			return;
		}// end function

	}
}

