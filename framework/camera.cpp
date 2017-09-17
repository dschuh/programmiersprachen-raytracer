#include "camera.hpp"

Camera::Camera():
    name_{"Default"}, fovX_{0.0f}{}

Camera::Camera(std::string const& nm, float fovx):
    name_{nm}, fovX_{fovx}{}

Camera::Camera(std::string const& nm, float fovx, glm::vec3 pos_, glm::vec3 dir_, glm::vec3 up_):
    name_{nm}, fovX_{fovx}, pos_{pos_}, dir_{dir_}, up_{up_}{}

Ray Camera::makeRay(int x, int y, int height, int width)const{
    glm::vec3 viewpoint{ 
        (float(x)/(float(width)))-0.5, 
        (float(y)/(float(height)))-0.5, 
        -1.0*(0.5/tan(fovX_/2))
    };
    Ray actualRay{pos_, viewpoint};
    return actualRay;
}

std::ostream& operator<<(std::ostream& os, Camera const& c){
    os << "Name:" << c.name_ << "\n" << "fov-X:" << c.fovX_ << "\n";

    return os;

}
