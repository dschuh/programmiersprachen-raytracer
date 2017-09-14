#ifndef HIT_HPP
#define HIT_HPP

#include "ray.hpp"
#include <glm/glm.hpp>
#include <memory>

class Shape;

struct Hit{

    bool hit_;
    float distance_;
    glm::vec3 hitpos_;
    glm::vec3 normal_;
    std::shared_ptr<Shape> shape;

    Hit();

};




#endif
