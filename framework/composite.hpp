#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "box.hpp"
#include "sphere.hpp"
#include "ray.hpp"

class Composite : public Shape 
{
    Composite();
    Composite(std::string const& name);
    ~Composite();

private:
    std::string m_name;
    std::shared_ptr<Shape>
    
};
#endif