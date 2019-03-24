#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

cmake_minimum_required(VERSION 3.1)

set(APP_NAME brave)
project (${APP_NAME})
set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)

# record sources, headers, resources...
set(GAME_SOURCE)
set(GAME_HEADER)

set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/Resources"
    )
if(APPLE OR WINDOWS)
    cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
endif()
include_directories(
        Classes
	Classes/base
        ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)
# add cross-platforms source files and header files 


list(APPEND GAME_SOURCE
    Classes/AppDelegate.cpp
    Classes/base/BaseNode.cpp
    Classes/base/AudioUtil.cpp
    Classes/base/DbPreload.cpp
    Classes/base/Indexes.cpp
    Classes/base/JsonUtil.cpp
    Classes/base/mc.cpp
    Classes/base/MYPThread.cpp
    Classes/base/FileUtil.cpp
    Classes/bezier/Bezier.cpp
    Classes/bezier/FitLine.cpp
    Classes/bezier/Path.cpp
    Classes/bezier/PathSegment.cpp
    Classes/bezier/Pointer.cpp
    Classes/common/ArgsParse.cpp
    Classes/common/Decoding.cpp
    Classes/common/DirectoryInfo.cpp
    Classes/common/Encoding.cpp
    Classes/common/FTP.cpp
    Classes/common/Functions.cpp
    Classes/common/Log.cpp
    Classes/common/md5.cpp
    Classes/common/NetConstDefine.cpp
    Classes/common/MYSocket.cpp
    Classes/common/strCodeing.cpp
    Classes/common/MYString.cpp
    Classes/dragonbones/animation/Animation.cpp
    Classes/dragonbones/animation/AnimationState.cpp
    Classes/dragonbones/animation/BaseTimelineState.cpp
    Classes/dragonbones/animation/TimelineState.cpp
    Classes/dragonbones/animation/WorldClock.cpp
    Classes/dragonbones/armature/Armature.cpp
    Classes/dragonbones/armature/Bone.cpp
    Classes/dragonbones/armature/Constraint.cpp
    Classes/dragonbones/armature/DeformVertices.cpp
    Classes/dragonbones/armature/Slot.cpp
    Classes/dragonbones/armature/TransformObject.cpp
    Classes/dragonbones/cocos2dx/CCArmatureDisplay.cpp
    Classes/dragonbones/cocos2dx/CCFactory.cpp
    Classes/dragonbones/cocos2dx/CCSlot.cpp
    Classes/dragonbones/cocos2dx/CCTextureAtlasData.cpp
    Classes/dragonbones/core/BaseObject.cpp
    Classes/dragonbones/core/DragonBones.cpp
    Classes/dragonbones/event/EventObject.cpp
    Classes/dragonbones/factory/BaseFactory.cpp
    Classes/dragonbones/geom/Point.cpp
    Classes/dragonbones/geom/Transform.cpp
    Classes/dragonbones/model/AnimationConfig.cpp
    Classes/dragonbones/model/AnimationData.cpp
    Classes/dragonbones/model/ArmatureData.cpp
    Classes/dragonbones/model/BoundingBoxData.cpp
    Classes/dragonbones/model/CanvasData.cpp
    Classes/dragonbones/model/ConstraintData.cpp
    Classes/dragonbones/model/DisplayData.cpp
    Classes/dragonbones/model/DragonBonesData.cpp
    Classes/dragonbones/model/SkinData.cpp
    Classes/dragonbones/model/TextureAtlasData.cpp
    Classes/dragonbones/model/UserData.cpp
    Classes/dragonbones/parser/BinaryDataParser.cpp
    Classes/dragonbones/parser/DataParser.cpp
    Classes/dragonbones/parser/JSONDataParser.cpp
    Classes/engine/BonusMoney.cpp
    Classes/engine/bullets/Bullet.cpp
    Classes/engine/bullets/Bullet_1.cpp
    Classes/engine/bullets/Bullet_2.cpp
    Classes/engine/bullets/Bullet_3.cpp
    Classes/engine/bullets/Bullet_4.cpp
    Classes/engine/bullets/Bullet_5.cpp
    Classes/engine/bullets/Bullet_51.cpp
    Classes/engine/bullets/Bullet_6.cpp
    Classes/engine/bullets/Bullet_61.cpp
    Classes/engine/bullets/Bullet_7.cpp
    Classes/engine/bullets/Bullet_8.cpp
    Classes/engine/bullets/Bullet_81.cpp
    Classes/engine/CallDelay.cpp
    Classes/engine/casts/Air.cpp
    Classes/engine/casts/Cast.cpp
    Classes/engine/casts/Cast_1.cpp
    Classes/engine/casts/Cast_2.cpp
    Classes/engine/casts/Cast_3.cpp
    Classes/engine/casts/Golem.cpp
    Classes/engine/casts/Iceman.cpp
    Classes/engine/casts/Map.cpp
    Classes/engine/CastSphere.cpp
    Classes/engine/decoration/Decoration.cpp
    Classes/engine/Feature.cpp
    Classes/engine/GetSphere.cpp
    Classes/engine/InTimer.cpp
    Classes/engine/level/Level1_mc.cpp
    Classes/engine/level/RoadLevels_mc.cpp
    Classes/engine/MoneyAdd.cpp
    Classes/engine/SavedCastTime.cpp
    Classes/engine/towers/BuildTowerMenu.cpp
    Classes/engine/towers/Exchange.cpp
    Classes/engine/towers/Tower.cpp
    Classes/engine/towers/Tower1.cpp
    Classes/engine/towers/Tower2.cpp
    Classes/engine/towers/Tower3.cpp
    Classes/engine/towers/Tower4.cpp
    Classes/engine/towers/Tower5.cpp
    Classes/engine/towers/Tower6.cpp
    Classes/engine/towers/Tower7.cpp
    Classes/engine/towers/Tower8.cpp
    Classes/engine/towers/TowerMenu.cpp
    Classes/engine/towers/TowerMenu_mc.cpp
    Classes/engine/towers/UltraTowerMenu.cpp
    Classes/engine/units/Unit.cpp
    Classes/engine/units/Unit_1.cpp
    Classes/engine/units/Unit_10.cpp
    Classes/engine/units/Unit_11.cpp
    Classes/engine/units/Unit_12.cpp
    Classes/engine/units/Unit_13.cpp
    Classes/engine/units/Unit_14.cpp
    Classes/engine/units/Unit_15.cpp
    Classes/engine/units/Unit_16.cpp
    Classes/engine/units/Unit_17.cpp
    Classes/engine/units/Unit_18.cpp
    Classes/engine/units/Unit_19.cpp
    Classes/engine/units/Unit_2.cpp
    Classes/engine/units/Unit_20.cpp
    Classes/engine/units/Unit_21.cpp
    Classes/engine/units/Unit_22.cpp
    Classes/engine/units/Unit_23.cpp
    Classes/engine/units/Unit_24.cpp
    Classes/engine/units/Unit_25.cpp
    Classes/engine/units/Unit_26.cpp
    Classes/engine/units/Unit_27.cpp
    Classes/engine/units/Unit_28.cpp
    Classes/engine/units/Unit_29.cpp
    Classes/engine/units/Unit_3.cpp
    Classes/engine/units/Unit_30.cpp
    Classes/engine/units/Unit_31.cpp
    Classes/engine/units/Unit_32.cpp
    Classes/engine/units/Unit_33.cpp
    Classes/engine/units/Unit_34.cpp
    Classes/engine/units/Unit_4.cpp
    Classes/engine/units/Unit_5.cpp
    Classes/engine/units/Unit_6.cpp
    Classes/engine/units/Unit_7.cpp
    Classes/engine/units/Unit_8.cpp
    Classes/engine/units/Unit_9.cpp
    Classes/engine/units/Unit_mc.cpp
    Classes/engine/Waves.cpp
    Classes/engine/World.cpp
    Classes/engine/WorldInterface.cpp
    Classes/engine/WorldInterface_mc.cpp
    Classes/engine/xml/ReadXML.cpp
    Classes/engine/xml/XmlConfigParser.cpp
    Classes/MainClass.cpp
    Classes/sys/bezierBox.cpp
    Classes/sys/I18n.cpp
    Classes/sys/saveBox.cpp
    Classes/sys/preloadSound.cpp
    Classes/screens/FastPause.cpp
    Classes/screens/MiddleScreen.cpp
    Classes/screens/StartMenu.cpp
    Classes/screens/Achievements.cpp
    Classes/screens/Defeat.cpp
    Classes/screens/DifficultyLevel.cpp
    Classes/screens/LevelsMenu.cpp
    Classes/screens/OpenLevel.cpp
    Classes/screens/Upgrades.cpp
    Classes/screens/Victory.cpp
    Classes/screens/PreVictory.cpp
    Classes/screens/StartLogo.cpp
    Classes/screens/Screen.cpp
    Classes/screens/PauseMenu.cpp
)
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
#     Classes/HelloWorldScene.h
     )
