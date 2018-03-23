#ifndef ENGINE_DEATHEFFECT_H
#define ENGINE_DEATHEFFECT_H

#include "BaseNode.h"
#include "engine/xml/ReadXML.h"
#include "engine/Waves.h"
#include "sys/saveBox.h"
#include "engine/WorldInterface.h"
#include "Feature.h"
#include "engine/level/Level.h"
#include "engine/level/Road.h"
#include "engine/level/PointTimer.h"
#include "bezier/Bezier.h"
#include "engine/units/Unit.h"
#include "World.h"

//#include "animation/Hint.h"

namespace engine
{ 
     class DeathEffect : public BaseSprite
    {
	public:
		int i;// = 0;
		int j;//private var j:int;
        //private var _mask:Sprite;
        //private var _particles:Array;
        //private var _particleSprite:Class;
        //private var _particleCount:int;
        //private var _completeAnimation:Boolean = false;
        //private var _bitmapDataTarget:BitmapData;
        //private var _bitmapTarget:Bitmap;
        //private var _target:DisplayObjectContainer;
        float _windX,_speedY;
		World * world;

        DeathEffect(cocos2d::Node * param1, param2:Class = null, param3:int = 18, param4:Number = 3, param5:Number = 0) : void
        {
            this->_particles = [];
            this->world = Main.mainClass.worldClass;
            this->_target = param1;
            this->_particleSprite = param2;
            this->_particleCount = param3;
            this->_windX = param5;
            this->_speedY = 1.2;
            this->drawMask(this->_target, this->_target.width, this->_target.height);
            this->copyTarget(this->_target);
            this->_bitmapTarget.mask = this->_mask;
            TweenLite.to(this->_mask, param4, {scaleY:0, onComplete:this->completeAnimation});
            this->world.listOfClasses.push(this);
            return;
        }// end function

		public MovieClip  drawDefParticle()
        {
            var _loc_1:* = new MovieClip();
            _loc_1.graphics.beginFill(65348);
            _loc_1.graphics.moveTo(-5, -6);
            _loc_1.graphics.lineTo(2, -4);
            _loc_1.graphics.lineTo(6, 1);
            _loc_1.graphics.lineTo(6, 6);
            _loc_1.graphics.lineTo(0, 4);
            _loc_1.graphics.lineTo(-4, 1);
            _loc_1.graphics.lineTo(-5, -6);
            return _loc_1;
        }// end function

        public function copyTarget(param1:DisplayObjectContainer) : void
        {
            var _loc_2:* = param1.getBounds(param1);
            var _loc_3:* = new Matrix();
            _loc_3.identity();
            _loc_3.translate(-_loc_2.x, -_loc_2.y);
            _loc_3.scale(param1.scaleX, param1.scaleY);
            this->_bitmapDataTarget = new BitmapData(param1.width, param1.height, true, 0);
            this->_bitmapDataTarget.draw(param1, _loc_3);
            this->_bitmapTarget = new Bitmap(this->_bitmapDataTarget);
            this->_bitmapTarget.x = param1.x + _loc_2.x;
            this->_bitmapTarget.y = param1.y + _loc_2.y;
            this->world.addChild(this->_bitmapTarget);
            param1.visible = false;
            return;
        }// end function

        public function drawMask(param1:DisplayObjectContainer, param2:Number, param3:Number) : void
        {
            var _loc_4:* = param1.getBounds(param1);
            this->_mask = new Sprite();
            this->_mask.graphics.lineStyle(1);
            this->_mask.graphics.beginFill(65348);
            this->_mask.graphics.drawRect(0, 0, param2, param3);
            this->_mask.rotation = 180;
            this->_mask.x = param1.x + param2 + _loc_4.x;
            this->_mask.y = param1.y + param3 + _loc_4.y;
            this->world.addChild(this->_mask);
            return;
        }// end function

