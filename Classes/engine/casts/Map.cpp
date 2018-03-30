#include "Map.h"
#include "engine/World.h"

namespace engine{
    namespace    casts
    {
        void setPoints(Common::Array<cocos2d::Point>& path, cocos2d::Point road1[],int len)
        {
            for (int i = 0; i < len; i++)
            {
                double x = road1[i].x;
                double y = road1[i].y;
                x -= Main::SCREEN_WIDTH_OUT_LEFT;
                y = Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - y;
                path[i] = cocos2d::Point(x, y);
            }
        }
        Map::Map()
        { 
            if (Main::mainClass->saveBoxClass->playLevel == 1)
            {
                this->mapLevel1();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 2)
            {
                this->mapLevel2();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 3)
            {
                this->mapLevel3();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 4)
            {
                this->mapLevel4();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 5)
            {
                this->mapLevel5();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 6)
            {
                this->mapLevel6();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 7)
            {
                this->mapLevel7();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 8)
            {
                this->mapLevel8();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 9)
            {
                this->mapLevel9();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 10)
            {
                this->mapLevel10();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 11)
            {
                this->mapLevel11();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 12)
            {
                this->mapLevel12();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 13)
            {
                this->mapLevel13();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 14)
            {
                this->mapLevel14();
            }
            else if (Main::mainClass->saveBoxClass->playLevel == 15)
            {
                this->mapLevel15();
            }
            if (this->road1.size())
            {
                this->i = 0;
                while (this->i < (this->road1.size() - 1))
                {
                    if (this->road1[this->i].x == this->road1[(this->i + 1)].x)
                    {
                        if (this->road1[this->i].y > this->road1[(this->i + 1)].y)
                        {
                            this->j = this->road1[this->i].y;
                            while (this->j > this->road1[(this->i + 1)].y)
                            {
                                this->allPointsRoad1.push(cocos2d::Point(this->road1[this->i].x, this->j));
                                j--;
                            }
                        }
                        else
                        {
                            this->j = this->road1[this->i].y;
                            while (this->j < this->road1[(this->i + 1)].y)
                            {
                                this->allPointsRoad1.push(cocos2d::Point(this->road1[this->i].x, this->j));
                                j++;
                            }
                        }
                    }
                    else if (this->road1[this->i].x > this->road1[(this->i + 1)].x)
                    {
                        this->j = this->road1[this->i].x;
                        while (this->j > this->road1[(this->i + 1)].x)
                        { 
                            this->allPointsRoad1.push(cocos2d::Point(this->j, this->road1[this->i].y));
                            j--;
                        }
                    }
                    else
                    {
                        this->j = this->road1[this->i].x;
                        while (this->j < this->road1[(this->i + 1)].x)
                        {
                            this->allPointsRoad1.push(cocos2d::Point(this->j, this->road1[this->i].y));
                            j++;
                        }
                    }
                    i++;
                }
            }
            if (this->road2.size())
            {
                this->i = 0;
                while (this->i < (this->road2.size() - 1))
                {

                    if (this->road2[this->i].x == this->road2[(this->i + 1)].x)
                    {
                        if (this->road2[this->i].y > this->road2[(this->i + 1)].y)
                        {
                            this->j = this->road2[this->i].y;
                            while (this->j > this->road2[(this->i + 1)].y)
                            { 
                                this->allPointsRoad2.push(cocos2d::Point(this->road2[this->i].x, this->j));
                                j--;
                            }
                        }
                        else
                        {
                            this->j = this->road2[this->i].y;
                            while (this->j < this->road2[(this->i + 1)].y)
                            { 
                                this->allPointsRoad2.push(cocos2d::Point(this->road2[this->i].x, this->j));
                                j++;
                            }
                        }
                    }
                    else if (this->road2[this->i].x > this->road2[(this->i + 1)].x)
                    {
                        this->j = this->road2[this->i].x;
                        while (this->j > this->road2[(this->i + 1)].x)
                        { 
                            this->allPointsRoad2.push(cocos2d::Point(this->j, this->road2[this->i].y));
                            j--;
                        }
                    }
                    else
                    {
                        this->j = this->road2[this->i].x;
                        while (this->j < this->road2[(this->i + 1)].x)
                        { 
                            this->allPointsRoad2.push(cocos2d::Point(this->j, this->road2[this->i].y));
                            j++;
                        }
                    }
                    i++;
                }
            }
            if (this->road3.size())
            {
                this->i = 0;
                while (this->i < (this->road3.size() - 1))
                {

                    if (this->road3[this->i].x == this->road3[(this->i + 1)].x)
                    {
                        if (this->road3[this->i].y > this->road3[(this->i + 1)].y)
                        {
                            this->j = this->road3[this->i].y;
                            while (this->j > this->road3[(this->i + 1)].y)
                            {

                                this->allPointsRoad3.push(cocos2d::Point(this->road3[this->i].x, this->j));
                                j--;
                            }
                        }
                        else
                        {
                            this->j = this->road3[this->i].y;
                            while (this->j < this->road3[(this->i + 1)].y)
                            {

                                this->allPointsRoad3.push(cocos2d::Point(this->road3[this->i].x, this->j));
                                j++;
                            }
                        }
                    }
                    else if (this->road3[this->i].x > this->road3[(this->i + 1)].x)
                    {
                        this->j = this->road3[this->i].x;
                        while (this->j > this->road3[(this->i + 1)].x)
                        {

                            this->allPointsRoad3.push(cocos2d::Point(this->j, this->road3[this->i].y));
                            j++;
                        }
                    }
                    else
                    {
                        this->j = this->road3[this->i].x;
                        while (this->j < this->road3[(this->i + 1)].x)
                        {

                            this->allPointsRoad3.push(cocos2d::Point(this->j, this->road3[this->i].y));
                            j++;
                        }
                    }
                    i++;
                }
            }
            return;
        }// end function

