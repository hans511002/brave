#include "WorldInterface_mc.h"
namespace engine
{
	WorldInterface_mc::WorldInterface_mc():barinfoback(NULL),healthbar(NULL),moneybar(NULL),butCastAir(NULL),butCastGolem(NULL),
	    butCastIceman(NULL),fastbtn(NULL),faster(NULL),buyFire(NULL),buyIce(NULL),buyLevin(NULL),buyStone(NULL),buyGetAll(NULL),getAll(NULL),
	    ause(NULL),startWaves(NULL),stoneBacklight(NULL),levinBacklight(NULL),iceBacklight(NULL),fireBacklight(NULL),iceBack(NULL),fireBack(NULL),
	    levinBack(NULL),stoneBack(NULL),iceSphere(NULL),fireSphere(NULL),levinSphere(NULL),stoneSphere(NULL),lastTime(NULL),waveTXT(NULL),
	    liveTXT(NULL),moneyTXT(NULL),levinNumTXT(NULL),iceNumTXT(NULL),fireNumTXT(NULL),stoneNumTXT(NULL),getAllNumTXT(NULL)
	{

	}
	bool WorldInterface_mc::init()
	{
		BaseNode::init();
		string basePath="worldinterface/"
		string fasterAniName="faster";
		string fasterPath=basePath+"startbtn/fasterbtn";
		DBCCFactory::getInstance()->loadDragonBonesData(fasterPath + "/skeleton.xml", fasterAniName);
		DBCCFactory::getInstance()->loadTextureAtlas(fasterPath + "/texture.xml", fasterAniName);
		this->faster = DBCCFactory::getInstance()->buildArmatureNode(fasterAniName);


	}
}
