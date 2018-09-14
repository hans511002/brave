#ifndef BASE_AUDIOUTIL_H
#define BASE_AUDIOUTIL_H
#include "cocos2d.h"
 
namespace std
{
    namespace AudioUtil
    {
        extern bool soundOn;
		extern bool musicOn;
		extern string audioDir;
		extern string nowMusic;
		extern map<string,unsigned int> soundEffect;
        
        string getAudioPath(const char * file);
        void setAudioDir(const char * path);
		void musicManage(const string & onoff);
		void soundManage(const string & onoff);
		
        
        void preloadMusic(const char * path);
        void playMusic(const char * file,bool loop=true);
        void stopMusic(bool releaseData = false);
        void pauseMusic();
        void rewindMusic();
        bool isPlayMusic();
        void setMusicVolume(float vol);
        float getMusicVolume();
          
        void preloadEffect(const char * file);
        unsigned int playSoundWithVol(const char * file,float vol=1.0f,bool loop=false);
        inline unsigned int playSound(const char * file,bool loop=false){return playSoundWithVol(file,-1,loop);};
        void stopEffect (unsigned int soundId );
        void pauseEffect (unsigned int soundId );
        void resumeEffect (unsigned int soundId );
        void unloadEffect (const char * filePath );
        void stopAllEffects ();
        void pauseAllEffects ();
        void resumeAllEffects ();
        void setEffectsVolume(float vol); 
        float getEffectsVolume();
        
        void stopAll();
 
////预加载背景音乐
//SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(music/xxxx.mp3);
////开始播放背景音乐，true表示循环
//SimpleAudioEngine::sharedEngine()->playBackgroundMusic(music/xxxx.mp3,true);
////停止背景音乐，这是一个缺省参数函数，传参表示是否释放音乐文件
//SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
////暂停背景音乐
//SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
////重头调用背景音乐
//SimpleAudioEngine::sharedEngine()->rewindBackgroundMusic();
////返回布尔型参数，表示是否在放着背景音乐
//SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()
////设置音量0.0-1.0
//SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);

////预加载音效
//SimpleAudioEngine::sharedEngine()->preloadEffect(music/xxxx.mp3);
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


    };    
    
}

 
#endif

