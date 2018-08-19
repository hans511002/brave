LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)


LOCAL_MODULE := brave_shared

LOCAL_MODULE_FILENAME := libbrave

LOCAL_ARM_MODE := arm

#
LOCAL_SRC_FILES := main.cpp \
../../../Classes/AppDelegate.cpp \
   ../../../Classes/base/BaseNode.cpp                                             \
   ../../../Classes/base/DbPreload.cpp                                            \
   ../../../Classes/base/Indexes.cpp                                              \
   ../../../Classes/base/JsonUtil.cpp                                             \
   ../../../Classes/base/mc.cpp                                                   \
   ../../../Classes/base/MYPThread.cpp                                              \
   ../../../Classes/base/FileUtil.cpp                                            \
   ../../../Classes/bezier/Bezier.cpp                                             \
   ../../../Classes/bezier/FitLine.cpp                                            \
   ../../../Classes/bezier/Path.cpp                                               \
   ../../../Classes/bezier/PathSegment.cpp                                        \
   ../../../Classes/bezier/Pointer.cpp                                            \
   ../../../Classes/common/ArgsParse.cpp                                          \
   ../../../Classes/common/Decoding.cpp                                           \
   ../../../Classes/common/DirectoryInfo.cpp                                      \
   ../../../Classes/common/Encoding.cpp                                           \
   ../../../Classes/common/FTP.cpp                                                \
   ../../../Classes/common/Functions.cpp                                          \
   ../../../Classes/common/Log.cpp                                                \
   ../../../Classes/common/md5.cpp                                                \
   ../../../Classes/common/NetConstDefine.cpp                                     \
   ../../../Classes/common/MYSocket.cpp                                             \
   ../../../Classes/common/strCodeing.cpp                                         \
   ../../../Classes/common/MYString.cpp                                             \
   ../../../Classes/dragonbones/animation/Animation.cpp                           \
   ../../../Classes/dragonbones/animation/AnimationState.cpp                      \
   ../../../Classes/dragonbones/animation/BaseTimelineState.cpp                   \
   ../../../Classes/dragonbones/animation/TimelineState.cpp                       \
   ../../../Classes/dragonbones/animation/WorldClock.cpp                          \
   ../../../Classes/dragonbones/armature/Armature.cpp                             \
   ../../../Classes/dragonbones/armature/Bone.cpp                                 \
   ../../../Classes/dragonbones/armature/Constraint.cpp                           \
   ../../../Classes/dragonbones/armature/DeformVertices.cpp                       \
   ../../../Classes/dragonbones/armature/Slot.cpp                                 \
   ../../../Classes/dragonbones/armature/TransformObject.cpp                      \
   ../../../Classes/dragonbones/cocos2dx/CCArmatureDisplay.cpp                    \
   ../../../Classes/dragonbones/cocos2dx/CCFactory.cpp                            \
   ../../../Classes/dragonbones/cocos2dx/CCSlot.cpp                               \
   ../../../Classes/dragonbones/cocos2dx/CCTextureAtlasData.cpp                   \
   ../../../Classes/dragonbones/core/BaseObject.cpp                               \
   ../../../Classes/dragonbones/core/DragonBones.cpp                              \
   ../../../Classes/dragonbones/event/EventObject.cpp                             \
   ../../../Classes/dragonbones/factory/BaseFactory.cpp                           \
   ../../../Classes/dragonbones/geom/Point.cpp                                    \
   ../../../Classes/dragonbones/geom/Transform.cpp                                \
   ../../../Classes/dragonbones/model/AnimationConfig.cpp                         \
   ../../../Classes/dragonbones/model/AnimationData.cpp                           \
   ../../../Classes/dragonbones/model/ArmatureData.cpp                            \
   ../../../Classes/dragonbones/model/BoundingBoxData.cpp                         \
   ../../../Classes/dragonbones/model/CanvasData.cpp                              \
   ../../../Classes/dragonbones/model/ConstraintData.cpp                          \
   ../../../Classes/dragonbones/model/DisplayData.cpp                             \
   ../../../Classes/dragonbones/model/DragonBonesData.cpp                         \
   ../../../Classes/dragonbones/model/SkinData.cpp                                \
   ../../../Classes/dragonbones/model/TextureAtlasData.cpp                        \
   ../../../Classes/dragonbones/model/UserData.cpp                                \
   ../../../Classes/dragonbones/parser/BinaryDataParser.cpp                       \
   ../../../Classes/dragonbones/parser/DataParser.cpp                             \
   ../../../Classes/dragonbones/parser/JSONDataParser.cpp                         \
   ../../../Classes/engine/BonusMoney.cpp                                         \
   ../../../Classes/engine/bullets/Bullet.cpp                                     \
   ../../../Classes/engine/bullets/Bullet_1.cpp                                   \
   ../../../Classes/engine/bullets/Bullet_2.cpp                                   \
   ../../../Classes/engine/bullets/Bullet_3.cpp                                   \
   ../../../Classes/engine/bullets/Bullet_4.cpp                                   \
   ../../../Classes/engine/bullets/Bullet_5.cpp                                   \
   ../../../Classes/engine/bullets/Bullet_51.cpp                                  \
   ../../../Classes/engine/bullets/Bullet_6.cpp                                   \
   ../../../Classes/engine/bullets/Bullet_61.cpp                                  \
   ../../../Classes/engine/bullets/Bullet_7.cpp                                   \
   ../../../Classes/engine/bullets/Bullet_8.cpp                                   \
   ../../../Classes/engine/bullets/Bullet_81.cpp                                  \
   ../../../Classes/engine/CallDelay.cpp                                          \
   ../../../Classes/engine/casts/Air.cpp                                          \
   ../../../Classes/engine/casts/Cast.cpp                                         \
   ../../../Classes/engine/casts/Cast_1.cpp                                       \
   ../../../Classes/engine/casts/Cast_2.cpp                                       \
   ../../../Classes/engine/casts/Cast_3.cpp                                       \
   ../../../Classes/engine/casts/Golem.cpp                                        \
   ../../../Classes/engine/casts/Iceman.cpp                                       \
   ../../../Classes/engine/casts/Map.cpp                                          \
   ../../../Classes/engine/CastSphere.cpp                                         \
   ../../../Classes/engine/decoration/Decoration.cpp                              \
   ../../../Classes/engine/Feature.cpp                                            \
   ../../../Classes/engine/GetSphere.cpp                                          \
   ../../../Classes/engine/InTimer.cpp                                            \
   ../../../Classes/engine/level/Level1_mc.cpp                                    \
   ../../../Classes/engine/level/RoadLevels_mc.cpp                                \
   ../../../Classes/engine/MoneyAdd.cpp                                           \
   ../../../Classes/engine/SavedCastTime.cpp                                      \
   ../../../Classes/engine/towers/BuildTowerMenu.cpp                              \
   ../../../Classes/engine/towers/Exchange.cpp                                    \
   ../../../Classes/engine/towers/Tower.cpp                                       \
   ../../../Classes/engine/towers/Tower1.cpp                                      \
   ../../../Classes/engine/towers/Tower2.cpp                                      \
   ../../../Classes/engine/towers/Tower3.cpp                                      \
   ../../../Classes/engine/towers/Tower4.cpp                                      \
   ../../../Classes/engine/towers/Tower5.cpp                                      \
   ../../../Classes/engine/towers/Tower6.cpp                                      \
   ../../../Classes/engine/towers/Tower7.cpp                                      \
   ../../../Classes/engine/towers/Tower8.cpp                                      \
   ../../../Classes/engine/towers/TowerMenu.cpp                                   \
   ../../../Classes/engine/towers/TowerMenu_mc.cpp                                \
   ../../../Classes/engine/towers/UltraTowerMenu.cpp                              \
   ../../../Classes/engine/units/Unit.cpp                                         \
   ../../../Classes/engine/units/Unit_1.cpp                                       \
   ../../../Classes/engine/units/Unit_10.cpp                                      \
   ../../../Classes/engine/units/Unit_11.cpp                                      \
   ../../../Classes/engine/units/Unit_12.cpp                                      \
   ../../../Classes/engine/units/Unit_13.cpp                                      \
   ../../../Classes/engine/units/Unit_14.cpp                                      \
   ../../../Classes/engine/units/Unit_15.cpp                                      \
   ../../../Classes/engine/units/Unit_16.cpp                                      \
   ../../../Classes/engine/units/Unit_17.cpp                                      \
   ../../../Classes/engine/units/Unit_18.cpp                                      \
   ../../../Classes/engine/units/Unit_19.cpp                                      \
   ../../../Classes/engine/units/Unit_2.cpp                                       \
   ../../../Classes/engine/units/Unit_20.cpp                                      \
   ../../../Classes/engine/units/Unit_21.cpp                                      \
   ../../../Classes/engine/units/Unit_22.cpp                                      \
   ../../../Classes/engine/units/Unit_23.cpp                                      \
   ../../../Classes/engine/units/Unit_24.cpp                                      \
   ../../../Classes/engine/units/Unit_25.cpp                                      \
   ../../../Classes/engine/units/Unit_26.cpp                                      \
   ../../../Classes/engine/units/Unit_27.cpp                                      \
   ../../../Classes/engine/units/Unit_28.cpp                                      \
   ../../../Classes/engine/units/Unit_29.cpp                                      \
   ../../../Classes/engine/units/Unit_3.cpp                                       \
   ../../../Classes/engine/units/Unit_30.cpp                                      \
   ../../../Classes/engine/units/Unit_31.cpp                                      \
   ../../../Classes/engine/units/Unit_32.cpp                                      \
   ../../../Classes/engine/units/Unit_33.cpp                                      \
   ../../../Classes/engine/units/Unit_34.cpp                                      \
   ../../../Classes/engine/units/Unit_4.cpp                                       \
   ../../../Classes/engine/units/Unit_5.cpp                                       \
   ../../../Classes/engine/units/Unit_6.cpp                                       \
   ../../../Classes/engine/units/Unit_7.cpp                                       \
   ../../../Classes/engine/units/Unit_8.cpp                                       \
   ../../../Classes/engine/units/Unit_9.cpp                                       \
   ../../../Classes/engine/units/Unit_mc.cpp                                      \
   ../../../Classes/engine/Waves.cpp                                              \
   ../../../Classes/engine/World.cpp                                              \
   ../../../Classes/engine/WorldInterface.cpp                                     \
   ../../../Classes/engine/WorldInterface_mc.cpp                                  \
   ../../../Classes/engine/xml/ReadXML.cpp                                        \
   ../../../Classes/engine/xml/XmlConfigParser.cpp                                \
   ../../../Classes/MainClass.cpp                                                 \
   ../../../Classes/screens/FastPause.cpp                                         \
   ../../../Classes/screens/MiddleScreen.cpp                                      \
   ../../../Classes/sys/bezierBox.cpp                                             \
   ../../../Classes/sys/I18n.cpp                                                  \
   ../../../Classes/sys/saveBox.cpp        

#   ../../../Classes/screens/StartMenu.cpp                                         \
#   ../../../Classes/screens/Credits.cpp                                           \
#   ../../../Classes/screens/Achievements.cpp                                      \
#   ../../../Classes/screens/Defeat.cpp                                            \
#   ../../../Classes/screens/DifficultyLevel.cpp                                   \
#   ../../../Classes/screens/LevelsMenu.cpp                                        \
#   ../../../Classes/screens/OpenLevel.cpp                                         \
#   ../../../Classes/screens/Upgrades.cpp                                          \
#   ../../../Classes/screens/PauseMenu.cpp                                         \


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../cocos2d $(LOCAL_PATH)/../../../Classes $(LOCAL_PATH)/../../../Classes/base

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
