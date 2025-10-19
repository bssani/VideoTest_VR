// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VRMediaSphere.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIDEOTEST_VRMediaSphere_generated_h
#error "VRMediaSphere.generated.h already included, missing '#pragma once' in VRMediaSphere.h"
#endif
#define VIDEOTEST_VRMediaSphere_generated_h

#define FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSeekSeconds); \
	DECLARE_FUNCTION(execToggleHemisphere); \
	DECLARE_FUNCTION(execTogglePlayPause);


#define FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVRMediaSphere(); \
	friend struct Z_Construct_UClass_AVRMediaSphere_Statics; \
public: \
	DECLARE_CLASS(AVRMediaSphere, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VideoTest"), NO_API) \
	DECLARE_SERIALIZER(AVRMediaSphere)


#define FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AVRMediaSphere(AVRMediaSphere&&); \
	AVRMediaSphere(const AVRMediaSphere&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRMediaSphere); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRMediaSphere); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVRMediaSphere) \
	NO_API virtual ~AVRMediaSphere();


#define FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_18_PROLOG
#define FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_21_INCLASS_NO_PURE_DECLS \
	FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VIDEOTEST_API UClass* StaticClass<class AVRMediaSphere>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h


#define FOREACH_ENUM_EVRSTEREOMODE(op) \
	op(EVRStereoMode::Mono) \
	op(EVRStereoMode::SideBySide) \
	op(EVRStereoMode::OverUnder) 

enum class EVRStereoMode : uint8;
template<> struct TIsUEnumClass<EVRStereoMode> { enum { Value = true }; };
template<> VIDEOTEST_API UEnum* StaticEnum<EVRStereoMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
