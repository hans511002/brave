#include "Level1_mc.h"
#include "engine/xml/ReadXML.h"
#include "MainClass.h"
#include "engine/World.h"
#include "JsonUtil.h"
#include "cocostudio/DictionaryHelper.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetReader/WidgetReader.h"
using namespace cocostudio;

//CCActionInterval * actionBy1 = CCScaleBy::create(2.f, 2.f, 1.f);
//neru_pSprite->runAction(actionBy1); /
//miku_pSprite->runAction(CCSequence::create(actionBy1, actionBy1->reverse(), NULL));

//flag1->setPosition(760 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 255);
//flag2->setPosition(760 - Main::SCREEN_WIDTH_OUT_LEFT, Main::SCREEN_HEIGHT + Main::SCREEN_HEIGHT_OUT_DOWN - 290);
////flag1->getCCEventDispatcher()->addCustomEventListener(EventData::ANIMATION_FRAME_EVENT,std::bind(&Level1::flagHandler, this, std::placeholders::_1));
////flag1->getCCEventDispatcher()->addCustomEventListener(EventData::COMPLETE,std::bind(&Level1::flagHandler, this, std::placeholders::_1));
////flag1->getCCEventDispatcher()->addCustomEventListener(EventData::LOOP_COMPLETE,std::bind(&Level1::flagHandler, this, std::placeholders::_1));
  
		  
namespace engine{

	LevelPointer::LevelPointer() :MovieClip("worldinterface/", "pointer", "LevelBase"), statusAnima(0), timer(0), counter(0)
	{
		SET_NODETYPENAME();
		pointerCase = this->createCase("pointerCase");
		fireAnima = this->createMovieClipSub("fireAnima");
		eyesAnima = this->createMovieClipSub("eyesAnima");
		//mask1 = this->createMask("mask1");
		//mask2 = this->createMask("mask2");
		mask1 = (Sprite*)this->getArmature()->getSlot("mask1")->getDisplay();
		mask2 = (Sprite*)this->getArmature()->getSlot("mask2")->getDisplay();
		arrow = (Sprite*)this->getArmature()->getSlot("arrow")->getDisplay();
	}

	BuildTowerPlace::BuildTowerPlace(string arm) :MovieClip("worldinterface/", arm, "LevelBase")
	{
		SET_NODETYPENAME();
	 
		placeForBuildCase = this->createCase("placeForBuildCase");
		buildPoint = this->createCase("buildPoint");
        buildPoint->setMouseEnabled(false);
	};

	Level1_mc::Level1_mc(World *world) :Level(world, "worldinterface/", "Level1_mc", "Level1_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decoration1 = this->createMovieClipSub("decoration1");
		decorationCase = this->createCase("decorationCase");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		flags.push(flag1);
		flags.push(flag2);
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		pointers.push(pointer1); 
		decorations.push(decoration);
		decorations.push(decoration1);
	};
	Level2_mc::Level2_mc(World *world) :Level(world, "worldinterface/", "Level2_mc", "Level2_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		flags.push(flag1);
		flags.push(flag2);
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		pointers.push(pointer1); 
		decorations.push(decoration);
	};
	Level3_mc::Level3_mc(World *world) :Level(world, "worldinterface/", "Level3_mc", "Level3_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());

        pumpkin1Case=this->createCase("pumpkin1Case");
        pumpkin2Case=this->createCase("pumpkin2Case");
        pumpkin3Case=this->createCase("pumpkin3Case");        
        
		flags.push(flag1);
		flags.push(flag2);
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		pointers.push(pointer1); 
		pointers.push(pointer2); 
		decorations.push(decoration);
	};
	Level4_mc::Level4_mc(World *world) :Level(world, "worldinterface/", "Level4_mc", "Level4_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
		flag3 = this->createMovieClip("flag3", "worldinterface/", "flag", "LevelBase");
		flag4 = this->createMovieClip("flag4", "worldinterface/", "flag", "LevelBase");
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());
 
