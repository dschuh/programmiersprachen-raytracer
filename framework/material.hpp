#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "color.hpp"
#include <string>
#include <memory>

struct Material{

    std::string name_;
    Color ka_;
    Color kd_;
    Color ks_;
    float m_;

    Material();
    Material(std::string const& nm, Color const& ka, Color const& kd, Color const& ks, float m);

    friend std::ostream& operator<<(std::ostream& os, Material const& m);
    
};



#endif


