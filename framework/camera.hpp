#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <memory>
#include <glm/vec3.hpp>
#include "ray.hpp"

struct Camera{

    std::string name_;
    float fovX_;
    glm::vec3 pos_{0.0f};

    Camera();
    Camera(std::string const& nm, float opd);

    Ray makeRay(int x, int y, int height, int width) const;

    friend std::ostream& operator<<(std::ostream& os, Camera const& c);

};

#endif
