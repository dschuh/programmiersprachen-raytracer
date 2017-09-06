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

Hit Sphere::intersect(Ray const& ray, float& distance){ //funktioniert ebenfalls nicht? Vll bin ich auch zu doof, um den test richtig zu schreiben.
        Hit hit = Hit();
        auto direction = glm::normalize(ray.direction_);
        hit.hit = glm::intersectRaySphere(ray.origin_, direction, center_, pow(radius_, 2), distance);
        hit.hitray = ray;
        hit.hitpos = ray.origin_ + direction * distance;
        //!! geht das mit this?
        hit.shape = std::shared_ptr<Sphere>(this);
		return hit;
}
