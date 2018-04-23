#ifndef ENGINE_WORLDINTERFACE_H
#define ENGINE_WORLDINTERFACE_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"
//#include "MainClass.h"
//#include "World.h"
#include "JsonUtil.h"
#include "WorldInterface_mc.h"
#include "engine/units/Unit.h"

namespace engine
{ 
	class World;
	class  WorldInterface :public cocos2d::Node
    {
	public:
		int i;
        //public var tempObject:Object;
        //public var tempObject1:Object;
        //public var tempObject2:Object;
        WorldInterface_mc *container; //public var container:WorldInterface_mc;
        int fasterFlag;//int fasterFlag;////public var fasterFlag:int = 0;
		World * world;//public var world:World;
        //public var castMask:CastMask_mc;
		Common::Array<Common::Array<int> >  sphereCostHistory;//public var sphereCostHistory:Array;
        Common::Array<units::Unit*> listOfNewEnemies;//public var listOfNewEnemies:Array;
        ui::Text * lastTime;//public var lastTime:TextField;
        //public var listOfGetAhieve:Array;
		Common::Array<MovieClip *> listOfAnimation;//public var listOfAnimation:Array;
        //public var sellHint:Hint_mc;
        //public var getAllHint:Hint_mc;
        int fireCount;////public var fireCount:int = 0;
        int iceCount;////public var iceCount:int = 0;
        int stoneCount;////public var stoneCount:int = 0;
        int levinCount;////public var levinCount:int = 0;
        int getAllCount;////public var getAllCount:int = 0;
        int fireBuyHistory;////public var fireBuyHistory:int = 0;
        int iceBuyHistory;////public var iceBuyHistory:int = 0;
        int stoneBuyHistory;////public var stoneBuyHistory:int = 0;
        int levinBuyHistory;////public var levinBuyHistory:int = 0;
        bool blockCastGolem;////public var blockCastGolem:Boolean;
        bool blockCastIceman;////public var blockCastIceman:Boolean;
        bool blockCastAir;////public var blockCastAir:Boolean;
        int castGolemCounter;////public var castGolemCounter:int = 0;
        int castIcemanCounter;////public var castIcemanCounter:int = 0;
        int castAirCounter;////public var castAirCounter:int = 0;
        int castGolemTimer;////public var castGolemTimer:int;
        int castIcemanTimer;////public var castIcemanTimer:int;
        int castAirTimer;////public var castAirTimer:int;
		cocos2d::Point autoguidesMouse_pt;//public var autoguidesMouse_pt:Point;
		cocos2d::Point autoguidesObject;//public var autoguidesObject:Object;
		cocos2d::Point autoguidesObject_pt;//public var autoguidesObject_pt:Point;
        float autoguidesObjectWidth;////public var autoguidesObjectWidth:Number;
        float autoguidesObjectHeight;////public var autoguidesObjectHeight:Number;

		WorldInterface();
		CREATE_FUNC(WorldInterface);
		bool init();// (event:Event) : void
  

		void update();
        void clickHandler(Ref* ref);
        
        void mouseMoveHandler(cocos2d::Event* param1);
        void mouseDownHandler(cocos2d::Event *event);
        void mouseUpHandler(cocos2d::Event* event);
        bool onTouchBegan(Touch *touch, Event *unused_event);
        void onTouchEnded(Touch *touch, Event *unused_event);
        void onTouchCancelled(Touch *touch, Event *unused_event);
        void onTouchMoved(Touch *touch, Event *unused_event);

        void onMouseMove(Event *unused_event);
        void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
        void onTouchesMoved(const std::vector<Touch*>& touches, Event *pEvent);
        void onTouchesEnded(const std::vector<Touch*>& touches, Event *pEvent);
        void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

        void addCast(string param1) 
        {
            //if (param1 == "golem")
            //{
            //    this->world.cast = new Cast_1();
            //}
            //else if (param1 == "iceman")
            //{
            //    this->world.cast = new Cast_2();
            //}
            //else if (param1 == "air")
            //{
            //    this->world.cast = new Cast_3();
            //}
            //this->world.addChild(this->world.cast);
            //this->world.listOfClasses.push(this->world.cast);
        }// end function

		void updateInfo();

        void archiveManage(string param1, string param2) 
        {
            //if (param1 == "buy")
            //{
            //    if (param2 == "fire")
            //    {
            //        if (this->world.money >= Main.mainClass.readXMLClass.listOfFirePriceXML[this->fireBuyHistory])
            //        {
            //            (this->fireCount + 1);
            //            this->world.money = this->world.money - Main.mainClass.readXMLClass.listOfFirePriceXML[this->fireBuyHistory];
            //            this->sphereCostHistory[0].push(Main.mainClass.readXMLClass.listOfFirePriceXML[this->fireBuyHistory]);
            //            if (this->fireBuyHistory < (Main.mainClass.readXMLClass.listOfFirePriceXML.length - 1))
            //            {
            //                (this->fireBuyHistory + 1);
            //            }
            //        }
            //    }
            //    else if (param2 == "ice")
            //    {
            //        if (this->world.money >= Main.mainClass.readXMLClass.listOfIcePriceXML[this->iceBuyHistory])
            //        {
            //            (this->iceCount + 1);
            //            this->world.money = this->world.money - Main.mainClass.readXMLClass.listOfIcePriceXML[this->iceBuyHistory];
            //            this->sphereCostHistory[1].push(Main.mainClass.readXMLClass.listOfIcePriceXML[this->iceBuyHistory]);
            //            if (this->iceBuyHistory < (Main.mainClass.readXMLClass.listOfIcePriceXML.length - 1))
            //            {
            //                (this->iceBuyHistory + 1);
            //            }
            //        }
            //    }
            //    else if (param2 == "stone")
            //    {
            //        if (this->world.money >= Main.mainClass.readXMLClass.listOfStonePriceXML[this->stoneBuyHistory])
            //        {
            //            (this->stoneCount + 1);
            //            this->world.money = this->world.money - Main.mainClass.readXMLClass.listOfStonePriceXML[this->stoneBuyHistory];
            //            this->sphereCostHistory[2].push(Main.mainClass.readXMLClass.listOfStonePriceXML[this->stoneBuyHistory]);
            //            if (this->stoneBuyHistory < (Main.mainClass.readXMLClass.listOfStonePriceXML.length - 1))
            //            {
            //                (this->stoneBuyHistory + 1);
            //            }
            //        }
            //    }
            //    else if (param2 == "levin")
            //    {
            //        if (this->world.money >= Main.mainClass.readXMLClass.listOfLevinPriceXML[this->levinBuyHistory])
            //        {
            //            (this->levinCount + 1);
            //            this->world.money = this->world.money - Main.mainClass.readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
            //            this->sphereCostHistory[3].push(Main.mainClass.readXMLClass.listOfLevinPriceXML[this->levinBuyHistory]);
            //            if (this->levinBuyHistory < (Main.mainClass.readXMLClass.listOfLevinPriceXML.length - 1))
            //            {
            //                (this->levinBuyHistory + 1);
            //            }
            //        }
            //    }
            //    else if (param2 == "getAll")
            //    {
            //        if (this->world.money >= Main.mainClass.readXMLClass.listOfFirePriceXML[this->fireBuyHistory] + Main.mainClass.readXMLClass.listOfIcePriceXML[this->iceBuyHistory] + Main.mainClass.readXMLClass.listOfStonePriceXML[this->stoneBuyHistory] + Main.mainClass.readXMLClass.listOfLevinPriceXML[this->levinBuyHistory])
            //        {
            //            (this->getAllCount + 1);
            //            this->tempObject = Main.mainClass.readXMLClass.listOfFirePriceXML[this->fireBuyHistory] + Main.mainClass.readXMLClass.listOfIcePriceXML[this->iceBuyHistory] + Main.mainClass.readXMLClass.listOfStonePriceXML[this->stoneBuyHistory] + Main.mainClass.readXMLClass.listOfLevinPriceXML[this->levinBuyHistory];
            //            this->world.money = this->world.money - this->tempObject;
            //            if (this->fireBuyHistory < (Main.mainClass.readXMLClass.listOfFirePriceXML.length - 1))
            //            {
            //                (this->fireBuyHistory + 1);
            //            }
            //            if (this->iceBuyHistory < (Main.mainClass.readXMLClass.listOfIcePriceXML.length - 1))
            //            {
            //                (this->iceBuyHistory + 1);
            //            }
            //            if (this->stoneBuyHistory < (Main.mainClass.readXMLClass.listOfStonePriceXML.length - 1))
            //            {
            //                (this->stoneBuyHistory + 1);
            //            }
            //            if (this->levinBuyHistory < (Main.mainClass.readXMLClass.listOfLevinPriceXML.length - 1))
            //            {
            //                (this->levinBuyHistory + 1);
            //            }
            //        }
            //    }
            //}
            //else if (param1 == "get")
            //{
            //    if (param2 == "fire")
            //    {
            //        if (this->fireCount > 0)
            //        {
            //            if (!this->world.getSphere)
            //            {
            //                (this->fireCount - 1);
            //                this->world.getSphere = new GetSphere();
            //                this->world.getSphere.owner = this->container.fireSphere;
            //                this->world.getSphere.ownerType = "archive";
            //                this->world.getSphere.ownerPoint = this->container.fireSphere.myPoint;
            //                this->world.addChild(this->world.getSphere);
            //                this->world.getSphere.manage("add", "fire");
            //            }
            //            else if (this->world.getSphere.listOfStack.length < 4)
            //            {
            //                (this->fireCount - 1);
            //                this->world.getSphere.manage("add", "fire");
            //            }
            //        }
            //    }
            //    else if (param2 == "ice")
            //    {
            //        if (this->iceCount > 0)
            //        {
            //            if (!this->world.getSphere)
            //            {
            //                (this->iceCount - 1);
            //                this->world.getSphere = new GetSphere();
            //                this->world.getSphere.owner = this->container.iceSphere;
            //                this->world.getSphere.ownerType = "archive";
            //                this->world.getSphere.ownerPoint = this->container.iceSphere.myPoint;
            //                this->world.addChild(this->world.getSphere);
            //                this->world.getSphere.manage("add", "ice");
            //            }
            //            else if (this->world.getSphere.listOfStack.length < 4)
            //            {
            //                (this->iceCount - 1);
            //                this->world.getSphere.manage("add", "ice");
            //            }
            //        }
            //    }
            //    else if (param2 == "stone")
            //    {
            //        if (this->stoneCount > 0)
            //        {
            //            if (!this->world.getSphere)
            //            {
            //                (this->stoneCount - 1);
            //                this->world.getSphere = new GetSphere();
            //                this->world.getSphere.owner = this->container.stoneSphere;
            //                this->world.getSphere.ownerType = "archive";
            //                this->world.getSphere.ownerPoint = this->container.stoneSphere.myPoint;
            //                this->world.addChild(this->world.getSphere);
            //                this->world.getSphere.manage("add", "stone");
            //            }
            //            else if (this->world.getSphere.listOfStack.length < 4)
            //            {
            //                (this->stoneCount - 1);
            //                this->world.getSphere.manage("add", "stone");
            //            }
            //        }
            //    }
            //    else if (param2 == "levin")
            //    {
            //        if (this->levinCount > 0)
            //        {
            //            if (!this->world.getSphere)
            //            {
            //                (this->levinCount - 1);
            //                this->world.getSphere = new GetSphere();
            //                this->world.getSphere.owner = this->container.levinSphere;
            //                this->world.getSphere.ownerType = "archive";
            //                this->world.getSphere.ownerPoint = this->container.levinSphere.myPoint;
            //                this->world.addChild(this->world.getSphere);
            //                this->world.getSphere.manage("add", "levin");
            //            }
            //            else if (this->world.getSphere.listOfStack.length < 4)
            //            {
            //                (this->levinCount - 1);
            //                this->world.getSphere.manage("add", "levin");
            //            }
            //        }
            //    }
            //    else if (param2 == "getAll")
            //    {
            //        if (this->getAllCount > 0)
            //        {
            //            if (!this->world.getSphere)
            //            {
            //                (this->getAllCount - 1);
            //                this->world.getSphere = new GetSphere("getAll");
            //                this->world.getSphere.owner = this->container.getAll;
            //                this->world.getSphere.ownerType = "archive";
            //                this->world.getSphere.ownerPoint = this->container.getAll.myPoint;
            //                this->world.addChild(this->world.getSphere);
            //                this->world.getSphere.manage("add", "getAll");
            //            }
            //            else
            //            {
            //                (this->getAllCount - 1);
            //                this->world.getSphere.manage("add", "getAll");
            //            }
            //        }
            //    }
            //}
            //else if (param1 == "push")
            //{
            //    if (param2 == "fire")
            //    {
            //        (this->fireCount + 1);
            //    }
            //    else if (param2 == "ice")
            //    {
            //        (this->iceCount + 1);
            //    }
            //    else if (param2 == "stone")
            //    {
            //        (this->stoneCount + 1);
            //    }
            //    else if (param2 == "levin")
            //    {
            //        (this->levinCount + 1);
            //    }
            //    else if (param2 == "getAll")
            //    {
            //        if (this->container.getAll.currentFrame < 3)
            //        {
            //            (this->getAllCount + 1);
            //        }
            //        else
            //        {
            //            this->archiveManage("push", "fire");
            //            this->archiveManage("push", "ice");
            //            this->archiveManage("push", "stone");
            //            this->archiveManage("push", "levin");
            //        }
            //    }
            //}
            //this->updateInfo();
        }// end function

