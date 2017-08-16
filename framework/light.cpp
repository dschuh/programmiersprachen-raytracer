#include "light.hpp"

Light::Light():
    name_{"Default"}, position_{glm::vec3{0.0f, 0.0f, 0.0f}}, color_{Color{0.0f, 0.0f, 0.0f}}, brightness_{0.0f}{}

Light::Light(std::string const& nm, glm::vec3 const& pos, Color const& clr, float bgts):
    name_{nm}, position_{pos}, color_{clr}, brightness_{bgts}{}

void Light::setIntensity(){
    this->intensity_.a_ = this->color_.r * this->brightness_; 
    this->intensity_.b_ = this->color_.g * this->brightness_;
    this->intensity_.c_ = this->color_.b * this->brightness_;
}

std::ostream& operator<<(std::ostream& os, Light const& l){
    os << "Name:" << l.name_ << "\n" << "Position:" << "{" << l.position_.x << "," << l.position_.y << "," 
        << l.position_.z << "}" << "\n" << "Color:" << "{" << l.color_.r << "," << l.color_.g << "," 
        << l.color_.b << "}" << "\n" << "Brightness:" << l.brightness_ << "\n";

    return os;

}
