#include "hit.hpp"

Hit::Hit(){
    hit = false;
    hitray = Ray();
    hitpos = glm::vec3();
    shape = nullptr;
}