        void Map:: mapLevel1() 
        {
            cocos2d::Point road1[] = { cocos2d::Point(850, 274), cocos2d::Point(675, 274), cocos2d::Point(675, 431), cocos2d::Point(307, 431), cocos2d::Point(307, 326), cocos2d::Point(148, 326), cocos2d::Point(148, 167), cocos2d::Point(-50, 167) };
            setPoints(this->road1, road1, 8);

            //cocos2d::Point road1[] = {cocos2d::Point(850, 274), cocos2d::Point(675, 274), cocos2d::Point(675, 431), cocos2d::Point(307, 431), cocos2d::Point(307, 326), cocos2d::Point(148, 326), cocos2d::Point(148, 167), cocos2d::Point(-50, 167)};
            return;
        }// end function

        void Map:: mapLevel2()
        {
            cocos2d::Point road1[] = { cocos2d::Point(571, 650), cocos2d::Point(571, 433), cocos2d::Point(729, 433), cocos2d::Point(729, 171), cocos2d::Point(518, 171), cocos2d::Point(518, 327), cocos2d::Point(306, 327), cocos2d::Point(306, 172), cocos2d::Point(202, 172), cocos2d::Point(202, 327), cocos2d::Point(-50, 327)};
            setPoints(this->road1, road1, 11);
            //cocos2d::Point road1[] = {cocos2d::Point(571, 650), cocos2d::Point(571, 433), cocos2d::Point(729, 433), cocos2d::Point(729, 171), cocos2d::Point(518, 171), cocos2d::Point(518, 327), cocos2d::Point(306, 327), cocos2d::Point(306, 172), cocos2d::Point(202, 172), cocos2d::Point(202, 327), cocos2d::Point(-50, 327)};
            return;
        }// end function

        void Map:: mapLevel3()
        {
            cocos2d::Point road1[] = { cocos2d::Point(850, 276), cocos2d::Point(676, 276), cocos2d::Point(676, 486), cocos2d::Point(413, 486), cocos2d::Point(413, 381), cocos2d::Point(413, 327), cocos2d::Point(516, 327), cocos2d::Point(516, 220), cocos2d::Point(148, 220), cocos2d::Point(148, 169), cocos2d::Point(-50, 169) };
            cocos2d::Point road2[] = { cocos2d::Point(850, 276), cocos2d::Point(676, 276), cocos2d::Point(676, 486), cocos2d::Point(413, 486), cocos2d::Point(413, 381), cocos2d::Point(254, 381), cocos2d::Point(254, 433), cocos2d::Point(-50, 433) };
            setPoints(this->road1, road1, 11);
            setPoints(this->road2, road2, 8);
            return;
        }// end function

