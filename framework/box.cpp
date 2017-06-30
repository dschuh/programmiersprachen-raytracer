#include "box.hpp"

Box::Box(std::string const& nmBox):
    Shape{nmBox, Material{}},
	minimum{},
	maximum{}{
    std::cout << "box\n";
    }

Box::Box(std::string const& nmBox, Material const& matr, glm::vec3 const& min, glm::vec3 const& max):
    Shape{nmBox, matr},
	minimum{min},
	maximum{max}{
    std::cout << "box\n";
    }	

Box::~Box(){
    std::cout << "~box\n";
}

glm::vec3 const& Box::getMinimum() const{
	return minimum;
}

glm::vec3 const& Box::getMaximum() const{
	return maximum;
}

float Box::area() const {
	float a = maximum.x - minimum.x;
	float b = maximum.y - minimum.y;
	float c = maximum.z - minimum.z;	
	return (2*a*b+2*a*c+2*b*c); 
}

float Box::volume() const {
	float a = maximum.x - minimum.x;
	float b = maximum.y - minimum.y;
	float c = maximum.z - minimum.z;	
	return (a*b*c);
}

std::ostream& Box::print(std::ostream& os) const{
    Shape::print(os);
    os << "Minimum:" << "(" << minimum.x << "," << minimum.y << "," << minimum.z << ")" << "\n";
    os << "Maximum:" << "(" << maximum.x << "," << maximum.y << "," << maximum.z << ")" << "\n";
    return os;
}
