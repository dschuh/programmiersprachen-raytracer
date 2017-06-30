#include "material.hpp"

Material::Material():
    name{"empty"},
    ka{Color{0.0f, 0.0f, 0.0f}},
    kd{Color{0.0f, 0.0f, 0.0f}},
    ks{Color{0.0f, 0.0f, 0.0f}},
    m{0.0f}{}


Material::Material(std::string const& nm, Color const& ka, Color const& kd, Color const& ks, float m):
    name{nm},
    ka{ka},
    kd{kd},
    ks{ks},
    m{m}{}

std::ostream& operator<<(std::ostream& os, Material const& m){
    os << "Name:" << m.name << "\n ka:" << m.ka << "\n kd:" << m.kd << "\n ks:" << m.ks
       << "\n m:" << m.m;

    return os;

}
