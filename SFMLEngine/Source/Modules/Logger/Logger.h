#pragma once
#include <iostream>
#include <thread>

class Logger
{
public:
	static Logger* Instance();
	void PrintLog(std::string& Message);
private:
	static std::string Message_;
	bool FetchedMessage_ = false;
	std::thread* LoggerThread_;
	void StartupLogger();
private:
	explicit Logger() noexcept;
	virtual ~Logger() noexcept;
};

static auto* LG = Logger::Instance();