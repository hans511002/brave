package engine
{

    public class Testing extends Object
    {
        public var i:int;
        public var j:int;
        public var n:int;
        public var tempObject:Object;
        public var listOfStory:Array;
        public var loadWave:int;
        public var world:World;

        public function Testing()
        {
            this.listOfStory = [];
            this.world = Main.mainClass.worldClass;
            return;
        }// end function

        public function newWave() : void
        {
            this.listOfStory[this.world.wavesClass.nowWave] = [];
            this.listOfStory[this.world.wavesClass.nowWave][0] = this.world.money;
            this.listOfStory[this.world.wavesClass.nowWave][1] = this.world.worldInterface.fireCount;
            this.listOfStory[this.world.wavesClass.nowWave][2] = this.world.worldInterface.iceCount;
            this.listOfStory[this.world.wavesClass.nowWave][3] = this.world.worldInterface.stoneCount;
            this.listOfStory[this.world.wavesClass.nowWave][4] = this.world.worldInterface.levinCount;
            this.listOfStory[this.world.wavesClass.nowWave][5] = this.world.worldInterface.getAllCount;
            this.listOfStory[this.world.wavesClass.nowWave][6] = this.world.worldInterface.fireBuyHistory;
            this.listOfStory[this.world.wavesClass.nowWave][7] = this.world.worldInterface.iceBuyHistory;
            this.listOfStory[this.world.wavesClass.nowWave][8] = this.world.worldInterface.stoneBuyHistory;
            this.listOfStory[this.world.wavesClass.nowWave][9] = this.world.worldInterface.levinBuyHistory;
            this.listOfStory[this.world.wavesClass.nowWave][10] = Main.mainClass.readXMLClass.costTowerXML;
            this.listOfStory[this.world.wavesClass.nowWave][11] = [];
            this.tempObject = this.listOfStory[this.world.wavesClass.nowWave][11];
            this.i = 0;
            while (this.i < this.world.listOfTowers.length)
            {
                
                this.tempObject[this.i] = [];
                this.tempObject[this.i][0] = this.world.listOfTowers[this.i].towerType;
                this.tempObject[this.i][1] = this.world.listOfTowers[this.i].myPlace.name;
                this.tempObject[this.i][2] = [];
                if (this.world.listOfTowers[this.i].shootingTurnStack[0])
                {
                    this.tempObject[this.i][2][0] = [];
                    this.tempObject[this.i][2][0][0] = this.world.listOfTowers[this.i].shootingTurnStack[0][0];
                    this.tempObject[this.i][2][0][1] = this.world.listOfTowers[this.i].shootingTurnStack[0][1];
                    this.tempObject[this.i][2][0][2] = this.world.listOfTowers[this.i].shootingTurnStack[0][2];
                    this.tempObject[this.i][2][0][3] = this.world.listOfTowers[this.i].shootingTurnStack[0][3];
                }
                else
                {
                    this.tempObject[this.i][2][0] = null;
                }
                if (this.world.listOfTowers[this.i].shootingTurnStack[1])
                {
                    this.tempObject[this.i][2][1] = [];
                    this.tempObject[this.i][2][1][0] = this.world.listOfTowers[this.i].shootingTurnStack[1][0];
                    this.tempObject[this.i][2][1][1] = this.world.listOfTowers[this.i].shootingTurnStack[1][1];
                    this.tempObject[this.i][2][1][2] = this.world.listOfTowers[this.i].shootingTurnStack[1][2];
                    this.tempObject[this.i][2][1][3] = this.world.listOfTowers[this.i].shootingTurnStack[1][3];
                }
                else
                {
                    this.tempObject[this.i][2][1] = null;
                }
                if (this.world.listOfTowers[this.i].shootingTurnStack[2])
                {
                    this.tempObject[this.i][2][2] = [];
                    this.tempObject[this.i][2][2][0] = this.world.listOfTowers[this.i].shootingTurnStack[2][0];
                    this.tempObject[this.i][2][2][1] = this.world.listOfTowers[this.i].shootingTurnStack[2][1];
                    this.tempObject[this.i][2][2][2] = this.world.listOfTowers[this.i].shootingTurnStack[2][2];
                    this.tempObject[this.i][2][2][3] = this.world.listOfTowers[this.i].shootingTurnStack[2][3];
                }
                else
                {
                    this.tempObject[this.i][2][2] = null;
                }
                if (this.world.listOfTowers[this.i].shootingTurnStack[3])
                {
                    this.tempObject[this.i][2][3] = [];
                    this.tempObject[this.i][2][3][0] = this.world.listOfTowers[this.i].shootingTurnStack[3][0];
                    this.tempObject[this.i][2][3][1] = this.world.listOfTowers[this.i].shootingTurnStack[3][1];
                    this.tempObject[this.i][2][3][2] = this.world.listOfTowers[this.i].shootingTurnStack[3][2];
                    this.tempObject[this.i][2][3][3] = this.world.listOfTowers[this.i].shootingTurnStack[3][3];
                }
                else
                {
                    this.tempObject[this.i][2][3] = null;
                }
                this.tempObject[this.i][3] = this.world.listOfTowers[this.i].upgradeTypeAdd;
                var _loc_1:* = this;
                var _loc_2:* = this.i + 1;
                _loc_1.i = _loc_2;
            }
            return;
        }// end function

        public function load() : void
        {
            this.world = Main.mainClass.worldClass;
            this.world.money = this.listOfStory[this.loadWave][0];
            this.world.worldInterface.fireCount = this.listOfStory[this.loadWave][1];
            this.world.worldInterface.iceCount = this.listOfStory[this.loadWave][2];
            this.world.worldInterface.stoneCount = this.listOfStory[this.loadWave][3];
            this.world.worldInterface.levinCount = this.listOfStory[this.loadWave][4];
            this.world.worldInterface.getAllCount = this.listOfStory[this.loadWave][5];
            this.world.worldInterface.fireBuyHistory = this.listOfStory[this.loadWave][6];
            this.world.worldInterface.iceBuyHistory = this.listOfStory[this.loadWave][7];
            this.world.worldInterface.stoneBuyHistory = this.listOfStory[this.loadWave][8];
            this.world.worldInterface.levinBuyHistory = this.listOfStory[this.loadWave][9];
            Main.mainClass.readXMLClass.costTowerXML = this.listOfStory[this.loadWave][10];
            this.i = 0;
            while (this.i < this.world.listOfPlaces.length)
            {
                
                this.j = 0;
                while (this.j < this.listOfStory[this.loadWave][11].length)
                {
                    
                    if (this.listOfStory[this.loadWave][11][this.j][1] == this.world.listOfPlaces[this.i].name)
                    {
                        this.world.listOfPlaces[this.i].gotoAndStop(2);
                        var _loc_1:* = false;
                        this.world.listOfPlaces[this.i].setMouseChildren(false);
                        this.world.listOfPlaces[this.i].mouseEnabled = _loc_1;
                        if (this.listOfStory[this.loadWave][11][this.j][0] == 1)
                        {
                            this.tempObject = this.world.addTower("tower1", this.world.listOfPlaces[this.i]);
                        }
                        else if (this.listOfStory[this.loadWave][11][this.j][0] == 2)
                        {
                            this.tempObject = this.world.addTower("tower2", this.world.listOfPlaces[this.i]);
                        }
                        else if (this.listOfStory[this.loadWave][11][this.j][0] == 3)
                        {
                            this.tempObject = this.world.addTower("tower3", this.world.listOfPlaces[this.i]);
                        }
                        else if (this.listOfStory[this.loadWave][11][this.j][0] == 4)
                        {
                            this.tempObject = this.world.addTower("tower4", this.world.listOfPlaces[this.i]);
                        }
                        else if (this.listOfStory[this.loadWave][11][this.j][0] == 5)
                        {
                            this.tempObject = this.world.addTower("tower5", this.world.listOfPlaces[this.i]);
                        }
                        else if (this.listOfStory[this.loadWave][11][this.j][0] == 6)
                        {
                            this.tempObject = this.world.addTower("tower6", this.world.listOfPlaces[this.i]);
                        }
                        else if (this.listOfStory[this.loadWave][11][this.j][0] == 7)
                        {
                            this.tempObject = this.world.addTower("tower7", this.world.listOfPlaces[this.i]);
                        }
                        else if (this.listOfStory[this.loadWave][11][this.j][0] == 8)
                        {
                            this.tempObject = this.world.addTower("tower8", this.world.listOfPlaces[this.i]);
                        }
                        if (this.listOfStory[this.loadWave][11][this.j][2][0])
                        {
                            this.tempObject.spheresManage("push", "fire", this.listOfStory[this.loadWave][11][this.j][2][0][3]);
                        }
                        if (this.listOfStory[this.loadWave][11][this.j][2][1])
                        {
                            this.tempObject.spheresManage("push", "ice", this.listOfStory[this.loadWave][11][this.j][2][1][3]);
                        }
                        if (this.listOfStory[this.loadWave][11][this.j][2][2])
                        {
                            this.tempObject.spheresManage("push", "stone", this.listOfStory[this.loadWave][11][this.j][2][2][3]);
                        }
                        if (this.listOfStory[this.loadWave][11][this.j][2][3])
                        {
                            this.tempObject.spheresManage("push", "levin", this.listOfStory[this.loadWave][11][this.j][2][3][3]);
                        }
                        this.tempObject.upgradeTypeAdd = this.listOfStory[this.loadWave][11][this.j][3];
                        break;
                    }
                    var _loc_1:* = this;
                    var _loc_2:* = this.j + 1;
                    _loc_1.j = _loc_2;
                }
                var _loc_1:* = this;
                var _loc_2:* = this.i + 1;
                _loc_1.i = _loc_2;
            }
            if (this.loadWave > 0)
            {
                this.world.wavesClass.nowWave = this.loadWave - 1;
            }
            else
            {
                this.world.wavesClass.nowWave = 0;
            }
            this.i = 0;
            while (this.i < this.world.wavesClass.listOfWaves.length)
            {
                
                this.j = 0;
                while (this.j < (this.loadWave - 1))
                {
                    
                    this.world.wavesClass.listOfWaves[this.i].splice(0, 1);
                    var _loc_1:* = this;
                    var _loc_2:* = this.j + 1;
                    _loc_1.j = _loc_2;
                }
                var _loc_1:* = this;
                var _loc_2:* = this.i + 1;
                _loc_1.i = _loc_2;
            }
            this.world.worldInterface.blockCastGolem = false;
            this.world.worldInterface.blockCastIceman = false;
            this.world.worldInterface.blockCastAir = false;
            this.world.worldInterface.container.快.fastCase.setMouseEnabled(true);
            this.world.worldInterface.updateInfo();
            return;
        }// end function

    }
}
