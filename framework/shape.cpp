#include "shape.hpp"

Shape::Shape():
    name_{"Shape"}, material_{}{}
    

Shape::Shape(std::string const& name):
	name_{name}, material_{}{}

Shape::Shape(std::string const& name, std::shared_ptr<Material> const& material):
	name_{name},material_{material}{}

Shape::~Shape()
    {}

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

std::ostream& operator <<(std::ostream& ostream, std::shared_ptr<Shape> const& s)
{
	return s.print(ostream);
}
