#include "sdfloader.hpp"
 

Scene SDFloader::loadScene (std::string const& path){
    Scene scene;
    std::ifstream file;
    file.open(path);
    std::string line;
    Sphere spr;
    Box bx;
    std::map<std::string, std::shared_ptr<Shape>> pointed_shapes;

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
                    glm::vec3 pos;
                    glm::vec3 dir;
                    glm::vec3 up;
                    
                    ss >> name;
                    ss >> fov_x;  
                    ss >> pos.x;
                    ss >> pos.y;
                    ss >> pos.z;
                    ss >> dir.x;
                    ss >> dir.y;
                    ss >> dir.z;
                    ss >> up.x;
                    ss >> up.y;
                    ss >> up.z;

                    std::shared_ptr<Camera> camera = std::make_shared<Camera>(name,fov_x, pos, dir, up);
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
                        pointed_shapes[name] = sphere;
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
                        pointed_shapes[name] = box;
                    }
                    if (keyword == "composite"){
                        std::string name;
                        std::vector<std::shared_ptr<Shape>> layer;

                        ss >> name;
                        while(ss){
                            ss >> keyword;
                            std::shared_ptr<Shape> object = pointed_shapes.find(keyword)->second;
                            layer.push_back(object);
                        }
                        std::shared_ptr<Composite> holdComposite = std::make_shared<Composite>(name,layer);
                        scene.shapes = holdComposite;
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
