#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"

class Shape{
  protected:
    std::string const& name_;
    Color const& color_;

  public:
    Shape(std::string const& nm, Color const& clr);

    ~Shape();

    std::string getName() const;
    Color getColor() const;

	virtual float area() const = 0;
	virtual float volume() const = 0;

    virtual std::ostream& print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
