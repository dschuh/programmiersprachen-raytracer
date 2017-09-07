#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/vec3.hpp>
#include "color.hpp"
#include <memory>

struct Light{
    std::string name_;
    glm::vec3 position_;
    Color color_;
    float brightness_;

    Color setIntensity() const;

    Light();
    Light(std::string const& nm, glm::vec3 const& pos, Color const& clr, float bgts);

    friend std::ostream& operator<<(std::ostream& os, Light const& l);

};



#endif
