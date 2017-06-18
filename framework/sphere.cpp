#include "sphere.hpp"

	Sphere::Sphere(std::string const& nm):
        Shape{nm, Color{}},
		center{},
		radius{0}{}

	Sphere::Sphere(std::string const& nm, Color const& clr, glm::vec3 const& ctr, float r):
        Shape{nm, clr},		
        center{ctr},
		radius{r}{}

	glm::vec3 Sphere::getCenter() const{
		return this -> center;
	}

	float Sphere::getRadius() const{
		return this -> radius;
	}

	float Sphere::area() const {
		return (4* M_PI * this -> radius * this -> radius);
	}
		
	float Sphere::volume() const {
		return ((4.0f/3.0f)* M_PI * this -> radius * this -> radius * this -> radius);
	}
