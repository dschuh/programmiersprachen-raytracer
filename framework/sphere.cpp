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

Sphere::Sphere(glm::vec3 const& center, float r, std::shared_ptr<Material> const& material, std::string const& name):
    Shape{name, material},
    center_{center},
    radius_{r}
    {}    

Sphere::~Sphere(){}
    
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

Hit Sphere::intersect(Ray const& ray) const{
        Hit spherehit = Hit();
        spherehit.hitray_ = ray;
        spherehit.normal_ = glm::normalize(ray.direction_);
        spherehit.hit_ = glm::intersectRaySphere(ray.origin_, spherehit.normal_, center_, pow(radius_, 2), spherehit.distance_);
        spherehit.hitpos_ = ray.origin_ + spherehit.normal_ * spherehit.distance_;       
        spherehit.distance_ = glm::distance(ray.origin_, spherehit.hitpos_);
        spherehit.shape = std::make_shared<Sphere>(center_, radius_, get_material(), get_name());
        spherehit.normal_ = glm::normalize(spherehit.hitpos_ - center_);
		return spherehit;
}