if(ANDROID)
    # change APP_NAME to the share library name for Android, it's value depend on AndroidManifest.xml
    #set(APP_NAME MyGame)
    list(APPEND GAME_SOURCE
         proj.android/jni/main.cpp
         )
elseif(LINUX)
    list(APPEND GAME_SOURCE
         proj.linux/main.cpp
         )
elseif(WINDOWS)
    list(APPEND GAME_HEADER
         proj.win32/main.h
         proj.win32/resource.h
         )
    list(APPEND GAME_SOURCE
         proj.win32/main.cpp
         proj.win32/game.rc
         ${common_res_files}
         )
elseif(APPLE)
    if(IOS)
        list(APPEND GAME_HEADER
             proj.ios_mac/ios/AppController.h
             proj.ios_mac/ios/RootViewController.h
             )
        set(APP_UI_RES
            proj.ios_mac/ios/LaunchScreen.storyboard
            proj.ios_mac/ios/LaunchScreenBackground.png
            proj.ios_mac/ios/Images.xcassets
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/ios/main.m
             proj.ios_mac/ios/AppController.mm
             proj.ios_mac/ios/RootViewController.mm
             proj.ios_mac/ios/Prefix.pch
             ${APP_UI_RES}
             )
    elseif(MACOSX)
        set(APP_UI_RES
            proj.ios_mac/mac/Icon.icns
            proj.ios_mac/mac/Info.plist
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/mac/main.cpp
             proj.ios_mac/mac/Prefix.pch
             ${APP_UI_RES}
             )
    endif()
    list(APPEND GAME_SOURCE ${common_res_files})
