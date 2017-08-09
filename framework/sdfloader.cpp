#include "sdfloader.hpp"

SDFloader::SDFloader():
    holdMaterial{},
    holdLights{},
    cam{}
    {}

Scene SDFloader::loadScene (std::string const& path){
    Scene scene;

    std::ifstream file;
    file.open(path);
    std::string line;
    Material matr;
    Light lgt;

    while(std::getline(file,line)){
        std::stringstream ss;
        std::string keyword;
        ss << line;
        ss >> keyword;
            if (keyword == "define"){
                ss >> keyword;
               if (keyword == "material"){
                    
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
                }
                if (keyword == "light"){
                    ss >> lgt.name;
                    ss >> lgt.position.x;
                    ss >> lgt.position.y;
                    ss >> lgt.position.z;
                    ss >> lgt.color.r;
                    ss >> lgt.color.g;
                    ss >> lgt.color.b;
                    ss >> lgt.brightness;
                }
                if (keyword == "camera"){
                    ss >> scene.camera.name;
                    ss >> scene.camera.fovX;
                }
            }
            scene.materials[matr.name] = matr;
            scene.lights.push_back(lgt);
    }
    return scene;
}
