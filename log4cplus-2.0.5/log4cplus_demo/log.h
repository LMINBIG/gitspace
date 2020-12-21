/*****************************************************************************\
*
*                            停车场管理系统硬件虚拟平台 1.0
*
*           Copyright (C) 2019, 杭州华云科技有限公司 研发部
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* 文  件  名：log.h
* 用      途：日志模块的接口
* 作      者：李敏
* 创建日期：2019.11
* 版 本 号：1.0.0.001
* 修改历史：
*
* ===========================================================================
*
* N O T E:
*           1. Platform: WIN32
*
*****************************************************************************/

#pragma once

#if defined(__linux__)
#define VSPRINTF vsnprintf
#elif defined(_WIN32)
#define VSPRINTF _vsnprintf
#endif

class Log
{
public:
	Log();
	~Log();

	/// 启动日志系统
	/// @param[in] properties_filename 日志系统配置文件文件名
	/// log种类和属性都在配置文件中设置
	void Init(const char* properties_filename);
	void Close();

public:
	void Debug(const char* pFormat, ...);

	void Error(const char* pFormat, ...);

	void Fatal(const char* pFormat, ...);

	void Info(const char* pFormat, ...);

	void Warn(const char* pFormat, ...);

	void Trace(const char* pFormat, ...);

public:
	static inline Log* getSingletonPtr()
	{
		return &getSingleton();
	}

	static inline Log& getSingleton()
	{
		static Log _instance;
		return _instance;
	}

 };


#define HYLog Log::getSingleton()
//#define Plog Log::getSingleton()
//////////////////////////////////////////////////////////////////////////
// 断言日志
//////////////////////////////////////////////////////////////////////////
#define ASSERT_LOG(expr)\
    if ( (expr) ) {;} else g_Logger.Error(__FILE__, __LINE__, #expr);


//////////////////////////////////////////////////////////////////////////
// 以下的宏只有VS2005以及之上的版本可以使用！因为VS2005之下的版本不支持可变参数宏
//////////////////////////////////////////////////////////////////////////
#if defined(_MSC_VER) && _MSC_VER > 1400
#define LOG_DEBUG(...)    g_Logger.Debug(__VA_ARGS__);
#define LOG_ERROR(...)    g_Logger.Error(__VA_ARGS__);
#define LOG_FATAL(...)    g_Logger.Fatal(__VA_ARGS__);
#define LOG_INFO(...)     g_Logger.Info(__VA_ARGS__);
#define LOG_WARN(...)     g_Logger.Warn(__VA_ARGS__);
#define LOG_TRACE(...)    g_Logger.Trace(__VA_ARGS__);
#elif defined(__linux__)
#define LOG_DEBUG(...)    g_Logger.Debug(__VA_ARGS__);
#define LOG_ERROR(...)    g_Logger.Error(__VA_ARGS__);
#define LOG_FATAL(...)    g_Logger.Fatal(__VA_ARGS__);
#define LOG_INFO(...)     g_Logger.Info(__VA_ARGS__);
#define LOG_WARN(...)     g_Logger.Warn(__VA_ARGS__);
#define LOG_TRACE(...)    g_Logger.Trace(__VA_ARGS__);
#endif

