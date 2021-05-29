#include "Element.h"

#include <iostream>
//предефиниране на оператор << (redefining of << operator)
std::ostream& operator<<(std::ostream& out, const Element& rhs) {
	return rhs.ins(out);
}
//предефиниране на оператор << (redefining of 
std::istream& operator>>(std::istream& in, Element& rhs) {
	return rhs.ext(in);
};
