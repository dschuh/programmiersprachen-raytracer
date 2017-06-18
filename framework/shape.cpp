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
