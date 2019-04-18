#include "Training.h"
namespace training
{
	bool Training::preCheckEventTarget(std::MouseEvent * event, EventMouse::MouseEventType _mouseEventType) {
		if (useNodeEvent)return false;
		removeEventTarget(event, this);
		return false;
	};
	void Training::manageListeners(string param1) {
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