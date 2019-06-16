// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GlennvWsNLPBlueprintLibrary/Public/GlennvWsNLPBlueprintLibraryBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGlennvWsNLPBlueprintLibraryBPLibrary() {}
// Cross Module References
	GLENNVWSNLPBLUEPRINTLIBRARY_API UClass* Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_NoRegister();
	GLENNVWSNLPBLUEPRINTLIBRARY_API UClass* Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_GlennvWsNLPBlueprintLibrary();
	GLENNVWSNLPBLUEPRINTLIBRARY_API UFunction* Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder();
	GLENNVWSNLPBLUEPRINTLIBRARY_API UFunction* Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction();
// End Cross Module References
	void UGlennvWsNLPBlueprintLibraryBPLibrary::StaticRegisterNativesUGlennvWsNLPBlueprintLibraryBPLibrary()
	{
		UClass* Class = UGlennvWsNLPBlueprintLibraryBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetFileListOfRootFolder", &UGlennvWsNLPBlueprintLibraryBPLibrary::execGetFileListOfRootFolder },
			{ "GlennvWsNLPBlueprintLibrarySampleFunction", &UGlennvWsNLPBlueprintLibraryBPLibrary::execGlennvWsNLPBlueprintLibrarySampleFunction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics
	{
		struct GlennvWsNLPBlueprintLibraryBPLibrary_eventGetFileListOfRootFolder_Parms
		{
			TArray<FString> Files;
			FString RootFolderFullPath;
			FString Ext;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Ext;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_RootFolderFullPath;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Files;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Files_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GlennvWsNLPBlueprintLibraryBPLibrary_eventGetFileListOfRootFolder_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GlennvWsNLPBlueprintLibraryBPLibrary_eventGetFileListOfRootFolder_Parms), &Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_Ext = { UE4CodeGen_Private::EPropertyClass::Str, "Ext", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GlennvWsNLPBlueprintLibraryBPLibrary_eventGetFileListOfRootFolder_Parms, Ext), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_RootFolderFullPath = { UE4CodeGen_Private::EPropertyClass::Str, "RootFolderFullPath", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GlennvWsNLPBlueprintLibraryBPLibrary_eventGetFileListOfRootFolder_Parms, RootFolderFullPath), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_Files = { UE4CodeGen_Private::EPropertyClass::Array, "Files", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(GlennvWsNLPBlueprintLibraryBPLibrary_eventGetFileListOfRootFolder_Parms, Files), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_Files_Inner = { UE4CodeGen_Private::EPropertyClass::Str, "Files", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_Ext,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_RootFolderFullPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_Files,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::NewProp_Files_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::Function_MetaDataParams[] = {
		{ "Category", "GlennvWsNLPBlueprintLibraryTesting" },
		{ "DisplayName", "Get File List Of Root Folder" },
		{ "Keywords", "GlennvWsNLPBlueprintLibrary sample test testing" },
		{ "ModuleRelativePath", "Public/GlennvWsNLPBlueprintLibraryBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary, "GetFileListOfRootFolder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(GlennvWsNLPBlueprintLibraryBPLibrary_eventGetFileListOfRootFolder_Parms), Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics
	{
		struct GlennvWsNLPBlueprintLibraryBPLibrary_eventGlennvWsNLPBlueprintLibrarySampleFunction_Parms
		{
			float Param;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Param;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GlennvWsNLPBlueprintLibraryBPLibrary_eventGlennvWsNLPBlueprintLibrarySampleFunction_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::NewProp_Param = { UE4CodeGen_Private::EPropertyClass::Float, "Param", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GlennvWsNLPBlueprintLibraryBPLibrary_eventGlennvWsNLPBlueprintLibrarySampleFunction_Parms, Param), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::NewProp_Param,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::Function_MetaDataParams[] = {
		{ "Category", "GlennvWsNLPBlueprintLibraryTesting" },
		{ "DisplayName", "Execute Sample function" },
		{ "Keywords", "GlennvWsNLPBlueprintLibrary sample test testing" },
		{ "ModuleRelativePath", "Public/GlennvWsNLPBlueprintLibraryBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary, "GlennvWsNLPBlueprintLibrarySampleFunction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(GlennvWsNLPBlueprintLibraryBPLibrary_eventGlennvWsNLPBlueprintLibrarySampleFunction_Parms), Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_NoRegister()
	{
		return UGlennvWsNLPBlueprintLibraryBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_GlennvWsNLPBlueprintLibrary,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GetFileListOfRootFolder, "GetFileListOfRootFolder" }, // 2852864540
		{ &Z_Construct_UFunction_UGlennvWsNLPBlueprintLibraryBPLibrary_GlennvWsNLPBlueprintLibrarySampleFunction, "GlennvWsNLPBlueprintLibrarySampleFunction" }, // 2762604022
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GlennvWsNLPBlueprintLibraryBPLibrary.h" },
		{ "ModuleRelativePath", "Public/GlennvWsNLPBlueprintLibraryBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGlennvWsNLPBlueprintLibraryBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics::ClassParams = {
		&UGlennvWsNLPBlueprintLibraryBPLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGlennvWsNLPBlueprintLibraryBPLibrary, 603126245);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary(Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary, &UGlennvWsNLPBlueprintLibraryBPLibrary::StaticClass, TEXT("/Script/GlennvWsNLPBlueprintLibrary"), TEXT("UGlennvWsNLPBlueprintLibraryBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGlennvWsNLPBlueprintLibraryBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
