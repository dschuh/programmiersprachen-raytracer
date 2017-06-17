#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "ray.hpp"

class Sphere : public Shape{

	glm::vec3 center_;
	float radius_;

public:

	Sphere();
	Sphere(glm::vec3 const& center, float r, Color const& clr, String const& name);

	glm::vec3 const& get_center() const;
	float get_radius() const;

	float area() const override;
	float volume() const override;
};