#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "material.hpp"

class Shape{
  protected:
    std::string const& name_;
    Material const& material_;

  public:
    Shape(std::string const& nm, Material const& matr);

    ~Shape();

    std::string const& getName() const;
    Material const& getMaterial() const;

	virtual float area() const = 0;
	virtual float volume() const = 0;

    virtual std::ostream& print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
