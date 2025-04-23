// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Global/CAS_GameModeBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAS_CAS_GameModeBase_generated_h
#error "CAS_GameModeBase.generated.h already included, missing '#pragma once' in CAS_GameModeBase.h"
#endif
#define CAS_CAS_GameModeBase_generated_h

#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACAS_GameModeBase(); \
	friend struct Z_Construct_UClass_ACAS_GameModeBase_Statics; \
public: \
	DECLARE_CLASS(ACAS_GameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/CAS"), NO_API) \
	DECLARE_SERIALIZER(ACAS_GameModeBase)


#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACAS_GameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACAS_GameModeBase(ACAS_GameModeBase&&); \
	ACAS_GameModeBase(const ACAS_GameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACAS_GameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACAS_GameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACAS_GameModeBase) \
	NO_API virtual ~ACAS_GameModeBase();


#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_12_PROLOG
#define FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAS_API UClass* StaticClass<class ACAS_GameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Unreal_RSP_RSP_CAS_Source_CAS_Global_CAS_GameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
