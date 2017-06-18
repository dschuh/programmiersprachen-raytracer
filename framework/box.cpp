#include "box.hpp"
#include <glm/vec3.hpp>
#include <cmath>

Box::Box():
    Shape{"Box"},
    min_{glm::vec3{0.0f}},
    max_{glm::vec3{1.0f}}
    {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color, string const& name):
    Shape{name, color},
    min_{glm::vec3{min}},
    max_{glm::vec3{max}}
    {}

glm::vec3 const& Box::get_min() const
{
	return min_;
}

glm::vec3 const& Box::get_max() const
{
	return max_;
}

float Box::area() const {
	return  abs((2 * (max_.x - min_.x) * (max_.y - min_.y)) +
			(2 * (max_.x - min_.x) * (max_.z - min_.z)) +
			(2 * (max_.y - min_.y) * (max_.z - min_.z)));
}

float Box::volume() const{
	return  abs((max_.x - min_.x) * (max_.y - min_.y) *	(max_.z - min_.z));
}