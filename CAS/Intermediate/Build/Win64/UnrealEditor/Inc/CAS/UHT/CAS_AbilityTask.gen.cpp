// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/GAS/CAS_AbilityTask.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_AbilityTask() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_UCAS_AbilityTask();
CAS_API UClass* Z_Construct_UClass_UCAS_AbilityTask_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilityTask();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class UCAS_AbilityTask
void UCAS_AbilityTask::StaticRegisterNativesUCAS_AbilityTask()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCAS_AbilityTask);
UClass* Z_Construct_UClass_UCAS_AbilityTask_NoRegister()
{
	return UCAS_AbilityTask::StaticClass();
}
struct Z_Construct_UClass_UCAS_AbilityTask_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GAS/CAS_AbilityTask.h" },
		{ "ModuleRelativePath", "GAS/CAS_AbilityTask.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCAS_AbilityTask>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCAS_AbilityTask_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilityTask,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_AbilityTask_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCAS_AbilityTask_Statics::ClassParams = {
	&UCAS_AbilityTask::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_AbilityTask_Statics::Class_MetaDataParams), Z_Construct_UClass_UCAS_AbilityTask_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCAS_AbilityTask()
{
	if (!Z_Registration_Info_UClass_UCAS_AbilityTask.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCAS_AbilityTask.OuterSingleton, Z_Construct_UClass_UCAS_AbilityTask_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCAS_AbilityTask.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<UCAS_AbilityTask>()
{
	return UCAS_AbilityTask::StaticClass();
}
UCAS_AbilityTask::UCAS_AbilityTask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCAS_AbilityTask);
UCAS_AbilityTask::~UCAS_AbilityTask() {}
// End Class UCAS_AbilityTask

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AbilityTask_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCAS_AbilityTask, UCAS_AbilityTask::StaticClass, TEXT("UCAS_AbilityTask"), &Z_Registration_Info_UClass_UCAS_AbilityTask, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCAS_AbilityTask), 3874229880U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AbilityTask_h_275711996(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AbilityTask_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AbilityTask_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
