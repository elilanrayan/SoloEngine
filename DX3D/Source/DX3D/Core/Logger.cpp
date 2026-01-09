#include <DX3D/Core/Logger.h>
#include <iostream>


dx3d::Logger::Logger(LogLevel logLevel) : m_logLevel(logLevel)
{
	std::clog << "Masterclass" << "\n";
	std::clog << "--------------------" << "\n";
}

dx3d::Logger::~Logger()
{
}

void dx3d::Logger::log(LogLevel level, const char* message) 
{
	auto logLevelToString = [](LogLevel level) {
		switch (level)
		{
		case LogLevel::Info :
			return "info";

		case LogLevel::Warning:
			return "warning";
		case LogLevel::Error:
			return "Error";
		default:
			return "unknow";
		}
	};


	if (level > m_logLevel) return;
	std::clog << "[DX3D " << logLevelToString(level) << "]:" << message << "\n";
}
