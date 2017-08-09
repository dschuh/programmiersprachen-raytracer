#include "camera.hpp"

Camera::Camera():
    name{"Default"}, fovX{0.0f}{}

Camera::Camera(std::string const& nm, float opd):
    name{nm}, fovX{opd}{}

std::ostream& operator<<(std::ostream& os, Camera const& c){
    os << "Name:" << c.name << "\n" << "fov-X:" << c.fovX << "\n";

    return os;

}
