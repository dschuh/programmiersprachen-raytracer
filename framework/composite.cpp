#include "composite.hpp"

Composite::Composite():
    name("default composite"),
    composite_()
    {}

Composite::Composite(std::string const& name, std::vector<std::shared_ptr<Shape>> comp):
    name(name),
    composite_(comp)
    {}

 Composite::~Composite()
    {} 

void Composite::add_shape(std::shared_ptr<Shape> const& shape)
    {
        composite_.push_back(shape);
    }

void Composite::set_name(std::string const nm)
    {
        name=nm;
    }

float Composite::area() const{
    float area = 0.0f;
    for(auto const& shape : composite_){
        area = shape -> area();
    }
    return area;
}

float Composite::volume() const{
    float volume = 0.0f;
    for(auto const& shape : composite_){
        volume = shape -> volume();
    }
    return volume;
}

std::ostream& Composite::print(std::ostream& ostream) const{
    for(auto const& shape : composite_){
        shape ->print(ostream);
        ostream << "\n";
    }
return ostream;
}

Hit Composite::intersect(Ray const& ray) const{
    Hit hit_temp;
    Hit hit_close;
    for(auto const& i : composite_){
      hit_temp = i -> intersect(ray);
      if(hit_temp.distance_ < hit_close.distance_)
      {
          hit_close = hit_temp;
      }
    }
    return hit_close;
}

