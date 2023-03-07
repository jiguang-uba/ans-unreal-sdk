// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnalysysAgent.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "AnalysysAgentFunctionLibrary.h"

#define LOCTEXT_NAMESPACE "FAnalysysAgentModule"

void FAnalysysAgentModule::StartupModule()
{
	//UAnalysysAgentFunctionLibrary::LogStartFunction();
}

void FAnalysysAgentModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAnalysysAgentModule, AnalysysAgent)