        void castGolem()// : void
        {
            //this->container.butCastGolem.gotoAndStop(6);
            //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            //this->castRegime("on");
            //this->world.road.visible = false;
            //this->addCast("golem");
        }// end function

        void castIceman() 
        {
            //this->container.butCastIceman.gotoAndStop(6);
            //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            //this->castRegime("on");
            //this->world.road.visible = false;
            //this->addCast("iceman");
        }// end function

        void castAir() 
        {
            //this->container.butCastAir.gotoAndStop(6);
            //Sounds.instance.playSoundWithVol("snd_menu_mouseDown", 0.9);
            //this->castRegime("on");
            //this->world.road.visible = false;
            //this->addCast("air");
        }// end function

        void addPause() 
        {
            //this->container.pause.gotoAndStop((this->container.pause.totalFrames - 1));
            //this->container.pause.openFlag = false;
            //this->container.pause.closeFlag = true;
            //this->world.menuObject = new PauseMenu();
            //this->world.addChild(this->world.menuObject);
        }// end function

        void addFastPause()
        {
            //this->world.menuObject = new FastPause();
            //this->world.addChild(this->world.menuObject);
        }// end function

        void addEncyclopedia() 
        {
            //this->world.menuObject = new Encyclopedia();
            //this->world.addChild(this->world.menuObject);
            //this->container.book.gotoAndStop((this->container.book.totalFrames - 1));
            //this->container.book.openFlag = false;
            //this->container.book.closeFlag = true;
        }// end function

        void downloadCast() 
        {
            //if (this->castGolemCounter > 0)
            //{
            //    if (this->castGolemCounter < this->castGolemTimer)
            //    {
            //        (this->castGolemCounter + 1);
            //        this->container.butCastGolem.cont.contMask.scaleY = this->castGolemCounter / this->castGolemTimer;
            //    }
            //    else
            //    {
            //        this->castGolemCounter = 0;
            //        this->container.butCastGolem.cont.contMask.scaleY = 1;
            //        this->container.butCastGolem.gotoAndStop(1);
            //        this->container.butCastGolem.castGolemCase.buttonMode = true;
            //        this->autoguidersButtons();
            //        Sounds.instance.playSound("snd_cast_ready");
            //    }
            //}
            //if (this->castIcemanCounter > 0)
            //{
            //    if (this->castIcemanCounter < this->castIcemanTimer)
            //    {
            //        (this->castIcemanCounter + 1);
            //        this->container.butCastIceman.cont.contMask.scaleY = this->castIcemanCounter / this->castIcemanTimer;
            //    }
            //    else
            //    {
            //        this->castIcemanCounter = 0;
            //        this->container.butCastIceman.cont.contMask.scaleY = 1;
            //        this->container.butCastIceman.gotoAndStop(1);
            //        this->container.butCastIceman.castIcemanCase.buttonMode = true;
            //        this->autoguidersButtons();
            //        Sounds.instance.playSound("snd_cast_ready");
            //    }
            //}
            //if (this->castAirCounter > 0)
            //{
            //    if (this->castAirCounter < this->castAirTimer)
            //    {
            //        (this->castAirCounter + 1);
            //        this->container.butCastAir.cont.contMask.scaleY = this->castAirCounter / this->castAirTimer;
            //    }
            //    else
            //    {
            //        this->castAirCounter = 0;
            //        this->container.butCastAir.cont.contMask.scaleY = 1;
            //        this->container.butCastAir.gotoAndStop(1);
            //        this->container.butCastAir.castAirCase.buttonMode = true;
            //        this->autoguidersButtons();
            //        Sounds.instance.playSound("snd_cast_ready");
            //    }
            //} 
        }// end function

