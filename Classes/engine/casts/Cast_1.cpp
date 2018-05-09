#include "engine/world.h"
#include "Cast_1.h"
#include "Golem.h"

namespace engine{
    namespace    casts
    {
        bool Cast_1::init()
        {
            container = new MovieClip("cast/", "MoveGolem_mc","MoveGolem_mc");
            this->addChild(container);
            Cast::init();
			this->autorelease();
            return true;
        }// end function
        void Cast_1::update()
        {
            Cast::update();
            return;
        }// end function
       
        void  Cast_1::mouseMoveHandler(cocos2d::Event * param1)
        {
            //if (param1.target.name == "castGolemCase")
            //{
            //    if (container->currentFrame == 1)
            //    {
            //        container->gotoAndStop(2);
            //    }
            //    if (world->worldInterface->container->butCastGolem.currentFrame != 6)
            //    {
            //        world->worldInterface->container->butCastGolem.gotoAndStop(6);
            //    }
            //}
            //else
            //{
            //    if (world->worldInterface->container->butCastGolem.currentFrame != 5)
            //    {
            //        world->worldInterface->container->butCastGolem.gotoAndStop(5);
            //    }
            //    if (scanWay())
            //    {
            //        if (container->currentFrame == 2)
            //        {
            //            container->gotoAndStop(1);
            //        }
            //    }
            //    else if (container->currentFrame == 1)
            //    {
            //        container->gotoAndStop(2);
            //    }
            //}
            return;
        }// end function
        
        void   Cast_1::mouseDownHandler(cocos2d::Event *event)
        {
            if (event)
            {
                //if (event.target.name != "castGolemCase" && scanWay())
                //{ 
                //    this->mouseChildren = true;
                //    this->mouseEnabled = true;
                //    //event = new MouseEvent(MouseEvent.MOUSE_DOWN);
                //    world->worldInterface->castGolemCounter++;
                //    //world->worldInterface->container->butCastGolem.gotoAndStop(4);
                //    //world->worldInterface->container->butCastGolem.castGolemCase.buttonMode = false;
                //    //world->worldInterface->container->butCastGolem.cont.contMask.scaleY = 0;
                //    this->addGolem();
                //    kill();
                //}
                //else if (event.target.name == "castGolemCase" || event.target.name == "castIcemanCase" || event.target.name == "castAirCase")
                //{
                //    world->worldInterface->container->butCastGolem.gotoAndStop(1);
                //    kill();
                //}
            }
            container->gotoAndStop(3);
            return;
        }// end function
        void Cast_1::mouseUpHandler(cocos2d::Event  event)
        {
        }
        void Cast_1::addGolem()
        {
            cocos2d::Point tempObject  (world->mouseX, world->mouseY);
            Golem *  tempObject1 = NULL;
            int tempObject2 = 0;
            int tempObject3 = 10000;
            n = 1;
            while (n <= Main::mainClass->readXMLClass.strategies)
            {
                if (n == 1)
                {
                    map = &world->map.road1;
                }
                else if (n == 2)
                {
                    map = &world->map.road2;
                }
                else if (n == 3)
                {
                    map = &world->map.road3;
                }
                Common::Array<cocos2d::Point> &map = *this->map;
                i = 1;
                while (i < map.size())
                {
                    if (map[i].x == map[(i - 1)].x)
                    {
                        if (map[i].y >= map[(i - 1)].y)
                        {
                            j = map[(i - 1)].y;
                            while (j < map[i].y)
                            {
                                tempObject2 = tempObject.distance( cocos2d::Point(map[i].x, j));
                                if (tempObject2 < 30)
                                {
                                    if (tempObject2 < tempObject3)
                                    {
                                        tempObject3 = tempObject2;
                                    }
                                    else
                                    {
                                        tempObject1 = new Golem(cocos2d::Point(map[i].x, j), n, i);
                                        world->addChild(tempObject1);
                                        return;
                                    }
                                }
                                j = j + 5;
                            }
                        }
                        else
                        {
                            j = map[(i - 1)].y;
                            while (j >= map[i].y)
                            {

                                tempObject2 = tempObject.distance(  cocos2d::Point(map[i].x, j));
                                if (tempObject2 < 30)
                                {
                                    if (tempObject2 < tempObject3)
                                    {
                                        tempObject3 = tempObject2;
                                    }
                                    else
                                    {
                                        tempObject1 = new Golem(cocos2d::Point(map[i].x, j), n, i);
                                        world->addChild(tempObject1);
                                        return;
                                    }
                                }
                                j = j - 5;
                            }
                        }
                    }
                    else if (map[i].y == map[(i - 1)].y)
                    {
                        if (map[i].x >= map[(i - 1)].x)
                        {
                            j = map[(i - 1)].x;
                            while (j < map[i].x)
                            {

                                tempObject2 = tempObject.distance(  cocos2d::Point(j, map[i].y));
                                if (tempObject2 < 30)
                                {
                                    if (tempObject2 < tempObject3)
                                    {
                                        tempObject3 = tempObject2;
                                    }
                                    else
                                    {
                                        tempObject1 = new Golem(cocos2d::Point(j, map[i].y), n, i);
                                        world->addChild(tempObject1);
                                        return;
                                    }
                                }
                                j = j + 5;
                            }
                        }
                        else
                        {
                            j = map[(i - 1)].x;
                            while (j >= map[i].x)
                            {

                                tempObject2 = tempObject.distance(  cocos2d::Point(j, map[i].y));
                                if (tempObject2 < 30)
                                {
                                    if (tempObject2 < tempObject3)
                                    {
                                        tempObject3 = tempObject2;
                                    }
                                    else
                                    {
                                        tempObject1 = new Golem(cocos2d::Point(j, map[i].y), n, i);
                                        world->addChild(tempObject1);
                                        return;
                                    }
                                }
                                j = j - 5;
                            }
                        }
                    }
                    i++;
                }
                n++;
            }
            return;
        }// end function

    }
}
