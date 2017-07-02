#include "sphere.hpp"
#include <cmath>

Sphere::Sphere():
    Shape{"Sphere"},
    center_{glm::vec3{0.0f}},
    radius_{1.0f}
    {}

Sphere::Sphere(glm::vec3 const& center, float r):
    Shape{"Sphere"},
    center_{center},
    radius_{r}
    {}

Sphere::Sphere(glm::vec3 const& center, float r, Material const& material, std::string const& name):
    Shape{name, material},
    center_{center},
    radius_{r}
    {}    

Sphere::~Sphere(){
    //std::cout << "Sphere-Destruktor wird auf " << get_name() << " aufgerufen \n";
}
    
glm::vec3 const& Sphere::get_center() const{
    return center_;
}

float const& Sphere::get_radius() const{
    return radius_;
}

float Sphere::area() const {
	return fabs(4.0f * M_PI * pow(radius_, 2.0f));
}

float Sphere::volume() const {
	return fabs((4.0f/3.0f)* M_PI * pow(radius_, 3));
}

std::ostream& Sphere::print(std::ostream& ostream) const{
	Shape::print(ostream);
	ostream << "Center: " << "["<< center_.x << ","<< center_.y << ","<< center_.z << "]" << "\n"
	        << "Radius: " << radius_ <<"\n"<<"\n";
}

bool Sphere::intersect(Ray const& ray, float& distance){
		auto direction = glm::normalize(ray.direction);
		auto result = glm::intersectRaySphere(ray.origin, direction,
							center_, pow(radius_, 2), distance);
		return result;
}