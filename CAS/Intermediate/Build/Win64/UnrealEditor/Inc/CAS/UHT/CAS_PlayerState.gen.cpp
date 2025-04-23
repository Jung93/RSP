// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CAS/Character/CAS_PlayerState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_PlayerState() {}

// Begin Cross Module References
CAS_API UClass* Z_Construct_UClass_ACAS_PlayerState();
CAS_API UClass* Z_Construct_UClass_ACAS_PlayerState_NoRegister();
CAS_API UClass* Z_Construct_UClass_UCAS_AbilitySystemComponent_NoRegister();
CAS_API UClass* Z_Construct_UClass_UCAS_AttributeSet_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_CAS();
// End Cross Module References

// Begin Class ACAS_PlayerState
void ACAS_PlayerState::StaticRegisterNativesACAS_PlayerState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACAS_PlayerState);
UClass* Z_Construct_UClass_ACAS_PlayerState_NoRegister()
{
	return ACAS_PlayerState::StaticClass();
}
struct Z_Construct_UClass_ACAS_PlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Character/CAS_PlayerState.h" },
		{ "ModuleRelativePath", "Character/CAS_PlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "Category", "Abilities" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/CAS_PlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeSet_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/CAS_PlayerState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeSet;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACAS_PlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACAS_PlayerState_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACAS_PlayerState, AbilitySystemComponent), Z_Construct_UClass_UCAS_AbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACAS_PlayerState_Statics::NewProp_AttributeSet = { "AttributeSet", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACAS_PlayerState, AttributeSet), Z_Construct_UClass_UCAS_AttributeSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeSet_MetaData), NewProp_AttributeSet_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACAS_PlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACAS_PlayerState_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACAS_PlayerState_Statics::NewProp_AttributeSet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_PlayerState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACAS_PlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_CAS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_PlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ACAS_PlayerState_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(ACAS_PlayerState, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACAS_PlayerState_Statics::ClassParams = {
	&ACAS_PlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACAS_PlayerState_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_PlayerState_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACAS_PlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_ACAS_PlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACAS_PlayerState()
{
	if (!Z_Registration_Info_UClass_ACAS_PlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACAS_PlayerState.OuterSingleton, Z_Construct_UClass_ACAS_PlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACAS_PlayerState.OuterSingleton;
}
template<> CAS_API UClass* StaticClass<ACAS_PlayerState>()
{
	return ACAS_PlayerState::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACAS_PlayerState);
ACAS_PlayerState::~ACAS_PlayerState() {}
// End Class ACAS_PlayerState

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACAS_PlayerState, ACAS_PlayerState::StaticClass, TEXT("ACAS_PlayerState"), &Z_Registration_Info_UClass_ACAS_PlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACAS_PlayerState), 3861141866U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_2995955596(TEXT("/Script/CAS"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
