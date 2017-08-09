#include "light.hpp"

Light::Light():
    name{"Default"}, position{glm::vec3{0.0f, 0.0f, 0.0f}}, color{Color{0.0f, 0.0f, 0.0f}}, brightness{0.0f}{}

Light::Light(std::string const& nm, glm::vec3 const& pos, Color const& clr, float bgts):
    name{nm}, position{pos}, color{clr}, brightness{bgts}{}

void Light::setIntensity(){
    this->intensity = 0.0f * this->brightness; //Was für ein Datentyp ist intensity???
}

float const& Light::getIntensity(){
    return this->intensity;
}

std::ostream& operator<<(std::ostream& os, Light const& l){
    os << "Name:" << l.name << "\n" << "Position:" << "{" << l.position.x << "," << l.position.y << "," 
        << l.position.z << "}" << "\n" << "Color:" << "{" << l.color.r << "," << l.color.g << "," 
        << l.color.b << "}" << "\n" << "Brightness:" << l.brightness << "\n";

    return os;

}
