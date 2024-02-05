// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodea_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_a;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_a()
	{
		if (!Z_Registration_Info_UPackage__Script_a.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/a",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x6BC20389,
				0xD655B975,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_a.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_a.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_a(Z_Construct_UPackage__Script_a, TEXT("/Script/a"), Z_Registration_Info_UPackage__Script_a, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x6BC20389, 0xD655B975));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