endif()

# mark app complie info and libs info
set(APP_SRC
    ${GAME_SOURCE}
    ${GAME_HEADER}
    )
# mark app complie info and libs info
set(all_code_files
    ${GAME_HEADER}
    ${GAME_SOURCE}
    )
# 3.17.0
#cocos_build_app(${APP_NAME}    APP_SRC "${APP_SRC}"
#                DEPEND_COMMON_LIBS "cocos2d"
#                DEPEND_ANDROID_LIBS "cocos2d_android"
#                )

if(NOT ANDROID)
    add_executable(${APP_NAME} ${all_code_files})
else()
    add_library(${APP_NAME} SHARED ${all_code_files})
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
endif()

target_link_libraries(${APP_NAME} cocos2d)
target_include_directories(${APP_NAME}
        PRIVATE Classes
        PRIVATE ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

# mark app resources
setup_cocos_app_config(${APP_NAME})

if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
                              MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/mac/Info.plist"
                              )
    elseif(IOS)
        cocos_pak_xcode(${APP_NAME} INFO_PLIST "iOSBundleInfo.plist.in")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
    endif()
elseif(WINDOWS)
    #cocos_copy_target_dll(${APP_NAME} COPY_TO ${APP_BIN_DIR})
    cocos_copy_target_dll(${APP_NAME} COPY_TO ${APP_RES_DIR}/..)
endif()

if(LINUX OR WINDOWS)
    cocos_copy_target_res(${APP_NAME} COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
    #cocos_copy_res(COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif() 


