// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GamePlay/SaveGameData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSaveGameData() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	GAMEPLAY_API UClass* Z_Construct_UClass_USaveGameData();
	GAMEPLAY_API UClass* Z_Construct_UClass_USaveGameData_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GamePlay();
// End Cross Module References
	void USaveGameData::StaticRegisterNativesUSaveGameData()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USaveGameData);
	UClass* Z_Construct_UClass_USaveGameData_NoRegister()
	{
		return USaveGameData::StaticClass();
	}
	struct Z_Construct_UClass_USaveGameData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USaveGameData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_GamePlay,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameData_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SaveGameData.h" },
		{ "ModuleRelativePath", "SaveGameData.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USaveGameData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USaveGameData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USaveGameData_Statics::ClassParams = {
		&USaveGameData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USaveGameData_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USaveGameData()
	{
		if (!Z_Registration_Info_UClass_USaveGameData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USaveGameData.OuterSingleton, Z_Construct_UClass_USaveGameData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USaveGameData.OuterSingleton;
	}
	template<> GAMEPLAY_API UClass* StaticClass<USaveGameData>()
	{
		return USaveGameData::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USaveGameData);
	USaveGameData::~USaveGameData() {}
	struct Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_SaveGameData_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_SaveGameData_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USaveGameData, USaveGameData::StaticClass, TEXT("USaveGameData"), &Z_Registration_Info_UClass_USaveGameData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USaveGameData), 3604768441U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_SaveGameData_h_3877462328(TEXT("/Script/GamePlay"),
		Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_SaveGameData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_SaveGameData_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
