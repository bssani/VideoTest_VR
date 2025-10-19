// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VideoTest/VRMediaPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRMediaPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_VideoTest();
VIDEOTEST_API UClass* Z_Construct_UClass_AVRMediaPlayerController();
VIDEOTEST_API UClass* Z_Construct_UClass_AVRMediaPlayerController_NoRegister();
VIDEOTEST_API UClass* Z_Construct_UClass_AVRMediaSphere_NoRegister();
// End Cross Module References

// Begin Class AVRMediaPlayerController
void AVRMediaPlayerController::StaticRegisterNativesAVRMediaPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVRMediaPlayerController);
UClass* Z_Construct_UClass_AVRMediaPlayerController_NoRegister()
{
	return AVRMediaPlayerController::StaticClass();
}
struct Z_Construct_UClass_AVRMediaPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "VRMediaPlayerController.h" },
		{ "ModuleRelativePath", "VRMediaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IMC_Runtime_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd IMC/IA (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd C++\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd)\n" },
#endif
		{ "ModuleRelativePath", "VRMediaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd IMC/IA (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd C++\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_PlayPause_MetaData[] = {
		{ "ModuleRelativePath", "VRMediaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_ToggleHemisphere_MetaData[] = {
		{ "ModuleRelativePath", "VRMediaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_SeekForward_MetaData[] = {
		{ "ModuleRelativePath", "VRMediaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_SeekBackward_MetaData[] = {
		{ "ModuleRelativePath", "VRMediaPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MediaActor_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "VRMediaPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IMC_Runtime;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_PlayPause;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_ToggleHemisphere;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_SeekForward;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_SeekBackward;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MediaActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVRMediaPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IMC_Runtime = { "IMC_Runtime", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaPlayerController, IMC_Runtime), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IMC_Runtime_MetaData), NewProp_IMC_Runtime_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IA_PlayPause = { "IA_PlayPause", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaPlayerController, IA_PlayPause), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_PlayPause_MetaData), NewProp_IA_PlayPause_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IA_ToggleHemisphere = { "IA_ToggleHemisphere", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaPlayerController, IA_ToggleHemisphere), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_ToggleHemisphere_MetaData), NewProp_IA_ToggleHemisphere_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IA_SeekForward = { "IA_SeekForward", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaPlayerController, IA_SeekForward), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_SeekForward_MetaData), NewProp_IA_SeekForward_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IA_SeekBackward = { "IA_SeekBackward", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaPlayerController, IA_SeekBackward), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_SeekBackward_MetaData), NewProp_IA_SeekBackward_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_MediaActor = { "MediaActor", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaPlayerController, MediaActor), Z_Construct_UClass_AVRMediaSphere_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MediaActor_MetaData), NewProp_MediaActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVRMediaPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IMC_Runtime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IA_PlayPause,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IA_ToggleHemisphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IA_SeekForward,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_IA_SeekBackward,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaPlayerController_Statics::NewProp_MediaActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AVRMediaPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_VideoTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVRMediaPlayerController_Statics::ClassParams = {
	&AVRMediaPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AVRMediaPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AVRMediaPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVRMediaPlayerController()
{
	if (!Z_Registration_Info_UClass_AVRMediaPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVRMediaPlayerController.OuterSingleton, Z_Construct_UClass_AVRMediaPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVRMediaPlayerController.OuterSingleton;
}
template<> VIDEOTEST_API UClass* StaticClass<AVRMediaPlayerController>()
{
	return AVRMediaPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVRMediaPlayerController);
AVRMediaPlayerController::~AVRMediaPlayerController() {}
// End Class AVRMediaPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVRMediaPlayerController, AVRMediaPlayerController::StaticClass, TEXT("AVRMediaPlayerController"), &Z_Registration_Info_UClass_AVRMediaPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVRMediaPlayerController), 237997091U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaPlayerController_h_3232638182(TEXT("/Script/VideoTest"),
	Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_Source_VideoTest_VRMediaPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
