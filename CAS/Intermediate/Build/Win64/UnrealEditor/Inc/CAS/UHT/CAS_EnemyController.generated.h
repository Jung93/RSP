// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Controller/CAS_EnemyController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAS_CAS_EnemyController_generated_h
#error "CAS_EnemyController.generated.h already included, missing '#pragma once' in CAS_EnemyController.h"
#endif
#define CAS_CAS_EnemyController_generated_h

#define FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACAS_EnemyController(); \
	friend struct Z_Construct_UClass_ACAS_EnemyController_Statics; \
public: \
	DECLARE_CLASS(ACAS_EnemyController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CAS"), NO_API) \
	DECLARE_SERIALIZER(ACAS_EnemyController)


#define FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACAS_EnemyController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACAS_EnemyController(ACAS_EnemyController&&); \
	ACAS_EnemyController(const ACAS_EnemyController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACAS_EnemyController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACAS_EnemyController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACAS_EnemyController) \
	NO_API virtual ~ACAS_EnemyController();


#define FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_12_PROLOG
#define FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_15_INCLASS_NO_PURE_DECLS \
	FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAS_API UClass* StaticClass<class ACAS_EnemyController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GitHub_RSP_CAS_Source_CAS_Controller_CAS_EnemyController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
