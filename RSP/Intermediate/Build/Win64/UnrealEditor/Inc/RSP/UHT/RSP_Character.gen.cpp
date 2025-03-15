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
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
RSP_API UClass* Z_Construct_UClass_ARSP_Character();
RSP_API UClass* Z_Construct_UClass_ARSP_Character_NoRegister();
UPackage* Z_Construct_UPackage__Script_RSP();
// End Cross Module References

// Begin Class ARSP_Character Function AttackEnd
struct Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics
{
	struct RSP_Character_eventAttackEnd_Parms
	{
		UAnimMontage* Montage;
		bool bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RSP_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static void NewProp_bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RSP_Character_eventAttackEnd_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::NewProp_bInterrupted_SetBit(void* Obj)
{
	((RSP_Character_eventAttackEnd_Parms*)Obj)->bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::NewProp_bInterrupted = { "bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(RSP_Character_eventAttackEnd_Parms), &Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::NewProp_bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARSP_Character, nullptr, "AttackEnd", nullptr, nullptr, Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::RSP_Character_eventAttackEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::RSP_Character_eventAttackEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ARSP_Character_AttackEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ARSP_Character_AttackEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ARSP_Character::execAttackEnd)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_UBOOL(Z_Param_bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttackEnd(Z_Param_Montage,Z_Param_bInterrupted);
	P_NATIVE_END;
}
// End Class ARSP_Character Function AttackEnd

// Begin Class ARSP_Character
void ARSP_Character::StaticRegisterNativesARSP_Character()
{
	UClass* Class = ARSP_Character::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AttackEnd", &ARSP_Character::execAttackEnd },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__isAttack_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = \"Stat\", meta = (AllowPrivateAccess = \"true\"))\n//class UMyStatComponent* _statComponent;\n" },
#endif
		{ "ModuleRelativePath", "Public/RSP_Character.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = \"Stat\", meta = (AllowPrivateAccess = \"true\"))\nclass UMyStatComponent* _statComponent;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__attackRange_MetaData[] = {
		{ "Category", "RSP_Character" },
		{ "ModuleRelativePath", "Public/RSP_Character.h" },
	};
#endif // WITH_METADATA
	static void NewProp__isAttack_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp__isAttack;
	static const UECodeGen_Private::FFloatPropertyParams NewProp__attackRange;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ARSP_Character_AttackEnd, "AttackEnd" }, // 1651853675
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARSP_Character>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_ARSP_Character_Statics::NewProp__isAttack_SetBit(void* Obj)
{
	((ARSP_Character*)Obj)->_isAttack = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ARSP_Character_Statics::NewProp__isAttack = { "_isAttack", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ARSP_Character), &Z_Construct_UClass_ARSP_Character_Statics::NewProp__isAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__isAttack_MetaData), NewProp__isAttack_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARSP_Character_Statics::NewProp__attackRange = { "_attackRange", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARSP_Character, _attackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__attackRange_MetaData), NewProp__attackRange_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARSP_Character_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARSP_Character_Statics::NewProp__isAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARSP_Character_Statics::NewProp__attackRange,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARSP_Character_Statics::PropPointers) < 2048);
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
	FuncInfo,
	Z_Construct_UClass_ARSP_Character_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ARSP_Character_Statics::PropPointers),
	0,
	0x009000A5u,
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
struct Z_CompiledInDeferFile_FID_GitHub_RSP_RSP_Source_RSP_Public_RSP_Character_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARSP_Character, ARSP_Character::StaticClass, TEXT("ARSP_Character"), &Z_Registration_Info_UClass_ARSP_Character, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARSP_Character), 590912761U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_RSP_RSP_Source_RSP_Public_RSP_Character_h_79698128(TEXT("/Script/RSP"),
	Z_CompiledInDeferFile_FID_GitHub_RSP_RSP_Source_RSP_Public_RSP_Character_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_RSP_RSP_Source_RSP_Public_RSP_Character_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
