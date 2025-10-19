// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VideoTest/VRMediaSphere.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRMediaSphere() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
MEDIAASSETS_API UClass* Z_Construct_UClass_UFileMediaSource_NoRegister();
MEDIAASSETS_API UClass* Z_Construct_UClass_UMediaPlayer_NoRegister();
MEDIAASSETS_API UClass* Z_Construct_UClass_UMediaSoundComponent_NoRegister();
MEDIAASSETS_API UClass* Z_Construct_UClass_UMediaTexture_NoRegister();
UPackage* Z_Construct_UPackage__Script_VideoTest();
VIDEOTEST_API UClass* Z_Construct_UClass_AVRMediaSphere();
VIDEOTEST_API UClass* Z_Construct_UClass_AVRMediaSphere_NoRegister();
VIDEOTEST_API UEnum* Z_Construct_UEnum_VideoTest_EVRStereoMode();
// End Cross Module References

// Begin Enum EVRStereoMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EVRStereoMode;
static UEnum* EVRStereoMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EVRStereoMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EVRStereoMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VideoTest_EVRStereoMode, (UObject*)Z_Construct_UPackage__Script_VideoTest(), TEXT("EVRStereoMode"));
	}
	return Z_Registration_Info_UEnum_EVRStereoMode.OuterSingleton;
}
template<> VIDEOTEST_API UEnum* StaticEnum<EVRStereoMode>()
{
	return EVRStereoMode_StaticEnum();
}
struct Z_Construct_UEnum_VideoTest_EVRStereoMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
		{ "Mono.DisplayName", "Mono" },
		{ "Mono.Name", "EVRStereoMode::Mono" },
		{ "OverUnder.DisplayName", "OverUnder" },
		{ "OverUnder.Name", "EVRStereoMode::OverUnder" },
		{ "SideBySide.DisplayName", "SideBySide" },
		{ "SideBySide.Name", "EVRStereoMode::SideBySide" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EVRStereoMode::Mono", (int64)EVRStereoMode::Mono },
		{ "EVRStereoMode::SideBySide", (int64)EVRStereoMode::SideBySide },
		{ "EVRStereoMode::OverUnder", (int64)EVRStereoMode::OverUnder },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VideoTest_EVRStereoMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_VideoTest,
	nullptr,
	"EVRStereoMode",
	"EVRStereoMode",
	Z_Construct_UEnum_VideoTest_EVRStereoMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_VideoTest_EVRStereoMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VideoTest_EVRStereoMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VideoTest_EVRStereoMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_VideoTest_EVRStereoMode()
{
	if (!Z_Registration_Info_UEnum_EVRStereoMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EVRStereoMode.InnerSingleton, Z_Construct_UEnum_VideoTest_EVRStereoMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EVRStereoMode.InnerSingleton;
}
// End Enum EVRStereoMode

// Begin Class AVRMediaSphere Function SeekSeconds
struct Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics
{
	struct VRMediaSphere_eventSeekSeconds_Parms
	{
		int32 Seconds;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VRMedia" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::NewProp_Seconds = { "Seconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRMediaSphere_eventSeekSeconds_Parms, Seconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::NewProp_Seconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVRMediaSphere, nullptr, "SeekSeconds", nullptr, nullptr, Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::VRMediaSphere_eventSeekSeconds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::VRMediaSphere_eventSeekSeconds_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVRMediaSphere_SeekSeconds()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRMediaSphere_SeekSeconds_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRMediaSphere::execSeekSeconds)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Seconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SeekSeconds(Z_Param_Seconds);
	P_NATIVE_END;
}
// End Class AVRMediaSphere Function SeekSeconds

// Begin Class AVRMediaSphere Function ToggleHemisphere
struct Z_Construct_UFunction_AVRMediaSphere_ToggleHemisphere_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VRMedia" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRMediaSphere_ToggleHemisphere_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVRMediaSphere, nullptr, "ToggleHemisphere", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRMediaSphere_ToggleHemisphere_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRMediaSphere_ToggleHemisphere_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVRMediaSphere_ToggleHemisphere()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRMediaSphere_ToggleHemisphere_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRMediaSphere::execToggleHemisphere)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleHemisphere();
	P_NATIVE_END;
}
// End Class AVRMediaSphere Function ToggleHemisphere

// Begin Class AVRMediaSphere Function TogglePlayPause
struct Z_Construct_UFunction_AVRMediaSphere_TogglePlayPause_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VRMedia" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Controls (\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xd1\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc8\xa3\xef\xbf\xbd\xef\xbf\xbd)\n" },
#endif
		{ "ModuleRelativePath", "VRMediaSphere.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Controls (\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xd1\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc8\xa3\xef\xbf\xbd\xef\xbf\xbd)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRMediaSphere_TogglePlayPause_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVRMediaSphere, nullptr, "TogglePlayPause", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRMediaSphere_TogglePlayPause_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRMediaSphere_TogglePlayPause_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVRMediaSphere_TogglePlayPause()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRMediaSphere_TogglePlayPause_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRMediaSphere::execTogglePlayPause)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TogglePlayPause();
	P_NATIVE_END;
}
// End Class AVRMediaSphere Function TogglePlayPause

// Begin Class AVRMediaSphere
void AVRMediaSphere::StaticRegisterNativesAVRMediaSphere()
{
	UClass* Class = AVRMediaSphere::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SeekSeconds", &AVRMediaSphere::execSeekSeconds },
		{ "ToggleHemisphere", &AVRMediaSphere::execToggleHemisphere },
		{ "TogglePlayPause", &AVRMediaSphere::execTogglePlayPause },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVRMediaSphere);
