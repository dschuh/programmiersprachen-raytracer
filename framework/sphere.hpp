#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <math.h>
#include "shape.hpp"

class Sphere : public Shape{

  private:
	glm::vec3 center;
	float radius;

  public:
	Sphere(std::string const& nm); //Default Constructor
	Sphere(std::string const& nm, Color const& clr, glm::vec3 const& ctr, float r); //Custom Constructor

	//Getter
	glm::vec3 getCenter() const;
	float getRadius() const;

	float area() const override;
	float volume() const override;

};

#endif
