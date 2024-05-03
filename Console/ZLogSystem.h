#pragma once
#include <iostream>
#include <mutex>
#include <cstdarg>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

class LogSystem
{
public:
	enum loglevel
	{
		level_info = 0, level_warning, level_error
	};
private:
	loglevel m_level = level_info;
	static LogSystem* m_log_system;
	static std::mutex m_mtx;
	char m_buffer[1024]; // �Զ����С�Ļ�����
	LogSystem() {}
	~LogSystem() {}
	char* BeginWrite() { return m_buffer; }
	size_t WritableBytes() { return sizeof(m_buffer); }

public:
	LogSystem(const LogSystem&) = delete;
	LogSystem& operator=(const LogSystem&) = delete;

	static LogSystem* getInstance();

	/**
	* ����loglevel
	* @param loglevel : level_info, level_warning, level_error 
	* @return void
	*/
	void setLogLevel(loglevel level);

	/**
	* ���info�ȼ�����Ϣ
	* @param string str 
	* @return void
	*/
	void log_Info(const char* format, ...);

	/**
	* ���warning�ȼ�����Ϣ
	* @param string str
	* @return void
	*/
	void log_Warning(const char* format, ...);

	/**
	* ���error�ȼ�����Ϣ
	* @param string str
	* @return void
	*/
	void log_Error(const char* format, ...);
};


