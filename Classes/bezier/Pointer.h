#ifndef BEZIER_POINTER_H
#define BEZIER_POINTER_H
#include "BaseHeaders.h"
#include "PathPoint.h"

namespace bezier
{
	class Pointer : public cocos2d::Node
	{
	public:
		float size;// = 8;
		static bool dragFlag;// = false;
		CREATE_FUNC(Pointer);

		Pointer() :size(8)
		{
			//graphics.beginFill(8421504);//填充颜色
			//graphics.drawCircle(0, 0, this.size); // 画一个圆
			////addEventListener(Event.ADDED_TO_STAGE, this.eAddToStage);
			//DrawPrimitives::drawCircle(VisibleRect::center(), 100, 0, 10, false);//参数依次为：圆心、半径、角度、段数、是否画出一条半径  
			DrawPrimitives::drawCircle(cocos2d::Vec2(0, 0), this->size, 0, 10, false);

			return;
		}// end function
		bool init(){

			return true;
		};

		//private function eAddToStage(event:Event) : void
		//{
		//    removeEventListener(Event.ADDED_TO_STAGE, this.eAddToStage);
		//    addEventListener(MouseEvent.MOUSE_DOWN, this.eMouseDown);
		//    stage.addEventListener(MouseEvent.MOUSE_UP, this.eMouseUp);
		//    return;
		//}// end function

		//private function eMouseUp(event:MouseEvent) : void
		//{
		//    stopDrag();
		//    dragFlag = false;
		//    return;
		//}// end function

		//private function eMouseDown(event:MouseEvent) : void
		//{
		//    startDrag(false, new Rectangle(this.size, this.size, stage.stageWidth - this.size, stage.stageHeight - this.size));
		//    dragFlag = true;
		//    return;
		//}// end function

	};
}
#endif
