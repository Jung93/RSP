// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Global/CAS_GameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAS_CAS_GameInstance_generated_h
#error "CAS_GameInstance.generated.h already included, missing '#pragma once' in CAS_GameInstance.h"
#endif
#define CAS_CAS_GameInstance_generated_h

#define FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCAS_GameInstance(); \
	friend struct Z_Construct_UClass_UCAS_GameInstance_Statics; \
public: \
	DECLARE_CLASS(UCAS_GameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/CAS"), NO_API) \
	DECLARE_SERIALIZER(UCAS_GameInstance)


#define FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCAS_GameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCAS_GameInstance(UCAS_GameInstance&&); \
	UCAS_GameInstance(const UCAS_GameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCAS_GameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCAS_GameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCAS_GameInstance) \
	NO_API virtual ~UCAS_GameInstance();


#define FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_12_PROLOG
#define FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_15_INCLASS_NO_PURE_DECLS \
	FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAS_API UClass* StaticClass<class UCAS_GameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GitHub_RSP_CAS_Source_CAS_Global_CAS_GameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
