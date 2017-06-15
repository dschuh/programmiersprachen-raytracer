#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include <math.h>
#include "shape.hpp"

class Box : public Shape {

  private:
	glm::vec3 minimum;
	glm::vec3 maximum;

  public:
	Box(); //Default Constructor
	Box(glm::vec3 const& min, glm::vec3 const& max); //Custom Constructor	

	//Getter
	glm::vec3 getMinimum() const;
	glm::vec3 getMaximum() const;

	float area() const override;
	float volume() const override;

};

#endif
