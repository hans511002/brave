#pragma once
#include "BaseNode.h"
namespace engine
{
class LevelPointer :public MovieClip
{
public:
	MCCase * pointerCase;
	MovieClipSub * fireAnima;
	MovieClipSub * eyesAnima;
	Sprite * mask1;
	Sprite * mask2;
	Sprite * arrow;
	MCMask * mask3;//1
	MCMask * mask4;//2
	Sprite * mask5;//1 2

	LevelPointer();
	float counter;
	int timer;
	Vec2 myPoint;
	int statusAnima;
};
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
	mask3 = this->createMask("mask3");
	mask4 = this->createMask("mask4");
	mask5= (Sprite*)this->getArmature()->getSlot("arrow")->getDisplay();


}

}
