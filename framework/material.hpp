#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "color.hpp"

struct Material{

    std::string const& name;
    Color const& ka;
    Color const& kd;
    Color const& ks;
    float m;

    Material();
    Material(std::string const& nm, Color const& ka, Color const& kd, Color const& ks, float m);

    friend std::ostream& operator<<(std::ostream& os, Material const& m);
    
};



#endif


