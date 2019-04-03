#include "Logger.h"

 unique_ptr<Logger> Logger::instance_ ;


Logger::Logger(string filename)
{
	log_.open(filename);
	worker_.start();
}

void Logger::log(string info)
{
	worker_.execute([this, info]() { log_ << info << endl; });
	
}

void Logger::log(function<string()> f)
{
	
}
