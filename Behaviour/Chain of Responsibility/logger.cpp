#include <bits/stdc++.h>
using namespace std;

class LoggerService {
	LoggerService *nextLogger;

public:
	LoggerService(LoggerService *nextLogger) {
		this->nextLogger = nextLogger;
	}

	void log(string level, string message) {
		if (isCorrectLevel(level)) {
			cout << level << ": " << message << endl;
		} else {
			nextLogger->log(level, message);
		}
	}

	bool virtual isCorrectLevel(string level) = 0;
};

class InfoLogger: public LoggerService {
public:
	InfoLogger(LoggerService *next): LoggerService(next) {}

	bool isCorrectLevel(string level) override {
		return (level == "INFO");
	}

};


class WarningLogger: public LoggerService {
public:
	WarningLogger(LoggerService *next): LoggerService(next) {}

	bool isCorrectLevel(string level) override {
		return (level == "WARN");
	}

};


class ErrorLogger: public LoggerService {
public:
	ErrorLogger(LoggerService *next): LoggerService(next) {}

	bool isCorrectLevel(string level) override {
		return (level == "ERROR");
	}

};


int32_t main()
{
	LoggerService *logger = new InfoLogger( new WarningLogger( new ErrorLogger(NULL)));

	logger->log("INFO", "this is INFO log!");
	logger->log("WARN", "this is WARN log!");
	logger->log("ERROR", "this is ERROR log!");
}
