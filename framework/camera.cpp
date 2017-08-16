#include "camera.hpp"

Camera::Camera():
    name_{"Default"}, fovX_{0.0f}{}

Camera::Camera(std::string const& nm, float opd):
    name_{nm}, fovX_{opd}{}

std::ostream& operator<<(std::ostream& os, Camera const& c){
    os << "Name:" << c.name_ << "\n" << "fov-X:" << c.fovX_ << "\n";

    return os;

}
