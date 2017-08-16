#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <memory>

struct Camera{

    std::string name_;
    float fovX_;

    Camera();
    Camera(std::string const& nm, float opd);

    friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<Camera> const& c);

};

#endif
