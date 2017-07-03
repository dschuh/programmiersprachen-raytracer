#include "sdfloader.hpp"

SDFloader::SDFloader():
    holdMaterial{}
    {}

Scene SDFloader::loadMaterial (std::string const& path){
    Scene scene;

    std::ifstream file;
    file.open(path);
    std::string line;
    //std::map<std::string, Material>::iterator it = holdMaterial.begin();
    Material matr;

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
        }
        scene.materials[matr.name] = matr;
        //holdMaterial.insert(it,std::pair<std::string, Material> (matr.name,matr));
        //++it;
    }
    return scene;
}
