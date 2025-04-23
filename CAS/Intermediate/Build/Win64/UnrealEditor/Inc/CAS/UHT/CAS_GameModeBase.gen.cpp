// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Global/CAS_GameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_GameModeBase() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_ACAS_GameModeBase();
CAS_API UClass* Z_Construct_UClass_ACAS_GameModeBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACAS_GameModeBase
void ACAS_GameModeBase::StaticRegisterNativesACAS_GameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACAS_GameModeBase);
UClass* Z_Construct_UClass_ACAS_GameModeBase_NoRegister()
{
	return ACAS_GameModeBase::StaticClass();
}
struct Z_Construct_UClass_ACAS_GameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Global/CAS_GameModeBase.h" },
		{ "ModuleRelativePath", "Global/CAS_GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACAS_GameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACAS_GameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_GameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACAS_GameModeBase_Statics::ClassParams = {
	&ACAS_GameModeBase::StaticClass,
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
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_GameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ACAS_GameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACAS_GameModeBase()
{
	if (!Z_Registration_Info_UClass_ACAS_GameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACAS_GameModeBase.OuterSingleton, Z_Construct_UClass_ACAS_GameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACAS_GameModeBase.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACAS_GameModeBase>()
{
	return ACAS_GameModeBase::StaticClass();
}
ACAS_GameModeBase::ACAS_GameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACAS_GameModeBase);
ACAS_GameModeBase::~ACAS_GameModeBase() {}
// End Class ACAS_GameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACAS_GameModeBase, ACAS_GameModeBase::StaticClass, TEXT("ACAS_GameModeBase"), &Z_Registration_Info_UClass_ACAS_GameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACAS_GameModeBase), 3641420372U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_3485914593(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