        public function addParticle() : void
        {
            var _loc_2:* = null;
            var _loc_3:* = false;
            var _loc_4:* = 0;
            var _loc_5:* = 0;
            var _loc_6:* = NaN;
            var _loc_7:* = NaN;
            var _loc_8:* = null;
            var _loc_9:* = 0;
            var _loc_10:* = NaN;
            var _loc_11:* = null;
            var _loc_12:* = NaN;
            var _loc_13:* = null;
            if (this->_completeAnimation)
            {
                return;
            }
            var _loc_1:* = 0;
            while (_loc_1 < this->_particleCount)
            {
                
                _loc_2 = new Array();
                _loc_3 = false;
                _loc_4 = this->_bitmapDataTarget.width;
                while (_loc_4 >= 0)
                {
                    
                    _loc_12 = this->_bitmapDataTarget.getPixel32((_loc_4 - 1), this->_target.height - this->_mask.height) >> 24 & 255;
                    if (_loc_12 != 0 && !_loc_3)
                    {
                        _loc_13 = new Object();
                        _loc_13.sP = _loc_4;
                        _loc_3 = true;
                    }
                    else if (_loc_12 == 0 && _loc_3)
                    {
                        _loc_13.fP = _loc_4;
                        _loc_3 = false;
                        _loc_2.push(_loc_13);
                    }
                    _loc_4 = _loc_4 - 1;
                }
                if (_loc_2.length == 0)
                {
                    return;
                }
                _loc_5 = int(Math.random() * _loc_2.length);
                _loc_6 = _loc_2[_loc_5].sP - Math.random() * Math.abs(_loc_2[_loc_5].fP - _loc_2[_loc_5].sP);
                _loc_7 = this->_target.height - this->_mask.height;
                _loc_8 = new ColorTransform();
                _loc_9 = this->_bitmapDataTarget.getPixel32(_loc_6, _loc_7);
                _loc_10 = Math.random() * this->_speedY + this->_speedY / 2;
                _loc_8.color = _loc_9;
                if (!this->_particleSprite)
                {
                    _loc_11 = this->drawDefParticle();
                }
                else
                {
                    _loc_11 = new this->_particleSprite();
                }
                this->world.addChild(_loc_11);
                _loc_11.x = this->_mask.x - this->_mask.width + _loc_6;
                _loc_11.y = this->_mask.y - this->_mask.height + 5;
                _loc_11.transform.colorTransform = _loc_8;
                _loc_11.rotation = Math.random() * 180;
                var _loc_14:* = Math.random() * 0.3 + 0.2;
                _loc_11.scaleY = Math.random() * 0.3 + 0.2;
                _loc_11.scaleX = _loc_14;
                this->_particles.push({t:Math.random() * 5, mc:_loc_11, speed:_loc_10});
                _loc_1++;
            }
            return;
        }// end function

        public function update() : void
        {
            var _loc_1:* = null;
            this->addParticle();
            this->i = 0;
            while (this->i < this->_particles.length)
            {
                
                _loc_1 = this->_particles[this->i];
                _loc_1.t = _loc_1.t + 0.19;
                _loc_1.mc.x = _loc_1.mc.x + (Math.sin(_loc_1.t) * 1.2 + this->_windX);
                _loc_1.mc.y = _loc_1.mc.y - _loc_1.speed;
                _loc_1.mc.alpha = _loc_1.mc.alpha - 0.02;
                var _loc_2:* = _loc_1.mc.scaleY - 0.015;
                _loc_1.mc.scaleY = _loc_1.mc.scaleY - 0.015;
                _loc_1.mc.scaleX = _loc_2;
                if (_loc_1.mc.alpha <= 0)
                {
                    this->world.removeChild(_loc_1.mc);
                    this->_particles[this->i] = null;
                    this->_particles.splice(this->i, 1);
                    var _loc_2:* = this;
                    var _loc_3:* = this->i - 1;
                    _loc_2.i = _loc_3;
                }
                var _loc_2:* = this;
                var _loc_3:* = this->i + 1;
                _loc_2.i = _loc_3;
            }
            if (this->_particles.length == 0 && this->_completeAnimation)
            {
                this->destruct();
            }
            return;
        }// end function

        public function completeAnimation() : void
        {
            this->_completeAnimation = true;
            return;
        }// end function

        public function destruct() : void
        {
            this->i = 0;
            while (this->i < this->_particles.length)
            {
                
                this->world.removeChild(this->_particles[this->i]);
                this->_particles[this->i] = null;
                this->_particles.splice(this->i, 1);
                var _loc_1:* = this;
                var _loc_2:* = this->i - 1;
                _loc_1.i = _loc_2;
                var _loc_1:* = this;
                var _loc_2:* = this->i + 1;
                _loc_1.i = _loc_2;
            }
            if (this->_mask)
            {
                this->world.removeChild(this->_mask);
            }
            this->_mask = null;
            if (this->_bitmapTarget)
            {
                this->world.removeChild(this->_bitmapTarget);
            }
            this->_bitmapTarget = null;
            this->j = 0;
            while (this->j < this->world.listOfClasses.length)
            {
                
                if (this->world.listOfClasses[this->j] == this)
                {
                    this->world.listOfClasses.splice(this->j, 1);
                    break;
                }
                var _loc_1:* = this;
                var _loc_2:* = this->j + 1;
                _loc_1.j = _loc_2;
            }
            return;
        }// end function

    }
}
#endif

