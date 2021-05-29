#include "VectorLenghtException.h"

VectorLenghtException::VectorLenghtException(std::string const& what_arg) : errorMessage(what_arg) {}

VectorLenghtException::VectorLenghtException(char const* what_arg) : errorMessage(what_arg) {}

const char* VectorLenghtException::what() const
{
	return errorMessage.c_str();
}

