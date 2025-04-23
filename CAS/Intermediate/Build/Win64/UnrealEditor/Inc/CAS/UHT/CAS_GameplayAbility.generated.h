// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GAS/CAS_GameplayAbility.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAS_CAS_GameplayAbility_generated_h
#error "CAS_GameplayAbility.generated.h already included, missing '#pragma once' in CAS_GameplayAbility.h"
#endif
#define CAS_CAS_GameplayAbility_generated_h

#define FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCAS_GameplayAbility(); \
	friend struct Z_Construct_UClass_UCAS_GameplayAbility_Statics; \
public: \
	DECLARE_CLASS(UCAS_GameplayAbility, UGameplayAbility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CAS"), NO_API) \
	DECLARE_SERIALIZER(UCAS_GameplayAbility)


#define FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCAS_GameplayAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCAS_GameplayAbility(UCAS_GameplayAbility&&); \
	UCAS_GameplayAbility(const UCAS_GameplayAbility&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCAS_GameplayAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCAS_GameplayAbility); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCAS_GameplayAbility) \
	NO_API virtual ~UCAS_GameplayAbility();


#define FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_12_PROLOG
#define FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_15_INCLASS_NO_PURE_DECLS \
	FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAS_API UClass* StaticClass<class UCAS_GameplayAbility>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GitHub_RSP_CAS_Source_CAS_GAS_CAS_GameplayAbility_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
