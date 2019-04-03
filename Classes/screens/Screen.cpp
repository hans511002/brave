#include "Screen.h"
namespace screens
{
	Screen::Screen() :frameCounter(0), openFlag(true), closeFlag(false), dead(false), autoguidesObject(NULL), focusListener(NULL)
	{
		this->setContentSize(Size(Main::SCREEN_WIDTH, Main::SCREEN_HEIGHT));
	};
	bool Screen::preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType) {
        if(useNodeEvent)return false;
		removeEventTarget(event, this);
		return false;
	};
	void Screen::manageListeners(string param1) {
		if (param1 == "on")
		{
			if (std::useGlobalNode)
				std::globalNode = this;
			this->enableMouseHandler(true);
			this->enableFrameHandler(true);
		}
		else if (param1 == "off")
		{
			this->disableMouseHandler();
			this->disableFrameHandler();
		}
	};
}

