// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Character/CAS_EnemyCapt.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_EnemyCapt() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_ACAS_Character();
CAS_API UClass* Z_Construct_UClass_ACAS_EnemyCapt();
CAS_API UClass* Z_Construct_UClass_ACAS_EnemyCapt_NoRegister();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACAS_EnemyCapt
void ACAS_EnemyCapt::StaticRegisterNativesACAS_EnemyCapt()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACAS_EnemyCapt);
UClass* Z_Construct_UClass_ACAS_EnemyCapt_NoRegister()
{
	return ACAS_EnemyCapt::StaticClass();
}
struct Z_Construct_UClass_ACAS_EnemyCapt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/CAS_EnemyCapt.h" },
		{ "ModuleRelativePath", "Character/CAS_EnemyCapt.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACAS_EnemyCapt>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACAS_EnemyCapt_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACAS_Character,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_EnemyCapt_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACAS_EnemyCapt_Statics::ClassParams = {
	&ACAS_EnemyCapt::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_EnemyCapt_Statics::Class_MetaDataParams), Z_Construct_UClass_ACAS_EnemyCapt_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACAS_EnemyCapt()
{
	if (!Z_Registration_Info_UClass_ACAS_EnemyCapt.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACAS_EnemyCapt.OuterSingleton, Z_Construct_UClass_ACAS_EnemyCapt_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACAS_EnemyCapt.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACAS_EnemyCapt>()
{
	return ACAS_EnemyCapt::StaticClass();
}
ACAS_EnemyCapt::ACAS_EnemyCapt() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACAS_EnemyCapt);
ACAS_EnemyCapt::~ACAS_EnemyCapt() {}
// End Class ACAS_EnemyCapt

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Character_CAS_EnemyCapt_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACAS_EnemyCapt, ACAS_EnemyCapt::StaticClass, TEXT("ACAS_EnemyCapt"), &Z_Registration_Info_UClass_ACAS_EnemyCapt, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACAS_EnemyCapt), 1720372978U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Character_CAS_EnemyCapt_h_3043388698(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Character_CAS_EnemyCapt_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Character_CAS_EnemyCapt_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