UClass* Z_Construct_UClass_AVRMediaSphere_NoRegister()
{
	return AVRMediaSphere::StaticClass();
}
struct Z_Construct_UClass_AVRMediaSphere_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "VRMediaSphere.h" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereMesh_MetaData[] = {
		{ "Category", "VRMedia|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Components\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Components" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MediaSound_MetaData[] = {
		{ "Category", "VRMedia|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MediaPlayer_MetaData[] = {
		{ "Category", "VRMedia|Media" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime-created UObjects (BeginPlay\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd NewObject)\n" },
#endif
		{ "ModuleRelativePath", "VRMediaSphere.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime-created UObjects (BeginPlay\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd NewObject)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MediaTex_MetaData[] = {
		{ "Category", "VRMedia|Media" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileSource_MetaData[] = {
		{ "Category", "VRMedia|Media" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FullSphereMesh_MetaData[] = {
		{ "Category", "VRMedia|Mesh" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Assets\n" },
#endif
		{ "ModuleRelativePath", "VRMediaSphere.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Assets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HalfSphereMesh_MetaData[] = {
		{ "Category", "VRMedia|Mesh" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseEquirectMaterial_MetaData[] = {
		{ "Category", "VRMedia|Material" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MID_MetaData[] = {
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideoPath_MetaData[] = {
		{ "Category", "VRMedia|Playback" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Options\n" },
#endif
		{ "ModuleRelativePath", "VRMediaSphere.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Options" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIs180_MetaData[] = {
		{ "Category", "VRMedia|Playback" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StereoMode_MetaData[] = {
		{ "Category", "VRMedia|Playback" },
		{ "ModuleRelativePath", "VRMediaSphere.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SphereMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MediaSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MediaPlayer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MediaTex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FileSource;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FullSphereMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HalfSphereMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BaseEquirectMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VideoPath;
	static void NewProp_bIs180_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIs180;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StereoMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StereoMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AVRMediaSphere_SeekSeconds, "SeekSeconds" }, // 2815303803
		{ &Z_Construct_UFunction_AVRMediaSphere_ToggleHemisphere, "ToggleHemisphere" }, // 3034559978
		{ &Z_Construct_UFunction_AVRMediaSphere_TogglePlayPause, "TogglePlayPause" }, // 2668753135
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVRMediaSphere>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_SphereMesh = { "SphereMesh", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, SphereMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereMesh_MetaData), NewProp_SphereMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_MediaSound = { "MediaSound", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, MediaSound), Z_Construct_UClass_UMediaSoundComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MediaSound_MetaData), NewProp_MediaSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_MediaPlayer = { "MediaPlayer", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, MediaPlayer), Z_Construct_UClass_UMediaPlayer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MediaPlayer_MetaData), NewProp_MediaPlayer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_MediaTex = { "MediaTex", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, MediaTex), Z_Construct_UClass_UMediaTexture_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MediaTex_MetaData), NewProp_MediaTex_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_FileSource = { "FileSource", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, FileSource), Z_Construct_UClass_UFileMediaSource_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileSource_MetaData), NewProp_FileSource_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_FullSphereMesh = { "FullSphereMesh", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, FullSphereMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FullSphereMesh_MetaData), NewProp_FullSphereMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_HalfSphereMesh = { "HalfSphereMesh", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, HalfSphereMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HalfSphereMesh_MetaData), NewProp_HalfSphereMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_BaseEquirectMaterial = { "BaseEquirectMaterial", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, BaseEquirectMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseEquirectMaterial_MetaData), NewProp_BaseEquirectMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_MID = { "MID", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, MID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MID_MetaData), NewProp_MID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_VideoPath = { "VideoPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, VideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoPath_MetaData), NewProp_VideoPath_MetaData) };
void Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_bIs180_SetBit(void* Obj)
{
	((AVRMediaSphere*)Obj)->bIs180 = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_bIs180 = { "bIs180", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVRMediaSphere), &Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_bIs180_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIs180_MetaData), NewProp_bIs180_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_StereoMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_StereoMode = { "StereoMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRMediaSphere, StereoMode), Z_Construct_UEnum_VideoTest_EVRStereoMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StereoMode_MetaData), NewProp_StereoMode_MetaData) }; // 1009778950
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVRMediaSphere_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_SphereMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_MediaSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_MediaPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_MediaTex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_FileSource,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_FullSphereMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_HalfSphereMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_BaseEquirectMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_MID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_VideoPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_bIs180,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_StereoMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRMediaSphere_Statics::NewProp_StereoMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaSphere_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AVRMediaSphere_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_VideoTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaSphere_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVRMediaSphere_Statics::ClassParams = {
	&AVRMediaSphere::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AVRMediaSphere_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaSphere_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVRMediaSphere_Statics::Class_MetaDataParams), Z_Construct_UClass_AVRMediaSphere_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVRMediaSphere()
{
	if (!Z_Registration_Info_UClass_AVRMediaSphere.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVRMediaSphere.OuterSingleton, Z_Construct_UClass_AVRMediaSphere_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVRMediaSphere.OuterSingleton;
}
template<> VIDEOTEST_API UClass* StaticClass<AVRMediaSphere>()
{
	return AVRMediaSphere::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVRMediaSphere);
AVRMediaSphere::~AVRMediaSphere() {}
// End Class AVRMediaSphere

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EVRStereoMode_StaticEnum, TEXT("EVRStereoMode"), &Z_Registration_Info_UEnum_EVRStereoMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1009778950U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVRMediaSphere, AVRMediaSphere::StaticClass, TEXT("AVRMediaSphere"), &Z_Registration_Info_UClass_AVRMediaSphere, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVRMediaSphere), 925319966U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_1146047463(TEXT("/Script/VideoTest"),
	Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Source_VideoTest_VRMediaSphere_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
