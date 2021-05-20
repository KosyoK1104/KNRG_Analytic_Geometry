#include "EqualPointException.h"

EqualPointException::EqualPointException(std::string const& what_arg) : errorMessage(what_arg) {}
EqualPointException::EqualPointException(char const* what_arg) : errorMessage(what_arg){}

const char* EqualPointException::what() const
{
	return errorMessage.c_str();
}
