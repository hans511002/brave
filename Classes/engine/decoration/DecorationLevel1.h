#ifndef ENGINE_DECORATION_LEVEL1_H
#define ENGINE_DECORATION_LEVEL1_H
#include "BaseHeaders.h"
#include "engine/decoration/Decoration.h"

namespace engine{
	namespace  decoration
	{
		class DecorationLevel1 :public Decoration
		{
		public:
			MovieClip * container1;
			MovieClip * decorationCase;
			int decorationFlag;// : int = 0;
			int mouseDownCounter;// : int = 0;

			DecorationLevel1();
			 void _onStart() {
			 };
			//  public function update() : void
			//{
			//	if (this.decorationFlag > 0)
			//	{
			//		if (this.decorationFlag == 1)
			//		{
			//			if (container.currentFrame < container.totalFrames)
			//			{
			//				container.gotoAndStop((container.currentFrame + 1));
			//			}
			//			else
			//			{
			//				container.gotoAndStop(1);
			//				this.decorationFlag = 0;
			//				this.decorationCase.visible = true;
			//				container.visible = false;
			//				this.container1.visible = true;
			//			}
			//		}
			//		else if (this.decorationFlag == 2)
			//		{
			//			if (this.container1.currentFrame < this.container1.totalFrames)
			//			{
			//				this.container1.gotoAndStop((this.container1.currentFrame + 1));
			//				if (this.container1.currentFrame == 169)
			//				{
			//					world.achieveManage("achieve_dude_01");
			//				}
			//			}
			//			else
			//			{
			//				this.container1.gotoAndStop(1);
			//				this.decorationFlag = 0;
			//				this.decorationCase.visible = true;
			//				container.visible = true;
			//				this.container1.visible = false;
			//			}
			//		}
			//	}
			//	super.update();
			//	return;
			//}// end function

			//override public function mouseDownHandler(event:MouseEvent) : void
			//{
			//	if (event.target.name == "decorationCase")
			//	{
			//		(this.mouseDownCounter + 1);
			//		if (this.mouseDownCounter == 1)
			//		{
			//			this.decorationFlag = 1;
			//			this.decorationCase.visible = false;
			//		}
			//		else if (this.mouseDownCounter == 2)
			//		{
			//			this.mouseDownCounter = 0;
			//			this.decorationFlag = 2;
			//			this.decorationCase.visible = false;
			//		}
			//	}
			//	return;
			//}// end function

		};
	};
}
#endif
