// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VRMediaCmdLib.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIDEOTEST_VRMediaCmdLib_generated_h
#error "VRMediaCmdLib.generated.h already included, missing '#pragma once' in VRMediaCmdLib.h"
#endif
#define VIDEOTEST_VRMediaCmdLib_generated_h

#define FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCmdOptions);


#define FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVRMediaCmdLib(); \
	friend struct Z_Construct_UClass_UVRMediaCmdLib_Statics; \
public: \
	DECLARE_CLASS(UVRMediaCmdLib, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VideoTest"), NO_API) \
	DECLARE_SERIALIZER(UVRMediaCmdLib)


#define FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVRMediaCmdLib(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UVRMediaCmdLib(UVRMediaCmdLib&&); \
	UVRMediaCmdLib(const UVRMediaCmdLib&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVRMediaCmdLib); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVRMediaCmdLib); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVRMediaCmdLib) \
	NO_API virtual ~UVRMediaCmdLib();


#define FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h_12_PROLOG
#define FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VIDEOTEST_API UClass* StaticClass<class UVRMediaCmdLib>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaCmdLib_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
