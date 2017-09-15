#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "ray.hpp"
#include "material.hpp"
#include "hit.hpp"
#include "window.hpp"
#include "light.hpp"
#include <math.h>
#include <memory>

//forward-declare inclompete type
struct Hit;

class Shape{
public:
	Shape();
	Shape(std::string const& name);
	Shape(std::string const& name, std::shared_ptr<Material> const& material);

	~Shape();

	std::shared_ptr<Material> const& get_material() const;
	std::string const& get_name() const; //Nutzt man const& nicht nur bei der Übergabe von zusammen gesetzten Datentypen?
    //virtual Color compute_light(); //Const correctness einfügen

	virtual float area() const =0;
	virtual float volume() const =0;
	virtual std::ostream& print(std::ostream& os) const=0;
	virtual Hit intersect (Ray const& ray) const=0;
	virtual Color compute_light(Color const& ambient, Light const& light, Ray const& r, float distance)const =0;
	


private:
    std::shared_ptr<Material> material_;
	std::string name_;	

};

std::ostream& operator <<(std::ostream& ostream, Shape const& shape);

#endif
