// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/CAS_PlayerState.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAS_CAS_PlayerState_generated_h
#error "CAS_PlayerState.generated.h already included, missing '#pragma once' in CAS_PlayerState.h"
#endif
#define CAS_CAS_PlayerState_generated_h

#define FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACAS_PlayerState(); \
	friend struct Z_Construct_UClass_ACAS_PlayerState_Statics; \
public: \
	DECLARE_CLASS(ACAS_PlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CAS"), NO_API) \
	DECLARE_SERIALIZER(ACAS_PlayerState) \
	virtual UObject* _getUObject() const override { return const_cast<ACAS_PlayerState*>(this); }


#define FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACAS_PlayerState(ACAS_PlayerState&&); \
	ACAS_PlayerState(const ACAS_PlayerState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACAS_PlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACAS_PlayerState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACAS_PlayerState) \
	NO_API virtual ~ACAS_PlayerState();


#define FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_13_PROLOG
#define FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_16_INCLASS_NO_PURE_DECLS \
	FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAS_API UClass* StaticClass<class ACAS_PlayerState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GitHub_RSP_CAS_Source_CAS_Character_CAS_PlayerState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
