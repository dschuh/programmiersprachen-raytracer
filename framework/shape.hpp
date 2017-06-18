#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"

using namespace std;

class Shape{

private:

	Color color_;
	string name_;	

public:

	Shape();
	Shape(string const& name);
	Shape(string const& name, Color const& color);

	Color const& get_color() const;
	string const& get_name() const;

	virtual float area() const =0;
	virtual float volume() const =0;

	//virtual std::ostream& print(std::ostream& os) const;

};

std::ostream& operator <<(std::ostream& os, Shape const& shape);

#endif