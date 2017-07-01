#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "ray.hpp"

class Sphere : public Shape{

private:

	glm::vec3 center_;
	float radius_;

public:

	Sphere();
	Sphere(glm::vec3 const& center, float r);
	Sphere(glm::vec3 const& center, float r, Color const& clr, string const& name);
<<<<<<< HEAD
	~Sphere();

	glm::vec3 const& get_center() const;
	float get_radius() const;
=======

	glm::vec3 const& get_center() const;
	float const& get_radius() const;
>>>>>>> b0a8e5889e5176a1bbd8c6e1b5a2f1f04dad6ca8

	float area() const override;
	float volume() const override;

	std::ostream& print(std::ostream& ostream) const override;

<<<<<<< HEAD
	bool intersect(Ray const& ray, float distance);
=======
	bool intersect(Ray ray, float distance);
>>>>>>> b0a8e5889e5176a1bbd8c6e1b5a2f1f04dad6ca8

};


#endif