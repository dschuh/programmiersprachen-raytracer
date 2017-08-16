#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>

struct Ray{

glm::vec3 origin_ ;
glm::vec3 direction_ ;

Ray();
Ray(glm::vec3 const& origin, glm::vec3 const& direction);

};

#endif
