#include "Element.h"

#include <iostream>
//������������� �� �������� << (redefining of << operator)
std::ostream& operator<<(std::ostream& out, const Element& rhs) {
	return rhs.ins(out);
}
//������������� �� �������� << (redefining of 
std::istream& operator>>(std::istream& in, Element& rhs) {
	return rhs.ext(in);
};
