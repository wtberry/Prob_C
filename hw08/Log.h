// singleton Log class
#ifndef LOG_H
#define LOG_H
#include<iostream>
#include"Log.h"

class Log{

private:
	Log(); // the private constructor
	
public:
	static Log& getInstance(); // is it constant, return reference to Log
	virtual ~Log();
	
	void printd(const std::string& str) const;




}; // fucking semi colon
#endif
