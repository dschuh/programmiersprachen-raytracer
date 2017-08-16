#include "sdfloader.hpp"
#include "camera.hpp"
#include "intensity.hpp"
#include "light.hpp"
 

Scene SDFloader::loadScene (std::string const& path){
    Scene scene;
    std::ifstream file;
    file.open(path);
    std::string line;
    Sphere spr;
    Box bx;

    while(std::getline(file,line)){
        std::stringstream ss;
        std::string keyword;
        ss << line;
        ss >> keyword;
            if (keyword == "define"){
                ss >> keyword;
               if (keyword == "material"){
                    Material matr;
                    ss >> matr.name;
                    ss >> matr.ka.r;
                    ss >> matr.ka.g;
                    ss >> matr.ka.b;
                    ss >> matr.kd.r;
                    ss >> matr.kd.g;
                    ss >> matr.kd.b;
                    ss >> matr.ks.r;
                    ss >> matr.ks.g;
                    ss >> matr.ks.b;
                    ss >> matr.m; 
                    scene.materials[matr.name] = matr;
                }
                if (keyword == "light"){
                    Light lgt;
                    ss >> lgt.name;
                    ss >> lgt.position.x;
                    ss >> lgt.position.y;
                    ss >> lgt.position.z;
                    ss >> lgt.color.r;
                    ss >> lgt.color.g;
                    ss >> lgt.color.b;
                    ss >> lgt.brightness;
                    scene.lights.push_back(lgt);
                }
                if (keyword == "camera"){
                    Camera cam;
                    ss >> cam.name;
                    ss >> cam.fovX;
                    scene.camera = cam;
                }
                if (keyword == "shape"){
                    ss >> keyword;
                    if (keyword == "sphere"){
                        glm::vec3 center;
                        float radius;
                        Material material;
                        std::string name;

                        ss >> center.x;
                        ss >> center.y;
                        ss >> center.z;
                        ss >> radius;
                        ss >> keyword;
                        material = scene.materials.find(keyword)->second;
                        ss >> name;
                        std::shared_ptr<Shape> sphere = std::make_shared<Sphere>(center,radius,material,name);
                        scene.shapes.push_back(sphere);
                    }
                    if (keyword == "box"){

                        glm::vec3 min;
                        glm::vec3 max;
                        Material material;
                        std::string name;

                        ss >> min.x;
                        ss >> min.y;
                        ss >> min.z;
                        ss >> max.x;
                        ss >> max.y;
                        ss >> max.z;
                        ss >> keyword;
                        material = scene.materials.find(keyword)->second;
                        ss >> name;
                        std::shared_ptr<Shape> box = std::make_shared<Box>(min, max, material, name);
                        scene.shapes.push_back(box);
                    }
                    if (keyword == "composite"){
                        ss >> keyword;
                        if(keyword == ""){
        
                        }
                    } 
                }
            }
            if ( keyword == "ambient"){
                ss >> scene.ambiente.a_;
                ss >> scene.ambiente.b_;
                ss >> scene.ambiente.c_;
            }          
    }
    return scene;
}
