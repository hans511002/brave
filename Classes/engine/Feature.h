#ifndef ENGINE_FEATURE_H
#define ENGINE_FEATURE_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"
//#include "MainClass.h"
//#include "World.h"


namespace engine
{ 
	class World;
	
    class Feature  
    {
	public:
		int i, j; 
        //public var tempObject:Object;
        //public var tempObject1:Object;
		World* world ;
		int autoAddTowerCounter  ;

		Feature();

		void   update();

		void listOfMoveSpheres();

		void getSphereBeat(string param1, int param2);

		void returnGetSphereToArchive(string param1, int param2);

		void afterLoadXML();

		void scanPointersAtCast();

	};
}
 #endif
