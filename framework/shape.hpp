#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "material.hpp"

class Shape{
  protected:
    std::string name_;
    Material material_;

  public:
    Shape(std::string const& nm, Material const& matr);

    ~Shape();

    std::string getName() const;
    Material getMaterial() const;

	virtual float area() const = 0;
	virtual float volume() const = 0;

    virtual std::ostream& print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
