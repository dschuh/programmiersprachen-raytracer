#include "ray.hpp"

Ray::Ray()
	: origin_{glm::vec3{0.0}}
	, direction_{glm::vec3{0.0}}
	{}

Ray::Ray(glm::vec3 const& origin, glm::vec3 const& direction)
	: origin_{origin}
	, direction_{direction}
	{}

Ray Ray::transformRay(glm::mat4 const& world_transformation_inv, Ray const& ray){
	Ray new_ray;
	glm::vec3 new_origin(world_transformation_inv * glm::vec4(ray.origin_, 1));
   	glm::vec3 new_direction(world_transformation_inv * glm::vec4(ray.direction_, 0));
    new_ray.origin_ = new_origin;
   	new_ray.direction_ = new_direction;
	return new_ray;
} 