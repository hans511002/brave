package engine.casts
{

    public class Map extends Object
    {
        public var i:int;
        public var j:int;
        public var road1:Array;
        public var road2:Array;
        public var road3:Array;
        public var allPointsRoad1:Array;
        public var allPointsRoad2:Array;
        public var allPointsRoad3:Array;

        public function Map()
        {
            this.road1 = [];
            this.road2 = [];
            this.road3 = [];
            this.allPointsRoad1 = [];
            this.allPointsRoad2 = [];
            this.allPointsRoad3 = [];
            if (Main.mainClass.saveBoxClass.playLevel == 1)
            {
                this.mapLevel1();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 2)
            {
                this.mapLevel2();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 3)
            {
                this.mapLevel3();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 4)
            {
                this.mapLevel4();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 5)
            {
                this.mapLevel5();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 6)
            {
                this.mapLevel6();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 7)
            {
                this.mapLevel7();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 8)
            {
                this.mapLevel8();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 9)
            {
                this.mapLevel9();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 10)
            {
                this.mapLevel10();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 11)
            {
                this.mapLevel11();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 12)
            {
                this.mapLevel12();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 13)
            {
                this.mapLevel13();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 14)
            {
                this.mapLevel14();
            }
            else if (Main.mainClass.saveBoxClass.playLevel == 15)
            {
                this.mapLevel15();
            }
            if (this.road1)
            {
                this.i = 0;
                while (this.i < (this.road1.length - 1))
                {
                    
                    if (this.road1[this.i].x == this.road1[(this.i + 1)].x)
                    {
                        if (this.road1[this.i].y > this.road1[(this.i + 1)].y)
                        {
                            this.j = this.road1[this.i].y;
                            while (this.j > this.road1[(this.i + 1)].y)
                            {
                                
                                this.allPointsRoad1.push(new Point(this.road1[this.i].x, this.j));
                                var _loc_1:* = this;
                                var _loc_2:* = this.j - 1;
                                _loc_1.j = _loc_2;
                            }
                        }
                        else
                        {
                            this.j = this.road1[this.i].y;
                            while (this.j < this.road1[(this.i + 1)].y)
                            {
                                
                                this.allPointsRoad1.push(new Point(this.road1[this.i].x, this.j));
                                var _loc_1:* = this;
                                var _loc_2:* = this.j + 1;
                                _loc_1.j = _loc_2;
                            }
                        }
                    }
                    else if (this.road1[this.i].x > this.road1[(this.i + 1)].x)
                    {
                        this.j = this.road1[this.i].x;
                        while (this.j > this.road1[(this.i + 1)].x)
                        {
                            
                            this.allPointsRoad1.push(new Point(this.j, this.road1[this.i].y));
                            var _loc_1:* = this;
                            var _loc_2:* = this.j - 1;
                            _loc_1.j = _loc_2;
                        }
                    }
                    else
                    {
                        this.j = this.road1[this.i].x;
                        while (this.j < this.road1[(this.i + 1)].x)
                        {
                            
                            this.allPointsRoad1.push(new Point(this.j, this.road1[this.i].y));
                            var _loc_1:* = this;
                            var _loc_2:* = this.j + 1;
                            _loc_1.j = _loc_2;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            if (this.road2)
            {
                this.i = 0;
                while (this.i < (this.road2.length - 1))
                {
                    
                    if (this.road2[this.i].x == this.road2[(this.i + 1)].x)
                    {
                        if (this.road2[this.i].y > this.road2[(this.i + 1)].y)
                        {
                            this.j = this.road2[this.i].y;
                            while (this.j > this.road2[(this.i + 1)].y)
                            {
                                
                                this.allPointsRoad2.push(new Point(this.road2[this.i].x, this.j));
                                var _loc_1:* = this;
                                var _loc_2:* = this.j - 1;
                                _loc_1.j = _loc_2;
                            }
                        }
                        else
                        {
                            this.j = this.road2[this.i].y;
                            while (this.j < this.road2[(this.i + 1)].y)
                            {
                                
                                this.allPointsRoad2.push(new Point(this.road2[this.i].x, this.j));
                                var _loc_1:* = this;
                                var _loc_2:* = this.j + 1;
                                _loc_1.j = _loc_2;
                            }
                        }
                    }
                    else if (this.road2[this.i].x > this.road2[(this.i + 1)].x)
                    {
                        this.j = this.road2[this.i].x;
                        while (this.j > this.road2[(this.i + 1)].x)
                        {
                            
                            this.allPointsRoad2.push(new Point(this.j, this.road2[this.i].y));
                            var _loc_1:* = this;
                            var _loc_2:* = this.j - 1;
                            _loc_1.j = _loc_2;
                        }
                    }
                    else
                    {
                        this.j = this.road2[this.i].x;
                        while (this.j < this.road2[(this.i + 1)].x)
                        {
                            
                            this.allPointsRoad2.push(new Point(this.j, this.road2[this.i].y));
                            var _loc_1:* = this;
                            var _loc_2:* = this.j + 1;
                            _loc_1.j = _loc_2;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            if (this.road3)
            {
                this.i = 0;
                while (this.i < (this.road3.length - 1))
                {
                    
                    if (this.road3[this.i].x == this.road3[(this.i + 1)].x)
                    {
                        if (this.road3[this.i].y > this.road3[(this.i + 1)].y)
                        {
                            this.j = this.road3[this.i].y;
                            while (this.j > this.road3[(this.i + 1)].y)
                            {
                                
                                this.allPointsRoad3.push(new Point(this.road3[this.i].x, this.j));
                                var _loc_1:* = this;
                                var _loc_2:* = this.j - 1;
                                _loc_1.j = _loc_2;
                            }
                        }
                        else
                        {
                            this.j = this.road3[this.i].y;
                            while (this.j < this.road3[(this.i + 1)].y)
                            {
                                
                                this.allPointsRoad3.push(new Point(this.road3[this.i].x, this.j));
                                var _loc_1:* = this;
                                var _loc_2:* = this.j + 1;
                                _loc_1.j = _loc_2;
                            }
                        }
                    }
                    else if (this.road3[this.i].x > this.road3[(this.i + 1)].x)
                    {
                        this.j = this.road3[this.i].x;
                        while (this.j > this.road3[(this.i + 1)].x)
                        {
                            
                            this.allPointsRoad3.push(new Point(this.j, this.road3[this.i].y));
                            var _loc_1:* = this;
                            var _loc_2:* = this.j - 1;
                            _loc_1.j = _loc_2;
                        }
                    }
                    else
                    {
                        this.j = this.road3[this.i].x;
                        while (this.j < this.road3[(this.i + 1)].x)
                        {
                            
                            this.allPointsRoad3.push(new Point(this.j, this.road3[this.i].y));
                            var _loc_1:* = this;
                            var _loc_2:* = this.j + 1;
                            _loc_1.j = _loc_2;
                        }
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.i + 1;
                    _loc_1.i = _loc_2;
                }
            }
            return;
        }// end function

        public function mapLevel1() : void
        {
            this.road1 = [new Point(850, 274), new Point(675, 274), new Point(675, 431), new Point(307, 431), new Point(307, 326), new Point(148, 326), new Point(148, 167), new Point(-50, 167)];
            return;
        }// end function

        public function mapLevel2() : void
        {
            this.road1 = [new Point(571, 650), new Point(571, 433), new Point(729, 433), new Point(729, 171), new Point(518, 171), new Point(518, 327), new Point(306, 327), new Point(306, 172), new Point(202, 172), new Point(202, 327), new Point(-50, 327)];
            return;
        }// end function

        public function mapLevel3() : void
        {
            this.road1 = [new Point(850, 276), new Point(676, 276), new Point(676, 486), new Point(413, 486), new Point(413, 381), new Point(413, 327), new Point(516, 327), new Point(516, 220), new Point(148, 220), new Point(148, 169), new Point(-50, 169)];
            this.road2 = [new Point(850, 276), new Point(676, 276), new Point(676, 486), new Point(413, 486), new Point(413, 381), new Point(254, 381), new Point(254, 433), new Point(-50, 433)];
            return;
        }// end function

        public function mapLevel4() : void
        {
            this.road1 = [new Point(850, 277), new Point(675, 277), new Point(675, 168), new Point(147, 168), new Point(147, 328), new Point(-50, 328)];
            this.road2 = [new Point(850, 380), new Point(572, 380), new Point(572, 484), new Point(148, 484), new Point(148, 433), new Point(-50, 433)];
            return;
        }// end function

        public function mapLevel5() : void
        {
            this.road1 = [new Point(729, 650), new Point(729, 380), new Point(623, 380), new Point(623, 275), new Point(623, 168), new Point(253, 168), new Point(253, 327), new Point(96, 327), new Point(96, 221), new Point(-50, 221)];
            this.road2 = [new Point(729, 650), new Point(729, 380), new Point(623, 380), new Point(623, 275), new Point(413, 275), new Point(413, 433), new Point(42, 433), new Point(42, 650)];
            return;
        }// end function

        public function mapLevel6() : void
        {
            this.road1 = [new Point(850, 541 - 20), new Point(622, 541 - 20), new Point(622, 434 - 20), new Point(464, 434 - 20), new Point(464, 329 - 20), new Point(360, 329 - 20), new Point(255, 329 - 20), new Point(255, 488 - 20), new Point(96, 488 - 20), new Point(96, 328 - 20), new Point(-50, 328 - 20)];
            this.road2 = [new Point(850, 541 - 20), new Point(622, 541 - 20), new Point(622, 434 - 20), new Point(464, 434 - 20), new Point(464, 329 - 20), new Point(360, 329 - 20), new Point(360, 169 - 20), new Point(622, 169 - 20), new Point(622, 275 - 20), new Point(850, 275 - 20)];
            return;
        }// end function

        public function mapLevel7() : void
        {
            this.road1 = [new Point(850, 315), new Point(722, 315), new Point(722, 210), new Point(616, 210), new Point(616, 472), new Point(510, 472), new Point(510, 157), new Point(300, 157), new Point(300, 475), new Point(196, 475), new Point(196, 210), new Point(88, 210), new Point(88, 317), new Point(-50, 317)];
            return;
        }// end function

        public function mapLevel8() : void
        {
            this.road1 = [new Point(850, 474), new Point(466, 474), new Point(466, 316), new Point(728, 316), new Point(728, 157), new Point(307, 157), new Point(95, 157), new Point(95, -50)];
            this.road2 = [new Point(850, 474), new Point(466, 474), new Point(466, 316), new Point(728, 316), new Point(728, 157), new Point(307, 157), new Point(307, 264), new Point(96, 264), new Point(96, 368), new Point(307, 368), new Point(307, 473), new Point(-50, 473)];
            return;
        }// end function

        public function mapLevel9() : void
        {
            this.road1 = [new Point(850, 474), new Point(553, 474), new Point(553, 423), new Point(500, 423), new Point(500, 370), new Point(451, 370), new Point(451, 315), new Point(420, 315), new Point(389, 315), new Point(389, 262), new Point(342, 262), new Point(342, 211), new Point(288, 211), new Point(288, 158), new Point(-50, 158)];
            this.road2 = [new Point(850, 159), new Point(554, 159), new Point(554, 212), new Point(500, 212), new Point(500, 262), new Point(451, 262), new Point(451, 315), new Point(420, 315), new Point(389, 315), new Point(389, 372), new Point(343, 372), new Point(343, 423), new Point(289, 423), new Point(289, 475), new Point(-50, 475)];
            return;
        }// end function

        public function mapLevel10() : void
        {
            this.road1 = [new Point(850, 263), new Point(767, 263), new Point(767, 159), new Point(663, 159), new Point(663, 473), new Point(505, 473), new Point(505, 265), new Point(400, 265), new Point(400, -50)];
            this.road2 = [new Point(-50, 263), new Point(32, 263), new Point(32, 160), new Point(136, 160), new Point(136, 474), new Point(293, 474), new Point(293, 265), new Point(400, 265), new Point(400, -50)];
            return;
        }// end function

        public function mapLevel11() : void
        {
            this.road1 = [new Point(850, 157), new Point(726, 157), new Point(726, 314), new Point(621, 314), new Point(621, 422), new Point(516, 422), new Point(516, 527), new Point(253, 527), new Point(253, 423), new Point(96, 423), new Point(96, 317), new Point(-50, 317)];
            this.road2 = [new Point(850, 157), new Point(726, 157), new Point(726, 314), new Point(621, 314), new Point(621, 422), new Point(516, 422), new Point(411, 422), new Point(411, 266), new Point(305, 266), new Point(305, 159), new Point(510, 159)];
            return;
        }// end function

        public function mapLevel12() : void
        {
            this.road1 = [new Point(658, 650), new Point(658, 528), new Point(446, 528), new Point(446, 421), new Point(290, 421), new Point(290, 474), new Point(76, 474), new Point(76, 367), new Point(182, 367), new Point(182, 262), new Point(288, 262), new Point(288, 159), new Point(498, 159), new Point(498, 316), new Point(657, 316), new Point(657, 160), new Point(762, 160), new Point(762, -50)];
            this.road2 = [new Point(658, 650), new Point(658, 528), new Point(446, 528), new Point(446, 421), new Point(446, 316), new Point(498, 316), new Point(657, 316), new Point(657, 160), new Point(762, 160), new Point(762, -50)];
            return;
        }// end function

        public function mapLevel13() : void
        {
            this.road1 = [new Point(850, 474), new Point(624, 474), new Point(624, 317), new Point(729, 317), new Point(729, 159), new Point(518, 159), new Point(412, 159), new Point(412, 262), new Point(253, 262), new Point(253, 160), new Point(151, 160), new Point(151, 265), new Point(44, 265), new Point(44, 527), new Point(256, 527), new Point(256, 424), new Point(359, 424), new Point(359, 650)];
            this.road2 = [new Point(850, 474), new Point(624, 474), new Point(624, 317), new Point(729, 317), new Point(729, 159), new Point(518, 159), new Point(518, 340)];
            return;
        }// end function

        public function mapLevel14() : void
        {
            this.road1 = [new Point(131, 650), new Point(131, 476), new Point(290, 476), new Point(290, 422), new Point(448, 422), new Point(448, 317), new Point(552, 317), new Point(759, 317), new Point(759, 162), new Point(134, 162), new Point(134, 369), new Point(-50, 369)];
            this.road2 = [new Point(131, 650), new Point(131, 476), new Point(290, 476), new Point(290, 422), new Point(448, 422), new Point(448, 317), new Point(552, 317), new Point(552, 472), new Point(743, 472)];
            return;
        }// end function

        public function mapLevel15() : void
        {
            this.road1 = [new Point(401, 270), new Point(401, 421), new Point(248, 421), new Point(248, 525), new Point(90, 525), new Point(90, 316), new Point(195, 316), new Point(195, 110), new Point(-50, 110)];
            this.road2 = [new Point(401, 270), new Point(401, 421), new Point(558, 421), new Point(558, 525), new Point(714, 525), new Point(714, 317), new Point(609, 317), new Point(609, 109), new Point(850, 109)];
            return;
        }// end function

    }
}
