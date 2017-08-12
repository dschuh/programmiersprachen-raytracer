#ifndef SCENE_HPP
#define SCENE_HPP

#include "shape.hpp"
/*
#include "box.hpp"
#include "sphere.hpp"
<<<<<<< Updated upstream
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
=======
*/
struct Scene{

std::vector<shared_ptr<Shape>> shapes;
std::map<Material> materials;
std::vector<Light> lights;
//Kamera kamera
>>>>>>> Stashed changes
//usw.

};

#endif