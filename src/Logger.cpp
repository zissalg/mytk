#include "Logger.h"

Logger*  Logger::_instance = nullptr;

Logger::Logger() {
	openLog("log.txt", PrintMethod | WriteMethod);
}

Logger::~Logger() {
	_stream.close();
}

void Logger::close() {
	delete instance();
}

Logger* Logger::instance() {
	if (_instance == nullptr)
		_instance = new Logger();
	return _instance;
}

bool Logger::openLog(std::string fileName, unsigned method) {
	_stream.close();
	_stream.open(fileName);
	setMethod(method);

	return false;
}

void Logger::setMethod(unsigned flags) {
	_flags = flags;
}

void Logger::format(std::string level, std::string msg) {
	std::string temp = "[ " + getTimeStr() + " | " + level + " ] " + msg;

	if (_flags & WriteMethod)
		_stream << temp << std::endl;

	if (_flags & PrintMethod)
		std::cout << temp << std::endl;
}

std::string Logger::getTimeStr() {
	time_t now = time(nullptr);
	tm* lc = localtime(&now);
	std::string s;
	s += ((lc->tm_hour < 10) ? "0" + std::to_string(lc->tm_hour) : std::to_string(lc->tm_hour)) + ':';
	s += ((lc->tm_min < 10) ? "0" + std::to_string(lc->tm_min) : std::to_string(lc->tm_min)) + ':';
	s += ((lc->tm_sec < 10) ? "0" + std::to_string(lc->tm_sec) : std::to_string(lc->tm_sec));
	return s;
}
