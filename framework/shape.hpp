#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include <string>

typedef std::string String;

class Shape{

	Color color_;
	String name_;	

public:

	Shape();
	Shape(String const& name);
	Shape(Color const& color, String const& name);

	Color const& get_color() const;
	String const& get_name() const;

	virtual float area() const =0;
	virtual float volume() const =0;

	virtual std::ostream& print(std::ostream& os) const;

};

std::ostream& operator <<(std::ostream& os, Shape const& shape);

#endif