# Unreal Engine SDK
## 1.使用说明
Unreal Engine SDK 同时支持通过c++代码或蓝图调用接口上报数据，目前支持Androi、iOS，其他平台为空实现
集成前请先[下载 SDK](https://github.com/jiguang-uba/ans-unreal-sdk)

## 2.版本兼容
Unreal Engine 5.0 及以上版本
目前支持 Android、iOS。

### 3.快速集成

#### 集成插件
 将AnalysysAB目录方式您的项目Plugins文件夹（如果plugins目录不存在则需要创建名为plugins的文件夹）
#### 使用插件
>集成AnalysysAB插件之后，需要执行以下步骤
>>· 开启 Unreal Editor
>>· 打开 编辑 → 插件，启用 AnalysysAB
>>· 重启Unreal Editor
>如果您希望直接在 C++ 代码中使用 AnalysysAB接口，需要在项目的 *.Build.cs 文件中添加以下内容：
`PrivateDependencyModuleNames.AddRange(new string[] { "AnalysysAB" });`
`PrivateIncludePathModuleNames.AddRange(new string[] { "AnalysysAB" });`
>此外，还需要在使用 SDK 的文件中引用 AnalysysAgentFunctionLibrary.h 头文件
`#include "AnalysysAgentFunctionLibrary.h"`

### 4. 初始化SDK
>在 C++ 代码中，可采用下述调用进行初始化：
`UAnalysysAgentFunctionLibrary::StartAnalysysAgent("https://uba-up.analysysdata.com","c909fyjrehss","APPLE",2);`
>在蓝图中初始化：
image.png