		flags.push(flag1);
		flags.push(flag2);
		flags.push(flag3);
		flags.push(flag4);
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		pointers.push(pointer1); 
		pointers.push(pointer2); 
		decorations.push(decoration);
	};
	Level5_mc::Level5_mc(World *world) :Level(world, "worldinterface/", "Level5_mc", "Level5_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());
 
		flags.push(flag1);
		flags.push(flag2); 
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		pointers.push(pointer1); 
		pointers.push(pointer2); 
		decorations.push(decoration);
	};

    Level6_mc::Level6_mc(World *world) :Level(world, "worldinterface/", "Level6_mc", "Level6_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");

		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());

		additionally = this->createMovieClipSub("additionally");
 
		flags.push(flag1);
		flags.push(flag2); 
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		pointers.push(pointer1); 
		pointers.push(pointer2); 
		decorations.push(decoration);
		additionallys.push(additionally);
	};
	
	Level7_mc::Level7_mc(World *world) :Level(world, "worldinterface/", "Level7_mc", "Level7_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");

		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
 
		flags.push(flag1);
		flags.push(flag2); 
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10);
		pointers.push(pointer1);  
		decorations.push(decoration); 
	};
	
	Level8_mc::Level8_mc(World *world) :Level(world, "worldinterface/", "Level8_mc", "Level8_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");
		decoration1 = this->createMovieClipSub("decoration1");
		decoration1Case = this->createCase("decoration1Case");
		decoration2 = this->createMovieClipSub("decoration2");
		decoration2Case = this->createCase("decoration2Case");
		decoration3 = this->createMovieClipSub("decoration3");
		decoration3Case = this->createCase("decoration3Case");
		decoration4Case = this->createCase("decoration4Case");

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");

		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		place11 = (BuildTowerPlace*) this->createMovieClip("place11", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());
 
		flags.push(flag1);
		flags.push(flag2); 
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10);
		places.push(place11);
		pointers.push(pointer1);  
		pointers.push(pointer2);  
		decorations.push(decoration); 
		decorations.push(decoration1); 
		decorations.push(decoration2); 
		decorations.push(decoration3); 
	};
	
	Level9_mc::Level9_mc(World *world) :Level(world, "worldinterface/", "Level9_mc", "Level9_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");
 
		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
		flag3 = this->createMovieClip("flag3", "worldinterface/", "flag", "LevelBase");
		flag4 = this->createMovieClip("flag4", "worldinterface/", "flag", "LevelBase");

		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());
 
		flags.push(flag1);
		flags.push(flag2); 
		flags.push(flag3); 
		flags.push(flag4); 
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10); 
		pointers.push(pointer1);  
		pointers.push(pointer2);  
		decorations.push(decoration);  
	};
	Level10_mc::Level10_mc(World *world) :Level(world, "worldinterface/", "Level10_mc", "Level10_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");
 
		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
		flag3 = this->createMovieClip("flag3", "worldinterface/", "flag", "LevelBase");
		flag4 = this->createMovieClip("flag4", "worldinterface/", "flag", "LevelBase");

		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());
 
		flags.push(flag1);
		flags.push(flag2); 
		flags.push(flag3); 
		flags.push(flag4); 
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10); 
		pointers.push(pointer1);  
		pointers.push(pointer2);  
		decorations.push(decoration);  
	};
	Level11_mc::Level11_mc(World *world) :Level(world, "worldinterface/", "Level11_mc", "Level11_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");
 
		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
 
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		place11= (BuildTowerPlace*) this->createMovieClip("place11", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());

		additionally = this->createMovieClipSub("additionally");
 
		flags.push(flag1);
		flags.push(flag2);  
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10); 
		places.push(place11); 
		pointers.push(pointer1);  
		pointers.push(pointer2);  
		decorations.push(decoration);  
		additionallys.push(additionally);
	};
	Level12_mc::Level12_mc(World *world) :Level(world, "worldinterface/", "Level12_mc", "Level12_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");
 
		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
 
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		place11= (BuildTowerPlace*) this->createMovieClip("place11", new BuildTowerPlace("placeRight"));
		place12= (BuildTowerPlace*) this->createMovieClip("place12", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());
 
		flags.push(flag1);
		flags.push(flag2);  
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10); 
		places.push(place11); 
		places.push(place12); 
		pointers.push(pointer1);  
		pointers.push(pointer2);  
		decorations.push(decoration);  
	};
	Level13_mc::Level13_mc(World *world) :Level(world, "worldinterface/", "Level13_mc", "Level13_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");
 
		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
 
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		place11= (BuildTowerPlace*) this->createMovieClip("place11", new BuildTowerPlace("placeRight"));
		place12= (BuildTowerPlace*) this->createMovieClip("place12", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());

		additionally = this->createMovieClipSub("additionally");
  
		flags.push(flag1);
		flags.push(flag2);  
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10); 
		places.push(place11); 
		places.push(place12); 
		pointers.push(pointer1);  
		pointers.push(pointer2);  
		decorations.push(decoration);  
		additionallys.push(additionally);
	};
	Level14_mc::Level14_mc(World *world) :Level(world, "worldinterface/", "Level14_mc", "Level14_mc")
	{
        SET_NODETYPENAME(); 
		decoration = this->createMovieClipSub("decoration");
		decorationCase = this->createCase("decorationCase");
 
		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
 
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		place11= (BuildTowerPlace*) this->createMovieClip("place11", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());

		additionally = this->createMovieClipSub("additionally");
  
		flags.push(flag1);
		flags.push(flag2);  
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10); 
		places.push(place11); 
		pointers.push(pointer1);  
		pointers.push(pointer2);  
		decorations.push(decoration);  
		additionallys.push(additionally);
	};
	Level15_mc::Level15_mc(World *world) :Level(world, "worldinterface/", "Level15_mc", "Level15_mc")
	{
        SET_NODETYPENAME(); 

		flag1 = this->createMovieClip("flag1", "worldinterface/", "flag", "LevelBase");
		flag2 = this->createMovieClip("flag2", "worldinterface/", "flag", "LevelBase");
 
		place1 = (BuildTowerPlace*) this->createMovieClip("place1", new BuildTowerPlace("placeLeft"));
		place2 = (BuildTowerPlace*) this->createMovieClip("place2", new BuildTowerPlace("placeRight"));
		place3 = (BuildTowerPlace*) this->createMovieClip("place3", new BuildTowerPlace("placeRight"));
		place4 = (BuildTowerPlace*) this->createMovieClip("place4", new BuildTowerPlace("placeLeft"));
		place5 = (BuildTowerPlace*) this->createMovieClip("place5", new BuildTowerPlace("placeRight"));
		place6 = (BuildTowerPlace*) this->createMovieClip("place6", new BuildTowerPlace("placeRight"));
		place7 = (BuildTowerPlace*) this->createMovieClip("place7", new BuildTowerPlace("placeRight"));
		place8 = (BuildTowerPlace*) this->createMovieClip("place8", new BuildTowerPlace("placeRight"));
		place9 = (BuildTowerPlace*) this->createMovieClip("place9", new BuildTowerPlace("placeRight"));
		place10 = (BuildTowerPlace*) this->createMovieClip("place10", new BuildTowerPlace("placeRight"));
		place11= (BuildTowerPlace*) this->createMovieClip("place11", new BuildTowerPlace("placeRight"));
		place12= (BuildTowerPlace*) this->createMovieClip("place12", new BuildTowerPlace("placeRight"));
		place13= (BuildTowerPlace*) this->createMovieClip("place13", new BuildTowerPlace("placeRight"));
		place14= (BuildTowerPlace*) this->createMovieClip("place14", new BuildTowerPlace("placeRight"));
		place15= (BuildTowerPlace*) this->createMovieClip("place15", new BuildTowerPlace("placeRight"));
		
		pointer1 = (LevelPointer*)this->createMovieClip("pointer1", new LevelPointer());
		pointer2 = (LevelPointer*)this->createMovieClip("pointer2", new LevelPointer());
		pointer3 = (LevelPointer*)this->createMovieClip("pointer3", new LevelPointer());

		additionally = this->createMovieClipSub("additionally");
		additionally1 = this->createMovieClipSub("additionally1");
		additionally3 = this->createMovieClipSub("additionally3");
  
		flags.push(flag1);
		flags.push(flag2);  
		places.push(place1);
		places.push(place2);
		places.push(place3);
		places.push(place4);
		places.push(place5);
		places.push(place6);
		places.push(place7);
		places.push(place8);
		places.push(place9);
		places.push(place10); 
		places.push(place11); 
		places.push(place12); 
		places.push(place13); 
		places.push(place14); 
		places.push(place15); 
		pointers.push(pointer1);  
		pointers.push(pointer2);  
		pointers.push(pointer3);  
 		additionallys.push(additionally);
 		additionallys.push(additionally1);
 		additionallys.push(additionally3);
	};
}
