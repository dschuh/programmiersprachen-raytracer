#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include "ray.hpp"
#include "material.hpp"

class Shape{
public:
	Material material_;
	std::string name_;	

	Shape();
	Shape(std::string const& name);
	Shape(std::string const& name, Material const& material);

	~Shape();

	Material const& get_material() const;
	std::string const& get_name() const;

	virtual float area() const =0;
	virtual float volume() const =0;
	virtual std::ostream& print(std::ostream& os) const=0;
	virtual bool intersect (Ray const& ray, float& t)=0;
};

std::ostream& operator <<(std::ostream& ostream, Shape const& shape);

#endif
