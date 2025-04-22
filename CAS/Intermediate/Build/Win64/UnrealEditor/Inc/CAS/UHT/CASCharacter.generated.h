// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CASCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAS_CASCharacter_generated_h
#error "CASCharacter.generated.h already included, missing '#pragma once' in CASCharacter.h"
#endif
#define CAS_CASCharacter_generated_h

#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACASCharacter(); \
	friend struct Z_Construct_UClass_ACASCharacter_Statics; \
public: \
	DECLARE_CLASS(ACASCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CAS"), NO_API) \
	DECLARE_SERIALIZER(ACASCharacter)


#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACASCharacter(ACASCharacter&&); \
	ACASCharacter(const ACASCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACASCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACASCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACASCharacter) \
	NO_API virtual ~ACASCharacter();


#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASCharacter_h_18_PROLOG
#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASCharacter_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAS_API UClass* StaticClass<class ACASCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
