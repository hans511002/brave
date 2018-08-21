LOCAL_PATH := $(call my-dir)
LOCAL_PATH   +=/../../cocos2d/cocos/

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dx_internal_static

LOCAL_MODULE_FILENAME := libcocos2dxinternal

LOCAL_ARM_MODE := arm

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
MATHNEONFILE := $(LOCAL_PATH)/math/MathUtil.cpp.neon
else
MATHNEONFILE := $(LOCAL_PATH)/math/MathUtil.cpp
endif

LOCAL_SRC_FILES := \
$(LOCAL_PATH)/cocos2d.cpp \
$(LOCAL_PATH)/2d/CCAction.cpp \
$(LOCAL_PATH)/2d/CCActionCamera.cpp \
$(LOCAL_PATH)/2d/CCActionCatmullRom.cpp \
$(LOCAL_PATH)/2d/CCActionEase.cpp \
$(LOCAL_PATH)/2d/CCActionGrid.cpp \
$(LOCAL_PATH)/2d/CCActionGrid3D.cpp \
$(LOCAL_PATH)/2d/CCActionInstant.cpp \
$(LOCAL_PATH)/2d/CCActionInterval.cpp \
$(LOCAL_PATH)/2d/CCActionManager.cpp \
$(LOCAL_PATH)/2d/CCActionPageTurn3D.cpp \
$(LOCAL_PATH)/2d/CCActionProgressTimer.cpp \
$(LOCAL_PATH)/2d/CCActionTiledGrid.cpp \
$(LOCAL_PATH)/2d/CCActionTween.cpp \
$(LOCAL_PATH)/2d/CCAnimation.cpp \
$(LOCAL_PATH)/2d/CCAnimationCache.cpp \
$(LOCAL_PATH)/2d/CCAtlasNode.cpp \
$(LOCAL_PATH)/2d/CCCamera.cpp \
$(LOCAL_PATH)/2d/CCCameraBackgroundBrush.cpp \
$(LOCAL_PATH)/2d/CCClippingNode.cpp \
$(LOCAL_PATH)/2d/CCClippingRectangleNode.cpp \
$(LOCAL_PATH)/2d/CCComponent.cpp \
$(LOCAL_PATH)/2d/CCComponentContainer.cpp \
$(LOCAL_PATH)/2d/CCDrawNode.cpp \
$(LOCAL_PATH)/2d/CCDrawingPrimitives.cpp \
$(LOCAL_PATH)/2d/CCFastTMXLayer.cpp \
$(LOCAL_PATH)/2d/CCFastTMXTiledMap.cpp \
$(LOCAL_PATH)/2d/CCFont.cpp \
$(LOCAL_PATH)/2d/CCFontAtlas.cpp \
$(LOCAL_PATH)/2d/CCFontAtlasCache.cpp \
$(LOCAL_PATH)/2d/CCFontCharMap.cpp \
$(LOCAL_PATH)/2d/CCFontFNT.cpp \
$(LOCAL_PATH)/2d/CCFontFreeType.cpp \
$(LOCAL_PATH)/2d/CCGLBufferedNode.cpp \
$(LOCAL_PATH)/2d/CCGrabber.cpp \
$(LOCAL_PATH)/2d/CCGrid.cpp \
$(LOCAL_PATH)/2d/CCLabel.cpp \
$(LOCAL_PATH)/2d/CCLabelAtlas.cpp \
$(LOCAL_PATH)/2d/CCLabelBMFont.cpp \
$(LOCAL_PATH)/2d/CCLabelTTF.cpp \
$(LOCAL_PATH)/2d/CCLabelTextFormatter.cpp \
$(LOCAL_PATH)/2d/CCLayer.cpp \
$(LOCAL_PATH)/2d/CCLight.cpp \
$(LOCAL_PATH)/2d/CCMenu.cpp \
$(LOCAL_PATH)/2d/CCMenuItem.cpp \
$(LOCAL_PATH)/2d/CCMotionStreak.cpp \
$(LOCAL_PATH)/2d/CCNode.cpp \
$(LOCAL_PATH)/2d/CCNodeGrid.cpp \
$(LOCAL_PATH)/2d/CCParallaxNode.cpp \
$(LOCAL_PATH)/2d/CCParticleBatchNode.cpp \
$(LOCAL_PATH)/2d/CCParticleExamples.cpp \
$(LOCAL_PATH)/2d/CCParticleSystem.cpp \
$(LOCAL_PATH)/2d/CCParticleSystemQuad.cpp \
$(LOCAL_PATH)/2d/CCProgressTimer.cpp \
$(LOCAL_PATH)/2d/CCProtectedNode.cpp \
$(LOCAL_PATH)/2d/CCRenderTexture.cpp \
$(LOCAL_PATH)/2d/CCScene.cpp \
$(LOCAL_PATH)/2d/CCSprite.cpp \
$(LOCAL_PATH)/2d/CCSpriteBatchNode.cpp \
$(LOCAL_PATH)/2d/CCSpriteFrame.cpp \
$(LOCAL_PATH)/2d/CCSpriteFrameCache.cpp \
$(LOCAL_PATH)/2d/CCTMXLayer.cpp \
$(LOCAL_PATH)/2d/CCTMXObjectGroup.cpp \
$(LOCAL_PATH)/2d/CCTMXTiledMap.cpp \
$(LOCAL_PATH)/2d/CCTMXXMLParser.cpp \
$(LOCAL_PATH)/2d/CCTextFieldTTF.cpp \
$(LOCAL_PATH)/2d/CCTileMapAtlas.cpp \
$(LOCAL_PATH)/2d/CCTransition.cpp \
$(LOCAL_PATH)/2d/CCTransitionPageTurn.cpp \
$(LOCAL_PATH)/2d/CCTransitionProgress.cpp \
$(LOCAL_PATH)/2d/CCTweenFunction.cpp \
$(LOCAL_PATH)/2d/CCAutoPolygon.cpp \
$(LOCAL_PATH)/3d/CCFrustum.cpp \
$(LOCAL_PATH)/3d/CCPlane.cpp \
$(LOCAL_PATH)/platform/CCFileUtils.cpp \
$(LOCAL_PATH)/platform/CCGLView.cpp \
$(LOCAL_PATH)/platform/CCImage.cpp \
$(LOCAL_PATH)/platform/CCSAXParser.cpp \
$(LOCAL_PATH)/platform/CCThread.cpp \
$(LOCAL_PATH)/$(MATHNEONFILE) \
$(LOCAL_PATH)/math/CCAffineTransform.cpp \
$(LOCAL_PATH)/math/CCGeometry.cpp \
$(LOCAL_PATH)/math/CCVertex.cpp \
$(LOCAL_PATH)/math/Mat4.cpp \
$(LOCAL_PATH)/math/Quaternion.cpp \
$(LOCAL_PATH)/math/TransformUtils.cpp \
$(LOCAL_PATH)/math/Vec2.cpp \
$(LOCAL_PATH)/math/Vec3.cpp \
$(LOCAL_PATH)/math/Vec4.cpp \
$(LOCAL_PATH)/base/CCNinePatchImageParser.cpp \
$(LOCAL_PATH)/base/CCStencilStateManager.cpp \
$(LOCAL_PATH)/base/CCAsyncTaskPool.cpp \
$(LOCAL_PATH)/base/CCAutoreleasePool.cpp \
$(LOCAL_PATH)/base/CCConfiguration.cpp \
$(LOCAL_PATH)/base/CCConsole.cpp \
$(LOCAL_PATH)/base/CCController-android.cpp \
$(LOCAL_PATH)/base/CCController.cpp \
$(LOCAL_PATH)/base/CCData.cpp \
$(LOCAL_PATH)/base/CCDataVisitor.cpp \
$(LOCAL_PATH)/base/CCDirector.cpp \
$(LOCAL_PATH)/base/CCEvent.cpp \
$(LOCAL_PATH)/base/CCEventAcceleration.cpp \
$(LOCAL_PATH)/base/CCEventController.cpp \
$(LOCAL_PATH)/base/CCEventCustom.cpp \
$(LOCAL_PATH)/base/CCEventDispatcher.cpp \
$(LOCAL_PATH)/base/CCEventFocus.cpp \
$(LOCAL_PATH)/base/CCEventKeyboard.cpp \
$(LOCAL_PATH)/base/CCEventListener.cpp \
$(LOCAL_PATH)/base/CCEventListenerAcceleration.cpp \
$(LOCAL_PATH)/base/CCEventListenerController.cpp \
$(LOCAL_PATH)/base/CCEventListenerCustom.cpp \
$(LOCAL_PATH)/base/CCEventListenerFocus.cpp \
$(LOCAL_PATH)/base/CCEventListenerKeyboard.cpp \
$(LOCAL_PATH)/base/CCEventListenerMouse.cpp \
$(LOCAL_PATH)/base/CCEventListenerTouch.cpp \
$(LOCAL_PATH)/base/CCEventMouse.cpp \
$(LOCAL_PATH)/base/CCEventTouch.cpp \
$(LOCAL_PATH)/base/CCIMEDispatcher.cpp \
$(LOCAL_PATH)/base/CCNS.cpp \
$(LOCAL_PATH)/base/CCProfiling.cpp \
$(LOCAL_PATH)/base/CCProperties.cpp \
$(LOCAL_PATH)/base/CCRef.cpp \
$(LOCAL_PATH)/base/CCScheduler.cpp \
$(LOCAL_PATH)/base/CCScriptSupport.cpp \
$(LOCAL_PATH)/base/CCTouch.cpp \
$(LOCAL_PATH)/base/CCUserDefault-android.cpp \
$(LOCAL_PATH)/base/CCUserDefault.cpp \
$(LOCAL_PATH)/base/CCValue.cpp \
$(LOCAL_PATH)/base/ObjectFactory.cpp \
$(LOCAL_PATH)/base/TGAlib.cpp \
$(LOCAL_PATH)/base/ZipUtils.cpp \
$(LOCAL_PATH)/base/allocator/CCAllocatorDiagnostics.cpp \
$(LOCAL_PATH)/base/allocator/CCAllocatorGlobal.cpp \
$(LOCAL_PATH)/base/allocator/CCAllocatorGlobalNewDelete.cpp \
$(LOCAL_PATH)/base/atitc.cpp \
$(LOCAL_PATH)/base/base64.cpp \
$(LOCAL_PATH)/base/ccCArray.cpp \
$(LOCAL_PATH)/base/ccFPSImages.c \
$(LOCAL_PATH)/base/ccRandom.cpp \
$(LOCAL_PATH)/base/ccTypes.cpp \
$(LOCAL_PATH)/base/ccUTF8.cpp \
$(LOCAL_PATH)/base/ccUtils.cpp \
$(LOCAL_PATH)/base/etc1.cpp \
$(LOCAL_PATH)/base/pvr.cpp \
$(LOCAL_PATH)/base/s3tc.cpp \
$(LOCAL_PATH)/renderer/CCBatchCommand.cpp \
$(LOCAL_PATH)/renderer/CCCustomCommand.cpp \
$(LOCAL_PATH)/renderer/CCGLProgram.cpp \
$(LOCAL_PATH)/renderer/CCGLProgramCache.cpp \
$(LOCAL_PATH)/renderer/CCGLProgramState.cpp \
$(LOCAL_PATH)/renderer/CCGLProgramStateCache.cpp \
$(LOCAL_PATH)/renderer/CCGroupCommand.cpp \
$(LOCAL_PATH)/renderer/CCMaterial.cpp \
$(LOCAL_PATH)/renderer/CCMeshCommand.cpp \
$(LOCAL_PATH)/renderer/CCPass.cpp \
$(LOCAL_PATH)/renderer/CCPrimitive.cpp \
$(LOCAL_PATH)/renderer/CCPrimitiveCommand.cpp \
$(LOCAL_PATH)/renderer/CCQuadCommand.cpp \
$(LOCAL_PATH)/renderer/CCRenderCommand.cpp \
$(LOCAL_PATH)/renderer/CCRenderState.cpp \
$(LOCAL_PATH)/renderer/CCRenderer.cpp \
$(LOCAL_PATH)/renderer/CCTechnique.cpp \
$(LOCAL_PATH)/renderer/CCTexture2D.cpp \
$(LOCAL_PATH)/renderer/CCTextureAtlas.cpp \
$(LOCAL_PATH)/renderer/CCTextureCache.cpp \
$(LOCAL_PATH)/renderer/CCTextureCube.cpp \
$(LOCAL_PATH)/renderer/CCTrianglesCommand.cpp \
$(LOCAL_PATH)/renderer/CCVertexAttribBinding.cpp \
$(LOCAL_PATH)/renderer/CCVertexIndexBuffer.cpp \
$(LOCAL_PATH)/renderer/CCVertexIndexData.cpp \
$(LOCAL_PATH)/renderer/ccGLStateCache.cpp \
$(LOCAL_PATH)/renderer/CCFrameBuffer.cpp \
$(LOCAL_PATH)/renderer/ccShaders.cpp \
$(LOCAL_PATH)/vr/CCVRDistortion.cpp \
$(LOCAL_PATH)/vr/CCVRDistortionMesh.cpp \
$(LOCAL_PATH)/vr/CCVRGenericRenderer.cpp \
$(LOCAL_PATH)/vr/CCVRGenericHeadTracker.cpp \
$(LOCAL_PATH)/deprecated/CCArray.cpp \
$(LOCAL_PATH)/deprecated/CCDeprecated.cpp \
$(LOCAL_PATH)/deprecated/CCDictionary.cpp \
$(LOCAL_PATH)/deprecated/CCNotificationCenter.cpp \
$(LOCAL_PATH)/deprecated/CCSet.cpp \
$(LOCAL_PATH)/deprecated/CCString.cpp \
$(LOCAL_PATH)/physics/CCPhysicsBody.cpp \
$(LOCAL_PATH)/physics/CCPhysicsContact.cpp \
$(LOCAL_PATH)/physics/CCPhysicsJoint.cpp \
$(LOCAL_PATH)/physics/CCPhysicsShape.cpp \
$(LOCAL_PATH)/physics/CCPhysicsWorld.cpp \
$(LOCAL_PATH)/physics3d/CCPhysics3D.cpp \
$(LOCAL_PATH)/physics3d/CCPhysics3DWorld.cpp \
$(LOCAL_PATH)/physics3d/CCPhysics3DComponent.cpp \
$(LOCAL_PATH)/physics3d/CCPhysics3DDebugDrawer.cpp \
$(LOCAL_PATH)/physics3d/CCPhysics3DObject.cpp \
$(LOCAL_PATH)/physics3d/CCPhysics3DShape.cpp \
$(LOCAL_PATH)/physics3d/CCPhysicsSprite3D.cpp \
$(LOCAL_PATH)/physics3d/CCPhysics3DConstraint.cpp \
$(LOCAL_PATH)/navmesh/CCNavMesh.cpp \
$(LOCAL_PATH)/navmesh/CCNavMeshAgent.cpp \
$(LOCAL_PATH)/navmesh/CCNavMeshDebugDraw.cpp \
$(LOCAL_PATH)/navmesh/CCNavMeshObstacle.cpp \
$(LOCAL_PATH)/navmesh/CCNavMeshUtils.cpp \
$(LOCAL_PATH)/../external/ConvertUTF/ConvertUTFWrapper.cpp \
$(LOCAL_PATH)/../external/ConvertUTF/ConvertUTF.c \
$(LOCAL_PATH)/../external/md5/md5.c \
$(LOCAL_PATH)/../external/tinyxml2/tinyxml2.cpp \
$(LOCAL_PATH)/../external/unzip/ioapi_mem.cpp \
$(LOCAL_PATH)/../external/unzip/ioapi.cpp \
$(LOCAL_PATH)/../external/unzip/unzip.cpp \
$(LOCAL_PATH)/../external/edtaa3func/edtaa3func.cpp \
$(LOCAL_PATH)/../external/xxhash/xxhash.c \
$(LOCAL_PATH)/../external/poly2tri/common/shapes.cc \
$(LOCAL_PATH)/../external/poly2tri/sweep/advancing_front.cc \
$(LOCAL_PATH)/../external/poly2tri/sweep/cdt.cc \
$(LOCAL_PATH)/../external/poly2tri/sweep/sweep_context.cc \
$(LOCAL_PATH)/../external/poly2tri/sweep/sweep.cc \
$(LOCAL_PATH)/../external/clipper/clipper.cpp


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/. \
                    $(LOCAL_PATH)/.. \
                    $(LOCAL_PATH)/../external \
                    $(LOCAL_PATH)/../external/tinyxml2 \
                    $(LOCAL_PATH)/../external/unzip \
                    $(LOCAL_PATH)/../external/chipmunk/include/chipmunk \
                    $(LOCAL_PATH)/../external/xxhash \
                    $(LOCAL_PATH)/../external/nslog \
                    $(LOCAL_PATH)/../external/poly2tri \
                    $(LOCAL_PATH)/../external/poly2tri/common \
                    $(LOCAL_PATH)/../external/poly2tri/sweep \
                    $(LOCAL_PATH)/../external/clipper

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/../external \
                    $(LOCAL_PATH)/../external/tinyxml2 \
                    $(LOCAL_PATH)/../external/unzip \
                    $(LOCAL_PATH)/../external/chipmunk/include/chipmunk \
                    $(LOCAL_PATH)/../external/edtaa3func \
                    $(LOCAL_PATH)/../external/xxhash \
                    $(LOCAL_PATH)/../external/ConvertUTF \
                    $(LOCAL_PATH)/../external/nslog \
                    $(LOCAL_PATH)/../external/poly2tri \
                    $(LOCAL_PATH)/../external/poly2tri/common \
                    $(LOCAL_PATH)/../external/poly2tri/sweep \
                    $(LOCAL_PATH)/../external/clipper