        void castRegime(string param1) 
        {
            //if (param1 == "on")
            //{
            //    this->castMask.visible = true;
            //    this->world.manageMouse("hide");
            //    var _loc_2:* = false;
            //    this->container.mouseChildren = false;
            //    this->container.mouseEnabled = _loc_2;
            //    this->i = 0;
            //    while (this->i < this->world.listOfPlaces.length)
            //    {
            //        
            //        var _loc_2:* = false;
            //        this->world.listOfPlaces[this->i].mouseChildren = false;
            //        this->world.listOfPlaces[this->i].mouseEnabled = _loc_2;
            //        var _loc_2:* = this;
            //        var _loc_3:* = this->i + 1;
            //        _loc_2.i = _loc_3;
            //    }
            //    this->world.road.visible = true;
            //}
            //else if (param1 == "off")
            //{
            //    this->castMask.visible = false;
            //    this->world.manageMouse("show");
            //    var _loc_2:* = true;
            //    this->container.mouseChildren = true;
            //    this->container.mouseEnabled = _loc_2;
            //    this->i = 0;
            //    while (this->i < this->world.listOfPlaces.length)
            //    {
            //        
            //        var _loc_2:* = true;
            //        this->world.listOfPlaces[this->i].mouseChildren = true;
            //        this->world.listOfPlaces[this->i].mouseEnabled = _loc_2;
            //        var _loc_2:* = this;
            //        var _loc_3:* = this->i + 1;
            //        _loc_2.i = _loc_3;
            //    }
            //    this->world.road.visible = false;
            //    if (this->world.pointer1)
            //    {
            //        this->world.pointer1.alpha = 1;
            //    }
            //    if (this->world.pointer2)
            //    {
            //        this->world.pointer2.alpha = 1;
            //    }
            //    if (this->world.pointer3)
            //    {
            //        this->world.pointer3.alpha = 1;
            //    }
            //}
        }// end function

        void fastPlayControl(int param1= 0)
        {
            //if (param1 == 0)
            //{
            //    this->fasterFlag = 0;
            //    Main.mainClass.stage.frameRate = 30;
            //}
            //else if (param1 == 1)
            //{
            //    this->fasterFlag = 1;
            //    Main.mainClass.stage.frameRate = 1;
            //}
            //else if (param1 == 2)
            //{
            //    this->fasterFlag = 2;
            //    Main.mainClass.stage.frameRate = 30;
            //} 
        }// end function

		 void  barInfoView()
        {
            //if (this->world.selectObject is GetSphere && this->world.getSphere)
            //{
            //    if (this->world.getSphere.fireCount > 0 && this->world.getSphere.iceCount == 0 && this->world.getSphere.stoneCount == 0 && this->world.getSphere.levinCount == 0)
            //    {
            //        this->container.barInfo.noteTXT.text = "范围: " + Math.round(this->world.getSphere.myRadius) + "; 火焰伤害: " + Math.round(this->world.getSphere.myDamage);
            //    }
            //    else if (this->world.getSphere.fireCount == 0 && this->world.getSphere.iceCount > 0 && this->world.getSphere.stoneCount == 0 && this->world.getSphere.levinCount == 0)
            //    {
            //        this->container.barInfo.noteTXT.text = "范围: " + Math.round(this->world.getSphere.myRadius) + "; 寒冰伤害: " + Math.round(this->world.getSphere.myDamage);
            //    }
            //    else if (this->world.getSphere.fireCount == 0 && this->world.getSphere.iceCount == 0 && this->world.getSphere.stoneCount > 0 && this->world.getSphere.levinCount == 0)
            //    {
            //        this->container.barInfo.noteTXT.text = "范围: " + Math.round(this->world.getSphere.myRadius) + "; 岩石伤害: " + Math.round(this->world.getSphere.myDamage);
            //    }
            //    else if (this->world.getSphere.fireCount == 0 && this->world.getSphere.iceCount == 0 && this->world.getSphere.stoneCount == 0 && this->world.getSphere.levinCount > 0)
            //    {
            //        this->container.barInfo.noteTXT.text = "范围: " + Math.round(this->world.getSphere.myRadius) + "; 闪电伤害: " + Math.round(this->world.getSphere.myDamage);
            //    }
            //    else if (this->world.getSphere.getAllCount > 0)
            //    {
            //        this->container.barInfo.noteTXT.text = "范围: " + Math.round(this->world.getSphere.myRadius) + "; 伤害: " + Math.round(this->world.getSphere.myDamage);
            //    }
            //    else if (this->world.getSphere.fireCount > 0 && this->world.getSphere.iceCount > 0 && this->world.getSphere.stoneCount > 0 && this->world.getSphere.levinCount == 0 || this->world.getSphere.fireCount > 0 && this->world.getSphere.iceCount > 0 && this->world.getSphere.stoneCount == 0 && this->world.getSphere.levinCount > 0 || this->world.getSphere.fireCount > 0 && this->world.getSphere.iceCount == 0 && this->world.getSphere.stoneCount > 0 && this->world.getSphere.levinCount > 0 || this->world.getSphere.fireCount == 0 && this->world.getSphere.iceCount > 0 && this->world.getSphere.stoneCount > 0 && this->world.getSphere.levinCount > 0)
            //    {
            //        if (this->world.getSphere.fireCount > 1 || this->world.getSphere.iceCount > 1 || this->world.getSphere.stoneCount > 1 || this->world.getSphere.levinCount > 1)
            //        {
            //            this->container.barInfo.noteTXT.text = "范围: " + Math.round(this->world.getSphere.myRadius) + "; 伤害: " + Math.round(this->world.getSphere.myDamage * Main.mainClass.readXMLClass.getAllLittleDoubleMultiply);
            //        }
            //        else
            //        {
            //            this->container.barInfo.noteTXT.text = "范围: " + Math.round(this->world.getSphere.myRadius) + "; 伤害: " + Math.round(this->world.getSphere.myDamage * Main.mainClass.readXMLClass.getAllLittleMultiply);
            //        }
            //    }
            //    else
            //    {
            //        this->container.barInfo.noteTXT.text = "范围: " + Math.round(this->world.getSphere.myRadius) + "; 伤害: " + Math.round(this->world.getSphere.myDamage);
            //    }
            //}
            //else if (this->world.selectObject is Cast && this->world.cast)
            //{
            //    if (this->world.cast is Cast_1)
            //    {
            //        this->container.barInfo.healthTXT.text = Math.round(Main.mainClass.readXMLClass.castGolemHealthXML);
            //    }
            //    else if (this->world.cast is Cast_2)
            //    {
            //        this->container.barInfo.noteTXT.text = Math.round(Main.mainClass.readXMLClass.castIcemanLifeTimerXML / 30) + " 秒";
            //    }
            //    else if (this->world.cast is Cast_3)
            //    {
            //        this->container.barInfo.noteTXT.text = Math.round(Main.mainClass.readXMLClass.airLifeSecXML / 30) + " 秒";
            //    }
            //}
            //else if (this->world.selectObject is Unit)
            //{
            //    this->container.barInfo.healthTXT.text = Math.round(this->world.selectObject.health) + "/" + Math.round(this->world.selectObject.healthMax);
            //    if (this->container.barInfo.myTarget != this->world.selectObject)
            //    {
            //        this->container.barInfo.myTarget = this->world.selectObject;
            //        this->tempObject = Encyclopedia.enemyInfo(this->world.selectObject.typeUnit);
            //        if (this->tempObject[2] == "非常慢")
            //        {
            //            this->tempObject[2] = "非常慢";
            //        }
            //        else if (this->tempObject[2] == "慢")
            //        {
            //            this->tempObject[2] = "慢";
            //        }
            //        else if (this->tempObject[2] == "一般")
            //        {
            //            this->tempObject[2] = "一般";
            //        }
            //        else if (this->tempObject[2] == "快")
            //        {
            //            this->tempObject[2] = "快";
            //        }
            //        else if (this->tempObject[2] == "非常快")
            //        {
            //            this->tempObject[2] = "非常快";
            //        }
            //        else if (this->tempObject[2] == "无")
            //        {
            //            this->tempObject[2] = "无";
            //        }
            //        this->container.barInfo.speedTXT.text = this->tempObject[2];
            //        this->container.barInfo.penaltyTXT.text = this->tempObject[3];
            //        this->i = 4;
            //        while (this->i <= 7)
            //        {
            //            
            //            if (this->tempObject[this->i] == "无")
            //            {
            //                this->tempObject[this->i] = "无";
            //            }
            //            else if (this->tempObject[this->i] == "低")
            //            {
            //                this->tempObject[this->i] = "低";
            //            }
            //            else if (this->tempObject[this->i] == "中")
            //            {
            //                this->tempObject[this->i] = "中";
            //            }
            //            else if (this->tempObject[this->i] == "高")
            //            {
            //                this->tempObject[this->i] = "高";
            //            }
            //            var _loc_1:* = this;
            //            var _loc_2:* = this->i + 1;
            //            _loc_1.i = _loc_2;
            //        }
            //        this->container.barInfo.fireTXT.text = this->tempObject[4];
            //        this->container.barInfo.iceTXT.text = this->tempObject[5];
            //        this->container.barInfo.stoneTXT.text = this->tempObject[6];
            //        this->container.barInfo.levinTXT.text = this->tempObject[7];
            //    }
            //}
            //else if (this->world.selectObject is Golem)
            //{
            //    if (!this->world.selectObject.brother)
            //    {
            //        this->container.barInfo.healthTXT.text = Math.round(this->world.selectObject.health);
            //    }
            //    else
            //    {
            //        if (!this->world.selectObject.dead && !this->world.selectObject.brother.dead)
            //        {
            //            this->tempObject = Math.round(this->world.selectObject.health) + Math.round(this->world.selectObject.brother.health);
            //        }
            //        else if (!this->world.selectObject.dead)
            //        {
            //            this->tempObject = Math.round(this->world.selectObject.health);
            //        }
            //        else if (!this->world.selectObject.brother.dead)
            //        {
            //            this->tempObject = Math.round(this->world.selectObject.brother.health);
            //        }
            //        this->container.barInfo.healthTXT.text = Math.round(this->tempObject);
            //    }
            //}
            //else if (this->world.selectObject is Iceman)
            //{
            //    this->tempObject = int(this->world.selectObject.liveCounter / 30 + 0.99);
            //    if (this->tempObject > 0)
            //    {
            //        this->container.barInfo.noteTXT.text = this->tempObject + " 秒";
            //    }
            //    else
            //    {
            //        this->barInfoManage();
            //    }
            //}
            //else if (this->world.selectObject is Air)
            //{
            //    this->tempObject = int(this->world.selectObject.liveCounter / 30 + 0.99);
            //    if (this->tempObject > 0)
            //    {
            //        this->container.barInfo.noteTXT.text = this->tempObject + " 秒";
            //    }
            //    else
            //    {
            //        this->barInfoManage();
            //    }
            //}
            //else if (this->world.selectObject is TowerMenu || this->world.selectObject is UltraTowerMenu)
            //{
            //    if (this->world.selectObject.myTower.towerType < 5)
            //    {
            //        this->container.barInfo.noteTXT.text = "";
            //        if (this->world.selectObject.myTower.shootingTurnStack[0])
            //        {
            //            this->container.barInfo.noteTXT.text = "火焰: " + Math.round(Main.mainClass.readXMLClass.listOfFireTowerDamageXML[(this->world.selectObject.myTower.shootingTurnStack[0][3] - 1)]) + "; ";
            //        }
            //        if (this->world.selectObject.myTower.shootingTurnStack[1])
            //        {
            //            this->container.barInfo.noteTXT.text = this->container.barInfo.noteTXT.text + "寒冰: " + Math.round(Main.mainClass.readXMLClass.listOfIceTowerDamageXML[(this->world.selectObject.myTower.shootingTurnStack[1][3] - 1)]) + "; ";
            //        }
            //        if (this->world.selectObject.myTower.shootingTurnStack[2])
            //        {
            //            this->container.barInfo.noteTXT.text = this->container.barInfo.noteTXT.text + "岩石: " + Math.round(Main.mainClass.readXMLClass.listOfStoneTowerDamageXML[(this->world.selectObject.myTower.shootingTurnStack[2][3] - 1)]) + "; ";
            //        }
            //        if (this->world.selectObject.myTower.shootingTurnStack[3])
            //        {
            //            this->container.barInfo.noteTXT.text = this->container.barInfo.noteTXT.text + "闪电: " + Math.round(Main.mainClass.readXMLClass.listOfLevinTowerDamageXML[(this->world.selectObject.myTower.shootingTurnStack[3][3] - 1)]) + "; ";
            //        }
            //        if (this->container.barInfo.noteTXT.text == "")
            //        {
            //            this->container.barInfo.noteTXT.text = "无元素";
            //        }
            //        else
            //        {
            //            this->container.barInfo.noteTXT.text = this->container.barInfo.noteTXT.text.slice(0, this->container.barInfo.noteTXT.text.length - 2);
            //        }
            //    }
            //    else
            //    {
            //        if (this->world.selectObject.myTower.towerType == 8)
            //        {
            //            this->container.barInfo.noteTXT.text = "伤害: " + Math.round(this->world.selectObject.myTower.damage * 3);
            //        }
            //        else
            //        {
            //            this->container.barInfo.noteTXT.text = "伤害: " + Math.round(this->world.selectObject.myTower.damage);
            //        }
            //        if (this->world.selectObject.myTower.upgradeTypeAdd == 1)
            //        {
            //            if (this->world.selectObject.myTower.towerType == 5)
            //            {
            //                this->container.barInfo.noteTXT.text = this->container.barInfo.noteTXT.text + "; 额外伤害: " + Math.round(this->world.selectObject.myTower.upgr1_damage * 49);
            //            }
            //            else
            //            {
            //                this->container.barInfo.noteTXT.text = this->container.barInfo.noteTXT.text + "; 额外伤害: " + Math.round(this->world.selectObject.myTower.upgr1_damage);
            //            }
            //        }
            //    }
            //}
            //else if (this->world.selectObject)
            //{
            //    if (!this->world.towerMenu)
            //    {
            //        this->barInfoManage();
            //    }
            //    else
            //    {
            //        this->barInfoManage(this->world.towerMenu);
            //    }
            //}
            //return;
        }// end function

