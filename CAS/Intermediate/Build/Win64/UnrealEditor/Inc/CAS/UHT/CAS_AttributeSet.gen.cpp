// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/GAS/CAS_AttributeSet.h"
#include "GameplayAbilities/Public/AttributeSet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_AttributeSet() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_UCAS_AttributeSet();
CAS_API UClass* Z_Construct_UClass_UCAS_AttributeSet_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttributeData();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class UCAS_AttributeSet
void UCAS_AttributeSet::StaticRegisterNativesUCAS_AttributeSet()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCAS_AttributeSet);
UClass* Z_Construct_UClass_UCAS_AttributeSet_NoRegister()
{
	return UCAS_AttributeSet::StaticClass();
}
struct Z_Construct_UClass_UCAS_AttributeSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GAS/CAS_AttributeSet.h" },
		{ "ModuleRelativePath", "GAS/CAS_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CAS_AttributeSet" },
		{ "ModuleRelativePath", "GAS/CAS_AttributeSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CAS_AttributeSet" },
		{ "ModuleRelativePath", "GAS/CAS_AttributeSet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Health;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCAS_AttributeSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCAS_AttributeSet_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0040000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCAS_AttributeSet, Health), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) }; // 675369593
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCAS_AttributeSet_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0040000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCAS_AttributeSet, MaxHealth), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) }; // 675369593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCAS_AttributeSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAS_AttributeSet_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCAS_AttributeSet_Statics::NewProp_MaxHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_AttributeSet_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCAS_AttributeSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAttributeSet,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_AttributeSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCAS_AttributeSet_Statics::ClassParams = {
	&UCAS_AttributeSet::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCAS_AttributeSet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_AttributeSet_Statics::PropPointers),
	0,
	0x003000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_AttributeSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UCAS_AttributeSet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCAS_AttributeSet()
{
	if (!Z_Registration_Info_UClass_UCAS_AttributeSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCAS_AttributeSet.OuterSingleton, Z_Construct_UClass_UCAS_AttributeSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCAS_AttributeSet.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<UCAS_AttributeSet>()
{
	return UCAS_AttributeSet::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCAS_AttributeSet);
UCAS_AttributeSet::~UCAS_AttributeSet() {}
// End Class UCAS_AttributeSet

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AttributeSet_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCAS_AttributeSet, UCAS_AttributeSet::StaticClass, TEXT("UCAS_AttributeSet"), &Z_Registration_Info_UClass_UCAS_AttributeSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCAS_AttributeSet), 2034427046U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AttributeSet_h_1934466434(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AttributeSet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AttributeSet_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
