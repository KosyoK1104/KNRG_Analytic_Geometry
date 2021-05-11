#include "Element.h"

#include <iostream>

std::ostream& ins(std::ostream& out) {
	
}

std::istream& ext(std::istream& in) {
	
}

std::ostream& operator<<(std::ostream& out, const Element& rhs) {
	return rhs.ins(out);
}

std::istream& operator>>(std::istream& in, Element& rhs) {
	return rhs.ext(in);
};