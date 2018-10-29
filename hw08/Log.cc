// loggin singleton class
//
#include<iostream>
#include"Log.h"
// private constructor
//
Log::Log(){
	// create log instance
}

// call the constructor and return the instance
Log& Log::getInstance(){
	static Log log; // this only get executed for the first time
	return log;
}

// destructor
Log::~Log(){
}


// debug print statement
void Log::printd(const std::string& str) const{
	std::cout << str << std::endl;
}

