#include "Cast_3.h"
#include "engine/world.h"
#include "Air.h"

namespace engine{
    namespace    casts
    {
        bool Cast_3::init()
        {
            container = new ImageMovieClip("cast/MoveCast_mc/", "MoveAir_mc",2, 3);
            //container->gotoAndStop(2);
            this->addChild(container);
            Cast_3::init();
            this->this_pt =  cocos2d::Point(world->mouseX, world->mouseY);
			this->autorelease();
            return true;
        }// end function

        void Cast_3::update()
        {
            this->directionManage();
            Cast_3::update();
            return;
        }// end function

        void Cast_3::mouseMoveHandler(cocos2d::Event *param1)
        {
            //if (param1.target.name == "castAirCase")
            //{
            //    if (container->currentFrame == 1)
            //    {
            //        container->gotoAndStop(2);
            //    }
            //    if (world->worldInterface->container->butCastAir->currentFrame != 6)
            //    {
            //        world->worldInterface->container->butCastAir->gotoAndStop(6);
            //    }
            //}
            //else
            //{
            //    if (world->worldInterface->container->butCastAir->currentFrame != 5)
            //    {
            //        world->worldInterface->container->butCastAir->gotoAndStop(5);
            //    }
            //    if (scanWay())
            //    {
            //        if (container->currentFrame == 2)
            //        {
            //            container->gotoAndStop(1);
            //            container->left.stop();
            //            container->right.stop();
            //            container->up.stop();
            //            container->down.stop();
            //            container->left->setVisible(false);
            //            container->right->setVisible(false);
            //            container->up->setVisible(false);
            //            container->down->setVisible(false);
            //        }
            //    }
            //    else if (container->currentFrame == 1)
            //    {
            //        container->gotoAndStop(2);
            //    }
            //}
            return;
        }// end function

        void  Cast_3::mouseDownHandler(cocos2d::Event *event)
        {
            //if (event)
            //{
            //    if (event.target.name != "castAirCase" && scanWay())
            //    {
            //        this->mouseChildren = true;
            //        this->mouseEnabled = true;
            //        //event = new MouseEvent(MouseEvent.MOUSE_DOWN);
            //        world->worldInterface->castAirCounter++;
            //        world->worldInterface->container->butCastAir->gotoAndStop(4);
            //        world->worldInterface->container->butCastAir->castAirCase.buttonMode = false;
            //        world->worldInterface->container->butCastAir->cont.contMask.scaleY = 0;
            //        this->addAir();
            //        kill();
            //    }
            //    else if (event.target.name == "castGolemCase" || event.target.name == "castIcemanCase" || event.target.name == "castAirCase")
            //    {
            //        world->worldInterface.container->butCastAir->gotoAndStop(1);
            //        kill();
            //    }
            //}
            //container->gotoAndStop(3);
            return;
        }// end function

        void  Cast_3::mouseUpHandler(cocos2d::Event *event)
        {
            return;
        }// end function

