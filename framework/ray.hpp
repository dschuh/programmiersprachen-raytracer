#ifndef RAY_HPP
#define RAY_HPP

#include "../external/glm-0.9.5.3/glm/glm.hpp"

struct Ray{

glm::vec3 origin_ ;
glm::vec3 direction_ ;

Ray();
Ray(glm::vec3 const& origin, glm::vec3 const& direction);

};

#endif
