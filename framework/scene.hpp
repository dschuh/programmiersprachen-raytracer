#ifndef SCENE_HPP
#define SCENE_HPP

#include "shape.hpp"

#include "box.hpp"
#include "sphere.hpp"
#include "material.hpp"
#include "light.hpp"
#include "camera.hpp"
#include <memory>

struct Scene{

//Brauchen wir boxes uns spheres oder reichen shapes?
    Scene():
        lights{},
        ambiente{},
        materials{},
        camera{},
        shapes{}{}
        
    std::vector<Light> lights;
    Intensity ambiente;
    std::map<std::string, Material> materials;
    Camera camera;
    std::vector<std::shared_ptr<Shape>> shapes;



};

#endif
