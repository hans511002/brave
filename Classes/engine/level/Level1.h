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

			////��
			//dragonBones::DBCCArmatureNode * decoration;
			////��ľ����
			//dragonBones::DBCCArmatureNode * decoration1;
			////��ľ��ť
			//dragonBones::DBCCArmatureNode * decorationCase;

			////����
			//dragonBones::DBCCArmatureNode * flag1;
			//dragonBones::DBCCArmatureNode * flag2;
			////��
			//dragonBones::DBCCArmatureNode * place1;
			//dragonBones::DBCCArmatureNode * place2;
			//dragonBones::DBCCArmatureNode * place3;
			//dragonBones::DBCCArmatureNode * place4;
			//dragonBones::DBCCArmatureNode * place5;
			

			//��ǰ��һ��������ͼ��  ʱ�䵽��ʼ�� ������һ��, ���ֱ����һ��,�ɻ�ȡ��ͬ�����Ľ�� 
			//����������Ҫ������level��
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

