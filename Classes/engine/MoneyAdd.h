﻿#ifndef ENGINE_MONEYADD_H
#define ENGINE_MONEYADD_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"

#include "JsonUtil.h"

namespace engine
{
 
	struct MoneyAdd_mc :public MovieClip
	{
	public:
		ui::Text	* noteTXT;
		inline MoneyAdd_mc() :MovieClip("worldinterface/", "MoneyAdd_mc", "MoneyAdd_mc")
		{
			SET_NODETYPENAME();
			noteTXT = this->createText("noteTXT");
		}
	};
	class MoneyAdd : public BaseNode
	{
	public:
		int i;
		int tempObject;
		//public var container:MoneyAdd_mc;
		MoneyAdd_mc * container;// MoneyAdd_mc;
		int money;
		bool dead;
		World *world;

		MoneyAdd(int param1);
		virtual bool init();
		virtual void remove();
		virtual void update(float dt = 0);

		virtual void kill();

	};
}
#endif
