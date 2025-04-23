// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/GAS/CAS_GameplayAbility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_GameplayAbility() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_UCAS_GameplayAbility();
CAS_API UClass* Z_Construct_UClass_UCAS_GameplayAbility_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class UCAS_GameplayAbility
void UCAS_GameplayAbility::StaticRegisterNativesUCAS_GameplayAbility()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCAS_GameplayAbility);
UClass* Z_Construct_UClass_UCAS_GameplayAbility_NoRegister()
{
	return UCAS_GameplayAbility::StaticClass();
}
struct Z_Construct_UClass_UCAS_GameplayAbility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GAS/CAS_GameplayAbility.h" },
		{ "ModuleRelativePath", "GAS/CAS_GameplayAbility.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCAS_GameplayAbility>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCAS_GameplayAbility_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_GameplayAbility_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCAS_GameplayAbility_Statics::ClassParams = {
	&UCAS_GameplayAbility::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_GameplayAbility_Statics::Class_MetaDataParams), Z_Construct_UClass_UCAS_GameplayAbility_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCAS_GameplayAbility()
{
	if (!Z_Registration_Info_UClass_UCAS_GameplayAbility.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCAS_GameplayAbility.OuterSingleton, Z_Construct_UClass_UCAS_GameplayAbility_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCAS_GameplayAbility.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<UCAS_GameplayAbility>()
{
	return UCAS_GameplayAbility::StaticClass();
}
UCAS_GameplayAbility::UCAS_GameplayAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCAS_GameplayAbility);
UCAS_GameplayAbility::~UCAS_GameplayAbility() {}
// End Class UCAS_GameplayAbility

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCAS_GameplayAbility, UCAS_GameplayAbility::StaticClass, TEXT("UCAS_GameplayAbility"), &Z_Registration_Info_UClass_UCAS_GameplayAbility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCAS_GameplayAbility), 2088276380U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_2640977627(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