LOCAL_EXPORT_LDLIBS := -lGLESv2 \
                       -llog \
                       -landroid

LOCAL_STATIC_LIBRARIES := cocos_freetype2_static
LOCAL_STATIC_LIBRARIES += cocos_png_static
LOCAL_STATIC_LIBRARIES += cocos_jpeg_static
LOCAL_STATIC_LIBRARIES += cocos_tiff_static
LOCAL_STATIC_LIBRARIES += cocos_webp_static
LOCAL_STATIC_LIBRARIES += cocos_chipmunk_static
LOCAL_STATIC_LIBRARIES += cocos_zlib_static
LOCAL_STATIC_LIBRARIES += cocos_ssl_static
LOCAL_STATIC_LIBRARIES += recast_static
LOCAL_STATIC_LIBRARIES += bullet_static

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dxandroid_static
LOCAL_WHOLE_STATIC_LIBRARIES += cpufeatures

# define the macro to compile through support/zip_support/ioapi.c
LOCAL_CFLAGS   :=  -DUSE_FILE32API
LOCAL_CFLAGS   +=  -fexceptions

# Issues #9968
#ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
#    LOCAL_CFLAGS += -DHAVE_NEON=1
#endif

LOCAL_CPPFLAGS := -Wno-deprecated-declarations
LOCAL_EXPORT_CFLAGS   := -DUSE_FILE32API
LOCAL_EXPORT_CPPFLAGS := -Wno-deprecated-declarations

