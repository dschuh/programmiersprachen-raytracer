#include "sphere.hpp"

Sphere::Sphere():
    Shape{}
    center_{}
    radius_{}
    {}

Sphere::Sphere():
    Shape{"Sphere"}
    center_{glm::vec3 0.0f}
    radius_{1.0f}
    {}

Sphere::Sphere(glm::vec3 const& center, float r, Color const& clr, String const& name):
    Shape{name, color}
    center_{center}
    r_{r}
    {}    
    
glm::vec3 const& get_center() const{
    return center_;
}

float const& get_center() const{
    return radius_;
}