// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "a/aGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeaGameMode() {}
// Cross Module References
	A_API UClass* Z_Construct_UClass_AaGameMode();
	A_API UClass* Z_Construct_UClass_AaGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_a();
// End Cross Module References
	void AaGameMode::StaticRegisterNativesAaGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AaGameMode);
	UClass* Z_Construct_UClass_AaGameMode_NoRegister()
	{
		return AaGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AaGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AaGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_a,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AaGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "aGameMode.h" },
		{ "ModuleRelativePath", "aGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AaGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AaGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AaGameMode_Statics::ClassParams = {
		&AaGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AaGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AaGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AaGameMode()
	{
		if (!Z_Registration_Info_UClass_AaGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AaGameMode.OuterSingleton, Z_Construct_UClass_AaGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AaGameMode.OuterSingleton;
	}
	template<> A_API UClass* StaticClass<AaGameMode>()
	{
		return AaGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AaGameMode);
	AaGameMode::~AaGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_a_aGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_a_aGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AaGameMode, AaGameMode::StaticClass, TEXT("AaGameMode"), &Z_Registration_Info_UClass_AaGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AaGameMode), 3901968391U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_a_aGameMode_h_1362351262(TEXT("/Script/a"),
		Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_a_aGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_a_aGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
