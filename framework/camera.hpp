#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>

struct Camera{

    std::string name;
    float fovX;

    Camera();
    Camera(std::string const& nm, float opd);

    friend std::ostream& operator<<(std::ostream& os, Camera const& c);

};

#endif
