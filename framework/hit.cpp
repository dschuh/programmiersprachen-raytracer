#include "hit.hpp"

Hit::Hit():
    hit_{false},
    distance_{INFINITY},
    hitpos_{glm::vec3()},
    normal_{glm::vec3()},
    shape{nullptr}{}

