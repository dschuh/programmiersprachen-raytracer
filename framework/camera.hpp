#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>

struct Camera{ //Error -> missing initializer before struct --- Whaaaaaaaaaaat? Wasn da los?!

    std::string name;
    float fovX;

    Camera();
    Camera(std::string const& nm, float opd);

};

#endif
