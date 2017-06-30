#include "shape.hpp"

Shape::Shape(std::string const& nm, Material const& matr):
    name_{nm},
    material_{matr}{
    std::cout << "shape\n";}

Shape::~Shape(){
    std::cout << "~shape\n";
}

std::string const& Shape::getName() const{
    return name_;
}


Material const& Shape::getMaterial() const{
    return material_;
}    

std::ostream& Shape::print(std::ostream& os) const{
    os << "Name:" << name_ << "\n" << "Material: \n" << material_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}
