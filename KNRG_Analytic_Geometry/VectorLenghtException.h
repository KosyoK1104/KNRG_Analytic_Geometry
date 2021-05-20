#pragma once
#include <exception>
#include <string>

class VectorLenghtException :
    public std::exception
{
public:
    VectorLenghtException(std::string const&);
    VectorLenghtException(char const*);
    const char* what() const;

private:
    std::string errorMessage;
};

