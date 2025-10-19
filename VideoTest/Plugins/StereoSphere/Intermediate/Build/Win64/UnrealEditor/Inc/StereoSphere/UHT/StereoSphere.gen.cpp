// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StereoSphere/Public/StereoSphere.h"
#include "ActorLayerUtilities/Public/ActorLayerUtilities.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereoSphere() {}

// Begin Cross Module References
ACTORLAYERUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FActorLayer();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
MOVIERENDERPIPELINERENDERPASSES_API UClass* Z_Construct_UClass_UMoviePipelineImagePassBase();
MOVIERENDERPIPELINERENDERPASSES_API UClass* Z_Construct_UClass_UMoviePipelineImageSequenceOutputBase_NoRegister();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_DetailLighting();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_DetailLighting_NoRegister();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_LightingOnly();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_LightingOnly_NoRegister();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_NoRegister();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_PathTracer();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_PathTracer_NoRegister();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_ReflectionsOnly();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_ReflectionsOnly_NoRegister();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_Unlit();
STEREOSPHERE_API UClass* Z_Construct_UClass_UStereoSphere_Unlit_NoRegister();
STEREOSPHERE_API UEnum* Z_Construct_UEnum_StereoSphere_EAlignType();
STEREOSPHERE_API UEnum* Z_Construct_UEnum_StereoSphere_ERenderPass();
STEREOSPHERE_API UEnum* Z_Construct_UEnum_StereoSphere_ESurroundingType();
STEREOSPHERE_API UEnum* Z_Construct_UEnum_StereoSphere_ETextureSampingMethod();
STEREOSPHERE_API UScriptStruct* Z_Construct_UScriptStruct_FPanoramicPostProcessPass();
UPackage* Z_Construct_UPackage__Script_StereoSphere();
// End Cross Module References

// Begin ScriptStruct FPanoramicPostProcessPass
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PanoramicPostProcessPass;
class UScriptStruct* FPanoramicPostProcessPass::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PanoramicPostProcessPass.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PanoramicPostProcessPass.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPanoramicPostProcessPass, (UObject*)Z_Construct_UPackage__Script_StereoSphere(), TEXT("PanoramicPostProcessPass"));
	}
	return Z_Registration_Info_UScriptStruct_PanoramicPostProcessPass.OuterSingleton;
}
template<> STEREOSPHERE_API UScriptStruct* StaticStruct<FPanoramicPostProcessPass>()
{
	return FPanoramicPostProcessPass::StaticStruct();
}
struct Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHighPrecisionOutput_MetaData[] = {
		{ "Category", "Settings" },
		{ "DisplayName", "Use High Precision (32-bit) Output" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Material;
	static void NewProp_bHighPrecisionOutput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHighPrecisionOutput;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPanoramicPostProcessPass>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((FPanoramicPostProcessPass*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPanoramicPostProcessPass), &Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPanoramicPostProcessPass, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPanoramicPostProcessPass, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Material_MetaData), NewProp_Material_MetaData) };
void Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_bHighPrecisionOutput_SetBit(void* Obj)
{
	((FPanoramicPostProcessPass*)Obj)->bHighPrecisionOutput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_bHighPrecisionOutput = { "bHighPrecisionOutput", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPanoramicPostProcessPass), &Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_bHighPrecisionOutput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHighPrecisionOutput_MetaData), NewProp_bHighPrecisionOutput_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_Material,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewProp_bHighPrecisionOutput,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_StereoSphere,
	nullptr,
	&NewStructOps,
	"PanoramicPostProcessPass",
	Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::PropPointers),
	sizeof(FPanoramicPostProcessPass),
	alignof(FPanoramicPostProcessPass),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPanoramicPostProcessPass()
{
	if (!Z_Registration_Info_UScriptStruct_PanoramicPostProcessPass.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PanoramicPostProcessPass.InnerSingleton, Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_PanoramicPostProcessPass.InnerSingleton;
}
// End ScriptStruct FPanoramicPostProcessPass

// Begin Enum ERenderPass
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERenderPass;
static UEnum* ERenderPass_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ERenderPass.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ERenderPass.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_StereoSphere_ERenderPass, (UObject*)Z_Construct_UPackage__Script_StereoSphere(), TEXT("ERenderPass"));
	}
	return Z_Registration_Info_UEnum_ERenderPass.OuterSingleton;
}
template<> STEREOSPHERE_API UEnum* StaticEnum<ERenderPass>()
{
	return ERenderPass_StaticEnum();
}
struct Z_Construct_UEnum_StereoSphere_ERenderPass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "DetailLighting.Name", "ERenderPass::DetailLighting" },
		{ "LightingOnly.Name", "ERenderPass::LightingOnly" },
		{ "Lit.Name", "ERenderPass::Lit" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "PathTracer.Name", "ERenderPass::PathTracer" },
		{ "ReflectionsOnly.Name", "ERenderPass::ReflectionsOnly" },
		{ "Unlit.Name", "ERenderPass::Unlit" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ERenderPass::Lit", (int64)ERenderPass::Lit },
		{ "ERenderPass::Unlit", (int64)ERenderPass::Unlit },
		{ "ERenderPass::DetailLighting", (int64)ERenderPass::DetailLighting },
		{ "ERenderPass::LightingOnly", (int64)ERenderPass::LightingOnly },
		{ "ERenderPass::ReflectionsOnly", (int64)ERenderPass::ReflectionsOnly },
		{ "ERenderPass::PathTracer", (int64)ERenderPass::PathTracer },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_StereoSphere_ERenderPass_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_StereoSphere,
	nullptr,
	"ERenderPass",
	"ERenderPass",
	Z_Construct_UEnum_StereoSphere_ERenderPass_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_StereoSphere_ERenderPass_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_StereoSphere_ERenderPass_Statics::Enum_MetaDataParams), Z_Construct_UEnum_StereoSphere_ERenderPass_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_StereoSphere_ERenderPass()
{
	if (!Z_Registration_Info_UEnum_ERenderPass.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERenderPass.InnerSingleton, Z_Construct_UEnum_StereoSphere_ERenderPass_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ERenderPass.InnerSingleton;
}
// End Enum ERenderPass

// Begin Enum ESurroundingType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESurroundingType;
static UEnum* ESurroundingType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESurroundingType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESurroundingType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_StereoSphere_ESurroundingType, (UObject*)Z_Construct_UPackage__Script_StereoSphere(), TEXT("ESurroundingType"));
	}
	return Z_Registration_Info_UEnum_ESurroundingType.OuterSingleton;
}
template<> STEREOSPHERE_API UEnum* StaticEnum<ESurroundingType>()
{
	return ESurroundingType_StaticEnum();
}
struct Z_Construct_UEnum_StereoSphere_ESurroundingType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Hemisphere.DisplayName", "180 Degree" },
		{ "Hemisphere.Name", "ESurroundingType::Hemisphere" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "OmniDirectional.Name", "ESurroundingType::OmniDirectional" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESurroundingType::Hemisphere", (int64)ESurroundingType::Hemisphere },
		{ "ESurroundingType::OmniDirectional", (int64)ESurroundingType::OmniDirectional },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_StereoSphere_ESurroundingType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_StereoSphere,
	nullptr,
	"ESurroundingType",
	"ESurroundingType",
	Z_Construct_UEnum_StereoSphere_ESurroundingType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_StereoSphere_ESurroundingType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_StereoSphere_ESurroundingType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_StereoSphere_ESurroundingType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_StereoSphere_ESurroundingType()
{
	if (!Z_Registration_Info_UEnum_ESurroundingType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESurroundingType.InnerSingleton, Z_Construct_UEnum_StereoSphere_ESurroundingType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESurroundingType.InnerSingleton;
}
// End Enum ESurroundingType

// Begin Enum ETextureSampingMethod
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ETextureSampingMethod;
static UEnum* ETextureSampingMethod_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ETextureSampingMethod.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ETextureSampingMethod.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_StereoSphere_ETextureSampingMethod, (UObject*)Z_Construct_UPackage__Script_StereoSphere(), TEXT("ETextureSampingMethod"));
	}
	return Z_Registration_Info_UEnum_ETextureSampingMethod.OuterSingleton;
}
template<> STEREOSPHERE_API UEnum* StaticEnum<ETextureSampingMethod>()
{
	return ETextureSampingMethod_StaticEnum();
}
struct Z_Construct_UEnum_StereoSphere_ETextureSampingMethod_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Bicubic.Name", "ETextureSampingMethod::Bicubic" },
		{ "Billinear.Name", "ETextureSampingMethod::Billinear" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ETextureSampingMethod::Billinear", (int64)ETextureSampingMethod::Billinear },
		{ "ETextureSampingMethod::Bicubic", (int64)ETextureSampingMethod::Bicubic },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_StereoSphere_ETextureSampingMethod_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_StereoSphere,
	nullptr,
	"ETextureSampingMethod",
	"ETextureSampingMethod",
	Z_Construct_UEnum_StereoSphere_ETextureSampingMethod_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_StereoSphere_ETextureSampingMethod_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_StereoSphere_ETextureSampingMethod_Statics::Enum_MetaDataParams), Z_Construct_UEnum_StereoSphere_ETextureSampingMethod_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_StereoSphere_ETextureSampingMethod()
{
	if (!Z_Registration_Info_UEnum_ETextureSampingMethod.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ETextureSampingMethod.InnerSingleton, Z_Construct_UEnum_StereoSphere_ETextureSampingMethod_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ETextureSampingMethod.InnerSingleton;
}
// End Enum ETextureSampingMethod

// Begin Enum EAlignType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAlignType;
static UEnum* EAlignType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAlignType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAlignType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_StereoSphere_EAlignType, (UObject*)Z_Construct_UPackage__Script_StereoSphere(), TEXT("EAlignType"));
	}
	return Z_Registration_Info_UEnum_EAlignType.OuterSingleton;
}
template<> STEREOSPHERE_API UEnum* StaticEnum<EAlignType>()
{
	return EAlignType_StaticEnum();
}
struct Z_Construct_UEnum_StereoSphere_EAlignType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "Side_by_Side.Name", "EAlignType::Side_by_Side" },
		{ "Top_Bottom.Name", "EAlignType::Top_Bottom" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAlignType::Side_by_Side", (int64)EAlignType::Side_by_Side },
		{ "EAlignType::Top_Bottom", (int64)EAlignType::Top_Bottom },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_StereoSphere_EAlignType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_StereoSphere,
	nullptr,
	"EAlignType",
	"EAlignType",
	Z_Construct_UEnum_StereoSphere_EAlignType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_StereoSphere_EAlignType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_StereoSphere_EAlignType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_StereoSphere_EAlignType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_StereoSphere_EAlignType()
{
	if (!Z_Registration_Info_UEnum_EAlignType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAlignType.InnerSingleton, Z_Construct_UEnum_StereoSphere_EAlignType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAlignType.InnerSingleton;
}
// End Enum EAlignType

// Begin Class UStereoSphere
void UStereoSphere::StaticRegisterNativesUStereoSphere()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStereoSphere);
UClass* Z_Construct_UClass_UStereoSphere_NoRegister()
{
	return UStereoSphere::StaticClass();
}
struct Z_Construct_UClass_UStereoSphere_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "StereoSphere.h" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurroundingType_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "DisplayName", "Surrounding Type" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SampingMethod_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDepthOfField_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ClampMax", "240" },
		{ "ClampMin", "50" },
		{ "Delta", "10" },
		{ "DisplayName", "Enable Depth Of Field" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "UIMin", "50" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QualityImprovementPercentage_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ClampMax", "240" },
		{ "ClampMin", "50" },
		{ "Delta", "10" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "UIMin", "50" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumHorizontalSteps_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ClampMax", "100" },
		{ "ClampMin", "3" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "UIMin", "3" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumVerticalSteps_MetaData[] = {
		{ "Category", "StereoSphereSettings" },
		{ "ClampMax", "12" },
		{ "ClampMin", "3" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "UIMin", "3" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlapPercentage_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ClampMax", "100" },
		{ "ClampMin", "20" },
		{ "Delta", "5" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "UIMin", "20" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextureSharpnessBias_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ClampMax", "0" },
		{ "ClampMin", "-1" },
		{ "Delta", "0.1" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "UIMin", "-1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverscanPercentage_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "Delta", "0.1" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HorzFieldOfView_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VertFieldOfView_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllocateHistoryPerPane_MetaData[] = {
		{ "Category", "StereoSphere Settings" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStereo_MetaData[] = {
		{ "Category", "Stereo Settings" },
		{ "DisplayName", "Enable Stereo" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignType_MetaData[] = {
		{ "Category", "Stereo Settings" },
		{ "EditCondition", "bStereo" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFlipEyes_MetaData[] = {
		{ "Category", "Stereo Settings" },
		{ "EditCondition", "bStereo" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EyeSeparation_MetaData[] = {
		{ "Category", "Stereo Settings" },
		{ "EditCondition", "bStereo" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EyeConvergenceDistance_MetaData[] = {
		{ "Category", "Stereo Settings" },
		{ "EditCondition", "bStereo" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAccumulatorIncludesAlpha_MetaData[] = {
		{ "Category", "Alpha Settings" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableMultisampleEffects_MetaData[] = {
		{ "Category", "Post Processing" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalPostProcessMaterials_MetaData[] = {
		{ "Category", "PostProcess Render Materials Data" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveHighPrecisionPostProcessMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRenderMainPass_MetaData[] = {
		{ "Category", "Stencil Clip Layers" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAddDefaultLayer_MetaData[] = {
		{ "Category", "Stencil Clip Layers" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorLayers_MetaData[] = {
		{ "Category", "Stencil Clip Layers" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DataLayers_MetaData[] = {
		{ "AllowedClasses", "/Script/Engine.DataLayerAsset" },
		{ "Category", "Stencil Clip Layers" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePostProcessMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StencilLayerMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrevSequenceOutputBases_MetaData[] = {
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SurroundingType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SurroundingType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SampingMethod_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SampingMethod;
	static void NewProp_bEnableDepthOfField_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDepthOfField;
	static const UECodeGen_Private::FIntPropertyParams NewProp_QualityImprovementPercentage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumHorizontalSteps;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumVerticalSteps;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OverlapPercentage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TextureSharpnessBias;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OverscanPercentage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HorzFieldOfView;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VertFieldOfView;
	static void NewProp_bAllocateHistoryPerPane_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllocateHistoryPerPane;
	static void NewProp_bStereo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStereo;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AlignType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AlignType;
	static void NewProp_bFlipEyes_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipEyes;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EyeSeparation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EyeConvergenceDistance;
	static void NewProp_bAccumulatorIncludesAlpha_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAccumulatorIncludesAlpha;
	static void NewProp_bDisableMultisampleEffects_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableMultisampleEffects;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AdditionalPostProcessMaterials_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AdditionalPostProcessMaterials;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveHighPrecisionPostProcessMaterials_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_ActiveHighPrecisionPostProcessMaterials;
	static void NewProp_bRenderMainPass_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRenderMainPass;
	static void NewProp_bAddDefaultLayer_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAddDefaultLayer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorLayers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActorLayers;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DataLayers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DataLayers;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActivePostProcessMaterials_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActivePostProcessMaterials;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StencilLayerMaterial;
	static const UECodeGen_Private::FBoolPropertyParams NewProp_PrevSequenceOutputBases_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PrevSequenceOutputBases_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PrevSequenceOutputBases;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStereoSphere>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_SurroundingType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_SurroundingType = { "SurroundingType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, SurroundingType), Z_Construct_UEnum_StereoSphere_ESurroundingType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurroundingType_MetaData), NewProp_SurroundingType_MetaData) }; // 3190327670
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_SampingMethod_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_SampingMethod = { "SampingMethod", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, SampingMethod), Z_Construct_UEnum_StereoSphere_ETextureSampingMethod, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SampingMethod_MetaData), NewProp_SampingMethod_MetaData) }; // 4064378085
void Z_Construct_UClass_UStereoSphere_Statics::NewProp_bEnableDepthOfField_SetBit(void* Obj)
{
	((UStereoSphere*)Obj)->bEnableDepthOfField = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_bEnableDepthOfField = { "bEnableDepthOfField", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere), &Z_Construct_UClass_UStereoSphere_Statics::NewProp_bEnableDepthOfField_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDepthOfField_MetaData), NewProp_bEnableDepthOfField_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_QualityImprovementPercentage = { "QualityImprovementPercentage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, QualityImprovementPercentage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QualityImprovementPercentage_MetaData), NewProp_QualityImprovementPercentage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_NumHorizontalSteps = { "NumHorizontalSteps", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, NumHorizontalSteps), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumHorizontalSteps_MetaData), NewProp_NumHorizontalSteps_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_NumVerticalSteps = { "NumVerticalSteps", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, NumVerticalSteps), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumVerticalSteps_MetaData), NewProp_NumVerticalSteps_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_OverlapPercentage = { "OverlapPercentage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, OverlapPercentage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlapPercentage_MetaData), NewProp_OverlapPercentage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_TextureSharpnessBias = { "TextureSharpnessBias", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, TextureSharpnessBias), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextureSharpnessBias_MetaData), NewProp_TextureSharpnessBias_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_OverscanPercentage = { "OverscanPercentage", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, OverscanPercentage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverscanPercentage_MetaData), NewProp_OverscanPercentage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_HorzFieldOfView = { "HorzFieldOfView", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, HorzFieldOfView), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HorzFieldOfView_MetaData), NewProp_HorzFieldOfView_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_VertFieldOfView = { "VertFieldOfView", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, VertFieldOfView), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VertFieldOfView_MetaData), NewProp_VertFieldOfView_MetaData) };
void Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAllocateHistoryPerPane_SetBit(void* Obj)
{
	((UStereoSphere*)Obj)->bAllocateHistoryPerPane = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAllocateHistoryPerPane = { "bAllocateHistoryPerPane", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere), &Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAllocateHistoryPerPane_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllocateHistoryPerPane_MetaData), NewProp_bAllocateHistoryPerPane_MetaData) };
void Z_Construct_UClass_UStereoSphere_Statics::NewProp_bStereo_SetBit(void* Obj)
{
	((UStereoSphere*)Obj)->bStereo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_bStereo = { "bStereo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere), &Z_Construct_UClass_UStereoSphere_Statics::NewProp_bStereo_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStereo_MetaData), NewProp_bStereo_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_AlignType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_AlignType = { "AlignType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, AlignType), Z_Construct_UEnum_StereoSphere_EAlignType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignType_MetaData), NewProp_AlignType_MetaData) }; // 865618541
void Z_Construct_UClass_UStereoSphere_Statics::NewProp_bFlipEyes_SetBit(void* Obj)
{
	((UStereoSphere*)Obj)->bFlipEyes = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_bFlipEyes = { "bFlipEyes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere), &Z_Construct_UClass_UStereoSphere_Statics::NewProp_bFlipEyes_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFlipEyes_MetaData), NewProp_bFlipEyes_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_EyeSeparation = { "EyeSeparation", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, EyeSeparation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EyeSeparation_MetaData), NewProp_EyeSeparation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_EyeConvergenceDistance = { "EyeConvergenceDistance", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, EyeConvergenceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EyeConvergenceDistance_MetaData), NewProp_EyeConvergenceDistance_MetaData) };
void Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAccumulatorIncludesAlpha_SetBit(void* Obj)
{
	((UStereoSphere*)Obj)->bAccumulatorIncludesAlpha = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAccumulatorIncludesAlpha = { "bAccumulatorIncludesAlpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere), &Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAccumulatorIncludesAlpha_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAccumulatorIncludesAlpha_MetaData), NewProp_bAccumulatorIncludesAlpha_MetaData) };
void Z_Construct_UClass_UStereoSphere_Statics::NewProp_bDisableMultisampleEffects_SetBit(void* Obj)
{
	((UStereoSphere*)Obj)->bDisableMultisampleEffects = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_bDisableMultisampleEffects = { "bDisableMultisampleEffects", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere), &Z_Construct_UClass_UStereoSphere_Statics::NewProp_bDisableMultisampleEffects_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableMultisampleEffects_MetaData), NewProp_bDisableMultisampleEffects_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_AdditionalPostProcessMaterials_Inner = { "AdditionalPostProcessMaterials", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPanoramicPostProcessPass, METADATA_PARAMS(0, nullptr) }; // 2476161324
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_AdditionalPostProcessMaterials = { "AdditionalPostProcessMaterials", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, AdditionalPostProcessMaterials), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdditionalPostProcessMaterials_MetaData), NewProp_AdditionalPostProcessMaterials_MetaData) }; // 2476161324
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActiveHighPrecisionPostProcessMaterials_ElementProp = { "ActiveHighPrecisionPostProcessMaterials", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActiveHighPrecisionPostProcessMaterials = { "ActiveHighPrecisionPostProcessMaterials", nullptr, (EPropertyFlags)0x0114000000202000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, ActiveHighPrecisionPostProcessMaterials), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveHighPrecisionPostProcessMaterials_MetaData), NewProp_ActiveHighPrecisionPostProcessMaterials_MetaData) };
void Z_Construct_UClass_UStereoSphere_Statics::NewProp_bRenderMainPass_SetBit(void* Obj)
{
	((UStereoSphere*)Obj)->bRenderMainPass = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_bRenderMainPass = { "bRenderMainPass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere), &Z_Construct_UClass_UStereoSphere_Statics::NewProp_bRenderMainPass_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRenderMainPass_MetaData), NewProp_bRenderMainPass_MetaData) };
void Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAddDefaultLayer_SetBit(void* Obj)
{
	((UStereoSphere*)Obj)->bAddDefaultLayer = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAddDefaultLayer = { "bAddDefaultLayer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere), &Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAddDefaultLayer_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAddDefaultLayer_MetaData), NewProp_bAddDefaultLayer_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActorLayers_Inner = { "ActorLayers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActorLayer, METADATA_PARAMS(0, nullptr) }; // 2865297347
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActorLayers = { "ActorLayers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, ActorLayers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorLayers_MetaData), NewProp_ActorLayers_MetaData) }; // 2865297347
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_DataLayers_Inner = { "DataLayers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_DataLayers = { "DataLayers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, DataLayers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DataLayers_MetaData), NewProp_DataLayers_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActivePostProcessMaterials_Inner = { "ActivePostProcessMaterials", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActivePostProcessMaterials = { "ActivePostProcessMaterials", nullptr, (EPropertyFlags)0x0124080000202000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, ActivePostProcessMaterials), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePostProcessMaterials_MetaData), NewProp_ActivePostProcessMaterials_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_StencilLayerMaterial = { "StencilLayerMaterial", nullptr, (EPropertyFlags)0x0124080000202000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, StencilLayerMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StencilLayerMaterial_MetaData), NewProp_StencilLayerMaterial_MetaData) };
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_PrevSequenceOutputBases_ValueProp = { "PrevSequenceOutputBases", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_PrevSequenceOutputBases_Key_KeyProp = { "PrevSequenceOutputBases_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMoviePipelineImageSequenceOutputBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UStereoSphere_Statics::NewProp_PrevSequenceOutputBases = { "PrevSequenceOutputBases", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStereoSphere, PrevSequenceOutputBases), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrevSequenceOutputBases_MetaData), NewProp_PrevSequenceOutputBases_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStereoSphere_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_SurroundingType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_SurroundingType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_SampingMethod_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_SampingMethod,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_bEnableDepthOfField,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_QualityImprovementPercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_NumHorizontalSteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_NumVerticalSteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_OverlapPercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_TextureSharpnessBias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_OverscanPercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_HorzFieldOfView,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_VertFieldOfView,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAllocateHistoryPerPane,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_bStereo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_AlignType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_AlignType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_bFlipEyes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_EyeSeparation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_EyeConvergenceDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAccumulatorIncludesAlpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_bDisableMultisampleEffects,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_AdditionalPostProcessMaterials_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_AdditionalPostProcessMaterials,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActiveHighPrecisionPostProcessMaterials_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActiveHighPrecisionPostProcessMaterials,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_bRenderMainPass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_bAddDefaultLayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActorLayers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActorLayers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_DataLayers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_DataLayers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActivePostProcessMaterials_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_ActivePostProcessMaterials,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_StencilLayerMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_PrevSequenceOutputBases_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_PrevSequenceOutputBases_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_Statics::NewProp_PrevSequenceOutputBases,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UStereoSphere_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMoviePipelineImagePassBase,
	(UObject* (*)())Z_Construct_UPackage__Script_StereoSphere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStereoSphere_Statics::ClassParams = {
	&UStereoSphere::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UStereoSphere_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_Statics::Class_MetaDataParams), Z_Construct_UClass_UStereoSphere_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStereoSphere()
{
	if (!Z_Registration_Info_UClass_UStereoSphere.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStereoSphere.OuterSingleton, Z_Construct_UClass_UStereoSphere_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStereoSphere.OuterSingleton;
}
template<> STEREOSPHERE_API UClass* StaticClass<UStereoSphere>()
{
	return UStereoSphere::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStereoSphere);
// End Class UStereoSphere

// Begin Class UStereoSphere_PathTracer
void UStereoSphere_PathTracer::StaticRegisterNativesUStereoSphere_PathTracer()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStereoSphere_PathTracer);
UClass* Z_Construct_UClass_UStereoSphere_PathTracer_NoRegister()
{
	return UStereoSphere_PathTracer::StaticClass();
}
struct Z_Construct_UClass_UStereoSphere_PathTracer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "StereoSphere.h" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bReferenceMotionBlur_MetaData[] = {
		{ "Category", "Reference Motion Blur" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bReferenceMotionBlur_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bReferenceMotionBlur;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStereoSphere_PathTracer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UStereoSphere_PathTracer_Statics::NewProp_bReferenceMotionBlur_SetBit(void* Obj)
{
	((UStereoSphere_PathTracer*)Obj)->bReferenceMotionBlur = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStereoSphere_PathTracer_Statics::NewProp_bReferenceMotionBlur = { "bReferenceMotionBlur", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStereoSphere_PathTracer), &Z_Construct_UClass_UStereoSphere_PathTracer_Statics::NewProp_bReferenceMotionBlur_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bReferenceMotionBlur_MetaData), NewProp_bReferenceMotionBlur_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStereoSphere_PathTracer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStereoSphere_PathTracer_Statics::NewProp_bReferenceMotionBlur,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_PathTracer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UStereoSphere_PathTracer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStereoSphere,
	(UObject* (*)())Z_Construct_UPackage__Script_StereoSphere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_PathTracer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStereoSphere_PathTracer_Statics::ClassParams = {
	&UStereoSphere_PathTracer::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UStereoSphere_PathTracer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_PathTracer_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_PathTracer_Statics::Class_MetaDataParams), Z_Construct_UClass_UStereoSphere_PathTracer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStereoSphere_PathTracer()
{
	if (!Z_Registration_Info_UClass_UStereoSphere_PathTracer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStereoSphere_PathTracer.OuterSingleton, Z_Construct_UClass_UStereoSphere_PathTracer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStereoSphere_PathTracer.OuterSingleton;
}
template<> STEREOSPHERE_API UClass* StaticClass<UStereoSphere_PathTracer>()
{
	return UStereoSphere_PathTracer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStereoSphere_PathTracer);
UStereoSphere_PathTracer::~UStereoSphere_PathTracer() {}
// End Class UStereoSphere_PathTracer

// Begin Class UStereoSphere_Unlit
void UStereoSphere_Unlit::StaticRegisterNativesUStereoSphere_Unlit()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStereoSphere_Unlit);
UClass* Z_Construct_UClass_UStereoSphere_Unlit_NoRegister()
{
	return UStereoSphere_Unlit::StaticClass();
}
struct Z_Construct_UClass_UStereoSphere_Unlit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "StereoSphere.h" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStereoSphere_Unlit>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UStereoSphere_Unlit_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStereoSphere,
	(UObject* (*)())Z_Construct_UPackage__Script_StereoSphere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_Unlit_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStereoSphere_Unlit_Statics::ClassParams = {
	&UStereoSphere_Unlit::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_Unlit_Statics::Class_MetaDataParams), Z_Construct_UClass_UStereoSphere_Unlit_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStereoSphere_Unlit()
{
	if (!Z_Registration_Info_UClass_UStereoSphere_Unlit.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStereoSphere_Unlit.OuterSingleton, Z_Construct_UClass_UStereoSphere_Unlit_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStereoSphere_Unlit.OuterSingleton;
}
template<> STEREOSPHERE_API UClass* StaticClass<UStereoSphere_Unlit>()
{
	return UStereoSphere_Unlit::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStereoSphere_Unlit);
UStereoSphere_Unlit::~UStereoSphere_Unlit() {}
// End Class UStereoSphere_Unlit

// Begin Class UStereoSphere_DetailLighting
void UStereoSphere_DetailLighting::StaticRegisterNativesUStereoSphere_DetailLighting()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStereoSphere_DetailLighting);
UClass* Z_Construct_UClass_UStereoSphere_DetailLighting_NoRegister()
{
	return UStereoSphere_DetailLighting::StaticClass();
}
struct Z_Construct_UClass_UStereoSphere_DetailLighting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "StereoSphere.h" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStereoSphere_DetailLighting>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UStereoSphere_DetailLighting_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStereoSphere,
	(UObject* (*)())Z_Construct_UPackage__Script_StereoSphere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_DetailLighting_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStereoSphere_DetailLighting_Statics::ClassParams = {
	&UStereoSphere_DetailLighting::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_DetailLighting_Statics::Class_MetaDataParams), Z_Construct_UClass_UStereoSphere_DetailLighting_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStereoSphere_DetailLighting()
{
	if (!Z_Registration_Info_UClass_UStereoSphere_DetailLighting.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStereoSphere_DetailLighting.OuterSingleton, Z_Construct_UClass_UStereoSphere_DetailLighting_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStereoSphere_DetailLighting.OuterSingleton;
}
template<> STEREOSPHERE_API UClass* StaticClass<UStereoSphere_DetailLighting>()
{
	return UStereoSphere_DetailLighting::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStereoSphere_DetailLighting);
UStereoSphere_DetailLighting::~UStereoSphere_DetailLighting() {}
// End Class UStereoSphere_DetailLighting

// Begin Class UStereoSphere_LightingOnly
void UStereoSphere_LightingOnly::StaticRegisterNativesUStereoSphere_LightingOnly()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStereoSphere_LightingOnly);
UClass* Z_Construct_UClass_UStereoSphere_LightingOnly_NoRegister()
{
	return UStereoSphere_LightingOnly::StaticClass();
}
struct Z_Construct_UClass_UStereoSphere_LightingOnly_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "StereoSphere.h" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStereoSphere_LightingOnly>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UStereoSphere_LightingOnly_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStereoSphere,
	(UObject* (*)())Z_Construct_UPackage__Script_StereoSphere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_LightingOnly_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStereoSphere_LightingOnly_Statics::ClassParams = {
	&UStereoSphere_LightingOnly::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_LightingOnly_Statics::Class_MetaDataParams), Z_Construct_UClass_UStereoSphere_LightingOnly_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStereoSphere_LightingOnly()
{
	if (!Z_Registration_Info_UClass_UStereoSphere_LightingOnly.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStereoSphere_LightingOnly.OuterSingleton, Z_Construct_UClass_UStereoSphere_LightingOnly_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStereoSphere_LightingOnly.OuterSingleton;
}
template<> STEREOSPHERE_API UClass* StaticClass<UStereoSphere_LightingOnly>()
{
	return UStereoSphere_LightingOnly::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStereoSphere_LightingOnly);
UStereoSphere_LightingOnly::~UStereoSphere_LightingOnly() {}
// End Class UStereoSphere_LightingOnly

// Begin Class UStereoSphere_ReflectionsOnly
void UStereoSphere_ReflectionsOnly::StaticRegisterNativesUStereoSphere_ReflectionsOnly()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStereoSphere_ReflectionsOnly);
UClass* Z_Construct_UClass_UStereoSphere_ReflectionsOnly_NoRegister()
{
	return UStereoSphere_ReflectionsOnly::StaticClass();
}
struct Z_Construct_UClass_UStereoSphere_ReflectionsOnly_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "StereoSphere.h" },
		{ "ModuleRelativePath", "Public/StereoSphere.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStereoSphere_ReflectionsOnly>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UStereoSphere_ReflectionsOnly_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStereoSphere,
	(UObject* (*)())Z_Construct_UPackage__Script_StereoSphere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_ReflectionsOnly_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStereoSphere_ReflectionsOnly_Statics::ClassParams = {
	&UStereoSphere_ReflectionsOnly::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStereoSphere_ReflectionsOnly_Statics::Class_MetaDataParams), Z_Construct_UClass_UStereoSphere_ReflectionsOnly_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStereoSphere_ReflectionsOnly()
{
	if (!Z_Registration_Info_UClass_UStereoSphere_ReflectionsOnly.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStereoSphere_ReflectionsOnly.OuterSingleton, Z_Construct_UClass_UStereoSphere_ReflectionsOnly_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStereoSphere_ReflectionsOnly.OuterSingleton;
}
template<> STEREOSPHERE_API UClass* StaticClass<UStereoSphere_ReflectionsOnly>()
{
	return UStereoSphere_ReflectionsOnly::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStereoSphere_ReflectionsOnly);
UStereoSphere_ReflectionsOnly::~UStereoSphere_ReflectionsOnly() {}
// End Class UStereoSphere_ReflectionsOnly

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Plugins_StereoSphere_Source_StereoSphere_Public_StereoSphere_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ERenderPass_StaticEnum, TEXT("ERenderPass"), &Z_Registration_Info_UEnum_ERenderPass, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3051718555U) },
		{ ESurroundingType_StaticEnum, TEXT("ESurroundingType"), &Z_Registration_Info_UEnum_ESurroundingType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3190327670U) },
		{ ETextureSampingMethod_StaticEnum, TEXT("ETextureSampingMethod"), &Z_Registration_Info_UEnum_ETextureSampingMethod, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4064378085U) },
		{ EAlignType_StaticEnum, TEXT("EAlignType"), &Z_Registration_Info_UEnum_EAlignType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 865618541U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPanoramicPostProcessPass::StaticStruct, Z_Construct_UScriptStruct_FPanoramicPostProcessPass_Statics::NewStructOps, TEXT("PanoramicPostProcessPass"), &Z_Registration_Info_UScriptStruct_PanoramicPostProcessPass, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPanoramicPostProcessPass), 2476161324U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UStereoSphere, UStereoSphere::StaticClass, TEXT("UStereoSphere"), &Z_Registration_Info_UClass_UStereoSphere, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStereoSphere), 784158421U) },
		{ Z_Construct_UClass_UStereoSphere_PathTracer, UStereoSphere_PathTracer::StaticClass, TEXT("UStereoSphere_PathTracer"), &Z_Registration_Info_UClass_UStereoSphere_PathTracer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStereoSphere_PathTracer), 1475828063U) },
		{ Z_Construct_UClass_UStereoSphere_Unlit, UStereoSphere_Unlit::StaticClass, TEXT("UStereoSphere_Unlit"), &Z_Registration_Info_UClass_UStereoSphere_Unlit, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStereoSphere_Unlit), 3585221309U) },
		{ Z_Construct_UClass_UStereoSphere_DetailLighting, UStereoSphere_DetailLighting::StaticClass, TEXT("UStereoSphere_DetailLighting"), &Z_Registration_Info_UClass_UStereoSphere_DetailLighting, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStereoSphere_DetailLighting), 1963201859U) },
		{ Z_Construct_UClass_UStereoSphere_LightingOnly, UStereoSphere_LightingOnly::StaticClass, TEXT("UStereoSphere_LightingOnly"), &Z_Registration_Info_UClass_UStereoSphere_LightingOnly, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStereoSphere_LightingOnly), 1436078437U) },
		{ Z_Construct_UClass_UStereoSphere_ReflectionsOnly, UStereoSphere_ReflectionsOnly::StaticClass, TEXT("UStereoSphere_ReflectionsOnly"), &Z_Registration_Info_UClass_UStereoSphere_ReflectionsOnly, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStereoSphere_ReflectionsOnly), 1207492169U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Plugins_StereoSphere_Source_StereoSphere_Public_StereoSphere_h_3570561268(TEXT("/Script/StereoSphere"),
	Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Plugins_StereoSphere_Source_StereoSphere_Public_StereoSphere_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Plugins_StereoSphere_Source_StereoSphere_Public_StereoSphere_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Plugins_StereoSphere_Source_StereoSphere_Public_StereoSphere_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Plugins_StereoSphere_Source_StereoSphere_Public_StereoSphere_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Plugins_StereoSphere_Source_StereoSphere_Public_StereoSphere_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealEngineProject_VideoTest_VR_VideoTest_Plugins_StereoSphere_Source_StereoSphere_Public_StereoSphere_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
