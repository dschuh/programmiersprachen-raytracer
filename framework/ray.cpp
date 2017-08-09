#include "ray.hpp"

Ray::Ray():
	origin{glm::vec3{0.0}},
	direction{glm::vec3{0.0}}
	{}

Ray::Ray(glm::vec3 const& origin, glm::vec3 const& direction):
	origin{origin},
	direction{direction}
	{}
