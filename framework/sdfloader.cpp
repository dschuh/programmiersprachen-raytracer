#include "sdfloader.hpp"

SDFloader::SDFloader():
    holdMaterial{},
    holdLights{},
    amb{},
    cam{},
    holdSpheres{},
    holdBoxes{}{}

Scene SDFloader::loadScene (std::string const& path){
    Scene scene;
    std::ifstream file;
    file.open(path);
    std::string line;
    Material matr;
    Light lgt;
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
                    ss >> scene.camera.name;
                    ss >> scene.camera.fovX;
                }
                if (keyword == "shape"){
                    ss >> keyword;
                    if (keyword == "sphere"){
                        ss >> spr.center_.x;
                        ss >> spr.center_.y;
                        ss >> spr.center_.z;
                        ss >> spr.radius_;
                        ss >> keyword;
                        spr.material_ = scene.materials.find(keyword)->second;
                        ss >> spr.name_;
                        scene.spheres.push_back(spr);
                    }
                    if (keyword == "box"){
                        ss >> bx.min_.x;
                        ss >> bx.min_.y;
                        ss >> bx.min_.z;
                        ss >> bx.max_.x;
                        ss >> bx.max_.y;
                        ss >> bx.max_.z;
                        ss >> keyword;
                        bx.material_ = scene.materials.find(keyword)->second;
                        ss >> bx.name_;
                        scene.boxes.push_back(bx);
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
