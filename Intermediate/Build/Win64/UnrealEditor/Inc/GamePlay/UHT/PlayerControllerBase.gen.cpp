// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GamePlay/PlayerControllerBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerControllerBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	GAMEPLAY_API UClass* Z_Construct_UClass_APlayerControllerBase();
	GAMEPLAY_API UClass* Z_Construct_UClass_APlayerControllerBase_NoRegister();
	GAMEPLAY_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerInfo();
	UPackage* Z_Construct_UPackage__Script_GamePlay();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PlayerInfo;
class UScriptStruct* FPlayerInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PlayerInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PlayerInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlayerInfo, Z_Construct_UPackage__Script_GamePlay(), TEXT("PlayerInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PlayerInfo.OuterSingleton;
}
template<> GAMEPLAY_API UScriptStruct* StaticStruct<FPlayerInfo>()
{
	return FPlayerInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPlayerInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlayerInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "PlayerControllerBase.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPlayerInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlayerInfo>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlayerInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GamePlay,
		nullptr,
		&NewStructOps,
		"PlayerInfo",
		sizeof(FPlayerInfo),
		alignof(FPlayerInfo),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPlayerInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPlayerInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PlayerInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PlayerInfo.InnerSingleton, Z_Construct_UScriptStruct_FPlayerInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PlayerInfo.InnerSingleton;
	}
	void APlayerControllerBase::StaticRegisterNativesAPlayerControllerBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlayerControllerBase);
	UClass* Z_Construct_UClass_APlayerControllerBase_NoRegister()
	{
		return APlayerControllerBase::StaticClass();
	}
	struct Z_Construct_UClass_APlayerControllerBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayerControllerBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_GamePlay,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerControllerBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "PlayerControllerBase.h" },
		{ "ModuleRelativePath", "PlayerControllerBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayerControllerBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerControllerBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APlayerControllerBase_Statics::ClassParams = {
		&APlayerControllerBase::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_APlayerControllerBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerControllerBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlayerControllerBase()
	{
		if (!Z_Registration_Info_UClass_APlayerControllerBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlayerControllerBase.OuterSingleton, Z_Construct_UClass_APlayerControllerBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APlayerControllerBase.OuterSingleton;
	}
	template<> GAMEPLAY_API UClass* StaticClass<APlayerControllerBase>()
	{
		return APlayerControllerBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerControllerBase);
	APlayerControllerBase::~APlayerControllerBase() {}
	struct Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_PlayerControllerBase_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_PlayerControllerBase_h_Statics::ScriptStructInfo[] = {
		{ FPlayerInfo::StaticStruct, Z_Construct_UScriptStruct_FPlayerInfo_Statics::NewStructOps, TEXT("PlayerInfo"), &Z_Registration_Info_UScriptStruct_PlayerInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlayerInfo), 907437876U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_PlayerControllerBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APlayerControllerBase, APlayerControllerBase::StaticClass, TEXT("APlayerControllerBase"), &Z_Registration_Info_UClass_APlayerControllerBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayerControllerBase), 2295527035U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_PlayerControllerBase_h_754890778(TEXT("/Script/GamePlay"),
		Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_PlayerControllerBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_PlayerControllerBase_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_PlayerControllerBase_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_GamePlay_PlayerControllerBase_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
