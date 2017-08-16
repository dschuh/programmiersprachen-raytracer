#ifndef HIT_HPP
#define HIT_HPP

class Shape;

struct Hit{

    bool hit = false; 
    std::shared_ptr<Shape> shape = nullptr;
    Ray hitray = Ray({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});

};




#endif