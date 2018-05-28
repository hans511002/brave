#include "TowerMenu_mc.h"
#include "engine/World.h"

namespace engine
{
    namespace towers
    {
        TowerMenuHint_mc::TowerMenuHint_mc():MovieClip("tower/","TowerMenuHint_mc","TowerMenuHint_mc")
        {
            cont1=cont1Sphere1=cont1Sphere2=NULL; 
            cont               = this     ->createMovieClipSub("cont");
            contCont1          = cont     ->createMovieClipSub("cont1");
            contCont1Sphere1   = contCont1->createMovieClipSub("sphere1");
            contCont1Sphere2   = contCont1->createMovieClipSub("sphere2");
            nameTXT            = this     ->createText        ("nameTXT");
        };// end function
        TowerRadius_mc::TowerRadius_mc() :BaseSprite("Tower/TowerRadius_mc.png"), myTower(NULL)
        {
        }
        BtnUpgradeMenu::BtnUpgradeMenu() :BaseSprite("TowerMenu_mc/btnUpgradeMenu01.png")
        {
            //CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bg2.png");
            //this->setTexture(texture);
        };
        void BtnUpgradeMenu::setImage(int i){
            //string path = "";
            char path[64];
            sprintf(path,"TowerMenu_mc/btnUpgradeMenu0%d.png",i);
            CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(path);
            this->setTexture(texture);
        };
        SphereSlot::SphereSlot() :BaseSprite("TowerMenu_mc/sphereSlotbg01.png")
        {  
            this->fire = this->loadAni("worldinterface/sphere", "firesphere");
            this->ice = this->loadAni("worldinterface/sphere", "icesphere");
            this->stone = this->loadAni("worldinterface/sphere", "stonesphere");
            this->levin = this->loadAni("worldinterface/sphere", "levinsphere");

            this->addChild(this->fire);
            this->addChild(this->ice);
            this->addChild(this->stone);
            this->addChild(this->levin);
            //DBCCFactory::getInstance()->loadDragonBonesData(basePath + "sphere/stonesphere/skeleton.xml", "stonesphere");
            //DBCCFactory::getInstance()->loadTextureAtlas(basePath + "sphere/stonesphere/texture.xml", "stonesphere");
            //this->stoneSphere = DBCCFactory::getInstance()->buildArmatureNode("stonesphere");
            //DBCCFactory::getInstance()->loadDragonBonesData(basePath + "sphere/levinsphere/skeleton.xml", "levinsphere");
            //DBCCFactory::getInstance()->loadTextureAtlas(basePath + "sphere/levinsphere/texture.xml", "levinsphere");
            //this->levinSphere = DBCCFactory::getInstance()->buildArmatureNode("levinsphere");
            //DBCCFactory::getInstance()->loadDragonBonesData(basePath + "sphere/icesphere/skeleton.xml", "icesphere");
            //DBCCFactory::getInstance()->loadTextureAtlas(basePath + "sphere/icesphere/texture.xml", "icesphere");
            //this->iceSphere = DBCCFactory::getInstance()->buildArmatureNode("icesphere");
            //DBCCFactory::getInstance()->loadDragonBonesData(basePath + "sphere/fireSphere/skeleton.xml", "firesphere");
            //DBCCFactory::getInstance()->loadTextureAtlas(basePath + "sphere/fireSphere/texture.xml", "firesphere");
            //this->fireSphere = DBCCFactory::getInstance()->buildArmatureNode("firesphere");
            //this->loadAni(basePath + "sphere", "firesphere");
        };
        
        void SphereSlot::setImage(int type){
            //string path = "";
            char path[64];
            sprintf(path, "TowerMenu_mc/sphereSlotbg0%d.png", type);
            CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(path);
            this->setTexture(texture);
        };
    }
}
 