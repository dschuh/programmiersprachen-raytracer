#include "shape.hpp"

Shape::Shape():
    color_{Color{0.0f, 0.0f, 0.0f}},
    name_{"Shape"}
    {}

Shape::Shape(String const& name):
	color_{Color{0.0f, 0.0f, 0.0f}},
	name_{name}
	{}

Shape::Shape(Color const& color, String const& name):
	color_{color},
	name_{name}
	{}

Color const& Shape::get_color() const{
    return color_;
}

String const& Shape::get_name() const{
    return name_;
}