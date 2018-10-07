#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H
#include <iostream>
#include <stdexcept>

using namespace std;

class ErrorHandler
{
public:
	enum ErrorType
	{
		Warning,
		Error
	};

public:
	ErrorHandler(string message, ErrorType type = Warning);
	ErrorHandler(const char* message, ErrorType type = Warning);
};

#endif //ERROR_HANDLER_H