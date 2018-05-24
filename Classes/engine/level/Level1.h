#ifndef ENGINE_LVEL_LEVEL1_H
#define ENGINE_LVEL_LEVEL1_H
#include "BaseHeaders.h"

#include "Level.h"
namespace engine{
	namespace  level
	{
		class Level1 : public Level{
		public:
			CREATE_FUNC(Level1);

			////柴房
			//dragonBones::DBCCArmatureNode * decoration;
			////伐木工人
			//dragonBones::DBCCArmatureNode * decoration1;
			////伐木按钮
			//dragonBones::DBCCArmatureNode * decorationCase;

			////旗子
			//dragonBones::DBCCArmatureNode * flag1;
			//dragonBones::DBCCArmatureNode * flag2;
			////塔
			//dragonBones::DBCCArmatureNode * place1;
			//dragonBones::DBCCArmatureNode * place2;
			//dragonBones::DBCCArmatureNode * place3;
			//dragonBones::DBCCArmatureNode * place4;
			//dragonBones::DBCCArmatureNode * place5;
			

			//提前下一波到来的图标  时间到开始播 播完下一波, 点击直接下一波,可获取不同数量的金币 
			//部分属性需要提升到level中
			//dragonBones::DBCCArmatureNode * pointer1;
			
			MovieClip * decoration;
            MovieClip * decoration1;
            MovieClip * decorationCase;
            MovieClip * flag1;
            MovieClip * flag2;
            MovieClip * place1;
            MovieClip * place2;
            MovieClip * place3;
            MovieClip * place4;
            MovieClip * place5;
            MovieClip * pointer1;

			
			Level1(){
			}
			bool init();
		};

	}
}
#endif

