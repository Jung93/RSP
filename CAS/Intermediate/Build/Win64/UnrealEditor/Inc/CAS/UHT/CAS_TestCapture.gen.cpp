// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Character/EnemyCapt/CAS_TestCapture.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_TestCapture() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_ACAS_EnemyCapt();
CAS_API UClass* Z_Construct_UClass_ACAS_TestCapture();
CAS_API UClass* Z_Construct_UClass_ACAS_TestCapture_NoRegister();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACAS_TestCapture
void ACAS_TestCapture::StaticRegisterNativesACAS_TestCapture()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACAS_TestCapture);
UClass* Z_Construct_UClass_ACAS_TestCapture_NoRegister()
{
	return ACAS_TestCapture::StaticClass();
}
struct Z_Construct_UClass_ACAS_TestCapture_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/EnemyCapt/CAS_TestCapture.h" },
		{ "ModuleRelativePath", "Character/EnemyCapt/CAS_TestCapture.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACAS_TestCapture>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACAS_TestCapture_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACAS_EnemyCapt,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_TestCapture_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACAS_TestCapture_Statics::ClassParams = {
	&ACAS_TestCapture::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_TestCapture_Statics::Class_MetaDataParams), Z_Construct_UClass_ACAS_TestCapture_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACAS_TestCapture()
{
	if (!Z_Registration_Info_UClass_ACAS_TestCapture.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACAS_TestCapture.OuterSingleton, Z_Construct_UClass_ACAS_TestCapture_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACAS_TestCapture.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACAS_TestCapture>()
{
	return ACAS_TestCapture::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACAS_TestCapture);
ACAS_TestCapture::~ACAS_TestCapture() {}
// End Class ACAS_TestCapture

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_EnemyCapt_CAS_TestCapture_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACAS_TestCapture, ACAS_TestCapture::StaticClass, TEXT("ACAS_TestCapture"), &Z_Registration_Info_UClass_ACAS_TestCapture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACAS_TestCapture), 1073642851U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_EnemyCapt_CAS_TestCapture_h_4216430265(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_EnemyCapt_CAS_TestCapture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_EnemyCapt_CAS_TestCapture_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
