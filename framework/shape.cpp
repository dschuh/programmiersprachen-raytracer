#include "shape.hpp"

Shape::Shape(std::string const& nm, Color const& clr):
    name_{nm},
    color_{clr}{}

std::string Shape::getName() const{
    return this->name_;
}


Color Shape::getColor() const{
    return this-> color_;
}    

std::ostream& Shape::print(std::ostream& os) const{
    os << "Name:" << name_ << "\n";
    os << "Color:" << color_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}
