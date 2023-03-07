// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnalysysAgentFunctionLibrary.generated.h"
/**
 * 
 */
UCLASS()
class ANALYSYSAGENT_API UAnalysysAgentFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void LogStartFunction();

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void StartAnalysysAgent(const FString& url,const FString& appkey,const FString& channel,int debugMode);
    
    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void flush();
    
    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void alias(const FString& aliasId);
    
    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void identify(const FString& distinctId);
    
    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static FString getDistinctId();
    
    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void reset();
    
    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void track(const FString& eventName ,const FString& params);

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void pageView(const FString& pageName, const FString& params);

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void registerSuperProperties(const FString& params);

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void unRegisterSuperProperty(const FString& params);

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void clearSuperProperties();

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void profileSet(const FString& params);

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void profileSetOnce(const FString& params);

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void profileIncrement(const FString& params);

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void profileAppend(const FString& params);

    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void profileUnset(const FString& params);
    
    UFUNCTION(BlueprintCallable, Category = "AnalysysAgent")
    static void profileDelete();
};
