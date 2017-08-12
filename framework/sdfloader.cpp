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
<<<<<<< Updated upstream
    Material matr;
    Light lgt;
    Sphere spr;
    Box bx;
=======
    //std::map<std::string, Material>::iterator it = holdMaterial.begin();
    
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
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
=======
                    ss >> matr.m;
                }
            
                else if(keyword == "light"){
                    Light light;
                    //light.hpp auslesen
                    ss >> light;
                }

                else if(keyword == "shape"){
                    Shape shape;
                    ss >> keyword;

                    if (keyword == "box"){
                        ss >> name_;
                        ss >> min_.x;
                        ss >> min_.y;
                        ss >> min_.z;
                        ss >> max_.x;
                        ss >> max_.y;
                        ss >> max_.z;
                        ss >> material_;
                    }

                    else if (keyword == "sphere"){
                        ss >> name_;
                        ss >> center_.x;
                        ss >> center_.y;
                        ss >> center_.z;
                        ss >> radius_
                        ss >> material_;
                    }

                else if(keyword == "camera"){
                    Camera camera;
                    //camera.hpp auslesen
                    ss >> camera;
                    }
                }
        }
        scene.shapes.insert(shape);
        scene.materials[matr.name] = matr;
        //holdMaterial.insert(it,std::pair<std::string, Material> (matr.name,matr));
        //++it;
>>>>>>> Stashed changes
    }
    return scene;
}
