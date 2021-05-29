#pragma once
#include <string>
#include <exception>
class EqualPointException :
	public std::exception
{
public:
    EqualPointException(std::string const&);
    EqualPointException(char const*);
    const char* what() const;

private:
    std::string errorMessage;
};

