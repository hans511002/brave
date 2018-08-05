#ifndef ENGINE_WAVES_H
#define ENGINE_WAVES_H
#include "BaseHeaders.h"
#include "engine/xml/ReadXML.h"

#include "JsonUtil.h"

namespace engine
{ 
	template <class T = int> struct WaveData{
		T value;
		Common::Array<WaveData> d;
		WaveData() :value(0)
		{}
		inline WaveData & operator[](int i){
			return d[i];
		};
		int size(){
			return d.size();
		}
		inline T operator=(T i){
			return value=i;
		};
		inline  operator T (){
			return value ;
		};
 
		// prefix
		inline T operator++() { return ++value; }
		inline T operator--() { return --value; }

		// suffix
		inline T operator++(int) { T old = value; value++; return (old); }
		inline T operator--(int) { T old = value; value--; return  (old); }

		inline void clear() {
			this->d.clear();
		}
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
		Common::Array<WaveData<int> > listOfWaves;
		Common::Array<Common::Array<int> > additArr;
		Common::Array<Common::Array<int> > listOfReplacement;

		Waves();

		virtual  void startWaves();

		virtual void wavesHandler();

	};
}
#endif
