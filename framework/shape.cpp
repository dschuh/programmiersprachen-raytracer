#include "shape.hpp"

Shape::Shape():
    name_{"Shape"},
	color_{Color{0.0f, 0.0f, 0.0f}}
    {}

Shape::Shape(string const& name):
	name_{name},
	color_{Color{0.0f, 0.0f, 0.0f}}
	{}

Shape::Shape(string const& name, Color const& color):
	name_{name},
	color_{color}
	{}

Color const& Shape::get_color() const{
    return color_;
}

string const& Shape::get_name() const{
    return name_;
}

std::ostream& Shape::print(std::ostream& ostream) const
{
	ostream << "Name: "<< name_ << "\n"
			<< "Color: " << color_ 	;
	return ostream;
}

std::ostream& operator <<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}