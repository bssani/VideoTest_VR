// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VideoTest/VRMediaCmdLib.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRMediaCmdLib() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_VideoTest();
VIDEOTEST_API UClass* Z_Construct_UClass_UVRMediaCmdLib();
VIDEOTEST_API UClass* Z_Construct_UClass_UVRMediaCmdLib_NoRegister();
// End Cross Module References

// Begin Class UVRMediaCmdLib Function GetCmdOptions
struct Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics
{
	struct VRMediaCmdLib_eventGetCmdOptions_Parms
	{
		FString OutVideo;
		bool bOutIs180;
		FString OutStereo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VRMedia" },
		{ "ModuleRelativePath", "VRMediaCmdLib.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutVideo;
	static void NewProp_bOutIs180_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOutIs180;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutStereo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_OutVideo = { "OutVideo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRMediaCmdLib_eventGetCmdOptions_Parms, OutVideo), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_bOutIs180_SetBit(void* Obj)
{
	((VRMediaCmdLib_eventGetCmdOptions_Parms*)Obj)->bOutIs180 = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_bOutIs180 = { "bOutIs180", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VRMediaCmdLib_eventGetCmdOptions_Parms), &Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_bOutIs180_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_OutStereo = { "OutStereo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRMediaCmdLib_eventGetCmdOptions_Parms, OutStereo), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((VRMediaCmdLib_eventGetCmdOptions_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VRMediaCmdLib_eventGetCmdOptions_Parms), &Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_OutVideo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_bOutIs180,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_OutStereo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRMediaCmdLib, nullptr, "GetCmdOptions", nullptr, nullptr, Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::VRMediaCmdLib_eventGetCmdOptions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::VRMediaCmdLib_eventGetCmdOptions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UVRMediaCmdLib::execGetCmdOptions)
{
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutVideo);
	P_GET_UBOOL_REF(Z_Param_Out_bOutIs180);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutStereo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UVRMediaCmdLib::GetCmdOptions(Z_Param_Out_OutVideo,Z_Param_Out_bOutIs180,Z_Param_Out_OutStereo);
	P_NATIVE_END;
}
// End Class UVRMediaCmdLib Function GetCmdOptions

// Begin Class UVRMediaCmdLib
void UVRMediaCmdLib::StaticRegisterNativesUVRMediaCmdLib()
{
	UClass* Class = UVRMediaCmdLib::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCmdOptions", &UVRMediaCmdLib::execGetCmdOptions },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVRMediaCmdLib);
UClass* Z_Construct_UClass_UVRMediaCmdLib_NoRegister()
{
	return UVRMediaCmdLib::StaticClass();
}
struct Z_Construct_UClass_UVRMediaCmdLib_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "VRMediaCmdLib.h" },
		{ "ModuleRelativePath", "VRMediaCmdLib.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UVRMediaCmdLib_GetCmdOptions, "GetCmdOptions" }, // 213169346
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVRMediaCmdLib>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UVRMediaCmdLib_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_VideoTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVRMediaCmdLib_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UVRMediaCmdLib_Statics::ClassParams = {
	&UVRMediaCmdLib::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVRMediaCmdLib_Statics::Class_MetaDataParams), Z_Construct_UClass_UVRMediaCmdLib_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UVRMediaCmdLib()
{
	if (!Z_Registration_Info_UClass_UVRMediaCmdLib.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVRMediaCmdLib.OuterSingleton, Z_Construct_UClass_UVRMediaCmdLib_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UVRMediaCmdLib.OuterSingleton;
}
template<> VIDEOTEST_API UClass* StaticClass<UVRMediaCmdLib>()
{
	return UVRMediaCmdLib::StaticClass();
}
UVRMediaCmdLib::UVRMediaCmdLib(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UVRMediaCmdLib);
UVRMediaCmdLib::~UVRMediaCmdLib() {}
// End Class UVRMediaCmdLib

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaCmdLib_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UVRMediaCmdLib, UVRMediaCmdLib::StaticClass, TEXT("UVRMediaCmdLib"), &Z_Registration_Info_UClass_UVRMediaCmdLib, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVRMediaCmdLib), 2201930008U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaCmdLib_h_3644918134(TEXT("/Script/VideoTest"),
	Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaCmdLib_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaCmdLib_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
