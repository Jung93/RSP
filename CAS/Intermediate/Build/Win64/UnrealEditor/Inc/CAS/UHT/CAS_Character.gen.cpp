// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Character/CAS_Character.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_Character() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_ACAS_Character();
CAS_API UClass* Z_Construct_UClass_ACAS_Character_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACAS_Character
void ACAS_Character::StaticRegisterNativesACAS_Character()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACAS_Character);
UClass* Z_Construct_UClass_ACAS_Character_NoRegister()
{
	return ACAS_Character::StaticClass();
}
struct Z_Construct_UClass_ACAS_Character_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/CAS_Character.h" },
		{ "ModuleRelativePath", "Character/CAS_Character.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACAS_Character>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACAS_Character_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_Character_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACAS_Character_Statics::ClassParams = {
	&ACAS_Character::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_Character_Statics::Class_MetaDataParams), Z_Construct_UClass_ACAS_Character_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACAS_Character()
{
	if (!Z_Registration_Info_UClass_ACAS_Character.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACAS_Character.OuterSingleton, Z_Construct_UClass_ACAS_Character_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACAS_Character.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACAS_Character>()
{
	return ACAS_Character::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACAS_Character);
ACAS_Character::~ACAS_Character() {}
// End Class ACAS_Character

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_Character_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACAS_Character, ACAS_Character::StaticClass, TEXT("ACAS_Character"), &Z_Registration_Info_UClass_ACAS_Character, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACAS_Character), 926749683U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_Character_h_3242601119(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_Character_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_Character_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
