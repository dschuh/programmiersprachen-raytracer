#include "material.hpp"

Material::Material():
    name{"empty"}, ka_{Color{0.0f, 0.0f, 0.0f}}, kd_{Color{0.0f, 0.0f, 0.0f}}, ks_{Color{0.0f, 0.0f, 0.0f}}, 
    m_{0.0f}{}


Material::Material(std::string const& nm, Color const& ka, Color const& kd, Color const& ks, float m):
    name_{nm}, ka_{ka}, kd_{kd}, ks_{ks}, m_{m}{}

std::ostream& operator<<(std::ostream& os, std::shared_ptr<Material> const& m){
    os << "Name:" << m.name_ << "\n ka:" << m.ka_ << "\n kd:" << m.kd_ << "\n ks:" << m.ks_
       << "\n m:" << m.m_ << "\n";

    return os;

}
