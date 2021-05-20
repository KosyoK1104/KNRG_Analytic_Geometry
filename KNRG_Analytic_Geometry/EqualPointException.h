#include <exception>
#include <string>
#include "Point.h"

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
