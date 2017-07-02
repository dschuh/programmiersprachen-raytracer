#include "sdfloader.hpp"
#include <fstream>
#include <sstream>


Scene SdfLoader::loadFile(std::string const& path){
    
    Scene scene;
    std::ifstream file;
    file.open(path);
    std::string line;

    if(file.is_open()){
        std::cout << "Testlauf \n";

        while(std::getline(file, line)){
            std::stringstream ss;
            std::string keyword;
            ss<<line;
            ss>>keyword;
        }
    }
    return scene;
}
