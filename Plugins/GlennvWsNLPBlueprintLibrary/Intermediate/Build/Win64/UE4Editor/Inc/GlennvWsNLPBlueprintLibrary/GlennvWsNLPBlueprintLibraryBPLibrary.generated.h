// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GLENNVWSNLPBLUEPRINTLIBRARY_GlennvWsNLPBlueprintLibraryBPLibrary_generated_h
#error "GlennvWsNLPBlueprintLibraryBPLibrary.generated.h already included, missing '#pragma once' in GlennvWsNLPBlueprintLibraryBPLibrary.h"
#endif
#define GLENNVWSNLPBLUEPRINTLIBRARY_GlennvWsNLPBlueprintLibraryBPLibrary_generated_h

#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetFileListOfRootFolder) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Files); \
		P_GET_PROPERTY(UStrProperty,Z_Param_RootFolderFullPath); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Ext); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UGlennvWsNLPBlueprintLibraryBPLibrary::GetFileListOfRootFolder(Z_Param_Out_Files,Z_Param_RootFolderFullPath,Z_Param_Ext); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGlennvWsNLPBlueprintLibrarySampleFunction) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UGlennvWsNLPBlueprintLibraryBPLibrary::GlennvWsNLPBlueprintLibrarySampleFunction(Z_Param_Param); \
		P_NATIVE_END; \
	}


#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetFileListOfRootFolder) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Files); \
		P_GET_PROPERTY(UStrProperty,Z_Param_RootFolderFullPath); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Ext); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UGlennvWsNLPBlueprintLibraryBPLibrary::GetFileListOfRootFolder(Z_Param_Out_Files,Z_Param_RootFolderFullPath,Z_Param_Ext); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGlennvWsNLPBlueprintLibrarySampleFunction) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UGlennvWsNLPBlueprintLibraryBPLibrary::GlennvWsNLPBlueprintLibrarySampleFunction(Z_Param_Param); \
		P_NATIVE_END; \
	}


#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGlennvWsNLPBlueprintLibraryBPLibrary(); \
	friend struct Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UGlennvWsNLPBlueprintLibraryBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GlennvWsNLPBlueprintLibrary"), NO_API) \
	DECLARE_SERIALIZER(UGlennvWsNLPBlueprintLibraryBPLibrary)


#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUGlennvWsNLPBlueprintLibraryBPLibrary(); \
	friend struct Z_Construct_UClass_UGlennvWsNLPBlueprintLibraryBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UGlennvWsNLPBlueprintLibraryBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GlennvWsNLPBlueprintLibrary"), NO_API) \
	DECLARE_SERIALIZER(UGlennvWsNLPBlueprintLibraryBPLibrary)


#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGlennvWsNLPBlueprintLibraryBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGlennvWsNLPBlueprintLibraryBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGlennvWsNLPBlueprintLibraryBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGlennvWsNLPBlueprintLibraryBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGlennvWsNLPBlueprintLibraryBPLibrary(UGlennvWsNLPBlueprintLibraryBPLibrary&&); \
	NO_API UGlennvWsNLPBlueprintLibraryBPLibrary(const UGlennvWsNLPBlueprintLibraryBPLibrary&); \
public:


#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGlennvWsNLPBlueprintLibraryBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGlennvWsNLPBlueprintLibraryBPLibrary(UGlennvWsNLPBlueprintLibraryBPLibrary&&); \
	NO_API UGlennvWsNLPBlueprintLibraryBPLibrary(const UGlennvWsNLPBlueprintLibraryBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGlennvWsNLPBlueprintLibraryBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGlennvWsNLPBlueprintLibraryBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGlennvWsNLPBlueprintLibraryBPLibrary)


#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET
#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_25_PROLOG
#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET \
	G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_RPC_WRAPPERS \
	G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_INCLASS \
	G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET \
	G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_INCLASS_NO_PURE_DECLS \
	G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h_28_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GlennvWsNLPBlueprintLibraryBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID G__Desktop_DAE_Internship_AI_Plugins_GlennvWsNLPBlueprintLibrary_HostProject_Plugins_GlennvWsNLPBlueprintLibrary_Source_GlennvWsNLPBlueprintLibrary_Public_GlennvWsNLPBlueprintLibraryBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
