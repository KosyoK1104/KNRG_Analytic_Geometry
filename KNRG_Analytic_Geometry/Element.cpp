#include "Element.h"

#include <iostream>

std::ostream& operator<<(std::ostream& out, const Element& rhs) {
	return rhs.ins(out);
}

std::istream& operator>>(std::istream& in, Element& rhs) {
	return rhs.ext(in);
};

/*bool Element::operator==(const Element& e)
{
	return false;
}*/
