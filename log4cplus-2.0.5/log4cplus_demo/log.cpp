/**********************************************************************
* Copyright (C) 2019 -  - All Rights Reserved
*
* �ļ�����:       Log.cpp
* ժ    Ҫ:       ��־������,��־ģ��Ľӿ�
*
* ��    ��:       limin
* ��    ��:       �鿴�ļ����·�.
*
***********************************************************************/

#define  _CRT_SECURE_NO_WARNINGS
#include "log.h"

#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/ndc.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>


#include <memory>
#include <iostream>
//#include "HyPublic.h"

using namespace log4cplus;
using namespace log4cplus::helpers;

#define DO_LOGGER(logLevel, pFormat, bufSize)\
    log4cplus::Logger _logger = log4cplus::Logger::getInstance("rootLogger");\
    \
    if(_logger.isEnabledFor(logLevel))\
	{                \
		va_list args;            \
		va_start(args, pFormat);        \
		char buf[bufSize] = {0};        \
		VSPRINTF(buf, sizeof(buf), pFormat, args);    \
		va_end(args);           \
		_logger.forcedLog(logLevel, buf); \
	}


Log::Log()
{	
}


Log::~Log()
{

	log4cplus::Logger _logger = log4cplus::Logger::getInstance("rootLogger");
	LOG4CPLUS_INFO(_logger, "*********************************************************************************");
	LOG4CPLUS_INFO(_logger, "******************************HYParkingSytem Stop********************************");
	LOG4CPLUS_INFO(_logger, "*********************************************************************************");

	//DO_LOGGER(0, "*************************HYParkingSytem STOP**************************", 8192);
	_logger.shutdown();
}


void Log::Debug(const char* pFormat, ...)
{
	DO_LOGGER(log4cplus::DEBUG_LOG_LEVEL, pFormat, 8192);
}

void Log::Error(const char* pFormat, ...)
{
	DO_LOGGER(log4cplus::ERROR_LOG_LEVEL, pFormat, 8192);
}

void Log::Fatal(const char* pFormat, ...)
{
	DO_LOGGER(log4cplus::FATAL_LOG_LEVEL, pFormat, 8192);
}

void Log::Info(const char* pFormat, ...)
{
	DO_LOGGER(log4cplus::INFO_LOG_LEVEL, pFormat, 8192);
}

void Log::Warn(const char* pFormat, ...)
{
	DO_LOGGER(log4cplus::WARN_LOG_LEVEL, pFormat, 8192);
}

void Log::Trace(const char* pFormat, ...)
{
	DO_LOGGER(log4cplus::TRACE_LOG_LEVEL, pFormat, 8192);
}

void Log::Close()
{
	/*log4cplus::Logger _logger = log4cplus::Logger::getInstance("rootLogger");
	_logger.shutdown();*/
}

void Log::Init(const char* properties_filename)
{
	if (properties_filename == NULL) return;
	////����1��ʹ�������ļ�����log��ʽ
	log4cplus::initialize();
	log4cplus::PropertyConfigurator::doConfigure(properties_filename);
	log4cplus::Logger _logger = log4cplus::Logger::getInstance("rootLogger");


	//Logger _logger = Logger::getRoot();

	//����2������������log����
	//char szlogPath[256] = "";
	//SYSTEMTIME systime;
	//GetLocalTime(&systime);
	//_snprintf(szlogPath, sizeof(szlogPath) - 1, "%s\\%04d-%02d-%02d\\%04d-%02d-%02d.log", properties_filename, systime.wYear, systime.wMonth, systime.wDay, systime.wYear, systime.wMonth, systime.wDay);
	//
	////��Initializer����г�ʼ��
	//log4cplus::initialize();

	////��1��������FileAppender
	//SharedAppenderPtr _append(new RollingFileAppender(LOG4CPLUS_TEXT(szlogPath), 10 * 1024 * 1024, 10, true, true));
	//_append->setName(LOG4CPLUS_TEXT("file test"));

	////��2��������Appender�����ƺ������ʽ
	//log4cplus::tstring pattern = LOG4CPLUS_TEXT("%D{%Y-%m-%d %H:%M:%S.%q} %-5p [%5t] --- %m%n");
	//_append->setLayout(std::auto_ptr<Layout>(new PatternLayout(pattern)));
	////_append->setLayout(std::unique_ptr<Layout>(new PatternLayout(pattern)));

	//Logger::getRoot().addAppender(_append);
	//Logger root = Logger::getRoot();

	//Logger _logger = Logger::getInstance("rootLogger");
	//_logger.addAppender(_append);

}