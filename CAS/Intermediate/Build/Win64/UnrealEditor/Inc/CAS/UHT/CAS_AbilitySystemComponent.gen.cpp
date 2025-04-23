// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/GAS/CAS_AbilitySystemComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_AbilitySystemComponent() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_UCAS_AbilitySystemComponent();
CAS_API UClass* Z_Construct_UClass_UCAS_AbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class UCAS_AbilitySystemComponent
void UCAS_AbilitySystemComponent::StaticRegisterNativesUCAS_AbilitySystemComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCAS_AbilitySystemComponent);
UClass* Z_Construct_UClass_UCAS_AbilitySystemComponent_NoRegister()
{
	return UCAS_AbilitySystemComponent::StaticClass();
}
struct Z_Construct_UClass_UCAS_AbilitySystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object LOD Lighting Transform Sockets TextureStreaming Object LOD Lighting Transform Sockets TextureStreaming" },
		{ "IncludePath", "GAS/CAS_AbilitySystemComponent.h" },
		{ "ModuleRelativePath", "GAS/CAS_AbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCAS_AbilitySystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCAS_AbilitySystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_AbilitySystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCAS_AbilitySystemComponent_Statics::ClassParams = {
	&UCAS_AbilitySystemComponent::StaticClass,
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
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCAS_AbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCAS_AbilitySystemComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCAS_AbilitySystemComponent()
{
	if (!Z_Registration_Info_UClass_UCAS_AbilitySystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCAS_AbilitySystemComponent.OuterSingleton, Z_Construct_UClass_UCAS_AbilitySystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCAS_AbilitySystemComponent.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<UCAS_AbilitySystemComponent>()
{
	return UCAS_AbilitySystemComponent::StaticClass();
}
UCAS_AbilitySystemComponent::UCAS_AbilitySystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCAS_AbilitySystemComponent);
UCAS_AbilitySystemComponent::~UCAS_AbilitySystemComponent() {}
// End Class UCAS_AbilitySystemComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AbilitySystemComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCAS_AbilitySystemComponent, UCAS_AbilitySystemComponent::StaticClass, TEXT("UCAS_AbilitySystemComponent"), &Z_Registration_Info_UClass_UCAS_AbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCAS_AbilitySystemComponent), 4027023726U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AbilitySystemComponent_h_1908226144(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AbilitySystemComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_AbilitySystemComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
