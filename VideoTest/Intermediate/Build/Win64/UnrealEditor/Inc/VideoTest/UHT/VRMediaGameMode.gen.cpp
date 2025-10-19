// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VideoTest/VRMediaGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRMediaGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_VideoTest();
VIDEOTEST_API UClass* Z_Construct_UClass_AVRMediaGameMode();
VIDEOTEST_API UClass* Z_Construct_UClass_AVRMediaGameMode_NoRegister();
// End Cross Module References

// Begin Class AVRMediaGameMode
void AVRMediaGameMode::StaticRegisterNativesAVRMediaGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVRMediaGameMode);
UClass* Z_Construct_UClass_AVRMediaGameMode_NoRegister()
{
	return AVRMediaGameMode::StaticClass();
}
struct Z_Construct_UClass_AVRMediaGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "VRMediaGameMode.h" },
		{ "ModuleRelativePath", "VRMediaGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVRMediaGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AVRMediaGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_VideoTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVRMediaGameMode_Statics::ClassParams = {
	&AVRMediaGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AVRMediaGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVRMediaGameMode()
{
	if (!Z_Registration_Info_UClass_AVRMediaGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVRMediaGameMode.OuterSingleton, Z_Construct_UClass_AVRMediaGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVRMediaGameMode.OuterSingleton;
}
template<> VIDEOTEST_API UClass* StaticClass<AVRMediaGameMode>()
{
	return AVRMediaGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVRMediaGameMode);
AVRMediaGameMode::~AVRMediaGameMode() {}
// End Class AVRMediaGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVRMediaGameMode, AVRMediaGameMode::StaticClass, TEXT("AVRMediaGameMode"), &Z_Registration_Info_UClass_AVRMediaGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVRMediaGameMode), 3173240516U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaGameMode_h_1514744113(TEXT("/Script/VideoTest"),
	Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
