//
//  AnalysysABIOS.mm
//  FirstGame
//
//  Created by 
//  Copyright © 2022 Epic Games, Inc. All rights reserved.
//

#if PLATFORM_IOS

#import <Foundation/Foundation.h>
#include "AnalysysABIOS.h"
#import <AnalysysAgent/AnalysysAgent.h>


NSDictionary * ConvertJsonToDictionary(const char *json)
{
    NSString *jsonString = json != NULL ? [NSString stringWithUTF8String:json] : nil;
    if (!jsonString)
    {
        return nil;
    }
    NSDictionary * paramDic = nil;
    if (jsonString) {
        NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
        NSError *err = nil;
        NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData
                                                            options:NSJSONReadingMutableContainers
                                                              error:&err];
        if(err == nil && dic.count >0) {
            paramDic = [dic mutableCopy];
        }
    }
    return paramDic;
}

void AnalysysABIOS::start(const FString& url,const FString& appkey,const FString& channel,int debugMode)
{
	const char *char_url = TCHAR_TO_UTF8(*url);
    if (!char_url)
    {
        return;
    }
	NSString *serverUrl = [NSString stringWithUTF8String:char_url];
	const char *char_appkey = TCHAR_TO_UTF8(*appkey);
    if (!char_appkey)
    {
        return;
    }
	NSString *appkeyNSString = [NSString stringWithUTF8String:char_appkey];
	const char *char_channel = TCHAR_TO_UTF8(*channel);
    if (!char_channel)
    {
        return;
    }
	NSString *channelNSString = [NSString stringWithUTF8String:char_channel];
	AnalysysConfig.appKey = [appkeyNSString copy];
	AnalysysConfig.channel = [channelNSString copy];
	[AnalysysAgent startWithConfig:AnalysysConfig];
	[AnalysysAgent setAutoTrackClick:false];
	[AnalysysAgent setUploadURL:serverUrl];
	[AnalysysAgent setDebugMode:(AnalysysDebugMode)debugMode];
}

void AnalysysABIOS::flush()
{
    [AnalysysAgent flush];
}

void AnalysysABIOS::alias(const FString& aliasId)
{
    const char *char_aliasId = TCHAR_TO_UTF8(*aliasId);
    if (!char_aliasId)
    {
        return;
    }
    NSString *aliasIdString = [NSString stringWithUTF8String:char_aliasId];
    [AnalysysAgent alias:aliasIdString];
}

void AnalysysABIOS::identify(const FString& distinctId)
{
    const char *char_distinctId = TCHAR_TO_UTF8(*distinctId);
    if (!char_distinctId)
    {
        return;
    }
    NSString *distinctIdString = [NSString stringWithUTF8String:char_distinctId];
    [AnalysysAgent identify:distinctIdString];
}

FString AnalysysABIOS::getDistinctId()
{
    char *char_distinctId = (char *)[[AnalysysAgent getDistinctId] UTF8String];
    if (!char_distinctId)
    {
        return "";
    }
    FString result = FString(UTF8_TO_TCHAR(char_distinctId));
    return result;
}

void AnalysysABIOS::reset()
{
    [AnalysysAgent reset];
}

void AnalysysABIOS::track(const FString& eventName ,const FString& params)
{
    const char *char_event_name = TCHAR_TO_UTF8(*eventName);
    if (!char_event_name) {
        return;
    }
    NSString *eventNameString = [NSString stringWithUTF8String:char_event_name];
    const char *char_params = TCHAR_TO_UTF8(*params);
    NSDictionary *tempDict = ConvertJsonToDictionary(char_params);
    [AnalysysAgent track:eventNameString properties:tempDict];
}

void AnalysysABIOS::pageView(const FString& pageName ,const FString& params)
{
    const char *char_page_name = TCHAR_TO_UTF8(*pageName);
    if (!char_page_name) {
        return;
    }
    NSString *pageNameString = [NSString stringWithUTF8String:char_page_name];
    const char *char_params = TCHAR_TO_UTF8(*params);
    NSDictionary *tempDict = ConvertJsonToDictionary(char_params);
    [AnalysysAgent track:pageNameString properties:tempDict];
}

void AnalysysABIOS::registerSuperProperties(const FString& params)
{
    const char *char_params = TCHAR_TO_UTF8(*params);
    if (!char_params) {
        return;
    }
    NSDictionary *tempDict = ConvertJsonToDictionary(char_params);
    [AnalysysAgent registerSuperProperties:tempDict];
}

void AnalysysABIOS::unRegisterSuperProperty(const FString& params)
{
    const char *char_params = TCHAR_TO_UTF8(*params);
    if (!char_params) {
        return;
    }
    NSString *paramString = [NSString stringWithUTF8String:char_params];
    [AnalysysAgent unRegisterSuperProperty:paramString];
}

void AnalysysABIOS::clearSuperProperties()
{
    [AnalysysAgent clearSuperProperties];
}

void AnalysysABIOS::profileSet(const FString& params)
{
    const char *char_params = TCHAR_TO_UTF8(*params);
    if (!char_params) {
        return;
    }
    NSDictionary *tempDict = ConvertJsonToDictionary(char_params);
    [AnalysysAgent profileSet:tempDict];
}

void AnalysysABIOS::profileSetOnce(const FString& params)
{
    const char *char_params = TCHAR_TO_UTF8(*params);
    if (!char_params) {
        return;
    }
    NSDictionary *tempDict = ConvertJsonToDictionary(char_params);
    [AnalysysAgent profileSetOnce:tempDict];
}

void AnalysysABIOS::profileIncrement(const FString& params)
{
    const char *char_params = TCHAR_TO_UTF8(*params);
    if (!char_params) {
        return;
    }
    NSDictionary *tempDict = ConvertJsonToDictionary(char_params);
    [AnalysysAgent profileIncrement:tempDict];
}

void AnalysysABIOS::profileAppend(const FString& params)
{
    const char *char_params = TCHAR_TO_UTF8(*params);
    if (!char_params) {
        return;
    }
    NSDictionary *tempDict = ConvertJsonToDictionary(char_params);
    [AnalysysAgent profileAppend:tempDict];
}

void AnalysysABIOS::profileUnset(const FString& params)
{
    const char *char_params = TCHAR_TO_UTF8(*params);
    if (!char_params) {
        return;
    }
    NSString *paramString = [NSString stringWithUTF8String:char_params];
    [AnalysysAgent profileUnset:paramString];
}

void AnalysysABIOS::profileDelete()
{
    [AnalysysAgent profileDelete];
}


#endif
