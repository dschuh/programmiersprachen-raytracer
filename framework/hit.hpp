#ifndef HIT_HPP
#define HIT_HPP

#include "ray.hpp"
#include "shape.hpp"
#include "material.hpp"
#include <glm/glm.hpp>
#include <memory>

class Shape;

struct Hit{

    bool hit_;
    float distance_;
    Ray hitray_;
    glm::vec3 hitpos_;
    glm::vec3 normal_;
    std::shared_ptr<Shape> shape;

    Hit();

};




#endif
