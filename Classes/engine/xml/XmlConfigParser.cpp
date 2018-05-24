#include "XmlConfigParser.h"

namespace engine{
 
	std::map<std::string, dragonBones::XMLDocument *> XMLConfigParser::xmlCache;

	dragonBones::XMLDocument * XMLConfigParser::getDoc(std::string filePath, std::string name){
		std::map<std::string, dragonBones::XMLDocument *>::iterator it = xmlCache.find(name);
		if (it != xmlCache.end()){
			return  it->second;
		}
		else{
			const auto &data = cocos2d::FileUtils::getInstance()->getDataFromFile(filePath);
			if (data.getSize())
			{
				dragonBones::XMLDocument* doc = new dragonBones::XMLDocument();
				doc->Parse(reinterpret_cast<char*>(data.getBytes()), data.getSize());
				xmlCache.insert(std::map<std::string, dragonBones::XMLDocument *>::value_type(name, doc));
				return doc;
			}
			return false;
		}
	};
	bool XMLConfigParser::removeDoc(std::string fileName, std::string name){
		std::map<std::string, dragonBones::XMLDocument *>::iterator it = xmlCache.find(name);
		if (it != xmlCache.end()){
			dragonBones::XMLDocument* doc = it->second;
			xmlCache.erase(it);
			doc->~XMLDocument();
			return true;
		}
		return false;
	};
	XMLConfigParser::XMLConfigParser(std::string fileName, std::string name, bool del ):del(del){
		doc = NULL;
		std::map<std::string, dragonBones::XMLDocument *>::iterator it=	xmlCache.find(name);
		if (it != xmlCache.end()){
			this->doc = it->second;
		}else{
			const auto &data = cocos2d::FileUtils::getInstance()->getDataFromFile(fileName);
			if (data.getSize() )
			{  
				doc = new dragonBones::XMLDocument();
				doc->Parse(reinterpret_cast<char*>(data.getBytes()), data.getSize());
				if (!del)
					xmlCache.insert(std::map<std::string, dragonBones::XMLDocument *>::value_type(name, doc));
			}
		}
	};

	dragonBones::XMLElement * XMLConfigParser::findChild(dragonBones::XMLElement * root, std::string childName){
		dragonBones::XMLElement *cnode = root->FirstChildElement();
		while (cnode){
			if (childName == cnode->Name()){
				return cnode;
			}
			cnode = cnode->NextSiblingElement();
		}
		return cnode;
	}
	
	dragonBones::XMLElement *  XMLConfigParser::findChild(dragonBones::XMLElement * root, std::string nodePath,  std::string &attrName){
		attrName.clear();
		if (!root)return false;
		nodePath = Common::String::Trim(nodePath, '.');
		std::vector<std::string> elems;
		split(nodePath, '.', elems);
		dragonBones::XMLElement * node;
		int n = elems.size();
		size_t i = 0;
		std::string & lelName = elems.at(n - 1);
			 
		if (lelName.at(0) == '@'){
			n -= 1; 
			attrName = lelName.substr(1);
		}
		dragonBones::XMLElement * cnode = root; 
		while (i < n  && root){
			std::string & elName = elems.at(i);
			i++;
			cnode = findChild(root, elName);
			if (!cnode){
				return false;
			}
			root = cnode;
		}
		if (i < n){ 
			return false;
		} 
			
		return root;
	}
	vector<dragonBones::XMLElement *> XMLConfigParser::findChildList(dragonBones::XMLElement * root, std::string nodePath){
		nodePath = Common::String::Trim(nodePath, '.'); 
		vector<dragonBones::XMLElement *> res;
		std::vector<std::string> elems;
		split(nodePath, '.', elems);
		dragonBones::XMLElement * cnode = root ;
		int n = elems.size() - 1;
		size_t i = 0; 
		while (i < n  && cnode){
			std::string & elName = elems.at(i);
			i++;
			cnode = findChild(cnode, elName);
		}
		if (i < n || !cnode){
			return res;
		}
		std::string &childName = elems.at(i);
		cnode = cnode->FirstChildElement();
		while (cnode){
			if (childName == cnode->Name()){
				res.push_back( cnode);
			}
			cnode = cnode->NextSiblingElement();
		}
		return res;
	}
	vector<dragonBones::XMLElement *> XMLConfigParser::getChildList(dragonBones::XMLElement * root, std::string nodePath){
		return findChildList(root, nodePath);
	};
	vector<dragonBones::XMLElement *> XMLConfigParser::getChildList(std::string nodePath){
		//std::vector<std::string> elems;
		//split(nodePath, '.', elems);
		//dragonBones::XMLElement * node;
		//int n = elems.size()-1;
		//size_t i = 0;
		dragonBones::XMLElement * cnode = doc->RootElement();
		if (!cnode){
			return vector<dragonBones::XMLElement *>();
		}
		//while (i < n  && cnode){
		//	std::string & elName = elems.at(i);
		//	i++;
		//	cnode = findChild(cnode, elName); 
		//}
		//vector<dragonBones::XMLElement *> res;
		//if (i < n){
		//	return res;
		//}
		return findChildList(cnode, nodePath);
	};
}
