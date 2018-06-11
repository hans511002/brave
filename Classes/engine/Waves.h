#ifndef ENGINE_WAVES_H
#define ENGINE_WAVES_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"

#include "JsonUtil.h"

namespace engine
{ 
	struct WaveData{
		int value;
		Common::Array<WaveData> d;
		WaveData() :value(0)
		{}
		inline WaveData & operator[](int i){
			return d[i];
		};
		int size(){
			return d.size();
		}
		inline int operator=(int i){
			return value=i;
		};
		inline  operator int (){
			return value ;
		};
 
		// prefix
		inline int operator++() { return ++value; }
		inline int operator--() { return --value; }

		// suffix
		inline int operator++(int) { int old = value; value++; return (old); }
		inline int operator--(int) { int old = value; value--; return  (old); }

		inline WaveData &splice(int s, int n = 1){
			while (n){
				d.remove(s);
				n--;
			}
			return *this;
		}
	};
 
    class Waves 
    {
    public:
        int i,j, n;
        //public var tempObject:Object;
        //public var tempObject1:Object;
        World * world;
        bool waveWork,waveWorkSt1, waveWorkSt2,waveWorkSt3;
        int nowWave;
        int maxWaves;
		Common::Array<WaveData> listOfWaves;
		Common::Array<Common::Array<int> > additArr;
		Common::Array<Common::Array<int> > listOfReplacement;

		Waves();

        void startWaves();

        void wavesHandler() ;

	};
}
#endif
