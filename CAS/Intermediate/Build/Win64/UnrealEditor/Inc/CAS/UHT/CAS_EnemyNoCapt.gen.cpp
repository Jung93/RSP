// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Character/CAS_EnemyNoCapt.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_EnemyNoCapt() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_ACAS_Character();
CAS_API UClass* Z_Construct_UClass_ACAS_EnemyNoCapt();
CAS_API UClass* Z_Construct_UClass_ACAS_EnemyNoCapt_NoRegister();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACAS_EnemyNoCapt
void ACAS_EnemyNoCapt::StaticRegisterNativesACAS_EnemyNoCapt()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACAS_EnemyNoCapt);
UClass* Z_Construct_UClass_ACAS_EnemyNoCapt_NoRegister()
{
	return ACAS_EnemyNoCapt::StaticClass();
}
struct Z_Construct_UClass_ACAS_EnemyNoCapt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/CAS_EnemyNoCapt.h" },
		{ "ModuleRelativePath", "Character/CAS_EnemyNoCapt.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACAS_EnemyNoCapt>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACAS_EnemyNoCapt_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACAS_Character,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_EnemyNoCapt_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACAS_EnemyNoCapt_Statics::ClassParams = {
	&ACAS_EnemyNoCapt::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_EnemyNoCapt_Statics::Class_MetaDataParams), Z_Construct_UClass_ACAS_EnemyNoCapt_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACAS_EnemyNoCapt()
{
	if (!Z_Registration_Info_UClass_ACAS_EnemyNoCapt.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACAS_EnemyNoCapt.OuterSingleton, Z_Construct_UClass_ACAS_EnemyNoCapt_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACAS_EnemyNoCapt.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACAS_EnemyNoCapt>()
{
	return ACAS_EnemyNoCapt::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACAS_EnemyNoCapt);
ACAS_EnemyNoCapt::~ACAS_EnemyNoCapt() {}
// End Class ACAS_EnemyNoCapt

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_EnemyNoCapt_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACAS_EnemyNoCapt, ACAS_EnemyNoCapt::StaticClass, TEXT("ACAS_EnemyNoCapt"), &Z_Registration_Info_UClass_ACAS_EnemyNoCapt, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACAS_EnemyNoCapt), 675204284U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_EnemyNoCapt_h_3483134445(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_EnemyNoCapt_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_EnemyNoCapt_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
