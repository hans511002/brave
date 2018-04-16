#include "engine/World.h"
#include "Bullet.h"
#include "engine/units/Unit.h"


namespace engine{
    namespace bullets{

        Bullet::Bullet() :dead(false), world(NULL), container(NULL), enemyTarget(NULL), damage(0), bulletType(0), whoShoot(NULL)
            , liveCounter(0), liveTimer(0), distanceX(0), distanceY(0), spherePower(0), mainCounter(0), changeIndex(0), radius(0)
            , testTarget(NULL), testTower(NULL), greenFlag(false)
        {
            //this->addEventListener(Event.ADDED_TO_STAGE, this->init);
            return;
        }// end function



        bool Bullet::init()
        {
            //this->removeEventListener(Event.ADDED_TO_STAGE, this->init);
            //this->mouseChildren = false;
            //this->mouseEnabled = false;
            this->world = Main::mainClass->worldClass;
            this->world->listOfBullets.push(this);
            //this->world->listOfIndexes3.push(this);
            this->changeIndex = 10;
            return true;
        }// end function
        void Bullet::update()
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
            if ((this->testTarget->getPositionX() - this->this_pt.x) * (this->testTarget->getPositionX() - this->this_pt.x) / (this->radius * this->radius)
                + (this->testTarget->getPositionY() - this->this_pt.y) * (this->testTarget->getPositionY() - this->this_pt.y) / (tempObject * tempObject) <= 1)
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