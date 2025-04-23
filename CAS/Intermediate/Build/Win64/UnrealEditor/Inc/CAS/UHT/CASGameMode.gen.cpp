// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/CASGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCASGameMode() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_ACASGameMode();
CAS_API UClass* Z_Construct_UClass_ACASGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACASGameMode
void ACASGameMode::StaticRegisterNativesACASGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACASGameMode);
UClass* Z_Construct_UClass_ACASGameMode_NoRegister()
{
	return ACASGameMode::StaticClass();
}
struct Z_Construct_UClass_ACASGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CASGameMode.h" },
		{ "ModuleRelativePath", "CASGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACASGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACASGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACASGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACASGameMode_Statics::ClassParams = {
	&ACASGameMode::StaticClass,
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
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACASGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACASGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACASGameMode()
{
	if (!Z_Registration_Info_UClass_ACASGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACASGameMode.OuterSingleton, Z_Construct_UClass_ACASGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACASGameMode.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACASGameMode>()
{
	return ACASGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACASGameMode);
ACASGameMode::~ACASGameMode() {}
// End Class ACASGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACASGameMode, ACASGameMode::StaticClass, TEXT("ACASGameMode"), &Z_Registration_Info_UClass_ACASGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACASGameMode), 4001448549U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_518185333(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
