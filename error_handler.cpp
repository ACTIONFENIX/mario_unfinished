#include "error_handler.h"

ErrorHandler::ErrorHandler(string message, ErrorType type)
{
	if (type == Warning)
		cout << "Error: " << message << endl;
	else
		throw logic_error(string("Error") + message);
}

ErrorHandler::ErrorHandler(const char* message, ErrorType type)
{
	ErrorHandler(string(message));
}
