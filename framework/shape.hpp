#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include "ray.hpp"
#include "material.hpp"
#include <memory>

class Shape{
public:
	Shape();
	Shape(std::string const& name);
	Shape(std::string const& name, std::shared_ptr<Material> const& material);

	~Shape();

	Material const& get_material() const;
	std::string const& get_name() const;

	virtual float area() const =0;
	virtual float volume() const =0;
	virtual std::ostream& print(std::ostream& os) const=0;
	virtual bool intersect (Ray const& ray, float& t)=0;

private:
    std::shared_ptr<Material> material_;
	std::string name_;	

};

std::ostream& operator <<(std::ostream& ostream, std::shared<Shape> const& shape);

#endif