		void barInfoManage(cocos2d::Node* param1= NULL) 
        {
            //if (this->world.selectObject)
            //{
            //    if (this->world.selectObject is Unit)
            //    {
            //        this->world.selectObject.container.selectUnit.visible = false;
            //    }
            //}
            //if (!param1)
            //{
            //    this->world.selectObject = null;
            //    this->world.worldInterface.container.barInfo.gotoAndStop(1);
            //    this->i = this->world.listOfClasses.length - 1;
            //    while (this->i >= 0)
            //    {
            //        
            //        if (this->world.listOfClasses[this->i] is Golem || this->world.listOfClasses[this->i] is Iceman || this->world.listOfClasses[this->i] is Air)
            //        {
            //            this->world.selectObject = this->world.listOfClasses[this->i];
            //            if (this->world.listOfClasses[this->i] is Golem)
            //            {
            //                this->world.worldInterface.container.barInfo.gotoAndStop(4);
            //            }
            //            else if (this->world.listOfClasses[this->i] is Iceman || this->world.listOfClasses[this->i] is Air)
            //            {
            //                this->world.worldInterface.container.barInfo.gotoAndStop(5);
            //            }
            //            else
            //            {
            //                this->world.worldInterface.container.barInfo.gotoAndStop(2);
            //            }
            //            break;
            //        }
            //        var _loc_2:* = this;
            //        var _loc_3:* = this->i - 1;
            //        _loc_2.i = _loc_3;
            //    }
            //}
            //else
            //{
            //    this->world.selectObject = param1;
            //    if (this->world.selectObject is Unit)
            //    {
            //        this->world.selectObject.container.selectUnit.visible = true;
            //        this->world.worldInterface.container.barInfo.gotoAndStop(3);
            //        this->container.barInfo.myTarget = null;
            //    }
            //    else if (this->world.selectObject is Golem || this->world.selectObject is Cast_1)
            //    {
            //        this->world.worldInterface.container.barInfo.gotoAndStop(4);
            //    }
            //    else if (this->world.selectObject is Iceman || this->world.selectObject is Cast_2 || this->world.selectObject is Air || this->world.selectObject is Cast_3)
            //    {
            //        this->world.worldInterface.container.barInfo.gotoAndStop(5);
            //    }
            //    else
            //    {
            //        this->world.worldInterface.container.barInfo.gotoAndStop(2);
            //    }
            //    this->barInfoView();
            //}
        }// end function

		void breaking()  
        {
            //if (this->world.getSphere)
            //{
            //    this->castRegime("off");
            //    this->world.getSphere.retrieveGetSphereToArchive();
            //}
            //else if (this->world.cast)
            //{
            //    if (this->world.cast is Cast_1)
            //    {
            //        this->container.butCastGolem.gotoAndStop(1);
            //    }
            //    else if (this->world.cast is Cast_2)
            //    {
            //        this->container.butCastIceman.gotoAndStop(1);
            //    }
            //    else if (this->world.cast is Cast_3)
            //    {
            //        this->container.butCastAir.gotoAndStop(1);
            //    }
            //    this->world.cast.kill();
            //}
            //else if (this->world.exchange)
            //{
            //    this->world.exchange.kill();
            //}
            return;
        }// end function

		void hintUpdate()
        {
            //if (this->world.hint.visible)
            //{
            //    this->world.hint.x = this->mouseX;
            //    this->world.hint.y = this->mouseY;
            //    if (this->world.hint.currentFrame == 1)
            //    {
            //        if (this->world.hint.nameTXT.text == "击碎者重置")
            //        {
            //            if (this->container.butCastGolem.currentFrame == 4)
            //            {
            //                this->world.hint.timeTXT.text = int((this->castGolemTimer - this->castGolemCounter) / 30) + 1;
            //                this->world.hint.timeTXT.setTextFormat(Main.mainClass.boldTextFormat);
            //            }
            //            else
            //            {
            //                this->world.hint.visible = false;
            //            }
            //        }
            //        else if (this->world.hint.nameTXT.text == "冰冻者重置")
            //        {
            //            if (this->container.butCastIceman.currentFrame == 4)
            //            {
            //                this->world.hint.timeTXT.text = int((this->castIcemanTimer - this->castIcemanCounter) / 30) + 1;
            //                this->world.hint.timeTXT.setTextFormat(Main.mainClass.boldTextFormat);
            //            }
            //            else
            //            {
            //                this->world.hint.visible = false;
            //            }
            //        }
            //        else if (this->world.hint.nameTXT.text == "复活岛巨像重置")
            //        {
            //            if (this->container.butCastAir.currentFrame == 4)
            //            {
            //                this->world.hint.timeTXT.text = int((this->castAirTimer - this->castAirCounter) / 30) + 1;
            //                this->world.hint.timeTXT.setTextFormat(Main.mainClass.boldTextFormat);
            //            }
            //            else
            //            {
            //                this->world.hint.visible = false;
            //            }
            //        }
            //    }
            //}
        }// end function

