// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Controller/CAS_EnemyController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_EnemyController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
CAS_API UClass* Z_Construct_UClass_ACAS_EnemyController();
CAS_API UClass* Z_Construct_UClass_ACAS_EnemyController_NoRegister();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACAS_EnemyController
void ACAS_EnemyController::StaticRegisterNativesACAS_EnemyController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACAS_EnemyController);
UClass* Z_Construct_UClass_ACAS_EnemyController_NoRegister()
{
	return ACAS_EnemyController::StaticClass();
}
struct Z_Construct_UClass_ACAS_EnemyController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Controller/CAS_EnemyController.h" },
		{ "ModuleRelativePath", "Controller/CAS_EnemyController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACAS_EnemyController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACAS_EnemyController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_EnemyController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACAS_EnemyController_Statics::ClassParams = {
	&ACAS_EnemyController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_EnemyController_Statics::Class_MetaDataParams), Z_Construct_UClass_ACAS_EnemyController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACAS_EnemyController()
{
	if (!Z_Registration_Info_UClass_ACAS_EnemyController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACAS_EnemyController.OuterSingleton, Z_Construct_UClass_ACAS_EnemyController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACAS_EnemyController.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACAS_EnemyController>()
{
	return ACAS_EnemyController::StaticClass();
}
ACAS_EnemyController::ACAS_EnemyController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACAS_EnemyController);
ACAS_EnemyController::~ACAS_EnemyController() {}
// End Class ACAS_EnemyController

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACAS_EnemyController, ACAS_EnemyController::StaticClass, TEXT("ACAS_EnemyController"), &Z_Registration_Info_UClass_ACAS_EnemyController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACAS_EnemyController), 4018181639U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_2813686113(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
