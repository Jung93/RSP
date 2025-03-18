// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RSP_Character.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
#ifdef RSP_RSP_Character_generated_h
#error "RSP_Character.generated.h already included, missing '#pragma once' in RSP_Character.h"
#endif
#define RSP_RSP_Character_generated_h

#define FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAttackEnd);


#define FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARSP_Character(); \
	friend struct Z_Construct_UClass_ARSP_Character_Statics; \
public: \
	DECLARE_CLASS(ARSP_Character, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/RSP"), NO_API) \
	DECLARE_SERIALIZER(ARSP_Character)


#define FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARSP_Character(ARSP_Character&&); \
	ARSP_Character(const ARSP_Character&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARSP_Character); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARSP_Character); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ARSP_Character) \
	NO_API virtual ~ARSP_Character();


#define FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h_9_PROLOG
#define FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h_12_INCLASS_NO_PURE_DECLS \
	FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RSP_API UClass* StaticClass<class ARSP_Character>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_2025_Unreal_RSP_RSP_Source_RSP_Public_RSP_Character_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
