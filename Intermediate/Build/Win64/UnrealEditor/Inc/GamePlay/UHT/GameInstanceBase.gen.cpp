// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GamePlay/GameInstanceBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameInstanceBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	GAMEPLAY_API UClass* Z_Construct_UClass_UGameInstanceBase();
	GAMEPLAY_API UClass* Z_Construct_UClass_UGameInstanceBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GamePlay();
// End Cross Module References
	void UGameInstanceBase::StaticRegisterNativesUGameInstanceBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameInstanceBase);
	UClass* Z_Construct_UClass_UGameInstanceBase_NoRegister()
	{
		return UGameInstanceBase::StaticClass();
	}
	struct Z_Construct_UClass_UGameInstanceBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameInstanceBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_GamePlay,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameInstanceBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GameInstanceBase.h" },
		{ "ModuleRelativePath", "GameInstanceBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameInstanceBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameInstanceBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameInstanceBase_Statics::ClassParams = {
		&UGameInstanceBase::StaticClass,
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
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UGameInstanceBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameInstanceBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameInstanceBase()
	{
		if (!Z_Registration_Info_UClass_UGameInstanceBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameInstanceBase.OuterSingleton, Z_Construct_UClass_UGameInstanceBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGameInstanceBase.OuterSingleton;
	}
	template<> GAMEPLAY_API UClass* StaticClass<UGameInstanceBase>()
	{
		return UGameInstanceBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameInstanceBase);
	UGameInstanceBase::~UGameInstanceBase() {}
	struct Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_GameInstanceBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_GameInstanceBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGameInstanceBase, UGameInstanceBase::StaticClass, TEXT("UGameInstanceBase"), &Z_Registration_Info_UClass_UGameInstanceBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameInstanceBase), 2424524306U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_GameInstanceBase_h_3696292223(TEXT("/Script/GamePlay"),
		Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_GameInstanceBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_GameInstanceBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
