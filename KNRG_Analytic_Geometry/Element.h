#ifndef Element_h
#define Element_h

#include<iostream>


class Element
{
public:
	virtual std::ostream& ins(std::ostream& out) const;
	virtual std::istream& ext(std::istream& in);
};

std::ostream& operator<< (std::ostream& out, const Element& rhs);
std::istream& operator>> (std::istream& out, const Element& rhs);

#endif