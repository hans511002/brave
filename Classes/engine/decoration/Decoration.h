#ifndef ENGINE_DECORATION_H
#define ENGINE_DECORATION_H
#include "BaseHeaders.h"
#include "MainClass.h"
 
namespace engine{
	namespace  decoration
	{

		class Decoration :public BaseNode
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

			//virtual void update(float dt=0)
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

