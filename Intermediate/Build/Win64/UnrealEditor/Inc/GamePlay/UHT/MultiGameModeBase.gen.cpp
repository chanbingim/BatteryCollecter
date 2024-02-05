// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GamePlay/MultiGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	GAMEPLAY_API UClass* Z_Construct_UClass_AMultiGameModeBase();
	GAMEPLAY_API UClass* Z_Construct_UClass_AMultiGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GamePlay();
// End Cross Module References
	void AMultiGameModeBase::StaticRegisterNativesAMultiGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMultiGameModeBase);
	UClass* Z_Construct_UClass_AMultiGameModeBase_NoRegister()
	{
		return AMultiGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AMultiGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMultiGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GamePlay,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMultiGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MultiGameModeBase.h" },
		{ "ModuleRelativePath", "MultiGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMultiGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMultiGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMultiGameModeBase_Statics::ClassParams = {
		&AMultiGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMultiGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMultiGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMultiGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AMultiGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMultiGameModeBase.OuterSingleton, Z_Construct_UClass_AMultiGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMultiGameModeBase.OuterSingleton;
	}
	template<> GAMEPLAY_API UClass* StaticClass<AMultiGameModeBase>()
	{
		return AMultiGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMultiGameModeBase);
	AMultiGameModeBase::~AMultiGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_MultiGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_MultiGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMultiGameModeBase, AMultiGameModeBase::StaticClass, TEXT("AMultiGameModeBase"), &Z_Registration_Info_UClass_AMultiGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMultiGameModeBase), 2726879870U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_MultiGameModeBase_h_3003767353(TEXT("/Script/GamePlay"),
		Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_MultiGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_MultiGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
