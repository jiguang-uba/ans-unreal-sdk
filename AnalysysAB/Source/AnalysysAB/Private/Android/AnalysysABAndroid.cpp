//
//  AnalysysABIOS.cpp
//  FirstGame
//
//  Created by
//  Copyright © 2022 Epic Games, Inc. All rights reserved.
//

#if PLATFORM_ANDROID

#include "AnalysysABAndroid.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

static FString FStringFromLocalRef(JNIEnv* Env, jstring JavaString)
{
    FString ReturnString = FJavaHelper::FStringFromParam(Env, JavaString);

    if (Env && JavaString)
    {
        Env->DeleteLocalRef(JavaString);
    }

    return ReturnString;

}

void AnalysysABAndroid::start(const FString& url,const FString& appkey,const FString& channel,int debugMode)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "initAnalysysAgent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", false);
    jstring serverUrlString = env->NewStringUTF(TCHAR_TO_UTF8(*url));
    jstring appkeyString = env->NewStringUTF(TCHAR_TO_UTF8(*appkey));
    jstring channelString = env->NewStringUTF(TCHAR_TO_UTF8(*channel));
    jint debugModeInt = debugMode;
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, 
        methodID, serverUrlString, appkeyString, channelString, debugModeInt);
}

void AnalysysABAndroid::flush()
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "flush", "()V", false);
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID);
}

void AnalysysABAndroid::alias(const FString& aliasId)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "alias", "(Ljava/lang/String;)V", false);
    jstring aliasIdString = env->NewStringUTF(TCHAR_TO_UTF8(*aliasId));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, aliasIdString);
}

void AnalysysABAndroid::identify(const FString& param)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "identify", "(Ljava/lang/String;)V", false);
    jstring paramString = env->NewStringUTF(TCHAR_TO_UTF8(*param));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, paramString);
}

FString AnalysysABAndroid::getDistinctId()
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "getDistinctId", "()Ljava/lang/String;", false);
    jstring resultString = (jstring)FJavaWrapper::CallObjectMethod(env, FJavaWrapper::GameActivityThis, methodID);
    if (resultString != NULL)
    {
        return FStringFromLocalRef(env,resultString);
    }
    return "";
}

void AnalysysABAndroid::reset()
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "reset", "()V", false);
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID);
}

void AnalysysABAndroid::track(const FString& eventName ,const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "track", "(Ljava/lang/String;Ljava/lang/String;)V", false);
    jstring eventNameString = env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, eventNameString, properties);
}

void AnalysysABAndroid::pageView(const FString& pageName ,const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "pageView", "(Ljava/lang/String;Ljava/lang/String;)V", false);
    jstring pageNameString = env->NewStringUTF(TCHAR_TO_UTF8(*pageName));
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, pageNameString, properties);
}

void AnalysysABAndroid::registerSuperProperties(const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "registerSuperProperties", "(Ljava/lang/String;)V", false);
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, properties);
}

void AnalysysABAndroid::unRegisterSuperProperty(const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "unRegisterSuperProperty", "(Ljava/lang/String;)V", false);
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, properties);
}

void AnalysysABAndroid::clearSuperProperties()
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "clearSuperProperties", "()V", false);
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID);
}

void AnalysysABAndroid::profileSet(const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "profileSet", "(Ljava/lang/String;)V", false);
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, properties);
}

void AnalysysABAndroid::profileSetOnce(const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "profileSetOnce", "(Ljava/lang/String;)V", false);
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, properties);
}

void AnalysysABAndroid::profileIncrement(const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "profileIncrement", "(Ljava/lang/String;)V", false);
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, properties);
}

void AnalysysABAndroid::profileAppend(const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "profileAppend", "(Ljava/lang/String;)V", false);
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, properties);
}

void AnalysysABAndroid::profileUnset(const FString& params)
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "profileUnset", "(Ljava/lang/String;)V", false);
    jstring properties = env->NewStringUTF(TCHAR_TO_UTF8(*params));
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID, properties);
}

void AnalysysABAndroid::profileDelete()
{
    JNIEnv* env = FAndroidApplication::GetJavaEnv();
    jmethodID methodID = FJavaWrapper::FindMethod(env, FJavaWrapper::GameActivityClassID, "profileDelete", "()V", false);
    FJavaWrapper::CallVoidMethod(env, FJavaWrapper::GameActivityThis, methodID);
}

#endif