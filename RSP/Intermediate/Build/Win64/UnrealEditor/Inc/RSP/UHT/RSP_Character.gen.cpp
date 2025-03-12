// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RSP/Public/RSP_Character.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRSP_Character() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
RSP_API UClass* Z_Construct_UClass_ARSP_Character();
RSP_API UClass* Z_Construct_UClass_ARSP_Character_NoRegister();
UPackage* Z_Construct_UPackage__Script_RSP();
// End Cross Module References

// Begin Class ARSP_Character
void ARSP_Character::StaticRegisterNativesARSP_Character()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARSP_Character);
UClass* Z_Construct_UClass_ARSP_Character_NoRegister()
{
	return ARSP_Character::StaticClass();
}
struct Z_Construct_UClass_ARSP_Character_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "RSP_Character.h" },
		{ "ModuleRelativePath", "Public/RSP_Character.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARSP_Character>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARSP_Character_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_RSP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARSP_Character_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARSP_Character_Statics::ClassParams = {
	&ARSP_Character::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARSP_Character_Statics::Class_MetaDataParams), Z_Construct_UClass_ARSP_Character_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARSP_Character()
{
	if (!Z_Registration_Info_UClass_ARSP_Character.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARSP_Character.OuterSingleton, Z_Construct_UClass_ARSP_Character_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARSP_Character.OuterSingleton;
}
template<> RSP_API UClass* StaticClass<ARSP_Character>()
{
	return ARSP_Character::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARSP_Character);
ARSP_Character::~ARSP_Character() {}
// End Class ARSP_Character

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_RSP_Source_RSP_Public_RSP_Character_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARSP_Character, ARSP_Character::StaticClass, TEXT("ARSP_Character"), &Z_Registration_Info_UClass_ARSP_Character, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARSP_Character), 887965717U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_RSP_Source_RSP_Public_RSP_Character_h_1062885345(TEXT("/Script/RSP"),
	Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_RSP_Source_RSP_Public_RSP_Character_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_RSP_Source_RSP_Public_RSP_Character_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
