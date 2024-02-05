// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Widget/UserWidgetBaseClass.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUserWidgetBaseClass() {}
// Cross Module References
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_Widget();
	WIDGET_API UClass* Z_Construct_UClass_UUserWidgetBaseClass();
	WIDGET_API UClass* Z_Construct_UClass_UUserWidgetBaseClass_NoRegister();
	WIDGET_API UScriptStruct* Z_Construct_UScriptStruct_FVairable();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Vairable;
class UScriptStruct* FVairable::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Vairable.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Vairable.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVairable, Z_Construct_UPackage__Script_Widget(), TEXT("Vairable"));
	}
	return Z_Registration_Info_UScriptStruct_Vairable.OuterSingleton;
}
template<> WIDGET_API UScriptStruct* StaticStruct<FVairable>()
{
	return FVairable::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVairable_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVairable_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "UserWidgetBaseClass.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVairable_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVairable>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVairable_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Widget,
		nullptr,
		&NewStructOps,
		"Vairable",
		sizeof(FVairable),
		alignof(FVairable),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVairable_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVairable_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVairable()
	{
		if (!Z_Registration_Info_UScriptStruct_Vairable.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Vairable.InnerSingleton, Z_Construct_UScriptStruct_FVairable_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_Vairable.InnerSingleton;
	}
	void UUserWidgetBaseClass::StaticRegisterNativesUUserWidgetBaseClass()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUserWidgetBaseClass);
	UClass* Z_Construct_UClass_UUserWidgetBaseClass_NoRegister()
	{
		return UUserWidgetBaseClass::StaticClass();
	}
	struct Z_Construct_UClass_UUserWidgetBaseClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUserWidgetBaseClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Widget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUserWidgetBaseClass_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UserWidgetBaseClass.h" },
		{ "ModuleRelativePath", "UserWidgetBaseClass.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUserWidgetBaseClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUserWidgetBaseClass>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUserWidgetBaseClass_Statics::ClassParams = {
		&UUserWidgetBaseClass::StaticClass,
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
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUserWidgetBaseClass_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUserWidgetBaseClass_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUserWidgetBaseClass()
	{
		if (!Z_Registration_Info_UClass_UUserWidgetBaseClass.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUserWidgetBaseClass.OuterSingleton, Z_Construct_UClass_UUserWidgetBaseClass_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUserWidgetBaseClass.OuterSingleton;
	}
	template<> WIDGET_API UClass* StaticClass<UUserWidgetBaseClass>()
	{
		return UUserWidgetBaseClass::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUserWidgetBaseClass);
	UUserWidgetBaseClass::~UUserWidgetBaseClass() {}
	struct Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_Widget_UserWidgetBaseClass_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_Widget_UserWidgetBaseClass_h_Statics::ScriptStructInfo[] = {
		{ FVairable::StaticStruct, Z_Construct_UScriptStruct_FVairable_Statics::NewStructOps, TEXT("Vairable"), &Z_Registration_Info_UScriptStruct_Vairable, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVairable), 1524470397U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_Widget_UserWidgetBaseClass_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUserWidgetBaseClass, UUserWidgetBaseClass::StaticClass, TEXT("UUserWidgetBaseClass"), &Z_Registration_Info_UClass_UUserWidgetBaseClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUserWidgetBaseClass), 1111441100U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_Widget_UserWidgetBaseClass_h_444898146(TEXT("/Script/Widget"),
		Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_Widget_UserWidgetBaseClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_Widget_UserWidgetBaseClass_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_Widget_UserWidgetBaseClass_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_rlack_Documents_GitHub_BatteryCollecter_Source_Widget_UserWidgetBaseClass_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
