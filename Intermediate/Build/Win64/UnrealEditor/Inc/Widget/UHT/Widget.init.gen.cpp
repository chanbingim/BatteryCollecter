// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWidget_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Widget;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Widget()
	{
		if (!Z_Registration_Info_UPackage__Script_Widget.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Widget",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x7B0B8FE9,
				0x1E59C4E5,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Widget.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Widget.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Widget(Z_Construct_UPackage__Script_Widget, TEXT("/Script/Widget"), Z_Registration_Info_UPackage__Script_Widget, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x7B0B8FE9, 0x1E59C4E5));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
