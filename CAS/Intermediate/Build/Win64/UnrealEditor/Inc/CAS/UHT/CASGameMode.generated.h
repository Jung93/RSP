// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CASGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAS_CASGameMode_generated_h
#error "CASGameMode.generated.h already included, missing '#pragma once' in CASGameMode.h"
#endif
#define CAS_CASGameMode_generated_h

#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACASGameMode(); \
	friend struct Z_Construct_UClass_ACASGameMode_Statics; \
public: \
	DECLARE_CLASS(ACASGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/CAS"), CAS_API) \
	DECLARE_SERIALIZER(ACASGameMode)


#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACASGameMode(ACASGameMode&&); \
	ACASGameMode(const ACASGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(CAS_API, ACASGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACASGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACASGameMode) \
	CAS_API virtual ~ACASGameMode();


#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_9_PROLOG
#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAS_API UClass* StaticClass<class ACASGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_CASGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
