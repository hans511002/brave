#ifndef XML_CONFIG_H
#define XML_CONFIG_H
//#include "BaseHeaders.h"
#include "cocos2d.h"
#include "JsonUtil.h" 
#include "tinyxml2/tinyxml2.h"

namespace engine{
	 
		bool inline operator==(const  Common::String &a, const char * b)
		{
			return Common::String::strcmp(a.c_str(), b) == 0;
		};
		bool inline operator==(const  std::string &a,const char * b)
		{
			return Common::String::strcmp(a.c_str(), b) == 0;
		};
        inline  ostream& operator<<(ostream& target, tinyxml2::XMLElement * node)
		{
			if (!node)return target;
			if (node->ToText() && node->Value())
			{
				target << (char *)node->Value();
				//delete value;
				return target;
			}
			target << "<" << node->Name();
            const tinyxml2::XMLAttribute * cattr = node->FirstAttribute();
			while (cattr){
				target << " " << cattr->Name() << "=\"" << cattr->Value() << "\"";
				cattr = cattr->Next();
			}
			target << " >";
			if (node->FirstChildElement())
			{
                tinyxml2::XMLElement * cnode = node->FirstChildElement();
				while (cnode){
					target << cnode;
					cnode->NextSiblingElement();
				}
			}
			target << "</" << node->Name() << ">";
			return target;
		}

        inline Common::String& operator<<(Common::String& target, tinyxml2::XMLElement * node)
		{
			if (!node)return target;
			if (node->ToText() && node->Value())
			{
				target += (char *)node->Value();
				return target;
			}
			if (node->FirstChildElement())
			{
                tinyxml2::XMLElement * cnode = node->FirstChildElement();
				while (cnode){
					target << cnode;
					cnode->NextSiblingElement();
				}
			}
			return target;
		}
		inline Common::String operator+(Common::String target, tinyxml2::XMLElement * node)
		{
			Common::String temp;
			temp << node;
			return target + temp;
		}
		inline Common::String operator+(tinyxml2::XMLElement *node, Common::String target)
		{
			Common::String temp;
			temp << node;
			return temp + target;
		}
		inline Common::String& operator+=(Common::String& target, tinyxml2::XMLElement * node)
		{
			Common::String temp;
			temp << node;
			target += temp;
			return target;
		};
		
		class XMLConfigParser{
			bool del;
		public:
			static std::map<std::string, tinyxml2::XMLDocument *> xmlCache;
			tinyxml2::XMLDocument * doc;
			static tinyxml2::XMLElement * findChild(tinyxml2::XMLElement * root, std::string childName);
			static tinyxml2::XMLElement * findChild(tinyxml2::XMLElement * root, std::string nodePath, std::string &attrName);
			static vector<tinyxml2::XMLElement *> findChildList(tinyxml2::XMLElement * root, std::string childPath);
			static tinyxml2::XMLDocument * getDoc(std::string fileName, std::string name);
			static bool removeDoc(std::string fileName, std::string name); 
			XMLConfigParser(std::string fileName, std::string name,bool del=false) ;
			~XMLConfigParser(){
			    if(del){
			        this->doc->~XMLDocument();
					delete this->doc;
					doc = NULL;
			    }
			};
			inline tinyxml2::XMLElement * get(std::string nodePath)
			{
				std::string attrName;
				return  get(nodePath, &attrName);
			}
			inline tinyxml2::XMLElement * get(std::string nodePath, std::string *attrName)
			{
				if (!doc)return NULL;
				tinyxml2::XMLElement * root = doc->RootElement();
				if (!root)return NULL; 
				tinyxml2::XMLElement * resNode = findChild(root, nodePath, *attrName);
				return resNode;
			};
			vector<tinyxml2::XMLElement *> getChildList(std::string nodePath);
			vector<tinyxml2::XMLElement *> getChildList(tinyxml2::XMLElement * root, std::string nodePath);

#define GET_XML_NODE(T,castType) inline bool get(T & val,std::string nodePath)\
			{std::string attrName; \
			tinyxml2::XMLElement * resNode = get(nodePath, &attrName); \
			if (!resNode)return false; \
			const char *cval = NULL; \
			if (!attrName.empty()){ \
			cval = resNode->Attribute(attrName.c_str()); \
			}else{\
			cval = resNode->Value(); \
			}\
			if (!cval)return false;\
			castType  \
			return true; \
			}; inline bool get(tinyxml2::XMLElement * node, T & val, std::string nodePath=""){\
				const char *cval = NULL; \
				if (!nodePath.empty()){ \
					std::string attrName; \
					tinyxml2::XMLElement * resNode = findChild(node, nodePath, attrName);\
					if (!resNode)return false; \
					if (!attrName.empty()){ \
						cval = resNode->Attribute(attrName.c_str()); \
					}else{\
						cval = resNode->Value(); \
					}\
				}else{\
				cval = node->Value(); \
				}\
				if (!cval)return false; \
				castType  \
				return true; \
			}
			
			GET_XML_NODE(const char *, { val = (const char *)cval; });
			GET_XML_NODE(std::string, { val = (const char *)cval; });
			GET_XML_NODE(int, { val = atoi(cval); });
			GET_XML_NODE(short, { val = atoi(cval); });
			GET_XML_NODE(long long, { val = atoll(cval); });
			GET_XML_NODE(float, { val = atof(cval); });
			GET_XML_NODE(double, { val = Common::Convert::ToDouble(cval); });
			GET_XML_NODE(bool, { int iv = atoi(cval); if (iv)val = true; else val = (Common::String::strcmp(cval, "true") == 0); });

			//خ��ۈ纻ˇ@��ͷղ�˴є
#define GET_XML_NODE_VALUE(T,NAME,DEF) inline T NAME( std::string nodePath,T defaultVal=DEF){\
			T res;					\
			if (get(res, nodePath))		\
			return res;				\
			return defaultVal;			\
			};  \
			inline T  NAME(tinyxml2::XMLElement * node, std::string nodePath,T defaultVal = DEF){\
			T res;					\
			if (get(node, res, nodePath))		\
				return res;				\
				return defaultVal;			\
			}

			GET_XML_NODE_VALUE(int, getInt, 0);
			GET_XML_NODE_VALUE(short, getShort, 0);
			GET_XML_NODE_VALUE(bool, getBool, false);
			GET_XML_NODE_VALUE(float, getFloat, 0.0);
			GET_XML_NODE_VALUE(double, getDouble, 0.0);
			GET_XML_NODE_VALUE(long long, getLLong, 0);
			GET_XML_NODE_VALUE(std::string, getString, ""); 

#define GET_XML_NODE_ATTR(T,NAME,DEF) inline T NAME( std::string nodePath,std::string attrName,T defaultVal=DEF){\
			T res;									\
			if (get(res, nodePath + "@" + attrName))	\
			return res;								\
			return defaultVal;							\
			};  \
			inline T  NAME(tinyxml2::XMLElement * node,std::string attrName, T defaultVal = DEF){\
			T res;									\
			if (get(node,res, attrName))	\
			return res;								\
			return defaultVal;							\
			}

			GET_XML_NODE_ATTR(int, getIntAttribute, 0);
			GET_XML_NODE_ATTR(short, getShortAttribute, 0);
			GET_XML_NODE_ATTR(float, getFloatAttribute, 0.0);
			GET_XML_NODE_ATTR(double, getDoubleAttribute, 0.0);
			GET_XML_NODE_ATTR(long long, getLLongAttribute, 0);
			GET_XML_NODE_ATTR(std::string, getStringAttribute, "");
		};
	 
	
};
#endif
