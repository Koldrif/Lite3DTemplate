// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lite3DTemplate.h"

#define LOCTEXT_NAMESPACE "FLite3DTemplateModule"

void FLite3DTemplateModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FLite3DTemplateModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLite3DTemplateModule, Lite3DTemplate)