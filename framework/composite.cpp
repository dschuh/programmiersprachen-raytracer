#include "composite.hpp"

Composite::Composite():
    name("default composite"),
    composite_()
    {}

Composite::Composite(std::string const& name):
    name(name),
    composite_()
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

Hit Composite::closest_hit(Ray const& ray){
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