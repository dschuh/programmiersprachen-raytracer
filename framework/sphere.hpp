#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <math.h>
#include "shape.hpp"
#include "ray.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

class Sphere : public Shape{

  protected:
	glm::vec3 center;
	float radius;

  public:
	Sphere(std::string const& nmSphere); //Default Constructor
	Sphere(std::string const& nmSphere, Material const& matr, glm::vec3 const& ctr, float r); //Custom Constructor

    ~Sphere();

	//Getter
	glm::vec3 getCenter() const;
	float getRadius() const;

	float area() const override;
	float volume() const override;
   
    std::ostream& print(std::ostream& os) const override;

    bool intersect(Ray const& ray, float& distance);

};

#endif
