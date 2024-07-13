#include <bits/stdc++.h>
using namespace std;

class Logger {
	// we have to initialise it outside the class
	static int count;
public:
	Logger() {
		count++;
		cout << "New logger instance created !! Total = " << count << endl;
	}

	void Log(string msg) {
		cout << msg << endl;
	}
};
int Logger::count = 0;



class SingleLogger {
	// we have to initialise it outside the class
	static int count;
	static SingleLogger* loggerObj;
	SingleLogger() {
		count++;
		cout << "> New Singlelogger instance created !! Total = " << count << endl;
	}

public:
	static SingleLogger* getLoggerInstance() {
		if (loggerObj == nullptr) {
			loggerObj = new SingleLogger();
		}
		return loggerObj;
	}

	void Log(string msg) {
		cout << msg << endl;
	}
};
int SingleLogger::count = 0;
SingleLogger* SingleLogger::loggerObj = nullptr;




int32_t main()
{
	/*
	Singletone pattern means we only create 1 instance (object) of class
	In real world this is used in logger, db client etc
	*/

	Logger* logger1 = new Logger();
	logger1->Log("Logging with logger1");


	Logger* logger2 = new Logger();
	logger2->Log("Logging with logger2");

	/*
	How to make singletone class
	1. track number of objects using static counter
	2. put constructor in private so no body can create object
	3. create a static obj (belongs to class)
	4. now create a static function of CLASS, so it belongs to class not object to
	   create loggerObj
	*/

	SingleLogger* log1 = SingleLogger::getLoggerInstance();
	log1->Log("Singletone logger implemented with log1");

	SingleLogger* log2 = SingleLogger::getLoggerInstance();
	log2->Log("Singletone logger implemented withlog2");

	/*
	DEFINITION OF SINGLETONE:
	The Singleton pattern is a type of design pattern that restricts the instantiation
	of a class to a single object. This allows the class to create its instance the
	first time it is instantiated. However, on the next try, the existing instance of the
	class is returned. No new instance is created.
	*/

}
