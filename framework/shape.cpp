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