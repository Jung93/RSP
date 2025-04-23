// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Global/CAS_GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_GameInstance() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_UCAS_GameInstance();
CAS_API UClass* Z_Construct_UClass_UCAS_GameInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class UCAS_GameInstance
void UCAS_GameInstance::StaticRegisterNativesUCAS_GameInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCAS_GameInstance);
UClass* Z_Construct_UClass_UCAS_GameInstance_NoRegister()
{
	return UCAS_GameInstance::StaticClass();
}
struct Z_Construct_UClass_UCAS_GameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Global/CAS_GameInstance.h" },
		{ "ModuleRelativePath", "Global/CAS_GameInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCAS_GameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCAS_GameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_GameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCAS_GameInstance_Statics::ClassParams = {
	&UCAS_GameInstance::StaticClass,
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
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_GameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UCAS_GameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCAS_GameInstance()
{
	if (!Z_Registration_Info_UClass_UCAS_GameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCAS_GameInstance.OuterSingleton, Z_Construct_UClass_UCAS_GameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCAS_GameInstance.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<UCAS_GameInstance>()
{
	return UCAS_GameInstance::StaticClass();
}
UCAS_GameInstance::UCAS_GameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCAS_GameInstance);
UCAS_GameInstance::~UCAS_GameInstance() {}
// End Class UCAS_GameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCAS_GameInstance, UCAS_GameInstance::StaticClass, TEXT("UCAS_GameInstance"), &Z_Registration_Info_UClass_UCAS_GameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCAS_GameInstance), 2497789351U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_3940880786(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
