#pragma once

#include "Misc.h"

#define LOG_ENABLED
#ifdef LOG_ENABLED
#define LOG_DEBUG(msg)		Logger::instance()->format("DEBUG", msg)
#define LOG_ERROR(msg)		Logger::instance()->format("ERROR", msg)
#define LOG_WARN(msg)		Logger::instance()->format("WARNING", msg)
#define LOG_INFO(msg)		Logger::instance()->format("INFO", msg)
#else
#define LOG_DEBUG(msg)
#define LOG_ERROR(msg)
#define LOG_WARN(msg)
#define LOG_INFO(msg)
#endif

class Logger {
public:
	enum Method {
		PrintMethod = 1 << 1,
		WriteMethod = 1 << 2
	};
private:
	std::ofstream		_stream;
	unsigned			_flags;
	Logger();
	~Logger();
	static Logger*		_instance;
	static std::string	getTimeStr();
public:
		   void			format(std::string level, std::string msg);
		   void			setMethod(unsigned);
		   bool			openLog(std::string = "log.txt", unsigned method = PrintMethod);
	static void			close();
	static Logger*		instance();
};
