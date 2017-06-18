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

Sphere::Sphere(glm::vec3 const& center, float r, Color const& color, string const& name):
    Shape{name, color},
    center_{center},
    radius_{r}
    {}    
    
glm::vec3 const& Sphere::get_center() const{
    return center_;
}

float const& Sphere::get_radius() const{
    return radius_;
}

float Sphere::area() const {
	return abs(4.0f * M_PI * pow(radius_, 2.0f));
}

float Sphere::volume() const {
	return abs((4.0f/3.0f)* M_PI * pow(radius_, 3));
}