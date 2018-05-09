#ifndef ENGINE_BULLET_51_H
#define ENGINE_BULLET_51_H
#include "Bullet.h" 

namespace engine{
    namespace bullets{ 
        
        
        class Bullet_51 : public Bullet
        {
        public:
            bool turnFlag;//:Boolean;
            Common::Array<BaseNode*> listOfAnimation;

        Bullet_51()
        {
        }// end function

        bool init() 
        {
            bulletType = 51;
            liveCounter = 0;
            distanceX = -40;
            distanceY = -40;
            this->x = this_pt.x;
            this->y = this_pt.y;
            i = 0;
            while (i < 7)
            {
                
                distanceX = -40;
                distanceY = distanceY + 10;
                j = 0;
                while (j < 7)
                {
                    
                    distanceX = distanceX + 10;
                    if (this->turnFlag)
                    {
                        this->turnFlag = false;
                        tempObject = new BulletTower51_1_mc();
                        if (this_pt.x < whoShoot.this_pt.x)
                        {
                            tempObject.x = 44;
                        }
                        else
                        {
                            tempObject.scaleX = tempObject.scaleX * -1;
                            tempObject.x = -44;
                        }
                        tempObject.y = -624;
                    }
                    else
                    {
                        this->turnFlag = true;
                        tempObject = new BulletTower51_2_mc();
                        tempObject.x = 0;
                        tempObject.y = -624;
                    }
                    tempObject.stop();
                    tempObject.x = tempObject.x + distanceX;
                    tempObject.y = tempObject.y + distanceY;
                    tempObject.counter = 40;
                    tempObject.distX = (distanceX - tempObject.x) / tempObject.counter;
                    tempObject.distY = (distanceY - tempObject.y) / tempObject.counter;
                    tempObject.visible = false;
                    this->addChild(tempObject);
                    this->listOfAnimation.push(tempObject);
                    var _loc_3:* = j + 1;
                    j = _loc_3;
                }
                var _loc_3:* = i + 1;
                i = _loc_3;
            }
            super.init(event);
            Sounds.instance.playSound("snd_tower_shootUltraAdd1");
            return;
        }// end function

        void update() 
        {
            Bullet::update();
            liveCounter++;
            i = this->listOfAnimation.size() - 1;
            while (i >= 0)
            {
                
                if (!this->listOfAnimation[i].visible)
                {
                    if (Math.random() < 0.05)
                    {
                        this->listOfAnimation[i].visible = true;
                    }
                }
                else if (this->listOfAnimation[i].counter > 0)
                {
                    (this->listOfAnimation[i].counter - 1);
                    this->listOfAnimation[i].x = this->listOfAnimation[i].x + this->listOfAnimation[i].distX;
                    this->listOfAnimation[i].y = this->listOfAnimation[i].y + this->listOfAnimation[i].distY;
                }
                else if (this->listOfAnimation[i].currentFrame < this->listOfAnimation[i].totalFrames)
                {
                    this->listOfAnimation[i].gotoAndStop((this->listOfAnimation[i].currentFrame + 1));
                }
                else
                {
                    j = world.listOfUnits.length - 1;
                    while (j >= 0)
                    {
                        
                        tempObject = this->localToGlobal(new Point(this->listOfAnimation[i].x, this->listOfAnimation[i].y));
                        if (world.listOfUnits[j].atStage && world.listOfUnits[j].readyDamage)
                        {
                            if (Point.distance(world.listOfUnits[j].shoot_pt, tempObject) < Main.mainClass.readXMLClass.ultraAddFireStoneRadiusXML)
                            {
                                tempObject = world.listOfUnits[j];
                                if (tempObject.typeUnit != 23)
                                {
                                    tempObject.getHit(damage, "fire", 2, true, bulletType, whoShoot);
                                }
                                else
                                {
                                    tempObject.getHit(damage, "fire", 2, false, bulletType, whoShoot);
                                }
                            }
                        }
                        var _loc_2:* = j - 1;
                        j = _loc_2;
                    }
                    this->removeChild(this->listOfAnimation[i]);
                    this->listOfAnimation.splice(i, 1);
                }
                var _loc_2:* = i - 1;
                i = _loc_2;
            }
            if (liveCounter == 160)
            {
                i = this->listOfAnimation.length - 1;
                while (i >= 0)
                {
                    
                    if (this->listOfAnimation[i].currentFrame == 1)
                    {
                        this->removeChild(this->listOfAnimation[i]);
                        this->listOfAnimation.splice(i, 1);
                    }
                    var _loc_2:* = i - 1;
                    i = _loc_2;
                }
            }
            else if (this->listOfAnimation.length == 0)
            {
                kill();
            }
            return;
        }// end function
    };
    }
}
#endif

