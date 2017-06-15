#include "sphere.hpp"

	Sphere::Sphere():
		center{},
		radius{0}{}

	Sphere::Sphere(glm::vec3 const& ctr, float r):
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
		return ((4/3)* M_PI * this -> radius * this -> radius * this -> radius);
	}
