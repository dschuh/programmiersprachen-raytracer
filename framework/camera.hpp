#ifndef CAMERA_HPP
#define CAMERA_HPP
#define GLM_FORCE_RADIANS

#include <iostream>
#include <memory>
#include <glm/vec3.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include "ray.hpp"

class Camera{

public:

    Camera();
    Camera(std::string const& nm, float fovx);
    Camera(std::string const& nm, float fovx, glm::vec3 pos_, glm::vec3 dir_, glm::vec3 up_);

    void transform(glm::vec3 const& translationsvektor);
    void rotate(float winkel, glm::vec3 rotationsvektor);

    Ray makeRay(int x, int y, int height, int width) const;

    friend std::ostream& operator<<(std::ostream& os, Camera const& c);

private:

    std::string name_;
    float fovX_;
    glm::vec3 pos_{0.0f};
    glm::vec3 dir_{0.0f};
    glm::vec3 up_{0.0f};

    glm::mat4 transformation_;
    glm::mat4 transformation_inv_;

    glm::mat4 rotation_;
    glm::mat4 translation_;

};

#endif
