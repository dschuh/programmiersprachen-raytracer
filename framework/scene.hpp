#ifndef SCENE_HPP
#define SCENE_HPP

#include "box.hpp"
#include "sphere.hpp"
#include "light.hpp"
#include "camera.hpp"
#include <memory>

struct Scene{

    Scene():
        lights{}, ambiente{}, materials{}, camera{}, shapes{}{}
        
    std::vector<std::shared_ptr<Light>> lights;
    Intensity ambiente;
    std::map<std::string, std::shared_ptr<Material>> materials;
    std::shared_ptr<Camera> camera;
    std::vector<std::shared_ptr<Shape>> shapes;



};

#endif
