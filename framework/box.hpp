#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include "ray.hpp"
#include <cmath>

class Box : public Shape{

public:
	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max, std::shared_ptr<Material> const& material, std::string const& name);

	glm::vec3 const& get_min() const;
	glm::vec3 const& get_max() const;

	float area() const override;
	float volume() const override;
	
	bool intersect(Ray const& ray, float& distance) override;

	std::ostream& print(std::ostream& ostream) const override;

private:
	glm::vec3 min_;
	glm::vec3 max_; 

};

#endif
