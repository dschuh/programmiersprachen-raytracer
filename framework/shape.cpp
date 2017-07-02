#include "shape.hpp"

Shape::Shape():
    name_{"Shape"},
	material_{}
    {//std::cout << "Konstruktor wird auf " << name_ << " aufgerufen \n";
	}
    

Shape::Shape(std::string const& name):
	name_{name},
	material_{}
	{//std::cout << "Konstruktor wird auf " << name_ << " aufgerufen \n";
	}

Shape::Shape(std::string const& name, Material const& material):
	name_{name},
	material_{material}
	{//std::cout << "Konstruktor wird auf " << name_ << " aufgerufen \n";
	}

Shape::~Shape()
	{//std::cout << "Shape-Destruktor wird auf " << name_ << " aufgerufen \n";
	}

Material const& Shape::get_material() const{
    return material_;
}

std::string const& Shape::get_name() const{
    return name_;
}

std::ostream& Shape::print(std::ostream& ostream) const
{
	ostream << "Name: "<< name_ << "\n"
			<< "Material: " << material_;
	return ostream;
}

std::ostream& operator <<(std::ostream& ostream, Shape const& s)
{
	return s.print(ostream);
}