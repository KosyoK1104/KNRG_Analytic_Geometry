#ifndef Element_h
#define Element_h

#include<iostream>


class Element
{
public:
	virtual std::ostream& ins(std::ostream& out) const = 0;
	virtual std::istream& ext(std::istream& in) = 0;

};

std::ostream& operator<< (std::ostream& out, const Element& rhs);
std::istream& operator>> (std::istream& out, const Element& rhs);

#endif