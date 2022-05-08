#include "pch.h"
#include "Logger.h"
#include <mutex>

std::string Logger::Message_ = std::string();

Logger::Logger() noexcept
{
	StartupLogger();
}

Logger::~Logger() noexcept
{
	if (LoggerThread_)
	{
		delete LoggerThread_;
	}
}


Logger* Logger::Instance()
{
	static Logger lg;
	return &lg;
}

void Logger::PrintLog(std::string& Message)
{
	FetchedMessage_ = true;
	Message_ = Message;
}

void Logger::StartupLogger()
{
	LoggerThread_ = new std::thread([&]() 
	{
			while (true)
			{
				static std::mutex mtx;
				mtx.lock();
				if (FetchedMessage_)
				{
					std::cout << Message_ << std::endl;
					FetchedMessage_ = false;
				}
				mtx.unlock();
			}
	});
	LoggerThread_->detach();
}
