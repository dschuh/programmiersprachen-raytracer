#include "sdfloader.hpp"
 

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
                    std::string name;
                    Color ka;
                    Color kd;
                    Color ks;
                    float m;

                    ss >> name;
                    ss >> ka.r;
                    ss >> ka.g;
                    ss >> ka.b;
                    ss >> kd.r;
                    ss >> kd.g;
                    ss >> kd.b;
                    ss >> ks.r;
                    ss >> ks.g;
                    ss >> ks.b;
                    ss >> m; 
                    std::shared_ptr<Material> matr = std::make_shared<Material>(name, ka, kd, ks, m);
                    scene.materials[name] = matr;
                }
                if (keyword == "light"){
                    std::string name;
                    glm::vec3 position;
                    Color color;                    
                    float brightness;

                    ss >> name;
                    ss >> position.x;
                    ss >> position.y;
                    ss >> position.z;
                    ss >> color.r;
                    ss >> color.g;
                    ss >> color.b;
                    ss >> brightness;

                    std::shared_ptr<Light> light = std::make_shared<Light>(name,position,color,brightness);
                    scene.lights.push_back(light);
                }
                if (keyword == "camera"){
                    std::string name;
                    float fov_x;
                    
                    ss >> name;
                    ss >> fov_x;  
  
                    std::shared_ptr<Camera> camera = std::make_shared<Camera>(name,fov_x);
                    scene.camera = camera;
                }
                if (keyword == "shape"){
                    ss >> keyword;
                    if (keyword == "sphere"){
                        glm::vec3 center;
                        float radius;
                        std::shared_ptr<Material> material;
                        std::string name;

                        ss >> center.x;
                        ss >> center.y;
                        ss >> center.z;
                        ss >> radius;
                        ss >> keyword;
                        material = scene.materials.find(keyword)->second;
                        ss >> name;
                        std::shared_ptr<Shape> sphere = std::make_shared<Sphere>(center,radius,material,name);
                        scene.shapes[name] = sphere;
                    }
                    if (keyword == "box"){

                        glm::vec3 min;
                        glm::vec3 max;
                        std::shared_ptr<Material> material;
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
                        scene.shapes[name] = box;
                    }
                    if (keyword == "composite"){
                        std::string name;
                        std::vector<std::shared_ptr<Shape>> layer;

                        ss >> name;
                        while(ss){
                            ss >> keyword;
                            std::shared_ptr<Shape> object = scene.shapes.find(keyword)->second;
                            layer.push_back(object);
                        }
                        
                        scene.composite[name] = layer;
                    } 
                }
            }
            if ( keyword == "ambient"){
                ss >> scene.ambiente.r;
                ss >> scene.ambiente.g;
                ss >> scene.ambiente.b;
            }          
    }
    return scene;
}