include $(BUILD_STATIC_LIBRARY)

#==============================================================

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dx_static
LOCAL_MODULE_FILENAME := libcocos2d

#LOCAL_STATIC_LIBRARIES := cocostudio_static
#LOCAL_STATIC_LIBRARIES += cocosbuilder_static
#LOCAL_STATIC_LIBRARIES += cocos3d_static
#LOCAL_STATIC_LIBRARIES += spine_static
LOCAL_STATIC_LIBRARIES += cocos_network_static
LOCAL_STATIC_LIBRARIES += audioengine_static

include $(BUILD_STATIC_LIBRARY)
#==============================================================
$(call import-module,android/cpufeatures)
$(call import-module,freetype2/prebuilt/android)
$(call import-module,platform/android)
$(call import-module,png/prebuilt/android)
$(call import-module,zlib/prebuilt/android)
$(call import-module,jpeg/prebuilt/android)
$(call import-module,tiff/prebuilt/android)
$(call import-module,webp/prebuilt/android)
$(call import-module,chipmunk/prebuilt/android)
#$(call import-module,$(LOCAL_PATH)/3d)
$(call import-module,$(LOCAL_PATH)/audio/android)
#$(call import-module,$(LOCAL_PATH)/editor-support/cocosbuilder)
#$(call import-module,$(LOCAL_PATH)/editor-support/cocostudio)
#$(call import-module,$(LOCAL_PATH)/editor-support/spine)
$(call import-module,$(LOCAL_PATH)/network)
$(call import-module,$(LOCAL_PATH)/ui)
#$(call import-module,extensions)
$(call import-module,Box2D)
$(call import-module,bullet/prebuilt/android)
$(call import-module,recast)
$(call import-module,curl/prebuilt/android)
$(call import-module,websockets/prebuilt/android)
$(call import-module,openssl/prebuilt/android)
$(call import-module,flatbuffers)
