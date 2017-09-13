#ifndef HIT_HPP
#define HIT_HPP

#include "ray.hpp"
#include <glm/glm.hpp>
#include <memory>

class Shape;

struct Hit{

    bool hit;
    float distance;
    glm::vec3 hitpos;
    glm::vec3 normal;
    std::shared_ptr<Shape> shape;

    Hit();

};




#endif
