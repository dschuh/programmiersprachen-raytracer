#ifndef SCENE_HPP
#define SCENE_HPP

#include "box.hpp"
#include "sphere.hpp"
#include "material.hpp"
#include "light.hpp"
#include "camera.hpp"

struct Scene{

    Scene():
        lights{},
        materials{},
        camera{}{}
        

    std::vector<Light> lights;
    std::map<std::string, Material> materials;
    Camera camera;
//usw.


};

#endif