        void Cast_3::directionManage()
        {
            //if (container->currentFrame == 1)
            //{
            //    if (this->this_pt.x != world->mouseX || this->this_pt.y != world->mouseY)
            //    {
            //        this->this_pt = cocos2d::Point(world->mouseX, world->mouseY);
            //        tempObject1 = 10000;
            //        //tempObject3 = null;
            //        container->left->setVisible(false);
            //        container->right->setVisible(false);
            //        container->up->setVisible(false);
            //        container->down->setVisible(false);
            //        if (world->nowLevel == 9)
            //        {
            //            if (tempObject.x >= 370 && tempObject.x <= 470 && tempObject.y >= 240 && tempObject.y <= 390)
            //            {
            //                this->direction = "left";
            //                container->left->setVisible(true);
            //            }
            //        }
            //        if (!container->left.visible)
            //        {
            //            n = 1;
            //            while (n <= Main.mainClass.readXMLClass.strategies)
            //            {
            //                if (n == 1)
            //                {
            //                    map = world->map.road1;
            //                }
            //                else if (n == 2)
            //                {
            //                    map = world->map.road2;
            //                }
            //                else if (n == 3)
            //                {
            //                    map = world->map.road3;
            //                }
            //                i = map.length - 1;
            //                while (i > 0)
            //                {
            //                    if (map[i].x == map[(i - 1)].x)
            //                    {
            //                        if (map[i].y >= map[(i - 1)].y)
            //                        {
            //                            j = map[(i - 1)].y;
            //                            while (j < map[i].y)
            //                            {
            //                                tempObject2 = Point.distance(this->this_pt, new Point(map[i].x, j));
            //                                if (tempObject2 < 30)
            //                                {
            //                                    if (tempObject2 < tempObject1)
            //                                    {
            //                                        tempObject1 = tempObject2;
            //                                        tempObject3 = cocos2d::Point(map[i].x, j);
            //                                        this->direction = "down";
            //                                        container->down->setVisible(true);
            //                                    }
            //                                }
            //                                j = j + 5;
            //                            }
            //                        }
            //                        else
            //                        {
            //                            j = map[(i - 1)].y;
            //                            while (j >= map[i].y)
            //                            {
            //                                tempObject2 = Point.distance(this->this_pt, new Point(map[i].x, j));
            //                                if (tempObject2 < 30)
            //                                {
            //                                    if (tempObject2 < tempObject1)
            //                                    {
            //                                        tempObject1 = tempObject2;
            //                                        tempObject3 = cocos2d::Point(map[i].x, j);
            //                                        this->direction = "up";
            //                                        container->up->setVisible(true);
            //                                    }
            //                                }
            //                                j = j - 5;
            //                            }
            //                        }
            //                    }
            //                    else if (map[i].y == map[(i - 1)].y)
            //                    {
            //                        if (map[i].x >= map[(i - 1)].x)
            //                        {
            //                            j = map[(i - 1)].x;
            //                            while (j < map[i].x)
            //                            {
            //                                tempObject2 = Point.distance(this->this_pt, new Point(j, map[i].y));
            //                                if (tempObject2 < 30)
            //                                {
            //                                    if (tempObject2 < tempObject1)
            //                                    {
            //                                        tempObject1 = tempObject2;
            //                                        tempObject3 = cocos2d::Point(j, map[i].y);
            //                                        this->direction = "right";
            //                                        container->right->setVisible(true);
            //                                    }
            //                                }
            //                                j = j + 5;
            //                            }
            //                        }
            //                        else
            //                        {
            //                            j = map[(i - 1)].x;
            //                            while (j >= map[i].x)
            //                            {
            //                                tempObject2 = Point.distance(this->this_pt, new Point(j, map[i].y));
            //                                if (tempObject2 < 30)
            //                                {
            //                                    if (tempObject2 < tempObject1)
            //                                    {
            //                                        tempObject1 = tempObject2;
            //                                        tempObject3 = cocos2d::Point(j, map[i].y);
            //                                        this->direction = "left";
            //                                        container->left->setVisible(true);
            //                                    }
            //                                }
            //                                j = j - 5;
            //                            }
            //                        }
            //                    }
            //                    if (tempObject1 < tempObject2)
            //                    {
            //                        break;
            //                    }
            //                    i++;
            //                }
            //                if (tempObject1 < tempObject2)
            //                {
            //                    break;
            //                }
            //                n++;
            //            }
            //        }
            //    }
            //    if (container->left.visible)
            //    {
            //        if (container->left.currentFrame < container->left.totalFrames)
            //        {
            //            container->left.gotoAndStop((container->left.currentFrame + 1));
            //        }
            //        else
            //        {
            //            container->left.gotoAndStop(1);
            //        }
            //    }
            //    else if (container->right.visible)
            //    {
            //        if (container->right.currentFrame < container->right.totalFrames)
            //        {
            //            container->right.gotoAndStop((container->right.currentFrame + 1));
            //        }
            //        else
            //        {
            //            container->right.gotoAndStop(1);
            //        }
            //    }
            //    else if (container->up.visible)
            //    {
            //        if (container->up.currentFrame < container->up.totalFrames)
            //        {
            //            container->up.gotoAndStop((container->up.currentFrame + 1));
            //        }
            //        else
            //        {
            //            container->up.gotoAndStop(1);
            //        }
            //    }
            //    else if (container->down.visible)
            //    {
            //        if (container->down.currentFrame < container->down.totalFrames)
            //        {
            //            container->down.gotoAndStop((container->down.currentFrame + 1));
            //        }
            //        else
            //        {
            //            container->down.gotoAndStop(1);
            //        }
            //    }
            //}
            return;
        }// end function

        void  Cast_3::addAir()
        {
            this->directionManage();
            Air * tempObject=NULL;
            if (tempObject3.x>=0)
            {
                tempObject = new Air(tempObject3, this->direction);
            }
            else
            {
                tempObject = new Air(this->this_pt, this->direction);
            }
            world->addChild(tempObject);
            return;
        }// end function

    }
}
