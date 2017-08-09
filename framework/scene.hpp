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
        ambiente{},
        materials{},
        camera{},
        spheres{},
        boxes{}{}
        

    std::vector<Light> lights;
    Intensity ambiente;
    std::map<std::string, Material> materials;
    Camera camera;
    std::vector<Sphere> spheres;
    std::vector<Box> boxes;
//usw.


};

#endif
