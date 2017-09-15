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


Color Sphere::compute_light(Color const& ambient, Light const& light, Ray const& r){

    Color result{};
    Ray l{intersect(r).hitpos_, light.position_};
    Ray n{intersect(r).hitpos_, intersect(r).hitpos_ + intersect(r).hitpos_ - center_}; 
    Material mat = *get_material();
    int delta;

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

    auto vector_n = glm::normalize(n.direction_ - n.origin_);
    auto vector_l = glm::normalize(l.direction_ - l.origin_);
    
    float first_hold = vector_l.x * vector_n.x + vector_l.y * vector_n.y + vector_l.z * vector_n.z;

    auto vector_r = glm::normalize(glm::vec3{x,y,z});
    auto vector_v = glm::normalize(intersect(r).hitray_.direction_ - intersect(r).hitray_.origin_);

    if (intersect(Ray{glm::vec3{0.0f}, light.position_}).hit_ == true){
        delta = 0;
    }
    else{
        delta = 1;
    }

    float second_hold = vector_v.x * vector_r.x+ vector_v.y * vector_r.y + vector_v.z * vector_r.z;

    result.r = ambient.r * mat.ka_.r + inten.r * delta * (mat.kd_.r * first_hold + mat.ks_.r * 
        pow(second_hold, mat.m_));
    result.g = ambient.g * mat.ka_.g + inten.g * delta * (mat.kd_.g * first_hold + mat.ks_.g * 
        pow(second_hold, mat.m_));
    result.b = ambient.b * mat.ka_.b + inten.b * delta * (mat.kd_.b * first_hold + mat.ks_.b * 
        pow(second_hold, mat.m_));

    return result;
}