		void autoguidersButtons()
        {
            //this->autoguidesMouse_pt = new Point(Main.mainClass.worldClass.mouseX, Main.mainClass.worldClass.mouseY);
            //this->autoguidesObject = null;
            //this->autoguidesObject_pt = this->container.butCastGolem.localToGlobal(new Point(this->container.butCastGolem.castGolemCase.x, this->container.butCastGolem.castGolemCase.y));
            //this->autoguidesObjectWidth = this->container.butCastGolem.castGolemCase.width / 2;
            //this->autoguidesObjectHeight = this->container.butCastGolem.castGolemCase.height / 2;
            //if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //{
            //    this->autoguidesObject = this->container.butCastGolem.castGolemCase;
            //}
            //if (!this->autoguidesObject)
            //{
            //    this->autoguidesObject_pt = this->container.butCastIceman.localToGlobal(new Point(this->container.butCastIceman.castIcemanCase.x, this->container.butCastIceman.castIcemanCase.y));
            //    this->autoguidesObjectWidth = this->container.butCastIceman.castIcemanCase.width / 2;
            //    this->autoguidesObjectHeight = this->container.butCastIceman.castIcemanCase.height / 2;
            //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //    {
            //        this->autoguidesObject = this->container.butCastIceman.castIcemanCase;
            //    }
            //}
            //if (!this->autoguidesObject)
            //{
            //    this->autoguidesObject_pt = this->container.butCastAir.localToGlobal(new Point(this->container.butCastAir.castAirCase.x, this->container.butCastAir.castAirCase.y));
            //    this->autoguidesObjectWidth = this->container.butCastAir.castAirCase.width / 2;
            //    this->autoguidesObjectHeight = this->container.butCastAir.castAirCase.height / 2;
            //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //    {
            //        this->autoguidesObject = this->container.butCastAir.castAirCase;
            //    }
            //}
            //if (!this->autoguidesObject)
            //{
            //    this->autoguidesObject_pt = this->container.快.localToGlobal(new Point(this->container.快.fastCase.x, this->container.快.fastCase.y));
            //    this->autoguidesObjectWidth = this->container.快.fastCase.width / 2;
            //    this->autoguidesObjectHeight = this->container.快.fastCase.height / 2;
            //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //    {
            //        this->autoguidesObject = this->container.快.fastCase;
            //    }
            //}
            //if (!this->autoguidesObject)
            //{
            //    this->autoguidesObject_pt = this->container.fireSphere.localToGlobal(new Point(this->container.fireSphere.sphereCase.x, this->container.fireSphere.sphereCase.y));
            //    this->autoguidesObjectWidth = this->container.fireSphere.sphereCase.width / 2;
            //    this->autoguidesObjectHeight = this->container.fireSphere.sphereCase.height / 2;
            //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //    {
            //        this->autoguidesObject = this->container.fireSphere.sphereCase;
            //    }
            //}
            //if (!this->autoguidesObject)
            //{
            //    this->autoguidesObject_pt = this->container.iceSphere.localToGlobal(new Point(this->container.iceSphere.sphereCase.x, this->container.iceSphere.sphereCase.y));
            //    this->autoguidesObjectWidth = this->container.iceSphere.sphereCase.width / 2;
            //    this->autoguidesObjectHeight = this->container.iceSphere.sphereCase.height / 2;
            //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //    {
            //        this->autoguidesObject = this->container.iceSphere.sphereCase;
            //    }
            //}
            //if (!this->autoguidesObject)
            //{
            //    this->autoguidesObject_pt = this->container.stoneSphere.localToGlobal(new Point(this->container.stoneSphere.sphereCase.x, this->container.stoneSphere.sphereCase.y));
            //    this->autoguidesObjectWidth = this->container.stoneSphere.sphereCase.width / 2;
            //    this->autoguidesObjectHeight = this->container.stoneSphere.sphereCase.height / 2;
            //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //    {
            //        this->autoguidesObject = this->container.stoneSphere.sphereCase;
            //    }
            //}
            //if (!this->autoguidesObject)
            //{
            //    this->autoguidesObject_pt = this->container.levinSphere.localToGlobal(new Point(this->container.levinSphere.sphereCase.x, this->container.levinSphere.sphereCase.y));
            //    this->autoguidesObjectWidth = this->container.levinSphere.sphereCase.width / 2;
            //    this->autoguidesObjectHeight = this->container.levinSphere.sphereCase.height / 2;
            //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //    {
            //        this->autoguidesObject = this->container.levinSphere.sphereCase;
            //    }
            //}
            //if (!this->autoguidesObject)
            //{
            //    this->autoguidesObject_pt = this->container.getAll.localToGlobal(new Point(this->container.getAll.sphereCase.x, this->container.getAll.sphereCase.y));
            //    this->autoguidesObjectWidth = this->container.getAll.sphereCase.width / 2;
            //    this->autoguidesObjectHeight = this->container.getAll.sphereCase.height / 2;
            //    if (this->autoguidesMouse_pt.x >= this->autoguidesObject_pt.x - this->autoguidesObjectWidth && this->autoguidesMouse_pt.x <= this->autoguidesObject_pt.x + this->autoguidesObjectWidth && this->autoguidesMouse_pt.y >= this->autoguidesObject_pt.y - this->autoguidesObjectHeight && this->autoguidesMouse_pt.y <= this->autoguidesObject_pt.y + this->autoguidesObjectHeight)
            //    {
            //        this->autoguidesObject = this->container.getAll.sphereCase;
            //    }
            //}
            //if (this->autoguidesObject)
            //{
            //    this->tempObject = new Object();
            //    this->tempObject.target = this->autoguidesObject;
            //    this->mouseMoveHandler(this->tempObject);
            //}
        }// end function

        void spheresBlockManage(string param1 = "");

		void archiveSphereBacklightManage(string param1)
        {
            //if (this->world.towerMenu)
            //{
            //    this->tempObject = this->world.towerMenu;
            //}
            //else if (this->world.ultraTowerMenu)
            //{
            //    this->tempObject = this->world.ultraTowerMenu;
            //}
            //if (param1 == "fire")
            //{
            //    if (!this->container.fireBacklight.visible)
            //    {
            //        this->container.fireBacklight.visible = true;
            //    }
            //    if (!this->tempObject.myTower.shootingTurnStack[0])
            //    {
            //        if (this->container.fireBacklight.currentFrame == 1)
            //        {
            //            this->container.fireBacklight.gotoAndStop(this->container.fireBacklight.totalFrames);
            //        }
            //    }
            //    else if (this->container.fireBacklight.currentFrame != 1)
            //    {
            //        this->container.fireBacklight.gotoAndStop(1);
            //    }
            //}
            //else if (param1 == "ice")
            //{
            //    if (!this->container.iceBacklight.visible)
            //    {
            //        this->container.iceBacklight.visible = true;
            //    }
            //    if (!this->tempObject.myTower.shootingTurnStack[1])
            //    {
            //        if (this->container.iceBacklight.currentFrame == 1)
            //        {
            //            this->container.iceBacklight.gotoAndStop(this->container.iceBacklight.totalFrames);
            //        }
            //    }
            //    else if (this->container.iceBacklight.currentFrame != 1)
            //    {
            //        this->container.iceBacklight.gotoAndStop(1);
            //    }
            //}
            //else if (param1 == "stone")
            //{
            //    if (!this->container.stoneBacklight.visible)
            //    {
            //        this->container.stoneBacklight.visible = true;
            //    }
            //    if (!this->tempObject.myTower.shootingTurnStack[2])
            //    {
            //        if (this->container.stoneBacklight.currentFrame == 1)
            //        {
            //            this->container.stoneBacklight.gotoAndStop(this->container.stoneBacklight.totalFrames);
            //        }
            //    }
            //    else if (this->container.stoneBacklight.currentFrame != 1)
            //    {
            //        this->container.stoneBacklight.gotoAndStop(1);
            //    }
            //}
            //else if (param1 == "levin")
            //{
            //    if (!this->container.levinBacklight.visible)
            //    {
            //        this->container.levinBacklight.visible = true;
            //    }
            //    if (!this->tempObject.myTower.shootingTurnStack[3])
            //    {
            //        if (this->container.levinBacklight.currentFrame == 1)
            //        {
            //            this->container.levinBacklight.gotoAndStop(this->container.levinBacklight.totalFrames);
            //        }
            //    }
            //    else if (this->container.levinBacklight.currentFrame != 1)
            //    {
            //        this->container.levinBacklight.gotoAndStop(1);
            //    }
            //}
            //else
            //{
            //    if (this->container.fireBacklight.currentFrame != 1)
            //    {
            //        this->container.fireBacklight.gotoAndStop(1);
            //    }
            //    if (this->container.iceBacklight.currentFrame != 1)
            //    {
            //        this->container.iceBacklight.gotoAndStop(1);
            //    }
            //    if (this->container.stoneBacklight.currentFrame != 1)
            //    {
            //        this->container.stoneBacklight.gotoAndStop(1);
            //    }
            //    if (this->container.levinBacklight.currentFrame != 1)
            //    {
            //        this->container.levinBacklight.gotoAndStop(1);
            //    }
            //    if (!this->container.fireBacklight.turnFlag)
            //    {
            //        this->container.fireBacklight.turnFlag = true;
            //    }
            //    if (!this->container.iceBacklight.turnFlag)
            //    {
            //        this->container.iceBacklight.turnFlag = true;
            //    }
            //    if (!this->container.stoneBacklight.turnFlag)
            //    {
            //        this->container.stoneBacklight.turnFlag = true;
            //    }
            //    if (!this->container.levinBacklight.turnFlag)
            //    {
            //        this->container.levinBacklight.turnFlag = true;
            //    }
            //    if (this->container.fireBacklight.visible)
            //    {
            //        this->container.fireBacklight.visible = false;
            //    }
            //    if (this->container.iceBacklight.visible)
            //    {
            //        this->container.iceBacklight.visible = false;
            //    }
            //    if (this->container.stoneBacklight.visible)
            //    {
            //        this->container.stoneBacklight.visible = false;
            //    }
            //    if (this->container.levinBacklight.visible)
            //    {
            //        this->container.levinBacklight.visible = false;
            //    }
            //}
        }// end function

