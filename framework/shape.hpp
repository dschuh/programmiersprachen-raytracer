#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include "ray.hpp"

using namespace std;

class Shape{

private:
	Color color_;
	string name_;	

public:
	Shape();
	Shape(string const& name);
	Shape(string const& name, Color const& color);

	~Shape();

	Color const& get_color() const;
	string const& get_name() const;

	virtual float area() const =0;
	virtual float volume() const =0;

	virtual ostream& print(ostream& os) const;

	virtual bool intersect (Ray const& ray, float& t)=0;

};

ostream& operator <<(ostream& ostream, Shape const& shape);

#endif