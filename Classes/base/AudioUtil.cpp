#include "BaseHeaders.h" 
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

namespace std
{ 
//    namespace AudioUtil
//    {
		bool AudioUtil::soundOn = true; 
		bool AudioUtil::musicOn =true;  
        string AudioUtil::audioDir;
        string AudioUtil::nowMusic;
        map<string,unsigned int> AudioUtil::soundEffect;
            
        string AudioUtil::getAudioPath(const char * file){
            if(file[0]!='/' && !audioDir.empty()){
                return audioDir+"/"+file;
            }else{
                return file;
            }
        };
        
        void AudioUtil::setAudioDir(const char * path)
        {
            audioDir=path;
            soundOn=true;
        };
        void AudioUtil::musicManage(const string & onoff)
        {
            if(onoff=="on"){
				musicOn =true;
            }else if(onoff=="off"){
				musicOn =false;
                if(isPlayMusic())
					stopMusic();
            }            
        };
		void AudioUtil::soundManage(const string & onoff)
		{
			if (onoff == "on") {
				soundOn = true;
			}
			else if (onoff == "off") {
				soundOn = false;
				if (isPlayMusic())
					stopAllEffects();
			}
		};

        void AudioUtil::preloadMusic(const char * file)
        {
            auto audioengine = SimpleAudioEngine::getInstance();
            audioengine->preloadBackgroundMusic(getAudioPath(file).c_str());
        };
        void AudioUtil::playMusic(const char * file,bool loop){
            if(!AudioUtil::musicOn)return;
            AudioUtil::nowMusic=file;
            auto audioengine = SimpleAudioEngine::getInstance();
            audioengine->playBackgroundMusic(getAudioPath(file).c_str(),loop);
        };
        void AudioUtil::stopMusic(bool releaseData){
            if(!AudioUtil::musicOn)return;
            auto audioengine = SimpleAudioEngine::getInstance();
            audioengine->stopBackgroundMusic(releaseData);
        };
        void AudioUtil::pauseMusic(){
            auto audioengine = SimpleAudioEngine::getInstance();
            audioengine->pauseBackgroundMusic();
        };
        void AudioUtil::rewindMusic(){
            auto audioengine = SimpleAudioEngine::getInstance();
            audioengine->rewindBackgroundMusic();
        };
        bool AudioUtil::isPlayMusic(){
            return SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
        };
        void AudioUtil::setMusicVolume(float vol){
            return SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(vol);
        };
        float AudioUtil::getMusicVolume(){
            return SimpleAudioEngine::getInstance()->getBackgroundMusicVolume(); 
        };
        
        void AudioUtil::preloadEffect(const char * file)
        {
            SimpleAudioEngine::getInstance()->preloadEffect(getAudioPath(file).c_str());
        }
        unsigned int AudioUtil::playSoundWithVol(const char * file,float vol,bool loop)
        {
            if(!AudioUtil::soundOn)return 0;
            auto audioengine = SimpleAudioEngine::getInstance();
			unsigned int sid=audioengine->playEffect(getAudioPath(file).c_str(),loop,1.0f,0.0f,std::abs(vol));
            if(vol>=0)
                setEffectsVolume(vol);
			return sid;
        }
        void AudioUtil::stopEffect (unsigned int soundId )
        {
            SimpleAudioEngine::getInstance()->stopEffect(soundId);
        }
        void AudioUtil::pauseEffect (unsigned int soundId ){
            SimpleAudioEngine::getInstance()->pauseEffect(soundId);
        }
        void AudioUtil::resumeEffect (unsigned int soundId ){
            SimpleAudioEngine::getInstance()->resumeEffect(soundId);
        }
        void AudioUtil::unloadEffect (const char * file ){
            SimpleAudioEngine::getInstance()->unloadEffect(getAudioPath(file).c_str());
        }
        void AudioUtil::stopAllEffects (){
            SimpleAudioEngine::getInstance()->stopAllEffects();
        }
        void AudioUtil::pauseAllEffects (){
            SimpleAudioEngine::getInstance()->pauseAllEffects();
        }
        void AudioUtil::resumeAllEffects (){
            SimpleAudioEngine::getInstance()->resumeAllEffects();
        }
        void AudioUtil::setEffectsVolume(float vol){
            SimpleAudioEngine::getInstance()->setEffectsVolume(vol);
        }
        float AudioUtil::getEffectsVolume(){
            return SimpleAudioEngine::getInstance()->getEffectsVolume(); 
        };
        
        void AudioUtil::stopAll(){
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			SimpleAudioEngine::getInstance()->stopAllEffects();
        };
   
////开始播放背景音效，false表示不循环
//SimpleAudioEngine::sharedEngine()->playEffect(music/xxxx.mp3,false);
////停止音效，可以选择单独停掉一个音效，这个值是由playEffect返回的
//SimpleAudioEngine::sharedEngine()->stopEffect(m_nSoundId);
////停止全部音效
//SimpleAudioEngine::sharedEngine()->stopAllEffects();
////暂停单个音效
//SimpleAudioEngine::sharedEngine()->pauseEffect(m_nSoundId);
////重新开始音效
//SimpleAudioEngine::sharedEngine()->resumeEffect(m_nSoundId);
////暂停全部音效
//SimpleAudioEngine::sharedEngine()->pauseAllEffects();
////重新开始全部音效
//SimpleAudioEngine::sharedEngine()->resumeAllEffects();
////设置音效音量0.0-1.0
//SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
////卸载音效
//SimpleAudioEngine::sharedEngine()->unloadEffect(music/xxxx.mp3);
    
    
//virtual void preloadBackgroundMusic(const char * filePath)
//virtual void playBackgroundMusic ( const char * filePath,bool loop = false )
// virtual void stopBackgroundMusic ( bool releaseData = false ) 
//virtual void pauseBackgroundMusic ( ) // 暂停播放背景音乐。
//virtual void resumBackgroundMusic ( ) // 恢复播放背景音乐。
//virtual void rewindBackgroundMusic ( )//将背景音乐倒回起始点播放。
//virtual void preloadEffect(const char * filePath)//预加载音效文件。
//virtual unsigned int playEffect ( const char * filePath,bool loop = false,float pitch = 1.0f,float pan = 0.0f,float gain = 1.0f )
//参数
//filePath	音效文件的路径。
//loop	是否循环播放,默认为false,不循环。
//pitch	频率，正常情况下为1.0,在播放时也可以改变该值。
//pan	声道，范围为-1到1，为-1时表示只有左声道，为1时表示只有右声道。
//gain	音量增益, 范围为0到1，默认值为1。
//返回
//声音id。
//注解
//现在还不能完全支持所有参数，限制的功能如下：
//在Samsung Galaxy S2上如果启用了OpenSL那么pitch参数无效；
//在emscrippten, win32, marmalade上pitch/pan/gain参数无效

//virtual void stopEffect ( unsigned int soundId ) ///停止播放指定的音效。参数 soundId	playEffect返回的资源id。
//virtual void pauseEffect ( unsigned int soundId )
//virtual void resumeEffect ( unsigned int soundId )
//virtual void unloadEffect ( const char * filePath )


} 