		void fasterManage(bool param1)
        {
            //if (this->fasterFlag != 2)
            //{
            //    if (param1)
            //    {
            //        this->container.快.gotoAndStop(5);
            //    }
            //    else
            //    {
            //        this->container.快.gotoAndStop(4);
            //    }
            //    this->container.快.cont.stop();
            //    this->fastPlayControl(2);
            //    if (this->container.慢.currentFrame != 1)
            //    {
            //        this->container.慢.gotoAndStop(1);
            //    }
            //}
            //else
            //{
            //    if (param1)
            //    {
            //        this->container.快.gotoAndStop(2);
            //    }
            //    else
            //    {
            //        this->container.快.gotoAndStop(1);
            //    }
            //    this->fastPlayControl(0);
            //}
        }// end function

		void sellSphere(string param1)
        {
            //if (param1 == "fire")
            //{
            //    if (this->sphereCostHistory[0].length > 0)
            //    {
            //        this->tempObject = this->sphereCostHistory[0].pop();
            //    }
            //    else
            //    {
            //        this->tempObject = Main.mainClass.readXMLClass.listOfFirePriceXML[0];
            //    }
            //    this->world.money = this->world.money + Math.round(this->tempObject * Main.mainClass.readXMLClass.fireSellTax);
            //    (this->world.sellFireCounter + 1);
            //    (this->world.saveBox.gameSave.data.addit_sellFireCounter + 1);
            //    if (this->world.saveBox.gameSave.data.addit_sellFireCounter == 10)
            //    {
            //        this->world.achieveManage("sellFire_10_times");
            //    }
            //}
            //else if (param1 == "ice")
            //{
            //    if (this->sphereCostHistory[1].length > 0)
            //    {
            //        this->tempObject = this->sphereCostHistory[1].pop();
            //    }
            //    else
            //    {
            //        this->tempObject = Main.mainClass.readXMLClass.listOfIcePriceXML[0];
            //    }
            //    this->world.money = this->world.money + Math.round(this->tempObject * Main.mainClass.readXMLClass.iceSellTax);
            //    (this->world.sellIceCounter + 1);
            //    (this->world.saveBox.gameSave.data.addit_sellIceCounter + 1);
            //    if (this->world.saveBox.gameSave.data.addit_sellIceCounter == 10)
            //    {
            //        this->world.achieveManage("sellIce_10_times");
            //    }
            //}
            //else if (param1 == "stone")
            //{
            //    if (this->sphereCostHistory[2].length > 0)
            //    {
            //        this->tempObject = this->sphereCostHistory[2].pop();
            //    }
            //    else
            //    {
            //        this->tempObject = Main.mainClass.readXMLClass.listOfStonePriceXML[0];
            //    }
            //    this->world.money = this->world.money + Math.round(this->tempObject * Main.mainClass.readXMLClass.stoneSellTax);
            //    (this->world.sellStoneCounter + 1);
            //    (this->world.saveBox.gameSave.data.addit_sellStoneCounter + 1);
            //    if (this->world.saveBox.gameSave.data.addit_sellStoneCounter == 10)
            //    {
            //        this->world.achieveManage("sellStone_10_times");
            //    }
            //}
            //else if (param1 == "levin")
            //{
            //    if (this->sphereCostHistory[3].length > 0)
            //    {
            //        this->tempObject = this->sphereCostHistory[3].pop();
            //    else
            //    {
            //        this->tempObject = Main.mainClass.readXMLClass.listOfLevinPriceXML[0];
            //    }
            //    this->world.money = this->world.money + Math.round(this->tempObject * Main.mainClass.readXMLClass.levinSellTax);
            //    (this->world.sellLevinCounter + 1);
            //    (this->world.saveBox.gameSave.data.addit_sellLevinCounter + 1);
            //    if (this->world.saveBox.gameSave.data.addit_sellLevinCounter == 10)
            //    {
            //        this->world.achieveManage("sellLevin_10_times");
            //    }
            //}
            //else if (param1 == "getAll")
            //{
            //    this->sellSphere("fire");
            //    this->sellSphere("ice");
            //    this->sellSphere("stone");
            //    this->sellSphere("levin");
            //    (this->world.sellGetAllCounter + 1);
            //    this->world.achieveManage("sellFireIceStoneLevin");
            //}
            //this->updateInfo();
        }// end function

