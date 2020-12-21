/*****************************************************************************\
*
*                            ͣ��������ϵͳӲ������ƽ̨ 1.0
*
*           Copyright (C) 2019, ���ݻ��ƿƼ����޹�˾ �з���
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* ��  ��  ����log.h
* ��      ;����־ģ��Ľӿ�
* ��      �ߣ�����
* �������ڣ�2019.11
* �� �� �ţ�1.0.0.001
* �޸���ʷ��
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

	/// ������־ϵͳ
	/// @param[in] properties_filename ��־ϵͳ�����ļ��ļ���
	/// log��������Զ��������ļ�������
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
// ������־
//////////////////////////////////////////////////////////////////////////
#define ASSERT_LOG(expr)\
    if ( (expr) ) {;} else g_Logger.Error(__FILE__, __LINE__, #expr);


//////////////////////////////////////////////////////////////////////////
// ���µĺ�ֻ��VS2005�Լ�֮�ϵİ汾����ʹ�ã���ΪVS2005֮�µİ汾��֧�ֿɱ������
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

