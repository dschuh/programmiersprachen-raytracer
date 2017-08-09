#include "camera.hpp"

Camera::Camera():
    name{"Default"}, fovX{0.0f}{}

Camera::Camera(std::string const& nm, float opd):
    name{nm}, fovX{opd}{}