        void Map:: mapLevel4()
        {
            cocos2d::Point road1[] = { cocos2d::Point(850, 277), cocos2d::Point(675, 277), cocos2d::Point(675, 168), cocos2d::Point(147, 168), cocos2d::Point(147, 328), cocos2d::Point(-50, 328) };
            cocos2d::Point road2[] = { cocos2d::Point(850, 380), cocos2d::Point(572, 380), cocos2d::Point(572, 484), cocos2d::Point(148, 484), cocos2d::Point(148, 433), cocos2d::Point(-50, 433) };
            setPoints(this->road1, road1, 6);
            setPoints(this->road2, road2, 6);
            return;
        }// end function

        void Map:: mapLevel5()
        {
            cocos2d::Point road1[] = {cocos2d::Point(729, 650), cocos2d::Point(729, 380), cocos2d::Point(623, 380), cocos2d::Point(623, 275), cocos2d::Point(623, 168), cocos2d::Point(253, 168), cocos2d::Point(253, 327), cocos2d::Point(96, 327), cocos2d::Point(96, 221), cocos2d::Point(-50, 221)};
            cocos2d::Point road2[] = {cocos2d::Point(729, 650), cocos2d::Point(729, 380), cocos2d::Point(623, 380), cocos2d::Point(623, 275), cocos2d::Point(413, 275), cocos2d::Point(413, 433), cocos2d::Point(42, 433), cocos2d::Point(42, 650)};
            setPoints(this->road1, road1, 10);
            setPoints(this->road2, road2, 8);
            return;
        }// end function

        void Map:: mapLevel6()
        {
            cocos2d::Point road1[] = {cocos2d::Point(850, 541 - 20), cocos2d::Point(622, 541 - 20), cocos2d::Point(622, 434 - 20), cocos2d::Point(464, 434 - 20), cocos2d::Point(464, 329 - 20), cocos2d::Point(360, 329 - 20), cocos2d::Point(255, 329 - 20), cocos2d::Point(255, 488 - 20), cocos2d::Point(96, 488 - 20), cocos2d::Point(96, 328 - 20), cocos2d::Point(-50, 328 - 20)};
            cocos2d::Point road2[] = {cocos2d::Point(850, 541 - 20), cocos2d::Point(622, 541 - 20), cocos2d::Point(622, 434 - 20), cocos2d::Point(464, 434 - 20), cocos2d::Point(464, 329 - 20), cocos2d::Point(360, 329 - 20), cocos2d::Point(360, 169 - 20), cocos2d::Point(622, 169 - 20), cocos2d::Point(622, 275 - 20), cocos2d::Point(850, 275 - 20)};
            setPoints(this->road1, road1, 11);
            setPoints(this->road2, road2, 10);
            return;
        }// end function

        void Map:: mapLevel7()
        {
            cocos2d::Point road1[] = {cocos2d::Point(850, 315), cocos2d::Point(722, 315), cocos2d::Point(722, 210), cocos2d::Point(616, 210), cocos2d::Point(616, 472), cocos2d::Point(510, 472), cocos2d::Point(510, 157), cocos2d::Point(300, 157), cocos2d::Point(300, 475), cocos2d::Point(196, 475), cocos2d::Point(196, 210), cocos2d::Point(88, 210), cocos2d::Point(88, 317), cocos2d::Point(-50, 317)};
            setPoints(this->road1, road1, 14);
            return;
        }// end function

