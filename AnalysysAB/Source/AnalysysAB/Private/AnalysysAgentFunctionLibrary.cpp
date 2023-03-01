// Fill out your copyright notice in the Description page of Project Settings.


#include "AnalysysAgentFunctionLibrary.h"
#include "iOS/AnalysysABIOS.h"
#include "PC/AnalysysABPC.h"
#include "Android/AnalysysABAndroid.h"

#if PLATFORM_ANDROID
#define AnalyticsPlatformAB AnalysysABAndroid
#elif PLATFORM_IOS
#define AnalyticsPlatformAB AnalysysABIOS
#else
#define AnalyticsPlatformAB AnalysysABPC
#endif


void UAnalysysAgentFunctionLibrary::LogStartFunction() 
{
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("run plugin with StartupModule function call.")));
    UE_LOG(LogTemp, Display, TEXT("UAnalysysAgentFunctionLibrary::LogStartFunction()"));
}

void UAnalysysAgentFunctionLibrary::StartAnalysysAgent(const FString& url,const FString& appkey,const FString& channel,int debugMode)
{
    auto &manager = IPluginManager::Get();
    auto plugin = manager.FindPlugin("AnalysysAB");

    if (!plugin.IsValid()) 
    {
        return;
    }
    AnalyticsPlatformAB::start(url,appkey,channel,debugMode);
}

void UAnalysysAgentFunctionLibrary::flush()
{
    AnalyticsPlatformAB::flush();
}

void UAnalysysAgentFunctionLibrary::alias(const FString& aliasId)
{
    AnalyticsPlatformAB::alias(aliasId);
}

void UAnalysysAgentFunctionLibrary::identify(const FString& distinctId)
{
    AnalyticsPlatformAB::identify(distinctId);
}

FString UAnalysysAgentFunctionLibrary::getDistinctId()
{
    return AnalyticsPlatformAB::getDistinctId();
}

void UAnalysysAgentFunctionLibrary::reset()
{
    AnalyticsPlatformAB::reset();
}

void UAnalysysAgentFunctionLibrary::track(const FString& eventName, const FString& params)
{
    AnalyticsPlatformAB::track(eventName,params);
}

void UAnalysysAgentFunctionLibrary::pageView(const FString& pageName ,const FString& params)
{
    AnalyticsPlatformAB::pageView(pageName,params);
}

void UAnalysysAgentFunctionLibrary::registerSuperProperties(const FString& params)
{
    AnalyticsPlatformAB::registerSuperProperties(params);
}

void UAnalysysAgentFunctionLibrary::unRegisterSuperProperty(const FString& params)
{
    AnalyticsPlatformAB::unRegisterSuperProperty(params);
}

void UAnalysysAgentFunctionLibrary::clearSuperProperties()
{
    AnalyticsPlatformAB::clearSuperProperties();
}

void UAnalysysAgentFunctionLibrary::profileSet(const FString& params)
{
    AnalyticsPlatformAB::profileSet(params);
}

void UAnalysysAgentFunctionLibrary::profileSetOnce(const FString& params)
{
    AnalyticsPlatformAB::profileSetOnce(params);
}

void UAnalysysAgentFunctionLibrary::profileIncrement(const FString& params)
{
    AnalyticsPlatformAB::profileIncrement(params);
}

void UAnalysysAgentFunctionLibrary::profileAppend(const FString& params)
{
    AnalyticsPlatformAB::profileAppend(params);
}

void UAnalysysAgentFunctionLibrary::profileUnset(const FString& params)
{
    AnalyticsPlatformAB::profileUnset(params);
}

void UAnalysysAgentFunctionLibrary::profileDelete()
{
    AnalyticsPlatformAB::profileDelete();
}
