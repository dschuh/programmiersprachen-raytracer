#include "box.hpp"

Box::Box():
	minimum{},
	maximum{}{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
	minimum{min},
	maximum{max}{}	

glm::vec3 Box::getMinimum() const{
	return this -> minimum;
}

glm::vec3 Box::getMaximum() const{
	return this -> maximum;
}

float Box::area() const override{
	float a = this -> maximum.x this -> minimum.x;
	float b = this -> maximum.y this -> minimum.y;
	float c = this -> maximum.z this -> minimum.z;	
	return (2*a*b+2*a*c+2*b*c);
}

float Box::volume() const override{
	float a = this -> maximum.x this -> minimum.x;
	float b = this -> maximum.y this -> minimum.y;
	float c = this -> maximum.z this -> minimum.z;	
	return (a*b*c);
}