        void Map:: mapLevel8()
        {
            cocos2d::Point road1[] = {cocos2d::Point(850, 474), cocos2d::Point(466, 474), cocos2d::Point(466, 316), cocos2d::Point(728, 316), cocos2d::Point(728, 157), cocos2d::Point(307, 157), cocos2d::Point(95, 157), cocos2d::Point(95, -50)};
            cocos2d::Point road2[] = {cocos2d::Point(850, 474), cocos2d::Point(466, 474), cocos2d::Point(466, 316), cocos2d::Point(728, 316), cocos2d::Point(728, 157), cocos2d::Point(307, 157), cocos2d::Point(307, 264), cocos2d::Point(96, 264), cocos2d::Point(96, 368), cocos2d::Point(307, 368), cocos2d::Point(307, 473), cocos2d::Point(-50, 473)};
            setPoints(this->road1, road1, 8);
            setPoints(this->road2, road2, 12);
            return;
        }// end function

        void Map:: mapLevel9()
        {
            cocos2d::Point road1[] = {cocos2d::Point(850, 474), cocos2d::Point(553, 474), cocos2d::Point(553, 423), cocos2d::Point(500, 423), cocos2d::Point(500, 370), cocos2d::Point(451, 370), cocos2d::Point(451, 315), cocos2d::Point(420, 315), cocos2d::Point(389, 315), cocos2d::Point(389, 262), cocos2d::Point(342, 262), cocos2d::Point(342, 211), cocos2d::Point(288, 211), cocos2d::Point(288, 158), cocos2d::Point(-50, 158)};
            cocos2d::Point road2[] = {cocos2d::Point(850, 159), cocos2d::Point(554, 159), cocos2d::Point(554, 212), cocos2d::Point(500, 212), cocos2d::Point(500, 262), cocos2d::Point(451, 262), cocos2d::Point(451, 315), cocos2d::Point(420, 315), cocos2d::Point(389, 315), cocos2d::Point(389, 372), cocos2d::Point(343, 372), cocos2d::Point(343, 423), cocos2d::Point(289, 423), cocos2d::Point(289, 475), cocos2d::Point(-50, 475)};
            setPoints(this->road1, road1, 15);
            setPoints(this->road2, road2, 15);
            return;
        }// end function

        void Map:: mapLevel10()
        {
            cocos2d::Point road1[] = {cocos2d::Point(850, 263), cocos2d::Point(767, 263), cocos2d::Point(767, 159), cocos2d::Point(663, 159), cocos2d::Point(663, 473), cocos2d::Point(505, 473), cocos2d::Point(505, 265), cocos2d::Point(400, 265), cocos2d::Point(400, -50)};
            cocos2d::Point road2[] = {cocos2d::Point(-50, 263), cocos2d::Point(32, 263), cocos2d::Point(32, 160), cocos2d::Point(136, 160), cocos2d::Point(136, 474), cocos2d::Point(293, 474), cocos2d::Point(293, 265), cocos2d::Point(400, 265), cocos2d::Point(400, -50)};
            setPoints(this->road1, road1, 9);
            setPoints(this->road2, road2, 9);
            return;
        }// end function

        void Map:: mapLevel11()
        {
            cocos2d::Point road1[] = {cocos2d::Point(850, 157), cocos2d::Point(726, 157), cocos2d::Point(726, 314), cocos2d::Point(621, 314), cocos2d::Point(621, 422), cocos2d::Point(516, 422), cocos2d::Point(516, 527), cocos2d::Point(253, 527), cocos2d::Point(253, 423), cocos2d::Point(96, 423), cocos2d::Point(96, 317), cocos2d::Point(-50, 317)};
            cocos2d::Point road2[] = {cocos2d::Point(850, 157), cocos2d::Point(726, 157), cocos2d::Point(726, 314), cocos2d::Point(621, 314), cocos2d::Point(621, 422), cocos2d::Point(516, 422), cocos2d::Point(411, 422), cocos2d::Point(411, 266), cocos2d::Point(305, 266), cocos2d::Point(305, 159), cocos2d::Point(510, 159)};
            setPoints(this->road1, road1, 12);
            setPoints(this->road2, road2, 11);
            return;
        }// end function

