#include "scene.hpp"

Scene sdfloader::loadFile(std::string const& path){
    
    Scene scene;

    std::ifstream file;
    file.open(path);
    std::string line;

    if(file.is_open()){
        std::cout << "Testlauf \n";

        while(line != null){
            std::stringstream ss;
            std::string keyword;
            ss<<line;
            ss>>keyword;
        }
    }
    return scene;
}
