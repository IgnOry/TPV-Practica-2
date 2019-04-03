#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Worker.h"

using namespace std;

class Logger {

	static unique_ptr<Logger> instance_;
		

public:
	inline static void initInstance(string filename) { 
		if (instance_ == nullptr)
			instance(filename);
	};
	inline static void instance(string filename) {
		instance_.reset(new Logger(filename));
	};
	inline static Logger* getInstance() {
		return instance_.get();
	};
	~Logger() {
		log_.close();
	};
	void log(string info);
	void log(function<string()> f);
	
private:
	Logger(string filename);

	Worker worker_;
	ofstream log_;
};

