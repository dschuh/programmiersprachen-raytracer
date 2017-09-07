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

Hit Sphere::intersect(Ray const& ray, float& distance){
        Hit hit = Hit();
        auto direction = glm::normalize(ray.direction_);
        hit.hit = glm::intersectRaySphere(ray.origin_, direction, center_, pow(radius_, 2), distance);
        hit.hitray = ray;
        hit.hitpos = ray.origin_ + direction * distance;
        hit.shape = std::make_shared<Sphere>(center_, radius_, get_material(), get_name());
		return hit;
}

Color Sphere::compute_light(Color const& ambient, Light const& light, Ray const& r){
    Color result{};
    float d = 50.0f;
    Ray l{intersect(r, d).hitpos, glm::normalize(light.position_)};
    Ray n{intersect(r, d).hitpos, intersect(r, d).hitpos + intersect(r, d).hitpos - center_}; // n muss in Objekten einzeln berechnet werden override
    Material mat = *get_material();

    float x = (2 * pow(n.direction_.x - n.origin_.x, 2.0f) -1) * light.position_.x +  
        (2 * (n.direction_.x - n.origin_.x) * (n.direction_.y - n.origin_.y)) * light.position_.y + 
        (2 * (n.direction_.x - n.origin_.x) * (n.direction_.z - n.origin_.z)) * light.position_.z;
    float y = (2 * (n.direction_.x - n.origin_.x) * (n.direction_.y - n.origin_.y)) * light.position_.x + 
        (2 * pow(n.direction_.y - n.origin_.y, 2.0f) -1) * light.position_.y +
        (2 * (n.direction_.y - n.origin_.y) * (n.direction_.z - n.origin_.z)) * light.position_.z;
    float z = (2 * (n.direction_.x - n.origin_.x) * (n.direction_.z - n.origin_.z)) * light.position_.x +
        (2 * (n.direction_.z - n.origin_.z) * (n.direction_.y - n.origin_.y)) * light.position_.y +
        (2 * pow(n.direction_.z - n.origin_.z, 2.0f) -1) * light.position_.z;
    
    Color inten = light.setIntensity();
    
    float first_hold = (l.direction_.x - l.origin_.x) * (n.direction_.x - n.origin_.x) + 
        (l.direction_.y - l.origin_.y) * (n.direction_.y - n.origin_.y) +
        (l.direction_.z - l.origin_.z) * (n.direction_.z - n.origin_.z);

    float second_hold = (intersect(r, d).hitray.direction_.x - intersect(r, d).hitray.origin_.x) * x+ 
        (intersect(r, d).hitray.direction_.y - intersect(r, d).hitray.origin_.y) * y + 
        (intersect(r, d).hitray.direction_.z - intersect(r, d).hitray.origin_.z) * z;

    result.r = ambient.r * mat.ka_.r + inten.r * (mat.kd_.r * first_hold) + mat.ks_.r * pow(second_hold, mat.m_);
}
