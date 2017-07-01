#include "shape.hpp"

Shape::Shape():
    name_{"Shape"},
	color_{Color{0.0f, 0.0f, 0.0f}}
    {std::cout << "Konstruktor wird auf " << name_ << " aufgerufen \n";}

Shape::Shape(string const& name):
	name_{name},
	color_{Color{0.0f, 0.0f, 0.0f}}
	{std::cout << "Konstruktor wird auf " << name_ << " aufgerufen \n";}

Shape::Shape(string const& name, Color const& color):
	name_{name},
	color_{color}
	{std::cout << "Konstruktor wird auf " << name_ << " aufgerufen \n";}

Shape::~Shape(){
	std::cout << "Shape-Destruktor wird auf " << name_ << " aufgerufen \n";
}

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

std::ostream& operator <<(std::ostream& ostream, Shape const& s)
{
	return s.print(ostream);
}