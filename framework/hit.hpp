#ifndef HIT_HPP
#define HIT_HPP

#include "ray.hpp"

class Shape;

struct Hit{

    bool hit; 
    std::shared_ptr<Shape> shape;
    Ray hitray;

    Hit();

};




#endif