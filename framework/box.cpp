#include "box.hpp"

Box::Box(std::string const& nm):
    Shape{nm, Color{0.0f, 0.0f, 0.0f}},
	minimum{},
	maximum{}{}

Box::Box(std::string const& nm, Color const& clr,glm::vec3 const& min, glm::vec3 const& max):
    Shape{nm, clr},
	minimum{min},
	maximum{max}{}	

Box::~Box(){
    std::cout << "~box";
}

glm::vec3 Box::getMinimum() const{
	return this -> minimum;
}

glm::vec3 Box::getMaximum() const{
	return this -> maximum;
}

float Box::area() const {
	float a = this -> maximum.x - this -> minimum.x;
	float b = this -> maximum.y - this -> minimum.y;
	float c = this -> maximum.z - this -> minimum.z;	
	return (2*a*b+2*a*c+2*b*c); 
}

float Box::volume() const {
	float a = this -> maximum.x - this -> minimum.x;
	float b = this -> maximum.y - this -> minimum.y;
	float c = this -> maximum.z - this -> minimum.z;	
	return (a*b*c);
}

std::ostream& Box::print(std::ostream& os) const{
    Shape::print(os);
    os << "Minimum:" << "(" << minimum.x << "," << minimum.y << "," << minimum.z << ")" << "\n";
    os << "Maximum:" << "(" << maximum.x << "," << maximum.y << "," << maximum.z << ")" << "\n";
    return os;
}
