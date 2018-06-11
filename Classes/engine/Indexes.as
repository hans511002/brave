#ifndef ENGINE_CASTS_AIR_H
#define ENGINE_CASTS_AIR_H
#include "BaseHeaders.h"

namespace engine{
 

     class Indexes :BaseNode
    {
    public:
        int i;
        World *world;
        BaseNode * container;
        int indexParam;
        float alphaParam;
        string type;//:String = "default";
        float speedX;//:Number = 0;
        float speedY;//:Number = 0;

        Indexes(BaseNode *param1,int param2,float param3= 0):speedX(0),speedY(0)
        {
            this->world = Main::mainClass->worldClass;
            this->container = param1;
            //this->container.stop();
            this->addChild(this->container);
            this->indexParam = param2;
            this->alphaParam = param3;
            if (this->indexParam == 0)
            {
                //this->world->listOfIndexes0.push(this);
            }
            else if (this->indexParam == 1)
            {
                //this->world->listOfIndexes1.push(this);
            }
            else if (this->indexParam == 2)
            {
                //this->world->listOfIndexes2.push(this);
            }
            else if (this->indexParam == 3)
            {
                //this->world->listOfIndexes3.push(this);
            }
            this->world->addChild(this);
            //this->world->listOfClasses.push(this);
            this->mouseChildren = false;
            this->mouseEnabled = false;
            this->world->forseIndexFl = true;
            return;
        }// end function

      virtual   void update(float dt=0) 
        {
            if (this->container.currentFrame < this->container.totalFrames && this->container.alpha > 0)
            {
                this->container.gotoAndStop((this->container.currentFrame + 1));
                this->container.alpha = this->container.alpha - this->alphaParam;
                this->x = this->x + this->speedX;
                this->y = this->y + this->speedY;
            }
            else
            {
                this->world->removeChild(this);
                this->i = 0;
                while (this->i < this->world->listOfClasses.length)
                {
                    
                    if (this->world->listOfClasses[this->i] == this)
                    {
                        this->world->listOfClasses.splice(this->i, 1);
                        break;
                    }
                    i++;
                }
                if (this->indexParam == 0)
                {
                    this->i = 0;
                    while (this->i < this->world->listOfIndexes0.length)
                    {
                        
                        if (this->world->listOfIndexes0[this->i] == this)
                        {
                            this->world->listOfIndexes0.splice(this->i, 1);
                            break;
                        }
                        i++;
                    }
                }
                else if (this->indexParam == 1)
                {
                    this->i = 0;
                    while (this->i < this->world->listOfIndexes1.length)
                    {
                        
                        if (this->world->listOfIndexes1[this->i] == this)
                        {
                            this->world->listOfIndexes1.splice(this->i, 1);
                            break;
                        }
                        i++;
                    }
                }
                else if (this->indexParam == 2)
                {
                    this->i = 0;
                    while (this->i < this->world->listOfIndexes2.length)
                    {
                        
                        if (this->world->listOfIndexes2[this->i] == this)
                        {
                            this->world->listOfIndexes2.splice(this->i, 1);
                            break;
                        }
                        i++;
                    }
                }
                else if (this->indexParam == 3)
                {
                    this->i = 0;
                    while (this->i < this->world->listOfIndexes3.length)
                    {
                        
                        if (this->world->listOfIndexes3[this->i] == this)
                        {
                            this->world->listOfIndexes3.splice(this->i, 1);
                            break;
                        }
                        i++;
                    }
                }
            }
            return;
        }// end function

    }
}
#endif
