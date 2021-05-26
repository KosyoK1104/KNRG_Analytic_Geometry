#include "Element.h"

#include <iostream>
//предефиниране на оператор <<
std::ostream& operator<<(std::ostream& out, const Element& rhs) {
	return rhs.ins(out);
}
//предефиниране на оператор <<
std::istream& operator>>(std::istream& in, Element& rhs) {
	return rhs.ext(in);
};
