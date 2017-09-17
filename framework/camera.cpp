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

void Camera::transform(glm::vec3 const& translationsvektor){
	glm::mat4 T;
	T[0] = glm::vec4{1.0f, 0.0f, 0.0f, 0.0f};
	T[1] = glm::vec4{0.0f, 1.0f, 0.0f, 0.0f};
	T[2] = glm::vec4{0.0f, 0.0f, 1.0f, 0.0f};
	T[3] = glm::vec4{translationsvektor.x, translationsvektor.y, translationsvektor.z, 1.0f};
	translation_ = T;
	transformation_ = translation_ * rotation_;
 	transformation_inv_ = glm::inverse(transformation_);
}

void Camera::rotate(float winkel, glm::vec3 rotationsvektor){
	float winkel_in_rad = (winkel*M_PI)/180.0f;
	glm::mat4 R = glm::rotate(glm::mat4(1.0), winkel_in_rad, rotationsvektor);
	rotation_ = R;
	transformation_ = translation_ * rotation_;
  	transformation_inv_ = glm::inverse(transformation_);
}

std::ostream& operator<<(std::ostream& os, Camera const& c){
    os << "Name:" << c.name_ << "\n" << "fov-X:" << c.fovX_ << "\n";

    return os;

}
