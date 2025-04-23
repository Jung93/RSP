// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Controller/CAS_PlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_PlayerController() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_ACAS_PlayerController();
CAS_API UClass* Z_Construct_UClass_ACAS_PlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACAS_PlayerController
void ACAS_PlayerController::StaticRegisterNativesACAS_PlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACAS_PlayerController);
UClass* Z_Construct_UClass_ACAS_PlayerController_NoRegister()
{
	return ACAS_PlayerController::StaticClass();
}
struct Z_Construct_UClass_ACAS_PlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Controller/CAS_PlayerController.h" },
		{ "ModuleRelativePath", "Controller/CAS_PlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__inputMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Controller/CAS_PlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__inputMappingContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACAS_PlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACAS_PlayerController_Statics::NewProp__inputMappingContext = { "_inputMappingContext", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACAS_PlayerController, _inputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__inputMappingContext_MetaData), NewProp__inputMappingContext_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACAS_PlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACAS_PlayerController_Statics::NewProp__inputMappingContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_PlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACAS_PlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_PlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACAS_PlayerController_Statics::ClassParams = {
	&ACAS_PlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACAS_PlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_PlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_PlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ACAS_PlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACAS_PlayerController()
{
	if (!Z_Registration_Info_UClass_ACAS_PlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACAS_PlayerController.OuterSingleton, Z_Construct_UClass_ACAS_PlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACAS_PlayerController.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACAS_PlayerController>()
{
	return ACAS_PlayerController::StaticClass();
}
ACAS_PlayerController::ACAS_PlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACAS_PlayerController);
ACAS_PlayerController::~ACAS_PlayerController() {}
// End Class ACAS_PlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_PlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACAS_PlayerController, ACAS_PlayerController::StaticClass, TEXT("ACAS_PlayerController"), &Z_Registration_Info_UClass_ACAS_PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACAS_PlayerController), 2392354930U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_PlayerController_h_627161243(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_PlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
