#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape{

	glm::vec3 min_;
	glm::vec3 max_; 

public:

	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color, String const& name);

	glm::vec3 const& get_min() const;
	glm::vec3 const& get_max() const;

	float area() const override;
	float volume() const override;

	std::ostream& print(std::ostream& os) const override;
	
};

#endif