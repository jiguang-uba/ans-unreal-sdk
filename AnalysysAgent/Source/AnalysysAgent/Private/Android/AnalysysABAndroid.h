//
//  AnalysysABAndroid.mm
//  FirstGame
//
//  Created by 
//  Copyright © 2022 Epic Games, Inc. All rights reserved.
//

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
class AnalysysABAndroid
{

public:
    static void start(const FString& url,const FString& appkey,const FString& channel,int debugMode);
    
    static void flush();
    
    static void alias(const FString& aliasId);
    
    static void identify(const FString& distinctId);
    
    static FString getDistinctId();
    
    static void reset();
    
    static void track(const FString& eventName, const FString& params);
    
    static void pageView(const FString& pageName, const FString& params);
//    
    static void registerSuperProperties(const FString& params);
    
    static void unRegisterSuperProperty(const FString& params);
    
    static void clearSuperProperties();
    
    static void profileSet(const FString& params);
    
    static void profileSetOnce(const FString& params);
    
    static void profileIncrement(const FString& params);
    
    static void profileAppend(const FString& params);
    
    static void profileUnset(const FString& params);
    
    static void profileDelete();
};
