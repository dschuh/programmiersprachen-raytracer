#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
<<<<<<< HEAD
#include "ray.hpp"
=======
>>>>>>> b0a8e5889e5176a1bbd8c6e1b5a2f1f04dad6ca8

using namespace std;

class Shape{

<<<<<<< HEAD
=======
//-----Aufgabe 3---------------//
>>>>>>> b0a8e5889e5176a1bbd8c6e1b5a2f1f04dad6ca8
private:
	Color color_;
	string name_;	

public:
	Shape();
	Shape(string const& name);
	Shape(string const& name, Color const& color);

<<<<<<< HEAD
	~Shape();

=======
>>>>>>> b0a8e5889e5176a1bbd8c6e1b5a2f1f04dad6ca8
	Color const& get_color() const;
	string const& get_name() const;

	virtual float area() const =0;
	virtual float volume() const =0;

	virtual ostream& print(ostream& os) const;

<<<<<<< HEAD
	virtual bool intersect (Ray const& ray, float& t)=0;

=======
>>>>>>> b0a8e5889e5176a1bbd8c6e1b5a2f1f04dad6ca8
};

ostream& operator <<(ostream& ostream, Shape const& shape);

#endif