        void Map:: mapLevel12()
        {
            cocos2d::Point road1[] = {cocos2d::Point(658, 650), cocos2d::Point(658, 528), cocos2d::Point(446, 528), cocos2d::Point(446, 421), cocos2d::Point(290, 421), cocos2d::Point(290, 474), cocos2d::Point(76, 474), cocos2d::Point(76, 367), cocos2d::Point(182, 367), cocos2d::Point(182, 262), cocos2d::Point(288, 262), cocos2d::Point(288, 159), cocos2d::Point(498, 159), cocos2d::Point(498, 316), cocos2d::Point(657, 316), cocos2d::Point(657, 160), cocos2d::Point(762, 160), cocos2d::Point(762, -50)};
            cocos2d::Point road2[] = {cocos2d::Point(658, 650), cocos2d::Point(658, 528), cocos2d::Point(446, 528), cocos2d::Point(446, 421), cocos2d::Point(446, 316), cocos2d::Point(498, 316), cocos2d::Point(657, 316), cocos2d::Point(657, 160), cocos2d::Point(762, 160), cocos2d::Point(762, -50)};
            setPoints(this->road1, road1, 18);
            setPoints(this->road2, road2, 10);
            return;
        }// end function

        void Map:: mapLevel13()
        {
            cocos2d::Point road1[] = {cocos2d::Point(850, 474), cocos2d::Point(624, 474), cocos2d::Point(624, 317), cocos2d::Point(729, 317), cocos2d::Point(729, 159), cocos2d::Point(518, 159), cocos2d::Point(412, 159), cocos2d::Point(412, 262), cocos2d::Point(253, 262), cocos2d::Point(253, 160), cocos2d::Point(151, 160), cocos2d::Point(151, 265), cocos2d::Point(44, 265), cocos2d::Point(44, 527), cocos2d::Point(256, 527), cocos2d::Point(256, 424), cocos2d::Point(359, 424), cocos2d::Point(359, 650)};
            cocos2d::Point road2[] = {cocos2d::Point(850, 474), cocos2d::Point(624, 474), cocos2d::Point(624, 317), cocos2d::Point(729, 317), cocos2d::Point(729, 159), cocos2d::Point(518, 159), cocos2d::Point(518, 340)};
            setPoints(this->road1, road1, 18);
            setPoints(this->road2, road2, 7);
            return;
        }// end function

        void Map:: mapLevel14()
        {
            cocos2d::Point road1[] = {cocos2d::Point(131, 650), cocos2d::Point(131, 476), cocos2d::Point(290, 476), cocos2d::Point(290, 422), cocos2d::Point(448, 422), cocos2d::Point(448, 317), cocos2d::Point(552, 317), cocos2d::Point(759, 317), cocos2d::Point(759, 162), cocos2d::Point(134, 162), cocos2d::Point(134, 369), cocos2d::Point(-50, 369)};
            cocos2d::Point road2[] = {cocos2d::Point(131, 650), cocos2d::Point(131, 476), cocos2d::Point(290, 476), cocos2d::Point(290, 422), cocos2d::Point(448, 422), cocos2d::Point(448, 317), cocos2d::Point(552, 317), cocos2d::Point(552, 472), cocos2d::Point(743, 472)};
            setPoints(this->road1, road1, 12);
            setPoints(this->road2, road2, 9);
            return;
        }// end function

        void Map:: mapLevel15()
        {
            cocos2d::Point road1[] = {cocos2d::Point(401, 270), cocos2d::Point(401, 421), cocos2d::Point(248, 421), cocos2d::Point(248, 525), cocos2d::Point(90, 525), cocos2d::Point(90, 316), cocos2d::Point(195, 316), cocos2d::Point(195, 110), cocos2d::Point(-50, 110)};
            cocos2d::Point road2[] = {cocos2d::Point(401, 270), cocos2d::Point(401, 421), cocos2d::Point(558, 421), cocos2d::Point(558, 525), cocos2d::Point(714, 525), cocos2d::Point(714, 317), cocos2d::Point(609, 317), cocos2d::Point(609, 109), cocos2d::Point(850, 109)};
            setPoints(this->road1, road1, 9);
            setPoints(this->road2, road2, 9);
            return;
        }// end function

  }
}