		void addGetAchieve(string param1)
        {
            //this->tempObject = new GetAchieve_mc();
            //this->tempObject.stop();
            //this->tempObject.icon.stop();
            //this->tempObject.board.stop();
            //this->tempObject.x = 435;
            //this->tempObject.y = this->container.barInfo.y - 42;
            //this->tempObject.closeFlag = false;
            //this->tempObject.counter = 30;
            //var _loc_2:* = false;
            //this->tempObject.mouseChildren = false;
            //this->tempObject.mouseEnabled = _loc_2;
            //this->addChild(this->tempObject);
            //this->listOfGetAhieve.push(this->tempObject);
            //if (param1 == "firstKill")
            //{
            //    this->tempObject.icon.gotoAndStop(1);
            //    var _loc_2:* = "第一滴血";
            //    this->tempObject.myText = "第一滴血";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "kill_100_enemies")
            //{
            //    this->tempObject.icon.gotoAndStop(2);
            //    var _loc_2:* = "热烈无比";
            //    this->tempObject.myText = "热烈无比";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "kill_2500_enemies")
            //{
            //    this->tempObject.icon.gotoAndStop(3);
            //    var _loc_2:* = "杀手";
            //    this->tempObject.myText = "杀手";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "call_100_earlyWaves")
            //{
            //    this->tempObject.icon.gotoAndStop(4);
            //    var _loc_2:* = "毫无畏惧";
            //    this->tempObject.myText = "毫无畏惧";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "build_100_towers")
            //{
            //    this->tempObject.icon.gotoAndStop(5);
            //    var _loc_2:* = "建造者";
            //    this->tempObject.myText = "建造者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "createGolem_5_times")
            //{
            //    this->tempObject.icon.gotoAndStop(6);
            //    var _loc_2:* = "巨型支援";
            //    this->tempObject.myText = "巨型支援";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "createIceman_15_times")
            //{
            //    this->tempObject.icon.gotoAndStop(7);
            //    var _loc_2:* = "缓和";
            //    this->tempObject.myText = "缓和";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "createAir_7_times")
            //{
            //    this->tempObject.icon.gotoAndStop(8);
            //    var _loc_2:* = "远古支援";
            //    this->tempObject.myText = "远古支援";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "callAllWavesInLevel")
            //{
            //    this->tempObject.icon.gotoAndStop(9);
            //    var _loc_2:* = "大胆";
            //    this->tempObject.myText = "大胆";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "sellFireIceStoneLevin")
            //{
            //    this->tempObject.icon.gotoAndStop(10);
            //    var _loc_2:* = "破坏者";
            //    this->tempObject.myText = "破坏者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "sellFire_10_times")
            //{
            //    this->tempObject.icon.gotoAndStop(11);
            //    var _loc_2:* = "火焰破坏者";
            //    this->tempObject.myText = "火焰破坏者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "sellIce_10_times")
            //{
            //    this->tempObject.icon.gotoAndStop(12);
            //    var _loc_2:* = "寒冰破坏者";
            //    this->tempObject.myText = "寒冰破坏者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "sellStone_10_times")
            //{
            //    this->tempObject.icon.gotoAndStop(13);
            //    var _loc_2:* = "巨石破坏者";
            //    this->tempObject.myText = "巨石破坏者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "sellLevin_10_times")
            //{
            //    this->tempObject.icon.gotoAndStop(14);
            //    var _loc_2:* = "闪电破坏者";
            //    this->tempObject.myText = "闪电破坏者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "golemKill_250_enemies")
            //{
            //    this->tempObject.icon.gotoAndStop(15);
            //    var _loc_2:* = "粉碎者";
            //    this->tempObject.myText = "粉碎者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "icemanSlowdown_75_enemies")
            //{
            //    this->tempObject.icon.gotoAndStop(16);
            //    var _loc_2:* = "有点冷";
            //    this->tempObject.myText = "有点冷";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "icemanSlowdown_500_enemies")
            //{
            //    this->tempObject.icon.gotoAndStop(17);
            //    var _loc_2:* = "霜冻力量";
            //    this->tempObject.myText = "霜冻力量";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "buildUltraTower")
            //{
            //    this->tempObject.icon.gotoAndStop(18);
            //    var _loc_2:* = "进阶建造者";
            //    this->tempObject.myText = "进阶建造者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "buildUltraTower_50_times")
            //{
            //    this->tempObject.icon.gotoAndStop(19);
            //    var _loc_2:* = "专家建造者";
            //    this->tempObject.myText = "专家建造者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "buildAllUltraTowers")
            //{
            //    this->tempObject.icon.gotoAndStop(20);
            //    var _loc_2:* = "策略建造者";
            //    this->tempObject.myText = "策略建造者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "notCast")
            //{
            //    this->tempObject.icon.gotoAndStop(21);
            //    var _loc_2:* = "上手";
            //    this->tempObject.myText = "上手";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "castFire_150_times")
            //{
            //    this->tempObject.icon.gotoAndStop(22);
            //    var _loc_2:* = "火焰大师";
            //    this->tempObject.myText = "火焰大师";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "castIce_150_times")
            //{
            //    this->tempObject.icon.gotoAndStop(23);
            //    var _loc_2:* = "寒冰大师";
            //    this->tempObject.myText = "寒冰大师";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "castStone_150_times")
            //{
            //    this->tempObject.icon.gotoAndStop(24);
            //    var _loc_2:* = "岩石大师";
            //    this->tempObject.myText = "岩石大师";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "castLevin_150_times")
            //{
            //    this->tempObject.icon.gotoAndStop(25);
            //    var _loc_2:* = "闪电大师";
            //    this->tempObject.myText = "闪电大师";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "castGetAll_10_times")
            //{
            //    this->tempObject.icon.gotoAndStop(26);
            //    var _loc_2:* = "策略爆破者";
            //    this->tempObject.myText = "策略爆破者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "castGetAll_100_times")
            //{
            //    this->tempObject.icon.gotoAndStop(27);
            //    var _loc_2:* = "爆破者";
            //    this->tempObject.myText = "爆破者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "castKill_1_enemy")
            //{
            //    this->tempObject.icon.gotoAndStop(28);
            //    var _loc_2:* = "施法者";
            //    this->tempObject.myText = "施法者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "castKill_100_enemy")
            //{
            //    this->tempObject.icon.gotoAndStop(29);
            //    var _loc_2:* = "法术杀手";
            //    this->tempObject.myText = "法术杀手";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "complete_10_hardLevels")
            //{
            //    this->tempObject.icon.gotoAndStop(30);
            //    var _loc_2:* = "勇猛战士";
            //    this->tempObject.myText = "勇猛战士";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "complete_10_survivalLevels")
            //{
            //    this->tempObject.icon.gotoAndStop(31);
            //    var _loc_2:* = "幸存者";
            //    this->tempObject.myText = "幸存者";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "complete_10_withAllLives")
            //{
            //    this->tempObject.icon.gotoAndStop(32);
            //    var _loc_2:* = "活力四射";
            //    this->tempObject.myText = "活力四射";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_01")
            //{
            //    this->tempObject.icon.gotoAndStop(33);
            //    var _loc_2:* = "伐木工";
            //    this->tempObject.myText = "伐木工";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_02")
            //{
            //    this->tempObject.icon.gotoAndStop(34);
            //    var _loc_2:* = "忙忙碌碌";
            //    this->tempObject.myText = "忙忙碌碌";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_03")
            //{
            //    this->tempObject.icon.gotoAndStop(35);
            //    var _loc_2:* = "南瓜节";
            //    this->tempObject.myText = "南瓜节";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_04")
            //{
            //    this->tempObject.icon.gotoAndStop(36);
            //    var _loc_2:* = "修理工";
            //    this->tempObject.myText = "修理工";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_05")
            //{
            //    this->tempObject.icon.gotoAndStop(37);
            //    var _loc_2:* = "勇士";
            //    this->tempObject.myText = "勇士";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_06")
            //{
            //    this->tempObject.icon.gotoAndStop(38);
            //    var _loc_2:* = "睡眼阑珊";
            //    this->tempObject.myText = "睡眼阑珊";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_07")
            //{
            //    this->tempObject.icon.gotoAndStop(39);
            //    var _loc_2:* = "超级女声";
            //    this->tempObject.myText = "超级女声";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_08")
            //{
            //    this->tempObject.icon.gotoAndStop(40);
            //    var _loc_2:* = "老烟枪";
            //    this->tempObject.myText = "老烟枪";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_09")
            //{
            //    this->tempObject.icon.gotoAndStop(41);
            //    var _loc_2:* = "渔夫";
            //    this->tempObject.myText = "渔夫";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_10")
            //{
            //    this->tempObject.icon.gotoAndStop(42);
            //    var _loc_2:* = "决斗";
            //    this->tempObject.myText = "决斗";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_11")
            //{
            //    this->tempObject.icon.gotoAndStop(43);
            //    var _loc_2:* = "萨满";
            //    this->tempObject.myText = "萨满";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_12")
            //{
            //    this->tempObject.icon.gotoAndStop(44);
            //    var _loc_2:* = "疯狂射手";
            //    this->tempObject.myText = "疯狂射手";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_13")
            //{
            //    this->tempObject.icon.gotoAndStop(45);
            //    var _loc_2:* = "勇猛大头";
            //    this->tempObject.myText = "勇猛大头";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
            //else if (param1 == "achieve_dude_14")
            //{
            //    this->tempObject.icon.gotoAndStop(46);
            //    var _loc_2:* = "寻路无门";
            //    this->tempObject.myText = "寻路无门";
            //    this->tempObject.board.noteTXT.text = _loc_2;
            //}
 
        }// end function

