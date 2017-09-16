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
		return spherehit;
}


Color Sphere::compute_light(Color const& ambient, Light const& light, Ray const& ray) const{

    Color result{};

    Material mat = *get_material();

    int delta;

    Hit magic = intersect(ray);

    Color intensity = light.setIntensity();

    glm::vec3 n = glm::normalize(magic.hitpos_ - center_);

    Ray toLight{magic.hitpos_ + glm::normalize(light.position_ + magic.hitpos_), glm::normalize(light.position_ + magic.hitpos_)};

    glm::vec3 l = toLight.direction_;

    float ln = std::max(glm::dot(l, n), 0.0f);

    glm::vec3 r = glm::normalize(glm::reflect(l, n));

    glm::vec3 v = glm::normalize(glm::vec3{- ray.direction_.x, - ray.direction_.y, - ray.direction_.z});

    float rv = std::max(glm::dot(r, v), 0.0f);

    if(intersect(toLight).hit_){    
        delta = 0;
    }
    else{
        delta = 1;
    }

    result = ambient * mat.ka_ + intensity * delta * (mat.kd_ * ln + mat.ks_ * pow(rv, mat.m_));

    return result;
}


