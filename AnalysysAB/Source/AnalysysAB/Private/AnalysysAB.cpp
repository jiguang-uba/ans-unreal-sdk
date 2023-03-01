// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnalysysAB.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "AnalysysAgentFunctionLibrary.h"

#define LOCTEXT_NAMESPACE "FAnalysysABModule"

void FAnalysysABModule::StartupModule()
{
	//UAnalysysAgentFunctionLibrary::LogStartFunction();
}

void FAnalysysABModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAnalysysABModule, AnalysysAB)


