#ifndef SCENE_HPP
#define SCENE_HPP

#include "box.hpp"
#include "sphere.hpp"

struct Scene{

    Scene():
        materials{}{}

//std::vector<Shape> shapes; evtl als shared pointer
    //std::vector<Light> lights;
    std::map<std::string, Material> materials;
//Kamera kamera
//usw.


};

#endif
