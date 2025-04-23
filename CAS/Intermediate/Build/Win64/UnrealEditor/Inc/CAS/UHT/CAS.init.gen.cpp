// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCAS_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_CAS;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_CAS()
	{
		if (!Z_Registration_Info_UPackage__Script_CAS.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/CAS",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x0C0008FB,
				0x537962B0,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_CAS.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_CAS.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_CAS(Z_Construct_UPackage__Script_CAS, TEXT("/Script/CAS"), Z_Registration_Info_UPackage__Script_CAS, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0C0008FB, 0x537962B0));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
