#include "ray.hpp"

Ray::Ray():
	origin_{glm::vec3{0.0}}, direction_{glm::vec3{0.0}}{}

Ray::Ray(glm::vec3 const& origin, glm::vec3 const& direction):
	origin_{origin}, direction_{direction}{}
