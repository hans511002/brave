
#include "RoadLevels_mc.h"
#include "engine/World.h"

namespace engine
{
    RoadLevels_mc::RoadLevels_mc(int level) :level(level)
    {
        BezierBox & bezierBox = Main::mainClass->worldClass->saveBox->bezierBoxClass;
        if(level == 1)
        {
            sectors.push(Sector(0, 309 - 46, 247, 46));
            sectors.push(Sector(247 - 46, 309 - 205, 46, 162));
            sectors.push(Sector(247, 309 - 205, 204 - 46, 46));
            sectors.push(Sector(247 + 204 - 92, 0, 46, 150 - 46));
            sectors.push(Sector(247 + 204 - 46, 0, 416 - 46, 46));
            sectors.push(Sector(247 + 204 + 416 - 138, 46, 46, 203 - 46));
            sectors.push(Sector(247 + 204 + 416 - 92, 203 - 46, 218 - 46, 46));
            sectors.clear();
            calcSectors(bezierBox.level1_path1, bezierBox.level1_path2, bezierBox.level1_path3);
        }
        else if(level == 2)
        {
            calcSectors(bezierBox.level2_path1, bezierBox.level2_path2, bezierBox.level2_path3);
        }
        else if(level == 3)
        {
            calcSectors(bezierBox.level3_path1, bezierBox.level3_path2, bezierBox.level3_path3);
            calcSectors(bezierBox.level3_path11, bezierBox.level3_path12, bezierBox.level3_path13);
        }
        else if(level == 4)
        {
            calcSectors(bezierBox.level4_path1, bezierBox.level4_path2, bezierBox.level4_path3);
            calcSectors(bezierBox.level4_path11, bezierBox.level4_path12, bezierBox.level4_path13);
        }
        else if(level == 5)
        {
            calcSectors(bezierBox.level5_path1, bezierBox.level5_path2, bezierBox.level5_path3);
            calcSectors(bezierBox.level5_path11, bezierBox.level5_path12, bezierBox.level5_path13);
        }
        else if(level == 6)
        {
            calcSectors(bezierBox.level6_path1, bezierBox.level6_path2, bezierBox.level6_path3);
            calcSectors(bezierBox.level6_path11, bezierBox.level6_path12, bezierBox.level6_path13);
        }
        else if(level == 7)
        {
            calcSectors(bezierBox.level7_path1, bezierBox.level7_path2, bezierBox.level7_path3);
        }
        else if(level == 8)
        {
            calcSectors(bezierBox.level8_path1, bezierBox.level8_path2, bezierBox.level8_path3);
            calcSectors(bezierBox.level8_path11, bezierBox.level8_path12, bezierBox.level8_path13);
        }
        else if(level == 9)
        {
            calcSectors(bezierBox.level9_path1, bezierBox.level9_path2, bezierBox.level9_path3);
            calcSectors(bezierBox.level9_path11, bezierBox.level9_path12, bezierBox.level9_path13);
        }
        else if(level == 10)
        {
            calcSectors(bezierBox.level10_path1, bezierBox.level10_path2, bezierBox.level10_path3);
            calcSectors(bezierBox.level10_path11, bezierBox.level10_path12, bezierBox.level10_path13);
        }
        else if(level == 11)
        {
            calcSectors(bezierBox.level11_path1, bezierBox.level11_path2, bezierBox.level11_path3);
            calcSectors(bezierBox.level11_path11, bezierBox.level11_path12, bezierBox.level11_path13);
        }
        else if(level == 12)
        {
            calcSectors(bezierBox.level12_path1, bezierBox.level12_path2, bezierBox.level12_path3);
            calcSectors(bezierBox.level12_path11, bezierBox.level12_path12, bezierBox.level12_path13);
        }
        else if(level == 13)
        {
            calcSectors(bezierBox.level13_path1, bezierBox.level13_path2, bezierBox.level13_path3);
            calcSectors(bezierBox.level13_path11, bezierBox.level13_path12, bezierBox.level13_path13);
        }
        else if(level == 14)
        {
            calcSectors(bezierBox.level14_path1, bezierBox.level14_path2, bezierBox.level14_path3);
            calcSectors(bezierBox.level14_path11, bezierBox.level14_path12, bezierBox.level14_path13);
        }
        else if(level == 15)
        {
            calcSectors(bezierBox.level15_path1, bezierBox.level15_path2, bezierBox.level15_path3);
            calcSectors(bezierBox.level15_path11, bezierBox.level15_path12, bezierBox.level15_path13);
            calcSectors(bezierBox.level15_path11, bezierBox.level15_path12, bezierBox.level15_path1);
        }
        init();
    };
    bool RoadLevels_mc::init()
    {
        BaseNode::init();
        int len = sectors.size();
        for(int i = 0; i < len; i++)
        {
            Sector & sec = sectors.at(i);
            BaseNode * node = new BaseNode(sec.w, sec.h, true);
            node->setPosition(sec.x, sec.y);
            node->mouseEnabled = true;
            this->addChild(node);
			this->enableMouseHandler(useNodeEvent);

            node->setName("road");
            segments.push_back(node);
        }
        if(this->level == 1)
        {
            //this->setContentSize(Size(948,309));
            //this->drawRange();
            //this->setPosition(Vec2(-76.4f, Main::SCREEN_HEIGHT - 144.9f - 309));
        }
        return true;
    };
    void RoadLevels_mc::calcSectors(Common::Array<cocos2d::Point> & path1, Common::Array<cocos2d::Point> & path2, Common::Array<cocos2d::Point> & path3)
    {
        Common::Array<Sector> sect1;
        Common::Array<Sector> sect2;
        Common::Array<Sector> sect3;
        calcSectors(sect1, path1, 30);
        calcSectors(sect2, path2, 30);
        calcSectors(sect3, path3, 30);
        Common::Array<Sector> res;
        comPathSectors(res, sect1, sect2, sect3, 50);
        Sector rect;
        int len = res.size();
        for(int i = 0; i < len; i++)
        {
            rect = res.at(i);
            rect.w = rect.w - rect.x;
            rect.h = rect.h - rect.y;
            sectors.push(rect);
        }
        //sectors.concat(res);
    };
    void RoadLevels_mc::calcSectors(Common::Array<Sector> &res, Common::Array<cocos2d::Point> & path1, double r)
    {
        Common::Array<Common::Array<cocos2d::Point> > tres;
        int len = path1.size();
        for(int i = 0; i < len; i++)
        {
            int startIdx = i;
            int endIdx = i;
            float minx = 9999;
            float maxx = 0;
            float miny = 9999;
            float maxy = 0;
            for(int j = i; j < len; j++)
            {
                cocos2d::Point & point = path1[j];
                float tminx = std::min(minx, point.x);
                float tmaxx = std::max(maxx, point.x);
                float tminy = std::min(miny, point.y);
                float tmaxy = std::max(maxy, point.y);
                if(tmaxx - tminx > r && tmaxy - tminy > r)
                {
                    if(j > i + 1)
                    {
                        endIdx = j - 1;
                    }
                    else
                    {
                        endIdx = j;
                    }
                    break;
                }
                minx = tminx;
                maxx = tmaxx;
                miny = tminy;
                maxy = tmaxy;
                endIdx = j;
            }
            if(endIdx < len - 1)
                i = endIdx - 1;
            Common::Array<cocos2d::Point> list;
            for(int j = startIdx; j <= endIdx; j++)
            {
                list.push(path1[j]);
            }
            tres.push(list);
        }
        len = tres.size();
        for(int i = 0; i < len; i++)
        {
            Common::Array<cocos2d::Point> list = tres.at(i);
            float minx = 9999;
            float maxx = 0;
            float miny = 9999;
            float maxy = 0;
            for(int j = 0; j < list.size(); j++)
            {
                cocos2d::Point & point = list[j];
                minx = std::min(minx, point.x);
                maxx = std::max(maxx, point.x);
                miny = std::min(miny, point.y);
                maxy = std::max(maxy, point.y);
            }
            res.push(Sector(minx, miny, maxx, maxy));
        }
    };
    void RoadLevels_mc::comPathSectors(Common::Array<Sector> &res, Common::Array<Sector> sect1, Common::Array<Sector> sect2, Common::Array<Sector> sect3, double roadWidth)
    {
        int sect1StartIdx = 0;
        int sect2StartIdx = 0;
        int sect3StartIdx = 0;
        int sect1EndIdx = 0;
        int sect2EndIdx = 0;
        int sect3EndIdx = 0;
        int len1 = sect1.size();
        for(int i = 0; i < sect1.size(); i++)
        {
            Sector &point = sect1.at(i);
            string dir1 = "";
            sect1StartIdx = i;
            sect1EndIdx = i;
            if(point.w - point.x > point.h - point.y)
            {
                dir1 = "h";
            }
            else
            {
                dir1 = "v";
            }
            for(int j = sect1EndIdx + 1; j < len1; j++)
            {
                Sector & point = sect1.at(j);
                string tdir1 = "";
                if(point.w - point.x > point.h - point.y)
                {
                    tdir1 = "h";
                }
                else
                {
                    tdir1 = "v";
                }
                if(dir1 != tdir1)
                {
                    break;
                }
                sect1EndIdx = j;
            }
            i = sect1EndIdx;
            int len2 = sect2.size();
            for(int j = sect2StartIdx; j < len2; j++)
            {
                Sector & point = sect2.at(j);
                string tdir1 = "";
                if(point.w - point.x > point.h - point.y)
                {
                    tdir1 = "h";
                }
                else
                {
                    tdir1 = "v";
                }
                if(dir1 != tdir1)
                {
                    break;
                }
                sect2EndIdx = j;
            }
            int len3 = sect3.size();
            for(int j = sect3StartIdx; j < len3; j++)
            {
                Sector & point = sect3.at(j);
                string tdir1 = "";
                if(point.w - point.x > point.h - point.y)
                {
                    tdir1 = "h";
                }
                else
                {
                    tdir1 = "v";
                }
                if(dir1 != tdir1)
                {
                    break;
                }
                sect3EndIdx = j;

            }
            float minx = 9999;
            float miny = 9999;
            float maxx = -100;
            float maxy = -100;
            for(int j = sect1StartIdx; j <= sect1EndIdx; j++)
            {
                Sector & point = sect1.at(j);
                minx = std::min(minx, point.x);
                miny = std::min(miny, point.y);
                maxx = std::max(maxx, point.w);
                maxy = std::max(maxy, point.h);
            }
            for(int j = sect2StartIdx; j <= sect2EndIdx; j++)
            {
                Sector &point = sect2.at(j);
                minx = std::min(minx, point.x);
                miny = std::min(miny, point.y);
                maxx = std::max(maxx, point.w);
                maxy = std::max(maxy, point.h);
            }
            for(int j = sect3StartIdx; j <= sect3EndIdx; j++)
            {
                Sector & point = sect3.at(j);
                minx = std::min(minx, point.x);
                miny = std::min(miny, point.y);
                maxx = std::max(maxx, point.w);
                maxy = std::max(maxy, point.h);
            }
            sect2StartIdx = sect2EndIdx + 1;
            sect3StartIdx = sect3EndIdx + 1;

            double rect[4];
            rect[0] = minx;
            rect[1] = miny;
            rect[2] = maxx;
            rect[3] = maxy;
            if(rect[2] - rect[0] > rect[3] - rect[1])
            {
                if(rect[3] - rect[1] < roadWidth)
                {
                    double r = (roadWidth - rect[3] + rect[1]) / 2;
                    rect[1] -= r;
                    rect[3] += r;
                }
            }
            else
            {
                if(rect[2] - rect[0] < roadWidth)
                {
                    double r = (roadWidth - rect[2] + rect[0]) / 2;
                    rect[0] -= r;
                    rect[2] += r;
                }
            }
            res.push(Sector(rect[0], rect[1], rect[2], rect[3]));
        }
        string ldir = "";
        Sector * lrect = &res.at(0);
        if(lrect->w - lrect->x > lrect->h - lrect->y)
        {
            ldir = "h";
        }
        else
        {
            ldir = "v";
        }
        Sector * rect;
        int len = res.size();
        for(int i = 1; i < len; i++)
        {
            rect = &res.at(i);
            if(ldir == "h")
            {
                if(lrect->w <= rect->w)
                    lrect->w = rect->w;
                else
                    lrect->x = rect->x;
                if(lrect->h <= rect->h)//up
                    rect->y = lrect->y;
                else//down
                    rect->h = lrect->y;
            }
            else
            {//
                if(lrect->h <= rect->h)
                    lrect->h = rect->h;
                else
                    lrect->y = rect->y;
                if(lrect->w <= rect->w)//right
                    rect->x = lrect->w;
                else//left
                    rect->w = lrect->x;
            }
            //drawFitLine(g, lrect, i);
            lrect = rect;
            if(lrect->w - lrect->x > lrect->h - lrect->y)
            {
                ldir = "h";
            }
            else
            {
                ldir = "v";
            }
        }
    };

}
