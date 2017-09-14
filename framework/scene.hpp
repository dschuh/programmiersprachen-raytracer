#ifndef SCENE_HPP
#define SCENE_HPP

#include "shape.hpp"
#include "material.hpp"
#include "light.hpp"
#include "camera.hpp"
#include "composite.hpp"
#include <memory>
#include <vector>
#include <map>

struct Scene{

    Scene():
        lights{}, ambiente{}, materials{}, camera{}, shapes{}{}
        
    std::vector<std::shared_ptr<Light>> lights;
    Color ambiente;
    std::map<std::string, std::shared_ptr<Material>> materials;
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Composite> shapes;
    
};

#endif
