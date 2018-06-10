#ifndef ENGINE_DECORATION_H
#define ENGINE_DECORATION_H
#include "BaseNode.h"
#include "MainClass.h"
 namespace engine
{
	class World;
}
namespace engine{
	namespace  decoration
	{

		class Decoration :public BaseLayer
		{
		public:
			int i;// : int = 0;
			int j;//: int = 0;
			MovieClip * container;
			//public var tempObject : Object; 
			World* world ;
			int counter;//: int = 0;
			bool earthquakeFlag;// : Boolean;

			Decoration();

			//void update()
			//{
			//	return;
			//}// end function

			//public function mouseMoveHandler(param1) : void
			//{
			//	return;
			//}// end function

			//public function mouseDownHandler(event:MouseEvent) : void
			//{
			//	return;
			//}// end function

			//public function mouseUpHandler(event:MouseEvent) : void
			//{
			//	return;
			//}// end function

		};
	};
}
#endif

