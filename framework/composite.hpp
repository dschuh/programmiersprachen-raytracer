#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "shape.hpp"

class Composite : public Shape 
{
public:
    Composite();
    Composite(std::string const& name);
    ~Composite();

    void add_shape(std::shared_ptr<Shape> const& shape);
    void set_name(std::string const nm);
    Hit closest_hit(Ray const& ray);

private:
    std::string name;
    std::vector<std::shared_ptr<Shape>> composite_;
    
};
#endif
