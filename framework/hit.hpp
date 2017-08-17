#ifndef HIT_HPP
#define HIT_HPP

#include "ray.hpp"
#include <glm/glm.hpp>

class Shape;

struct Hit{

    bool hit; 
    Ray hitray;
    glm::vec3 hitpos;
    std::shared_ptr<Shape> shape;
    

    Hit();

};




#endif