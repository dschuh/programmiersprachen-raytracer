#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "ray.hpp"
#include "hit.hpp"
#include <cmath>

class Sphere : public Shape{

public:

	glm::vec3 center_;
	float radius_;

	Sphere();
	Sphere(glm::vec3 const& center, float r);
	Sphere(glm::vec3 const& center, float r, std::shared_ptr<Material> const& material, std::string const& name);
	~Sphere();

	glm::vec3 const& get_center() const;
	float const& get_radius() const;

	float area() const override;
	float volume() const override;

	std::ostream& print(std::ostream& ostream) const override;

	Hit intersect(Ray const& ray) const override;
    Color compute_light(Color const& ambient, Light const& light, Ray const& r, float distance);	

};


#endif
