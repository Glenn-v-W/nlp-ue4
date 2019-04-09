// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GlennvWsNLPBlueprintLibraryBPLibrary.h"
#include "GlennvWsNLPBlueprintLibrary.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "Runtime/Core/Public/HAL/FileManager.h"

UGlennvWsNLPBlueprintLibraryBPLibrary::UGlennvWsNLPBlueprintLibraryBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UGlennvWsNLPBlueprintLibraryBPLibrary::GlennvWsNLPBlueprintLibrarySampleFunction(float Param)
{
	return -1;
}

bool UGlennvWsNLPBlueprintLibraryBPLibrary::GetFileListOfRootFolder(TArray<FString>& Files, FString RootFolderFullPath, FString Ext)
{
	if (RootFolderFullPath.Len() < 1) return false;

	FPaths::NormalizeDirectoryName(RootFolderFullPath);

	IFileManager& FileManager = IFileManager::Get();

	if (Ext == "")
	{
		Ext = "*.*";
	}
	else
	{
		Ext = (Ext.Left(1) == ".") ? "*" + Ext : "*." + Ext;
	}

	FString FinalPath = RootFolderFullPath + "/" + Ext;
	FileManager.FindFiles(Files, *FinalPath, true, false);
	return true;
}