		void newEnemyUpdate()
        {
            //this->i = this->listOfNewEnemies.length - 1;
            //while (this->i >= 0)
            //{
            //    
            //    this->tempObject = this->listOfNewEnemies[this->i];
            //    if (this->tempObject.currentFrame < this->tempObject.totalFrames)
            //    {
            //        this->tempObject.gotoAndStop((this->tempObject.currentFrame + 1));
            //    }
            //    else
            //    {
            //        this->tempObject.gotoAndStop(1);
            //    }
            //    if (this->world.getSphere || this->world.cast)
            //    {
            //        if (this->tempObject.visible)
            //        {
            //            this->tempObject.visible = false;
            //        }
            //    }
            //    else if (!this->tempObject.visible)
            //    {
            //        this->tempObject.visible = true;
            //    }
            //    if (this->tempObject.x == 0)
            //    {
            //        this->tempObject.x = Main.SCREEN_WIDTH - 40;
            //        if (this->tempObject is NewEnemy_mc)
            //        {
            //            this->tempObject.newEnemyCase.buttonMode = true;
            //        }
            //        else if (this->tempObject is NewElement_mc)
            //        {
            //            this->tempObject.newElementCase.buttonMode = true;
            //        }
            //        this->tempObject.mouseStatus = 1;
            //        var _loc_1:* = 0;
            //        this->tempObject.scaleY = 0;
            //        this->tempObject.scaleX = _loc_1;
            //        if (this->listOfNewEnemies.length > 3)
            //        {
            //            this->listOfNewEnemies[0].mouseStatus = 4;
            //            this->listOfNewEnemies[0].mouseEnabled = false;
            //            this->listOfNewEnemies[0].mouseChildren = false;
            //        }
            //        if (this->listOfNewEnemies.length > 4)
            //        {
            //            this->listOfNewEnemies[1].mouseStatus = 4;
            //            this->listOfNewEnemies[1].mouseEnabled = false;
            //            this->listOfNewEnemies[1].mouseChildren = false;
            //        }
            //        if (this->listOfNewEnemies.length > 5)
            //        {
            //            this->listOfNewEnemies[2].mouseStatus = 4;
            //            this->listOfNewEnemies[2].mouseEnabled = false;
            //            this->listOfNewEnemies[2].mouseChildren = false;
            //        }
            //        if (this->listOfNewEnemies.length > 6)
            //        {
            //            this->listOfNewEnemies[3].mouseStatus = 4;
            //            this->listOfNewEnemies[3].mouseEnabled = false;
            //            this->listOfNewEnemies[3].mouseChildren = false;
            //        }
            //    }
            //    if (this->tempObject.mouseStatus != 3 && this->tempObject.mouseStatus != 4)
            //    {
            //        if (this->world.nowLevel != 12)
            //        {
            //            if (this->tempObject.y == 0)
            //            {
            //                if (this->listOfNewEnemies.length == 1)
            //                {
            //                    this->tempObject.y = 100;
            //                }
            //                else
            //                {
            //                    if (this->listOfNewEnemies.length > 0)
            //                    {
            //                        if (this->listOfNewEnemies[0].y == 0)
            //                        {
            //                            this->listOfNewEnemies[0].y = 100;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 1)
            //                    {
            //                        if (this->listOfNewEnemies[1].y == 0)
            //                        {
            //                            this->listOfNewEnemies[1].y = this->listOfNewEnemies[0].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 2)
            //                    {
            //                        if (this->listOfNewEnemies[2].y == 0)
            //                        {
            //                            this->listOfNewEnemies[2].y = this->listOfNewEnemies[1].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 3)
            //                    {
            //                        if (this->listOfNewEnemies[3].y == 0)
            //                        {
            //                            this->listOfNewEnemies[3].y = this->listOfNewEnemies[2].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 4)
            //                    {
            //                        if (this->listOfNewEnemies[4].y == 0)
            //                        {
            //                            this->listOfNewEnemies[4].y = this->listOfNewEnemies[3].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 5)
            //                    {
            //                        if (this->listOfNewEnemies[5].y == 0)
            //                        {
            //                            this->listOfNewEnemies[5].y = this->listOfNewEnemies[4].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 6)
            //                    {
            //                        if (this->listOfNewEnemies[6].y == 0)
            //                        {
            //                            this->listOfNewEnemies[6].y = this->listOfNewEnemies[5].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 7)
            //                    {
            //                        if (this->listOfNewEnemies[7].y == 0)
            //                        {
            //                            this->listOfNewEnemies[7].y = this->listOfNewEnemies[6].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 8)
            //                    {
            //                        if (this->listOfNewEnemies[8].y == 0)
            //                        {
            //                            this->listOfNewEnemies[8].y = this->listOfNewEnemies[8].y + 50;
            //                        }
            //                    }
            //                }
            //            }
            //            else if (this->tempObject.y > 100)
            //            {
            //                if (this->i == 0)
            //                {
            //                    if (this->tempObject.y > 100)
            //                    {
            //                        this->tempObject.y = this->tempObject.y - 10;
            //                    }
            //                }
            //                else if (this->i == 1)
            //                {
            //                    if (this->tempObject.y > 150)
            //                    {
            //                        this->tempObject.y = this->tempObject.y - 10;
            //                    }
            //                }
            //                else if (this->i == 2)
            //                {
            //                    if (this->tempObject.y > 200)
            //                    {
            //                        this->tempObject.y = this->tempObject.y - 10;
            //                    }
            //                }
            //            }
            //            if (this->tempObject.scaleX < 1)
            //            {
            //                this->tempObject.scaleX = this->tempObject.scaleX + 0.25;
            //                this->tempObject.scaleY = this->tempObject.scaleY + 0.25;
            //                if (this->tempObject.scaleX > 1)
            //                {
            //                    var _loc_1:* = 1;
            //                    this->tempObject.scaleY = 1;
            //                    this->tempObject.scaleX = _loc_1;
            //                }
            //            }
            //        }
            //        else
            //        {
            //            if (this->tempObject.y == 0)
            //            {
            //                if (this->listOfNewEnemies.length == 1)
            //                {
            //                    this->tempObject.y = 200;
            //                }
            //                else
            //                {
            //                    if (this->listOfNewEnemies.length > 0)
            //                    {
            //                        if (this->listOfNewEnemies[0].y == 0)
            //                        {
            //                            this->listOfNewEnemies[0].y = 200;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 1)
            //                    {
            //                        if (this->listOfNewEnemies[1].y == 0)
            //                        {
            //                            this->listOfNewEnemies[1].y = this->listOfNewEnemies[0].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 2)
            //                    {
            //                        if (this->listOfNewEnemies[2].y == 0)
            //                        {
            //                            this->listOfNewEnemies[2].y = this->listOfNewEnemies[1].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 3)
            //                    {
            //                        if (this->listOfNewEnemies[3].y == 0)
            //                        {
            //                            this->listOfNewEnemies[3].y = this->listOfNewEnemies[2].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 4)
            //                    {
            //                        if (this->listOfNewEnemies[4].y == 0)
            //                        {
            //                            this->listOfNewEnemies[4].y = this->listOfNewEnemies[3].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 5)
            //                    {
            //                        if (this->listOfNewEnemies[5].y == 0)
            //                        {
            //                            this->listOfNewEnemies[5].y = this->listOfNewEnemies[4].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 6)
            //                    {
            //                        if (this->listOfNewEnemies[6].y == 0)
            //                        {
            //                            this->listOfNewEnemies[6].y = this->listOfNewEnemies[5].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 7)
            //                    {
            //                        if (this->listOfNewEnemies[7].y == 0)
            //                        {
            //                            this->listOfNewEnemies[7].y = this->listOfNewEnemies[6].y + 50;
            //                        }
            //                    }
            //                    if (this->listOfNewEnemies.length > 8)
            //                    {
            //                        if (this->listOfNewEnemies[8].y == 0)
            //                        {
            //                            this->listOfNewEnemies[8].y = this->listOfNewEnemies[8].y + 50;
            //                        }
            //                    }
            //                }
            //            }
            //            else if (this->tempObject.y > 200)
            //            {
            //                if (this->i == 0)
            //                {
            //                    if (this->tempObject.y > 200)
            //                    {
            //                        this->tempObject.y = this->tempObject.y - 10;
            //                    }
            //                }
            //                else if (this->i == 1)
            //                {
            //                    if (this->tempObject.y > 250)
            //                    {
            //                        this->tempObject.y = this->tempObject.y - 10;
            //                    }
            //                }
            //                else if (this->i == 2)
            //                {
            //                    if (this->tempObject.y > 300)
            //                    {
            //                        this->tempObject.y = this->tempObject.y - 10;
            //                    }
            //                }
            //            }
            //            if (this->tempObject.scaleX < 1)
            //            {
            //                this->tempObject.scaleX = this->tempObject.scaleX + 0.25;
            //                this->tempObject.scaleY = this->tempObject.scaleY + 0.25;
            //                if (this->tempObject.scaleX > 1)
            //                {
            //                    var _loc_1:* = 1;
            //                    this->tempObject.scaleY = 1;
            //                    this->tempObject.scaleX = _loc_1;
            //                }
            //            }
            //        }
            //    }
            //    else if (this->tempObject.mouseStatus == 3)
            //    {
            //        if (this->tempObject.scaleX > 0)
            //        {
            //            this->tempObject.scaleX = this->tempObject.scaleX - 0.25;
            //            this->tempObject.scaleY = this->tempObject.scaleY - 0.25;
            //            if (this->tempObject.scaleX < 0)
            //            {
            //                var _loc_1:* = 0;
            //                this->tempObject.scaleY = 0;
            //                this->tempObject.scaleX = _loc_1;
            //            }
            //        }
            //        else if (this->tempObject is NewEnemy_mc)
            //        {
            //            this->world.menuObject = new Education("newEnemy", this->tempObject.typeUnit);
            //            this->world.addChild(this->world.menuObject);
            //            this->removeChild(this->tempObject);
            //            this->listOfNewEnemies.splice(this->i, 1);
            //        }
            //        else if (this->tempObject is NewElement_mc)
            //        {
            //            if (!this->world.menuObject)
            //            {
            //                this->world.menuObject = new Training_5(this->tempObject.type);
            //                this->world.addChild(this->world.menuObject);
            //            }
            //            this->removeChild(this->tempObject);
            //            this->listOfNewEnemies.splice(this->i, 1);
            //        }
            //    }
            //    else if (this->tempObject.mouseStatus == 4)
            //    {
            //        if (this->tempObject.scaleX > 0)
            //        {
            //            this->tempObject.scaleX = this->tempObject.scaleX - 0.25;
            //            this->tempObject.scaleY = this->tempObject.scaleY - 0.25;
            //            if (this->tempObject.scaleX < 0)
            //            {
            //                var _loc_1:* = 0;
            //                this->tempObject.scaleY = 0;
            //                this->tempObject.scaleX = _loc_1;
            //            }
            //        }
            //        else
            //        {
            //            this->removeChild(this->tempObject);
            //            this->listOfNewEnemies.splice(this->i, 1);
            //        }
            //    }
            //    var _loc_1:* = this;
            //    var _loc_2:* = this->i - 1;
            //    _loc_1.i = _loc_2;
            //}
        }// end function

	};

}
#endif
